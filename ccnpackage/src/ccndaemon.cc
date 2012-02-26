/*  
 *  This file is part of CCN-.
 * 
 *  CCN-Click is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CCN-Click is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CCN-Click.  If not, see <http://www.gnu.org/licenses/>.
 */

	
#include <click/config.h>
#include "ccndaemon.hh"
#include <iostream>
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include "ccn_packets.hh"

EXPORT_ELEMENT(CCNDaemon);
CLICK_DECLS
using namespace std;

CCNDaemon::CCNDaemon()
{

}


CCNDaemon *CCNDaemon::clone() const
{
	return new CCNDaemon;
}

const char *CCNDaemon::processing() const
{
	return AGNOSTIC;
}

/**
 * Creates a Click compatible packet and annotates it
 * 
 * @param External packet
 */
Packet *CCNDaemon::annotate_packet(Packet *p)
{
	/*Raw packet data*/
	const unsigned char *data = p->data();
	uint8_t type;
	/*Check packet type and annotate it correctly*/
	if(data[0] > 2)
		return NULL;
	type = data[0];
	
	Packet *ret = Packet::make((data + 1), CONTENT_SIZE_MAX);
	ret->set_anno_u8(0, type);
	
	return ret;
	
		
}

/**
 * Receives a packet from an outside source, annotates it and forwards it
 */
void CCNDaemon::push(int port, Packet *p)
{
	/*Annotate the packet into a new one*/
	//Packet *tmp = annotate_packet(p);
	if(port == 0)
	{
		cout << "Local" << endl;
		cout << "PID: " << endl; //TODO: Get PID 
	}
	else if (port == 1)
	{
		cout << "Remote" << endl;
		cout << "IP: " << p->transport_header() << endl;
	}
	else
		cout << "Error" << endl;
		
	p->kill();
	
		
}


CLICK_ENDDECLS
	
