#if !defined(_HEADER_)
#define _HEADER_
#pragma once

/// <summary>
/// Interface of  Header
/// </summary>
class Header
{
public:	
	/// <summary>
	/// Finalizes an instance of the <see cref="Header"/> Header.
	/// </summary>
	virtual ~Header() {}		
	/// <summary>
	/// Sizes the packet.
	/// </summary>
	/// <returns>the size of packet</returns>
	virtual int sizePacket() = 0;

};
#endif
