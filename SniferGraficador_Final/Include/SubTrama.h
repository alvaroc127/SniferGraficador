#if !defined(_SUBTRAMA_)
#define _SUBTRAMA_
#pragma once
#include <string>

/// <summary>
/// Interface of SubTrama
/// </summary>

class SubTrama
{
public:	
	/// <summary>
	/// Finalizes an instance of the <see cref="SubTrama"/> class.
	/// </summary>
	virtual ~SubTrama() {}	
	/// <summary>
	/// Sizes the p subtrama.
	/// </summary>
	/// <returns>sizePsubtram</returns>
	virtual int sizePSubtrama() = 0;	

	/// <summary>
	/// Sizes the sub.
	/// </summary>
	/// <returns> teh size of subTrama</returns>
	virtual int sizeSub() = 0;	


	/// <summary>
	/// Joins the header.
	/// </summary>
	/// <returns>tehe string of join header</returns>
	virtual std::string joinHeader() = 0;
};

#endif