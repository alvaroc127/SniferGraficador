#include "..\Include\CapturaDeRed.h"
#include<windows.h>
#include<process.h>


using namespace Tins;
using namespace std;


/// <summary>
/// This Method capture packet TCP of network and send from claisify
/// </summary>
//unsigned __stdcall CapturarPacket1(void *);
//struct MyData *dta = NULL;

CapturaDeRed::CapturaDeRed() 
{
	
};




CapturaDeRed::~CapturaDeRed()
{
};

/*
sacar carga util empezar mecanismos de clasificacion.
*/
string CapturaDeRed::clasificarPacket(std::vector<uint8_t> & carga, int pos) {
	string cab;
	stringstream ss;
	if (carga.empty() == false && carga.size() > 1) {
		for (int i = 0; i < 6 && i<carga.size(); i++) {
			ss << std::hex <<(int)carga.at(pos++);
		}
		cab = ss.str();
		ss.clear();
		cout.clear();
	}
	return cab;
}

void CapturaDeRed::CapturarPacket1() {
	Sniffer snfi(configCapture().name(), configSniffer());
	int pos = 0;
	bool band = true;
	do {
		PDU *pack = snfi.next_packet();
		TCP  tcp = pack->rfind_pdu<TCP>();
		IP ip = pack->rfind_pdu<IP>();
		try {
			RawPDU & raw = tcp.rfind_pdu<RawPDU>();
			do {
				pos=confHead(clasificarPacket(raw.payload(),pos), ip.src_addr().to_string(), raw.payload(),pos);
				if (pos == 0) {
					band = false;
					this->dat_time.swap(captDta_time());
				}
				else {
					band = true;
				}
			} while (pos<raw.payload().size()&&band==true&&this->wait==true);
			pos = 0;
			wait = true;
			delete(pack);
		}
		catch (pdu_not_found) {
			cout << "problema no encontrado" << endl;
			delete(pack);
		}
	} while (true);
}

/*
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
*/



const NetworkInterface  CapturaDeRed::configCapture() {
	NetworkInterface a;
	try {
		a = NetworkInterface::default_interface();
	}catch(invalid_interface) {
		vector<NetworkInterface> infaces = NetworkInterface::all();
		for (const NetworkInterface & ia: infaces) {
			cout << "iNTERFACE" << ia.name();
			wcout << "("<<ia.friendly_name()<<")"<< endl;
		}
		a = infaces.at(0);
	}
	return a;
}


const SnifferConfiguration  CapturaDeRed::configSniffer() {
	SnifferConfiguration sc;
	sc.set_promisc_mode(true);
	sc.set_snap_len(64 *1024);
	sc.set_filter("ip and tcp");
	return sc;
}


void CapturaDeRed::startCapture() {
	CapturarPacket1();
	/*
	HANDLE hTread;
	unsigned threadID;
	 MyData *data=new MyData;
	data->ifaceName = configCapture();
	data->s1 = configSniffer();

	creo el hil y lo asigno
	hTread = (HANDLE)_beginthreadex(NULL, 0,&CapturarPacket1, data, 0, &threadID);
	if (hTread) {
		std::cout << "hilo iniciado" << endl;
		SetPriorityClass(hTread, HIGH_PRIORITY_CLASS);
		WaitForSingleObject(hTread,INFINITE);
		delete(data);
	}
	*/
}



int CapturaDeRed::confHead(string head,string ip,vector<uint8_t> datas, int pos) {
	//cout << "esto es head" << head<<endl;
	if (head == "1509d00") {
		if(this->dat_time.empty()==false){
		MindrayPacket mp;
		mp.setFuente(ip);
		mp.setDtaTime(this->dat_time);
		HeaderTram he = mp.getHead();
		he.loadHead(datas, pos);
		cout << "la ip es" << mp.getFuente() << "con cabeza" << head << endl; cout<< "el paquete llego a las" << mp.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		cout << "restante trama" << datas.size() - pos << endl;
		if (he.sizePacket() <= (datas.size() - pos) ) {
			mp.setHead(he);
			pos=mp.clasifyData(datas, pos);
			this->wait = true;
			//ar.gestionarArchvo()
		}
		else {
			setVector(datas);
			this->mp = mp;
			this->wait = false;
			posG = pos;
			///cout << "se guardo trama" << endl;
			//guarda el paqutee
			// cargar datos 
			}
		}
	}
	else if (head == "150cc00") {
		if (pos==0) {
			this->dat_time.swap(captDta_time());
		}
		/*
		MindrayParametros mp1;
		mp1.setFuente(ip);
		//cout<<mp.getFuente()<<endl;
		mp1.setDtaTime(captDta_time());
		//cout << mp.getDataTime() << endl;
		HeaderTram he = mp1.getHead();
		he.loadHead(datas, pos);
		cout << "la ip es" << mp1.getFuente() << "con cabeza" << head << endl; cout << "el paquete llego a las" << mp1.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		if (datas.size() >= he.sizePacket) {
			mp1.setHead(he);
			mp1.clasifyData(datas, pos);
			//ar.gestionarArchvo()
		}
		else {
			setVector(datas);
			
			//guarda el paqutee
			// cargar datos 
		}
		*/
		
	}
	else if (head=="1503600" || head=="1503800") {
		/*
		//cargar el identificadorde alarma para los parametoro //alarma fisiologica y de sistema
		MindrayAlarma mp;
		mp.setFuente(ip);
		//cout<<mp.getFuente()<<endl;
		mp.setDtaTime(this->dat_time));
		//cout << mp.getDataTime() << endl;
		HeaderTram he = mp.getHead();
		he.loadHead(datas, pos);
		cout << "la ip es" << mp.getFuente() << "con cabeza" << head << endl; cout << "el paquete llego a las" << mp.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		if (datas.size() >= he.sizePacket) {
			mp.setHead(he);
			mp.clasifyData(datas, pos);
			//ar.gestionarArchvo()
		}
		else {
			setVector(datas);
			this->trama = &mp;
			//guarda el paqutee
			// cargar datos 
		}
		*/
	}
	else {
		if (datWait.empty()==false){
			datWait.insert(std::end(datWait), std::begin(datas), std::end(datas));
			if (this->mp.getFuente().empty() == false) {
				mp.clasifyData(datWait, posG);
				//clasificar archivo
				mp.getFuente().clear();
			}
			else if (this->ma.getFuente().empty() == false) {
				ma.clasifyData(datWait, posG);
				//gestionadoor de archivos
				ma.getFuente().clear();
			}
			else if (this->mpp.getFuente().empty() == false) {
				mpp.clasifyData(datWait, posG);
				//gestionador de archivos
				mpp.getFuente().clear();
			}
		}else{
			datas.clear();
			// no es packet
		}
	}
	return pos;
}


string  CapturaDeRed::captDta_time() {
	string data_ti;
	SYSTEMTIME  lt;
	GetLocalTime(&lt);
	data_ti+=std::to_string(lt.wYear)+"-"+std::to_string(lt.wMonth)+"-"+std::to_string(lt.wDayOfWeek)+" "+std::to_string(lt.wHour)+":"+std::to_string(lt.wMinute)+":"+std::to_string(lt.wSecond)+":"+
	std::to_string(lt.wMilliseconds);
	return  data_ti;
}



void CapturaDeRed::setVector(vector<uint8_t> v) {
	this->datWait.swap(v);
}

const vector<uint8_t> CapturaDeRed::getDataWait() {
	return this->datWait;
}


