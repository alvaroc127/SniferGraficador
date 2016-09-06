#include "..\Include\CapturaDeRed.h"
#include<windows.h>
#include<process.h>


using namespace Tins;
using namespace std;


/// <summary>
/// This Method capture packet TCP of network and send from claisify
/// </summary>
unsigned __stdcall CapturarPacket1(void *);
struct MyData *dta = NULL;

CapturaDeRed::CapturaDeRed() 
{
	
};




CapturaDeRed::~CapturaDeRed()
{
};

/*
sacar carga util empezar mecanismos de clasificacion.
*/
void CapturaDeRed::clasificarPacket(std::vector<uint8_t> carga) {
	for (const uint8_t a : carga) {
		printf("%x", a);
	}
}

unsigned __stdcall CapturarPacket1(void *ap)
{
	dta = (MyData*)ap;
	Sniffer snfi(dta->ifaceName.name(), dta->s1);
	do {
		PDU *pack = snfi.next_packet();
	 	TCP  tcp = pack->rfind_pdu<TCP>();
		try {
			RawPDU & raw = tcp.rfind_pdu<RawPDU>();
			CapturaDeRed::clasificarPacket(raw.payload());
			delete(pack);
		}
		catch (pdu_not_found) {
			cout << "problema no encontrado" << endl;
			delete(pack);
		}
	} while (true);
	_endthreadex(0);
	return 0;
}





const NetworkInterface CapturaDeRed::configCapture() {
	NetworkInterface iface = NetworkInterface::default_interface();
	return iface;
}


const SnifferConfiguration CapturaDeRed::configSniffer() {
	SnifferConfiguration sc;
	sc.set_promisc_mode(true);
	sc.set_snap_len(64 *1024);
	sc.set_filter("ip and tcp");
	return sc;
}


void CapturaDeRed::startCapture() {
	HANDLE hTread;
	unsigned threadID;
	 MyData *data=new MyData;
	data->ifaceName = configCapture();
	data->s1 = configSniffer();
	//creo el hil y lo asigno
	hTread = (HANDLE)_beginthreadex(NULL, 0,&CapturarPacket1, data, 0, &threadID);
	if (hTread) {
		std::cout << "hilo iniciado" << endl;
		SetPriorityClass(hTread, HIGH_PRIORITY_CLASS);
		WaitForSingleObject(hTread,INFINITE);
		delete(data);
	}
}
