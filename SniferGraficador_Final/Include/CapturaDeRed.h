#if !defined(_CAPTURADERED_)
#define _CAPTURADERED_
#pragma once
#include <tins\tins.h>
/// <summary>
/// Class CapturaDeRed
/// </summary>
using namespace Tins;

class CapturaDeRed
{
private:
		
		//definir la carga de subtrama

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	CapturaDeRed();	

	
	/// <summary>
	/// Finalizes an instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	~CapturaDeRed();
	
	void CapturarPacket();
	

};

#endif

