#if !defined(_SUBTRAMALARMA_)
#define _SUBTRAMALARMA_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubTramaAlarma
/// </summary>
/// <seealso cref="SubTramaParam" />
/// <seealso cref="SubTramaMetod" />
class SubTramaAlarma : virtual public SubTramaParam
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaAlarma"/> class.
	/// </summary>
	SubTramaAlarma();


	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaAlarma"/> class.
	/// </summary>
	~SubTramaAlarma();
	
};

#endif

