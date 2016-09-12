#if !defined(_TRAMA_)
#define _TRAMA_
#pragma once
#include <vector>

using namespace std;
class Trama
{
public:	
	/// <summary>
	/// Finalizes an instance of the <see cref="Trama"/> class.
	/// </summary>
	virtual ~Trama() {}	
	/// <summary>
	/// Clasifies the data.
	/// </summary>
	/// <param name="payload"> is the PayLoad from TCP</param>
	/// <param name="pos">is the pos in the vector</param>
	/// <returns> the posicion in the vector of payload</returns>
	virtual int clasifyData(vector<uint8_t>, int) = 0;
	
	/// <summary>
	/// Carfars the sub tram.
	/// </summary>
	/// <param name="">The payload of TCP .</param>
	/// <param name="">The pos in the payLoad .</param>
	/// <returns></returns>
	virtual int carfarSubTram(vector<uint8_t>, int) = 0;

	
	/// <summary>
	/// Gets the tipo.
	/// </summary>
	/// <param name="para">The para.</param>
	/// <returns></returns>
	 virtual int getTipo(int)  const = 0;

};

#endif