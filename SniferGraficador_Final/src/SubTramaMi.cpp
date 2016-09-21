#include "..\Include\SubTramaMi.h"
#include <string>
using namespace std;

SubTramaMi::SubTramaMi(const SubTramaMi &) {

}

SubTramaMi::SubTramaMi()
{
}


SubTramaMi::~SubTramaMi()
{
	datas.erase(datas.begin(), datas.end());
	this->datas.clear();
	start = 0;
	delete []start;
	size = 0;
	delete []size;
	end = 0;
	delete []end;
}


int SubTramaMi::loadHead(const std::vector<uint8_t> &datas, int pos) {
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
	return lenght(start)+lenght(end)+lenght(this->size);
}

std::string SubTramaMi::joinHeader() {
	uint32_t con = ((this->start[0] << 24) | (this->size[0]<< 16)| (this->size[1]<<8) | this->end[0]);
	return  to_string((int)con);
}

int SubTramaMi::addData(const std::vector<uint8_t> &datas,int pos, int tam) {
	int cont = 0;
	for (int i = pos; i < datas.size() && cont < tam;i++) {
		this->datas.push_back(datas.at(i));
		pos = i;
		cont++;
	}
	return ++pos;
}