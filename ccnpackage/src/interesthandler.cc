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
#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include <string.h>

using namespace std;

EXPORT_ELEMENT(InterestHandler);
CLICK_DECLS

InterestHandler::InterestHandler()
{
	pit = new HashTable<const char *, Vector<Face*> >();
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
	HashTable<const char *, Vector<Face*> >::iterator it;
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
		
		
		pit->set((char *)p->data(), faceList);
	}
	
	if(type == 2)
	{
		HashTable<const char *, Vector<Face*> >::iterator it;
		for(it = pit->begin(); it; ++it)
		{
			if(contains((char *)p->data(), it.key()))
			{
				//Forward the data
				
			}
		}
	}
	
	printPIT();
	p->kill();
}

bool InterestHandler::contains(const char *content_name, const char *intname)
{
	return (strncmp(content_name, intname, strlen(intname)));
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

CLICK_ENDDECLS
