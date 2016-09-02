#include "..\Include\CapturaDeRed.h"


using namespace Tins;

CapturaDeRed::CapturaDeRed() 
{
	
};



CapturaDeRed::~CapturaDeRed()
{
}



void CapturaDeRed::CapturarPacket() {
	NetworkInterface iface = NetworkInterface::default_interface();
	SnifferConfiguration sc;
	sc.set_promisc_mode(true);
	sc.set_snap_len(64 *1024);
	sc.set_filter("ip and tcp");
	Sniffer s(iface.name(), sc);
}

