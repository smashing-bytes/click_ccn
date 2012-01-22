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
#include "interesttable.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

EXPORT_ELEMENT(InterestTable);


InterestTable::InterestTable()
{

}


InterestTable *InterestTable::clone() const
{
	return new InterestTable;
}

const char *InterestTable::processing() const
{
	return AGNOSTIC;
}

void InterestTable::push(int port, Packet *p)
{
	click_chatter("Int Handler\n");
	p->kill();
}
/*
Packet *InterestTable::pull(int port)
{
	return input(0).pull();
}
*/
int InterestTable::initialize(ErrorHandler *errh)
{
    errh->message("Testing PIT");
    return 0;
}

	
