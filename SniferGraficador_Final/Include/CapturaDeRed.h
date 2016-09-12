#if !defined(_CAPTURADERED_)
#define _CAPTURADERED_
#define TINS_STATIC
#pragma once
#include <vector>
#include <tins\tins.h>
#include "..\Include\Trama.h"
#include "..\Include\MindrayPacket.h"
#include "..\Include\MindrayAlarma.h"
#include "..\Include\MindrayParametros.h"


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
	MindrayAlarma ma;
	MindrayPacket mp;
	MindrayParametros mpp;
	vector<uint8_t> datWait;
	string dat_time;
	bool wait;
	int posG;
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
	 string clasificarPacket(std::vector<uint8_t> &, int );
	
	/// <summary>
	/// Configurations the capture.
	/// </summary>
	/// <returns></returns>
	const NetworkInterface  configCapture();
		
	/// <summary>
	/// Confingrations the sniffer.
	/// </summary>
	/// <returns></returns>
	const SnifferConfiguration  configSniffer();
	
	/// <summary>
	/// Starts the capture.
	/// </summary>
	void startCapture();
		
	/// <summary>
	/// Capturars the packet1.
	/// </summary>
	void CapturarPacket1();

	
	/// <summary>
	/// Confs the head.
	/// </summary>
	/// <returns></returns>
	int confHead(string head,string ip,vector<uint8_t>, int);
	
	/// <summary>
	/// Capture the data time.
	/// </summary>
	/// <returns></returns>
	 string  captDta_time();
		

		
	/// <summary>
	/// Sets the vector.
	/// </summary>
	/// <param name="">The .</param>
	void setVector(vector<uint8_t>);
	
	/// <summary>
	/// Gets the data wait.
	/// </summary>
	/// <returns></returns>
	const vector<uint8_t>  getDataWait();
	

};


#endif

