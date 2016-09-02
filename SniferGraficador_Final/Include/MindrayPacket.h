#if !defined(_MINDRAYPACKET_)
#define _MINDRAYPACKET_
#pragma once
#include <vector>
#include <string>
#include "Trama.h"
#include "HeaderTram.h"
#include "SubTrama.h"

/// <summary>
/// Class MindrayPacke
/// </summary>
/// <seealso cref="Trama" />
class MindrayPacket : public Trama
{
private:
	std::string fuente;
	const  HeaderTram head;
	int tam=0;
	std::vector<SubTrama>subtrmas;
	std::string data_time;

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayPacket"/> class.
	/// </summary>
	MindrayPacket();

	/// <summary>
	/// Finalizes an instance of the <see cref="MindrayPacket"/> class.
	/// </summary>
	~MindrayPacket();

	
	/// <summary>
	/// Cargars the sub trama.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int carfarSubTrama(vector<uint8_t>, int);


	/// <summary>
	/// Cargars the sub trama.
	/// </summary>
	/// <param name="">The .</param>
	int clasifyData(vector<uint8_t>, int);
};
#endif
