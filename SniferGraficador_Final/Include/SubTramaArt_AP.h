#if !defined(_SUBTRAMAART_)
#define _SUBTRAMAART_
#pragma once
#include "SubTramaParam.h"
#include "SubTramaMetod.h"
/// <summary>
/// Class SubTramaArt_Ap
/// </summary>
class SubTramaArt_AP: virtual  public SubTramaParam, SubTramaMetod
{
private:
	int alto;
	int bajo;
	int parentesis;
	int val;
	bool band;
public:	
		
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaArt_AP"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTramaArt_AP(const SubTramaArt_AP &);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaArt_AP"/> class.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	SubTramaArt_AP(uint8_t[], uint8_t[], uint8_t[]);


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
	void clasficaSubTra(const std::vector<uint8_t> &,int);
	
	/// <summary>
	/// Runs the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int runData(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the hight.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadHight(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Loads the low.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadLow(const std::vector<uint8_t> &, int);

	
	/// <summary>
	/// Loads the parentesis.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadParentesis(const std::vector<uint8_t> &, int);
	
	/// <summary>
	/// Determines whether this instance is band.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is band; otherwise, <c>false</c>.
	/// </returns>
	bool isBand();
};

#endif
