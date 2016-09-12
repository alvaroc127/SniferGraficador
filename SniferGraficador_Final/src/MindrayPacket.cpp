#include "..\Include\MindrayPacket.h"



MindrayPacket::MindrayPacket() {



};


MindrayPacket::MindrayPacket(const MindrayPacket & ref)
{
	*this = ref;
};


MindrayPacket::~MindrayPacket()
{


};


int MindrayPacket::carfarSubTram(vector<uint8_t>datas, int pos) {
	SubTramaMi su;
	pos=su.loadHead(datas, pos);
	//cout << "este es el join de subHead" << su.joinHeader() << endl;
	//getchar();
	if (su.joinHeader()=="32507909") {
		pos = su.addData(datas, pos,su.sizePSubtrama()*2);
	}else if(su.joinHeader()=="33556485"){
		pos=su.addData(datas,pos,su.sizePSubtrama()*2);
	}else{
		pos=su.addData(datas,pos,su.sizePSubtrama());
	}
	this->subtrmas.push_back(su);
	return pos;
};

int MindrayPacket::clasifyData(vector<uint8_t>datas , int pos) {
	pos=this->head.loadHead(datas, pos);
	pos+=7;
	//printf("el valor actual en datas es %X\n", datas.at(pos)); 
	//printf("y el siguiente %X\n", datas.at(pos + 1));
	do {
		pos=carfarSubTram(datas,pos);
	} while (pos < head.sizePacket());
	//cout << "tam paquete : "<< this->head.sizePacket() << endl;
	return pos;
};

void MindrayPacket::setFuente(string  fuente) {
	this->fuente.swap(fuente);
}

void MindrayPacket::setDtaTime(string data_time) {
	this->data_time.swap(data_time);
}



void MindrayPacket::setHead(HeaderTram head) {
	this->head = head;
}


 string  MindrayPacket::getFuente() {
	return this->fuente;
}


const string & MindrayPacket::getDataTime() {
	return this->data_time;
}

const HeaderTram & MindrayPacket::getHead() {
	return this->head;
}


int MindrayPacket::getTipo(int tip) const {
	return tip+1;
}