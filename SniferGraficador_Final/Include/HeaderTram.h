#if !defined(_HEADERTRAM_)
#define _HEADERTRAM_
#pragma once
#include "Header.h"
/// <summary>
/// Class of HeaderTrama
/// </summary>
/// <seealso cref="Header" />

class HeaderTram : public Header
{
private:
	int start[6];
	int size[2];
	int hi_ze[8];
	int crc[2];
	int low_ser[6];
	int code1[2];
	int consta1[3];
	int consta2[2];
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="HeaderTram"/> class.
	/// </summary>
	HeaderTram();	
	/// <summary>
	/// Finalizes an instance of the <see cref="HeaderTram"/> class.
	/// </summary>
	~HeaderTram();	
	/// <summary>
	/// Sizes the packet.
	/// </summary>
	/// <returns></returns>
	int sizePacket();
	
};

#endif