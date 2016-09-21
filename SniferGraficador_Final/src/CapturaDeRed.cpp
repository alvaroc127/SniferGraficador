#include "..\Include\CapturaDeRed.h"
#include<crtdbg.h>


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
string CapturaDeRed::clasificarPacket(const std::vector<uint8_t> & carga, int pos) {
	string cab;
	stringstream ss;
	if (carga.empty() == false && carga.size() > 4 && pos+1<carga.size()) {
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
	Tins::Sniffer snfi(configCapture().name(), configSniffer());
	int pos =0,posAux = 0;
	bool band = true;
	TCP tcp;
	IP ip;
	PDU *pack;
	do {
		pack = snfi.next_packet();
		tcp = pack->rfind_pdu<TCP>();
		ip = pack->rfind_pdu<IP>();
		try {
		 RawPDU raw = tcp.rfind_pdu<RawPDU>();
			do {
				posAux = pos;
				pos=confHead(clasificarPacket(raw.payload(),pos), ip.src_addr().to_string(), raw.payload(),pos);
				//cout << "pos " << pos << "posAux " << posAux << endl;
				if (pos == posAux && this->wait==true) {
					pos=searchHead(raw.payload(), pos);
					//cout<<"esto es "<<"esto es pos"<<pos<<"-- "<<posAux<<"-*///"<<clasificarPacket(raw.payload(),pos)<<"esto es "<<endl;
					if (pos==posAux) {
						band = false;
					}
				}
			} while (pos<raw.payload().size()&&this->wait==true&&band==true);
			pos = 0;
			wait = true;
			band = true;
			//delete(pack);
		}
		catch (pdu_not_found) {
			//cout << "problema no encontrado" << endl;
			cout.clear();
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



Tins::NetworkInterface  CapturaDeRed::configCapture() {
	NetworkInterface a;
	try {
		a = NetworkInterface::default_interface();
	}catch(invalid_interface) {
		vector<NetworkInterface> infaces = NetworkInterface::all();
		a = infaces.at(0);
		infaces.clear();
	}
	return a;
}


 Tins::SnifferConfiguration  CapturaDeRed::configSniffer() {
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



int CapturaDeRed::confHead(const std::string &head, const std::string &ip,const std::vector<uint8_t>  & datas , int pos) {
	//cout << "esto es head" << head<<endl;
	if (head == "1509d00") {
		if(this->dat_time.empty()==false){
		MindrayPacket mp;
		mp.setFuente(ip);
		mp.setDtaTime(this->dat_time);
		HeaderTram he = mp.getHead();
		he.loadHead(datas, pos);
		//cout << "la ip es" << mp.getFuente() << "con cabeza" << head << endl; cout<< "el paquete llego a las" << mp.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		//cout << "restante trama" << datas.size() - pos << endl;
		if (he.sizePacket() <= (datas.size() - pos) ) {
			mp.setHead(he);
			pos=mp.clasifyData(datas, pos);
			this->wait = true;
			mp.~MindrayPacket();
			//ar.gestionarArchvo()
		}
		else {
			//cout << "incompleto quedo en espera" << endl;
			setVector(datas);
			this->mp = mp;
			this->wait = false;
			posG = pos;
			///cout << "se guardo trama" << endl;
			//guarda el paqutee
			// cargar datos 
			}
		}
		else {
			//cout << "no cargo ECG"<<endl;
		}
	}
	else if (head == "150cc00") {
		this->dat_time.swap(captDta_time());	
		MindrayParametros mp1;
		mp1.setFuente(ip);
		//cout<<mp.getFuente()<<endl;
		mp1.setDtaTime(dat_time);
		//cout << mp.getDataTime() << endl;
		HeaderTram he = mp1.getHead();
		//cout << "pos head"<< pos << endl;
		he.loadHead(datas, pos);
		//cout << "en parametros la ip es" << mp1.getFuente() << "con cabeza" << head << endl; cout << "el paquete llego a las" << mp1.getDataTime() << " el tamanio " << he.sizePacket() << endl;
		if (datas.size() >= he.sizePacket()) {
			mp1.setHead(he);
			pos=mp1.clasifyData(datas, pos);
			this->wait = true;
			mp1.~MindrayParametros();
			//ar.gestionarArchvo()
		}
		else {
			setVector(datas);
			this->mpp = mp1;
			this->wait = false;
			posG = pos;
			//guarda el paqutee
			// cargar datos 
		}	
		
	}
	else {
		if (datWait.empty()==false){
			datWait.insert(std::end(datWait), std::begin(datas), std::end(datas));
			if (this->mp.getFuente().empty() == false) {
				pos=mp.clasifyData(datWait, posG);
				//clasificar archivo
				mp.getFuente().clear();
				datWait.clear();
			}
			else if (this->ma.getFuente().empty() == false) {
				ma.clasifyData(datWait, posG);
				//gestionadoor de archivos
				ma.getFuente().clear();
				datWait.clear();
			}
			else if (this->mpp.getFuente().empty() == false) {
				mpp.clasifyData(datWait, posG);
				//gestionador de archivos
				mpp.getFuente().clear();
				datWait.clear();
			}
			else {
				//cout << "ENTROOOOOOOOOOOOOOOOOOOOOOOOOO NO hizo NDA" << endl;
			}
		}else{

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



void CapturaDeRed::setVector(const vector<uint8_t> &v) {
	this->datWait = v;
}

 vector<uint8_t> CapturaDeRed::getDataWait() {
	return this->datWait;
}


int CapturaDeRed::searchHead(const vector<uint8_t> &datas, int pos) {
	string hed;
	stringstream posib;
	bool ban = false;
	int cont = 0;
	uint32_t var;
	uint32_t var2;
	//printf(" INICIO %0x\n", datas.at(pos));
	for (pos; pos < datas.size()  && pos+6 <datas.size() && ban==false ;pos++) {
		cont = pos;
		var = ((datas.at(cont++) << 16) | (datas.at(cont++) << 8) | (datas.at(cont++)));
		var2 = ((datas.at(cont++) << 16) | (datas.at(cont++) << 8) | (datas.at(cont++)));
		posib << std::hex <<var;
		posib << std::hex << var2;
		hed = posib.str();
		posib.str("");
		//printf("esto es el valor %x",var);
		//printf("%x\n", var2);
		cout<<hed<<endl;
		if (hed == "105009d0000") {
			ban = true;
			//cout << "esto es cabeza1-*-*"<< hed<< endl;
			pos = cont - 6;
		}
		else if (hed == "10500cc0000"){
			//cout << "esto es cabeza2-*-*" << hed << endl;
			ban = true;
			pos = cont - 6;
		}
		else if (hed == "10500360000" || hed == "10500380000") {
			//cout << "esto es cabeza3-*-*" << hed << endl;
			ban = true;
			pos = cont - 6;
		}
		else {
			hed.clear();
		} 
	}
	posib.clear();
	hed.clear();
	return pos-1;
}