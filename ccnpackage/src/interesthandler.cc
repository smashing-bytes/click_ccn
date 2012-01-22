/*  
 *  This file is part of CCN-.
 * 
 *  CCN- is free software: you can redistribute it and/or modify
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

	
#include "interesthandler.hh"
#include <iostream>
#include </config.h>
#include </args.hh>
#include </error.hh>
#include </llrpc.h>

using namespace std;

EXPORT_ELEMENT(InterestHandler);
_DECLS

InterestHandler::InterestHandler()
{
	pit = new HashTable<const unsigned char *, Vector<Face*> >();
}

InterestHandler::~InterestHandler()
{
	
}
InterestHandler *InterestHandler::clone() const
{
	return new InterestHandler;
}

const char *InterestHandler::processing() const
{
	return AGNOSTIC;
}

void InterestHandler::printPIT()
{
	HashTable<const unsigned char *, Vector<Face*> >::iterator it;
	for(it = pit->begin(); it; ++it)
	{
		cout << it.key() << "\n";
		
	}
		
	
}
void InterestHandler::push(int port, Packet *p)
{
	/*Check packet annotation*/
	uint8_t type = p->anno_u8(0);
	if(type == 0 || type == 1)
	{
		/*Construct face list*/
		Vector<Face*> faceList;
		faceList.push_back(new Face());
		
		pit->set(p->data(), faceList);
	}
	
	printPIT();
	p->kill();
}
/*
Packet *InterestHandler::pull(int port)
{
	return input(0).pull();
}
*/
int InterestHandler::initialize(ErrorHandler *errh)
{
    errh->message("Testing PIT");
    return 0;
}

_ENDDECLS
