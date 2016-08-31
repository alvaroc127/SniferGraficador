#if !defined(_SUBTRAMSPO2_)
#define _SUBTRAMSPO2_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubTramSpo2
/// </summary>
/// <seealso cref="SubTramaParam" />
/// <seealso cref="SubTramaMetod" />
class SubTramSpo2 : virtual	public SubTramaParam, SubTramaMetod
{
private:
	int dato1;
	int frecuencia;

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramSpo2"/> class.
	/// </summary>
	SubTramSpo2();

	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramSpo2"/> class.
	/// </summary>
	~SubTramSpo2();
	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra();
	
	
};

#endif