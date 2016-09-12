#if !defined(_MINDRAYPACKET_)
#define _MINDRAYPACKET_
#pragma once
#include <vector>
#include <string>
#include "Trama.h"
#include "HeaderTram.h"
#include "SubTramaMi.h"


/// <summary>
/// Class MindrayPacke
/// </summary>
/// <seealso cref="Trama" />
class MindrayPacket : public Trama
{
private:
	std::string fuente;
	HeaderTram head;
	int tam = 0;
	std::vector<SubTramaMi>subtrmas;
	std::string data_time;

public:	

	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayPacket"/> class.
	/// </summary>
	/// <param name="">The .</param>
	MindrayPacket(const MindrayPacket &);

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
	int carfarSubTram(vector<uint8_t>, int);


	/// <summary>
	/// Cargars the sub trama.
	/// </summary>
	/// <param name="">The .</param>
	int clasifyData(vector<uint8_t>, int);

	/// <summary>
	/// Sets the fuente.
	/// </summary>
	/// <param name="">The .</param>
	void setFuente(const string);


	/// <summary>
	/// Sets the dta time.
	/// </summary>
	/// <param name="">The .</param>
	void setDtaTime(const string);


	/// <summary>
	/// Sets the head.
	/// </summary>
	/// <param name="">The .</param>
	void setHead(HeaderTram);
	
	/// <summary>
	/// Gets the head.
	/// </summary>
	/// <returns></returns>
	const HeaderTram & getHead();

	/// <summary>
	/// Gets the fuente.
	/// </summary>
	/// <returns></returns>
	 string getFuente();

	/// <summary>
	/// Gets the data time.
	/// </summary>
	/// <returns></returns>
	const string & getDataTime();
	
	/// <summary>
	/// Gets the tipo.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	 int getTipo(int) const;


	 

};
#endif
