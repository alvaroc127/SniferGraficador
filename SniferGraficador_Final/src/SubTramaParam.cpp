#include "..\Include\SubTramaParam.h"
#include "..\Include\SubTramaAlarma.h"
#include "..\Include\SubTramaArt_AP.h"
#include "..\Include\SubTramaECG.h"
#include "..\Include\SubTramaImpedancia.h"
#include "..\Include\SubtRamTemp.h"
#include "..\Include\SubTramSpo2.h"
#include <iostream>



SubTramaParam::SubTramaParam(const SubTramaParam &a) {

}

SubTramaParam::SubTramaParam()
{
}


SubTramaParam::~SubTramaParam()
{
	this->datas.erase(datas.begin(), datas.end());
	this->datas.clear();
	  start=0;
	  vodi=0;
	 size=0;
	 delete [] start;
	 delete [] vodi;
	 delete [] size;
}

SubTramaParam::SubTramaParam(int t1,int t2 , int t3) {
	this->start = new uint8_t[t1];//2
	this->vodi = new uint8_t[t2];//3
	this->size = new uint8_t[t3];//2
	this->siz= t1 + t2 + t3;
}

SubTramaParam::SubTramaParam(uint8_t start1 [] , uint8_t vody [], uint8_t size[]){
	this->start = start1;
	this->vodi = vody;
	this->size = size;
	
}


std::string SubTramaParam::joinHeader(){
	std::stringstream a1;
	uint16_t v1;
	uint32_t v2;
	uint16_t v3;
	v1 = ((this->start[0]<< 8) | this->start[1]);
	a1 << std::hex << v1;
	v2 = (this->vodi[0] << 16) | this->vodi[1] << 8 | this->vodi[2];
	a1 << std::hex << v2;
	v3 = this->size[0] << 8 | this->size[1];
	a1 << std::hex << v3;
	return a1.str();
}


int SubTramaParam::sizeSub() {
	return this->siz;
}


int SubTramaParam::sizePSubtrama() {
	uint16_t con = ((this->size[0] << 8) | this->size[1]);
	return (int)con;
}



int SubTramaParam::seleccionMetod(int cod) {
	std::cout << cod << std::endl;
	int tip = 0;
	if (cod ==65541) {
		tip=0;
	}
	else if (cod==1114117) {
		tip += 1;
	}else if (cod==2294026) {
		tip += 2;
	}
	else if (cod==1179653) {
		tip += 3;
	}
	else if (cod==8454149) {
		tip += 5;
	}
	else if (cod==8650757) {
		tip += 6;
	}
	else{
		tip = 10;
	}
	return tip;
}

int SubTramaParam::loadHead(const std::vector<uint8_t> & datas, int pos) {
	int pos1 = 0;
	for (int i = 0; i < datas.size() && i < 7; i++) {
		if (i<2) {
			this->start[pos1++] = datas.at(pos++);
		}
		else if(i>=2 && i< 5){
			if (i == 2)pos1 = 0;
			this->vodi[pos1++] =  datas.at(pos++);
		}
		else if(i >= 5 && i < 7){
			if (i == 5) pos1 = 0;
			this->size[pos1++] = datas.at(pos++);
		}
	}
	return pos;
}

int SubTramaParam::addData(const std::vector<uint8_t> & datas, int pos, int tam) {
	int cont = 0;
	for (int i = pos; i < datas.size() && cont < tam; i++) {
		this->datas.push_back(datas.at(i));
		pos = i;
		cont++;
	}
	return ++pos;
}


uint8_t * SubTramaParam::getstart() {
	return this->start;
}

uint8_t * SubTramaParam::getsize() {
	return this->size;
}

uint8_t * SubTramaParam::getvodi() {
	return this->vodi;
}

void SubTramaParam::setSiz(int siz) {
	this->siz = siz;
}