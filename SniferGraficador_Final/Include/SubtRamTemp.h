#if !defined(_SUBTRAMPTEMP_)
#define _SUBTRAMPTEMP_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubtRampTemp
/// </summary>
/// <seealso cref="SubTramaParam" />
/// <seealso cref="SubTramaMetod" />
class SubtRamTemp : virtual public SubTramaParam, SubTramaMetod
{
private:



public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubtRamTemp"/> class.
	/// </summary>
	SubtRamTemp();
	/// <summary>
	/// Finalizes an instance of the <see cref="SubtRamTemp"/> class.
	/// </summary>
	~SubtRamTemp();
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra();
};

#endif