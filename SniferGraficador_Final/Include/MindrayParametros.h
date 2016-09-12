#if !defined(_MINDRAYPARAMETROS_)
#define _MINDRAYPARAMETROS_
#pragma once
#include "Trama.h"
#include "HeaderTram.h"
#include "SubTrama.h"

class MindrayParametros: public Trama
{
private:
	std::string fuente;
	const HeaderTram head;
	int tam;
	std::vector<SubTrama>subtrmas;
	std::string data_time;


public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="MindrayParametros"/> class.
	/// </summary>
	MindrayParametros();	
	/// <summary>
	/// Finalizes an instance of the <see cref="MindrayParametros"/> class.
	/// </summary>
	~MindrayParametros();		


	/// <summary>
	/// Cargars the sub tram.
	/// </summary>
	/// <returns></returns>
	int carfarSubTram(vector<uint8_t>, int);

	/// <summary>
	/// Clasifies the data.
	/// </summary>
	/// <returns></returns>
	int clasifyData(vector<uint8_t>, int);	

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