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
#include "contentstore.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

EXPORT_ELEMENT(ContentStore);


ContentStore::ContentStore()
{
	cs = new HashTable<const unsigned char *, Packet* >();
}


ContentStore *ContentStore::clone() const
{
	return new ContentStore;
}

const char *ContentStore::processing() const
{
	return AGNOSTIC;
}

void ContentStore::push(int port, Packet *p)
{
	HashTable<const unsigned char *, Packet* >::iterator it;
	uint8_t* type = p->anno_u8();
	
	for(it = cs->begin(); it; ++it) //Scan the Content-Store
	{
		
			
		
		
	}
	p->kill();
}
/*
Packet *InterestHandler::pull(int port)
{
	return input(0).pull();
}
*/
int ContentStore::initialize(ErrorHandler *errh)
{
    errh->message("Testing ContentStore");
    return 0;
}

	
