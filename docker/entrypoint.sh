#---------------------------------------------------------------------
#
# Docker entrypoint file for setting up environment variables and generating conf file
#   Valid for Ubuntu-18.04 (bionic)
#
#---------------------------------------------------------------------
#!/bin/bash

INSTANCE=1
PREFIX='/usr/local/etc/oai'
mkdir -m 0777 -p $PREFIX
cp /openair-nrf/etc/nrf.conf  $PREFIX

declare -A NRF_CONF

NRF_CONF[@INSTANCE@]=$INSTANCE
NRF_CONF[@PREFIX@]=$PREFIX
NRF_CONF[@PID_DIRECTORY@]='/var/run'

NRF_CONF[@NRF_INTERFACE_NAME_FOR_SBI@]=$NRF_INTERFACE_NAME_FOR_SBI

NRF_CONF[@NRF_INTERFACE_PORT_FOR_SBI@]=$NRF_INTERFACE_PORT_FOR_SBI
NRF_CONF[@NRF_INTERFACE_HTTP2_PORT_FOR_SBI@]=$NRF_INTERFACE_HTTP2_PORT_FOR_SBI
NRF_CONF[@NRF_API_VERSION@]=$NRF_API_VERSION


for K in "${!NRF_CONF[@]}"; do 
  egrep -lRZ "$K" $PREFIX | xargs -0 -l sed -i -e "s|$K|${NRF_CONF[$K]}|g"
  ret=$?;[[ ret -ne 0 ]] && echo "Tried to replace $K with ${NRF_CONF[$K]}"
done

cd /openair-nrf/bin/ && ./oai_nrf -c /usr/local/etc/oai/nrf.conf -o