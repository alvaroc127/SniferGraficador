#if !defined(_SUBTRAMAART_)
#define _SUBTRAMAART_
#pragma once
#include "SubTrama.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubTramaArt_Ap
/// </summary>
class SubTramaArt_AP: virtual  public SubTrama, SubTramaMetod
{
private:
	int alto;
	int bajo;
	int parentesis;

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaArt_AP"/> class.
	/// </summary>
	SubTramaArt_AP();
	
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaArt_AP"/> class.
	/// </summary>
	~SubTramaArt_AP();
		
	/// <summary>
	/// Clasficas the sub tra.
	/// </summary>
	void clasficaSubTra();

};

#endif
