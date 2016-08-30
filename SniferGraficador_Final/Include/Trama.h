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

};

