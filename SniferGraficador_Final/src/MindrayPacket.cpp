#include "..\Include\MindrayPacket.h"



MindrayPacket::MindrayPacket() {



};


MindrayPacket::MindrayPacket(const MindrayPacket & ref)
{
	
};


MindrayPacket::~MindrayPacket()
{
	this->head.~HeaderTram();
	this->subtrmas.erase(subtrmas.begin(), subtrmas.end());
	this->subtrmas.clear();
	this->data_time.clear();
	this->fuente.clear();
};


int MindrayPacket::carfarSubTram(const std::vector<uint8_t> &datas, int pos) {
	SubTramaMi su;
	int tamar = 0;
	pos=su.loadHead(datas, pos);
	tamar = su.sizePSubtrama();
	std::cout << "este es el join de subHead" << su.joinHeader() << std::endl;
	//getchar();
	if (su.joinHeader() == "32507909") {
		pos = su.addData(datas, pos,su.sizePSubtrama()*2);
		this->tam += (tamar*2) + su.sizeSub();
	}else if(su.joinHeader() == "33556485"){
		pos=su.addData(datas,pos,su.sizePSubtrama()*2);
		this->tam += (tamar * 2) + su.sizeSub();
	}else{
		pos=su.addData(datas,pos,su.sizePSubtrama());
		this->tam += tamar  + su.sizeSub();
	}
	this->subtrmas.push_back(su);
	su.~SubTramaMi();
	return pos;
};

int MindrayPacket::clasifyData(const std::vector<uint8_t> &datas  , int pos) {
	int tma=0;
	pos=this->head.loadHead(datas, pos);
	tma = head.sizePacket();
	this->tam = head.cantPacket(0);
	pos+=7;
	//printf("el valor actual en datas es %X\n", datas.at(pos)); 
	//printf("y el siguiente %X\n", datas.at(pos + 1));
	do {
		pos=carfarSubTram(datas,pos);
	} while (this->tam < tma);
	this->tam = 0;
	//cout << "tam paquete : "<< this->head.sizePacket() << endl;
	return pos;
};

void MindrayPacket::setFuente(const std::string  &fuente) {
	this->fuente = fuente;
}

void MindrayPacket::setDtaTime(const std::string &data_time) {
	this->data_time = data_time;
}



void MindrayPacket::setHead(const HeaderTram &head) {
	this->head = head;
}


std::string  MindrayPacket::getFuente() {
	return this->fuente;
}


 std::string  MindrayPacket::getDataTime() {
	return this->data_time;
}

 HeaderTram MindrayPacket::getHead() {
	return this->head;
}






