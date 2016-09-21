#include "..\Include\MindrayAlarma.h"



MindrayAlarma::MindrayAlarma(const MindrayAlarma &a) {


}

MindrayAlarma::MindrayAlarma()
{
}


MindrayAlarma::~MindrayAlarma()
{
}

int MindrayAlarma::carfarSubTram(const std::vector<uint8_t> &datas,int pos) {


	return 0;
}



int MindrayAlarma::clasifyData(const std::vector<uint8_t> &datas,int post) {

	return 0;
}

int MindrayAlarma::getTipo(int tip) const {
	return tip + 2;
}

std::string MindrayAlarma::getFuente() {
	return this->fuente;
}


void  MindrayAlarma::setFuente(const std::string fuent){
	this->fuente = fuent;
}