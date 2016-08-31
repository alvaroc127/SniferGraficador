#if !defined(_SUBTRAMAPARAM_)
#define _SUBTRAMAPARAM_
#pragma once
#include <vector>
#include "SubTrama.h"


/// <summary>
/// Class SubtramaParam
/// </summary>
/// <seealso cref="SubTrama" />
class SubTramaParam : virtual  public SubTrama
{
private:
	int start[2];
	int size[2];
	int end[2];
	std::vector<uint8_t>datas;
		
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	SubTramaParam();	

	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaParam"/> class.
	/// </summary>
	~SubTramaParam();	

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
	
	/// <summary>
	/// Cants the byte sub.
	/// </summary>
	void cantByteSub();

	
	/// <summary>
	/// Seleccions the metod.
	/// </summary>
	void seleccionMetod();


};
#endif