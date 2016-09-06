#if !defined(_CAPTURADERED_)
#define _CAPTURADERED_
#define TINS_STATIC
#pragma once
#include <vector>
#include <tins\tins.h>
/// <summary>
/// Class CapturaDeRed
/// </summary>
using namespace Tins;


typedef struct MyData {
	SnifferConfiguration s1;
	NetworkInterface ifaceName;
};



class CapturaDeRed
{
	
private:
	bool wait;
	//definir la carga de subtrama

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	CapturaDeRed();


	/// <summary>
	/// Finalizes an instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	~CapturaDeRed();


	

	/// <summary>
	/// sort the packet of networck for save in the arch
	/// </summary>
	static void clasificarPacket(std::vector<uint8_t>);
	
	/// <summary>
	/// Configurations the capture.
	/// </summary>
	/// <returns></returns>
	const NetworkInterface configCapture();
		
	/// <summary>
	/// Confingrations the sniffer.
	/// </summary>
	/// <returns></returns>
	const SnifferConfiguration configSniffer();
	
	/// <summary>
	/// Starts the capture.
	/// </summary>
	void startCapture();
	

};


#endif

