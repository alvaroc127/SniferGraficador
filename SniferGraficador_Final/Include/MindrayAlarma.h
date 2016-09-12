#if !defined(_MINDRAYALARMA_)
#define _MINDRAYALARMA_
#pragma once
#include "Trama.h"
#include "SubTrama.h"
#include "HeaderTram.h"
/// <summary>
/// Class Mindray Alarma
/// </summary>
/// <seealso cref="Trama" />
class MindrayAlarma : public Trama
{
private:
	std::vector<SubTrama> subtra;
	HeaderTram head;
	int tam=0;
	int tip=0;
	std::string fuente;
	std::string date_time;

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayAlarma"/> class.
	/// </summary>
	MindrayAlarma();	
	/// <summary>
	/// Finalizes an instance of the <see cref="MindrayAlarma"/> class.
	/// </summary>
	~MindrayAlarma();	


	/// <summary>
	/// Clasifies the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int clasifyData(vector<uint8_t>, int);


	/// <summary>
	/// Carfars the sub tram.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int carfarSubTram(vector<uint8_t>, int);
	
	/// <summary>
	/// Gets the tipo.
	/// </summary>
	/// <param name="">The .</param>
	/// <returns></returns>
	int getTipo(int) const;
	
	/// <summary>
	/// Gets the fuente.
	/// </summary>
	/// <returns></returns>
	std::string getFuente();

};
#endif