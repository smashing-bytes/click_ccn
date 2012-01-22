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

	
#include <click/config.h>
#include "fib.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include <iostream>

EXPORT_ELEMENT(Forwarding);

using namespace std;

Forwarding::Forwarding()
{

}


Forwarding *Forwarding::clone() const
{
	return new Forwarding;
}

const char *Forwarding::processing() const
{
	return AGNOSTIC;
}


void Forwarding::push(int port, Packet *p)
{
	click_chatter("Forwarding received packet! %s\n", p->data());
	click_chatter("Annotation byte at offset 0 is: %d\n", p->anno_u8(0));
	output(0).push(p);
	//p->kill();
}

/**
 * incoming ?
 */
Packet *Forwarding::pull(int port)
{

	return input(0).pull();
}

int Forwarding::initialize(ErrorHandler *errh)
{

	return 0;
}



	
