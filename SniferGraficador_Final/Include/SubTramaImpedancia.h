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
	/// Cants the byte sub.
	/// </summary>
	void cantByteSub();
	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra();
	
	/// <summary>
	/// Joins the header.
	/// </summary>
	/// <returns></returns>
	std::string joinHeader();
	
	/// <summary>
	/// Sizes the sub.
	/// </summary>
	/// <returns></returns>
	int sizeSub();
		
	/// <summary>
	/// Sizes the p subtrama.
	/// </summary>
	/// <returns></returns>
	int sizePSubtrama();
};
#endif
