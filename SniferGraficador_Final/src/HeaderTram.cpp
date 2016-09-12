#include "..\Include\HeaderTram.h"



using namespace std;



HeaderTram::HeaderTram()
{
};


HeaderTram::~HeaderTram()
{
};

 int HeaderTram::sizePacket() {
	  uint16_t con=((this->size[0] << 8) |this->size[1]);
	 return (int)con;
};


 int HeaderTram::loadHead(std::vector<uint8_t> data, int pos) {
	 int pos1=0;
	 for (int i = 0; i < data.size() && i < 24; i++) {
		 if (i < 6){
			 this->start[pos1++] = (0x0 << 8) | data.at(i);
			 pos++;
		 }
		 else if (i >= 6 && i < 8) {
			 if (i==6)pos1 = 0;
			 this->size[pos1++] = (0x0 << 8) | data.at(i);
			 pos++;
		 }else if (i >= 8 && i < 16) {
			 if (i == 8)pos1 = 0;
			 this->hi_ze[pos1++] = data.at(i);
			 pos++;
		 }else if (i >= 16 && i < 18) {
			 if (i == 16)pos1 = 0;
			 this->crc[pos1++] = data.at(i);
			 pos++;
		 }else if (i >= 18 && i< 24) {
			 if (i == 18)pos1 = 0;
			 this->low_ser[pos1++] = data.at(i);
			 pos++;
		 }
	 }
	
	 return pos;
 }

