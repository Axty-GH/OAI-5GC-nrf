#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "logger.hpp"
#include "nrf-pos-service.hpp"


using namespace std;


NrfPosition::NrfPosition(string filepath) : m_file_path(filepath)
{
	ifstream in_fstream;
	istringstream line_stream;
	
	string temp_str;
	string temp_time;
	double temp_lati;
	double temp_longi;
	double temp_alti;

	in_fstream.open(filepath, ios::in);
	if(in_fstream.fail())
	{
		cout << "Ephemeris File Failed to Open" << endl;
		m_normal_flag = 0;
		return;
	}

	m_pos_vec.clear();
	while(getline(in_fstream, temp_str))
	{	// Read each line of ephemeris file
		line_stream.clear();
		line_stream.str(temp_str);

		// Time
		getline(line_stream, temp_str, ',');
		temp_time = temp_str;
		// Latitude
		getline(line_stream, temp_str, ',');
		temp_lati = stod(temp_str);
		// Longitude
		getline(line_stream, temp_str, ',');
		temp_longi = stod(temp_str);
		// Altitude
		getline(line_stream, temp_str, ',');
		temp_alti = stod(temp_str);

		m_pos_vec.emplace_back(temp_time, temp_lati, temp_longi, temp_alti);
	}
}

void NrfPosition::Start(void)
{
	static unsigned long count = 0;
	stringstream strstream;

	// Config decimal output format
	strstream.unsetf(ios::fixed);
	strstream.setf(ios_base::showpoint);
	strstream.precision(6);

	while(m_normal_flag)
	{
		strstream.clear();
		strstream.str("");
		strstream << "Latitude:" << m_pos_vec[count].lati << "°\tLongitude:" << m_pos_vec[count].longi << "°\tAltitude:" << m_pos_vec[count].alti << "km";
		Logger::nrf_pos().info(strstream.str().c_str());
	
		if(m_pos_vec.size())
		{
			count = (count+1) % m_pos_vec.size();
		}
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
}
