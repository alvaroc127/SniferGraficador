#define TINS_STATIC
#include <iostream>
#include <vector>
#include <tins\tins.h>
#include "ofMain.h"
#include "ofApp.h"

using namespace Tins;
using namespace std;

//========================================================================
int main( ){
	ofSetupOpenGL(1024, 768, OF_WINDOW);
		// <-------- setup the GL context
	vector<NetworkInterface> interfaces = NetworkInterface::all();
	for (const NetworkInterface& iface : interfaces) {
		// First print the name (GUID)
		cout << "Interface name: " << iface.name() << endl;
		// Now print the friendly name, a wstring that will contain something like 
		// "Local Area Connection 2"
		wcout << " (" << iface.friendly_name() << ")" << endl;
	}
	NetworkInterface iface = NetworkInterface::default_interface();
	cout << "Default Interface " << iface.name() << endl;
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_snap_len(64 * 1024);
	//config.set_timeout(10);
	config.set_filter(" ip and tcp and port 80");
	Sniffer snifer(iface.name(), config);
	Packet pack = snifer.next_packet();
	
	cout << "paso" << endl;
	const TCP & tcp = pack.pdu()->rfind_pdu<TCP>();
	TCP tcp1 = TCP(tcp);
	cout << tcp1.header_size() << endl;
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
