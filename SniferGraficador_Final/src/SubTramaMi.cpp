#include "..\Include\SubTramaMi.h"



SubTramaMi::SubTramaMi()
{
}


SubTramaMi::~SubTramaMi()
{


}


int SubTramaMi::loadHead(std::vector<uint8_t> datas, int pos) {
	int pos1 = 0;
	for (int i = 0; i < datas.size() && i < 4; i++) {
		if (i < 1) {
			this->start[pos1++] = (0x0 << 8) | datas.at(pos);
			pos++;
		}
		else if (i >= 1 && i < 3) {
			if (i == 1) pos1 = 0;
			this->size[pos1++] = (0x0 << 8) | datas.at(pos);
			pos++;
		}
		else {
			if (i == 3)pos1 = 0;
			this->end[pos1++] = (0x0 << 8) | datas.at(pos);
			pos++;
		}
	}
	return pos;
}

int SubTramaMi::sizePSubtrama(){
	uint16_t con = ((this->size[0] << 8) | this->size[1]);
	return (int)con;
}


int SubTramaMi::sizeSub(){


	return 0;
}

std::string SubTramaMi::joinHeader() {
	uint32_t con = ((this->start[0] << 24) | (this->size[0]<< 16)| (this->size[1]<<8) | this->end[0]);
	return std::to_string((int)con);
}

int SubTramaMi::addData(std::vector<uint8_t> datas,int pos, int tam) {
	int cont = 0;
	for (int i = pos; i < datas.size() && cont < tam;i++) {
		this->datas.push_back(datas.at(i));
		pos = i;
		cont++;
	}
	return ++pos;
}