#ifndef NRF_POS_SERVICE_HPP
#define NRF_POS_SERVICE_HPP

#include <string>
#include <vector>

struct posElmt //record of position
{
	std::string time;
	double lati;
	double longi;
	double alti;

	posElmt(std::string t, double la, double lo, double al) : time(t), lati(la), longi(lo), alti(al)
	{ }
};

class NrfPosition
{
private:
	std::string m_file_path; //ephemeris file path
	std::vector<posElmt> m_pos_vec;
	bool m_normal_flag = 1; //in case fail to open ephemeris file

public:
	NrfPosition(std::string filepath);

	void Start(void);
};

#endif /* NRF_POS_SERVICE_HPP */