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



typedef struct MyData {
	Tins::SnifferConfiguration s1;
	Tins::NetworkInterface ifaceName;
};



class CapturaDeRed
{
	
private:
	MindrayAlarma ma;
	MindrayPacket mp;
	MindrayParametros mpp;
	std::vector<uint8_t> datWait;
	std::string dat_time;
	bool wait =true;
	int posG=0;
	//definir la carga de subtrama

public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	CapturaDeRed();


	/// <summary>
	/// Finalizes an instance of the <see cref="CapturaDeRed"/> class.
	/// </summary>
	virtual ~CapturaDeRed();


	

	/// <summary>
	/// sort the packet of networck for save in the arch
	/// </summary>
	 std::string clasificarPacket(const  std::vector<uint8_t> & , int );
	
	/// <summary>
	/// Configurations the capture.
	/// </summary>
	/// <returns></returns>
	Tins::NetworkInterface  configCapture();
		
	/// <summary>
	/// Confingrations the sniffer.
	/// </summary>
	/// <returns></returns>
	Tins::SnifferConfiguration  configSniffer();
	
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
	int confHead(const std::string  &head,const  std::string &ip,const std::vector<uint8_t>&, int);
	
	/// <summary>
	/// Capture the data time.
	/// </summary>
	/// <returns></returns>
	std::string  captDta_time();
		

		
	/// <summary>
	/// Sets the vector.
	/// </summary>
	/// <param name="">The .</param>
	void setVector(const std::vector<uint8_t> &);
	
	/// <summary>
	/// Gets the data wait.
	/// </summary>
	/// <returns></returns>
	std::vector<std::uint8_t>  getDataWait();
		
	/// <summary>
	/// Buscars the head.
	/// </summary>
	/// <param name="">The .</param>
	/// <param name="">The .</param>
	/// <returns></returns>
	int searchHead(const std::vector<uint8_t> &, int);

};


#endif

