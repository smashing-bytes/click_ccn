/*  
 *  This file is part of CCN-Click.
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

	
#include </config.h>
#include "producer.hh"
#include </args.hh>
#include </error.hh>
#include </llrpc.h>
#include "ccn_packets.hh"
#include <iostream>

EXPORT_ELEMENT(Producer);
ELEMENT_REQUIRES(packets);
using namespace std;

Producer::Producer()
{

}


Producer *Producer::clone() const
{
	return new Producer;
}

const char *Producer::processing() const
{
	return AGNOSTIC;
}


void Producer::push(int port, Packet *p)
{

	p->kill();
}

/**
 * incoming ?
 */
Packet *Producer::pull(int port)
{

	return input(0).pull();
}

int Producer::initialize(ErrorHandler *errh)
{
	cout << "Producer initialized!" << endl;
	
	const char *name = "/a/b/c";
	sleep(1);
	Packet *p = create_interest(name, true);
	output(0).push(p);
	
	
	name = "/a/b/";

	p = create_interest(name, true);
	output(0).push(p);
	sleep(1);
	
	name = "/a/";

	p = create_interest(name, true);
	output(0).push(p);
	sleep(1);
	
	return 0;
}

Packet *Producer::simple_action(Packet *p)
{
	_chatter("Forwarding received packet!\n");
	return 0;
}

	
ELEMENT_REQUIRES(packets)
