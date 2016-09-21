#if !defined(_SUBTRAMAMI_)
#define _SUBTRAMAMI_
#pragma once
#include "SubTrama.h"
#include <vector>

class SubTramaMi : virtual public SubTrama
{
private:
	uint8_t *start=new uint8_t[1];
	uint8_t *size=new uint8_t[2];
	uint8_t *end=new uint8_t[1]; 
	std::vector<uint8_t> datas;
public:		

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaMi"/> class.
	/// </summary>
	/// <param name="">The .</param>
	SubTramaMi(const SubTramaMi &);

	/// <summary>
	/// Initializes a new instance of the <see cref="SubTramaMi"/> class.
	/// </summary>
	SubTramaMi();	


	/// <summary>
	/// Finalizes an instance of the <see cref="SubTramaMi"/> class.
	/// </summary>
	 ~SubTramaMi();
	
	/// <summary>
	/// Loads the subtr.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int loadHead(const std::vector<uint8_t> & , int);

	
	/// <summary>
	/// Sizes the p subtrama.
	/// </summary>
	/// <returns></returns>
	int sizePSubtrama();
	
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
	/// Adds the data.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int addData(const std::vector<uint8_t> &, int,int);

};
#endif