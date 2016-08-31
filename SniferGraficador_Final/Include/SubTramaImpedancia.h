#if !defined(_SUBTRAMAIMPEDANCIA_)
#define _SUBTRAMAIMPEDANCIA_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubtramaImpedancia
/// </summary>
/// <seealso cref="SubTramaParam" />
class SubTramaImpedancia : virtual  public SubTramaParam , SubTramaMetod
{
private:
	int impedanciaX2;

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	SubTramaImpedancia();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaImpedancia"/> class.
	/// </summary>
	~SubTramaImpedancia();
	

	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra();


};
#endif
