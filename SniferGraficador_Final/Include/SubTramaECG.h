#if !defined(_SUBTRAMAPARAM_)
#define _SUBTRMAPARAM_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubtramaECG
/// </summary>
/// <seealso cref="SubTramaParam" />
class SubTramaECG : virtual public SubTramaParam, SubTramaMetod
{
private:


public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	SubTramaECG();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaECG"/> class.
	/// </summary>
	~SubTramaECG();
	
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra();
};


#endif

