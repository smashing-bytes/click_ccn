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

	
#ifndef _CONTENTSTORE_HH_
#define _CONTENTSTORE_HH_
#include <click/element.hh>
#include <click/hashtable.hh>
#include <click/vector.hh>
CLICK_DECLS

class ContentStore : public Element
{
	private:
	HashTable<const unsigned char * , Packet* > *cs;
	public:

	ContentStore();
	const char* class_name() const { return "ContentStore"; }
	ContentStore *clone() const;
	const char *processing() const;
	void push(int port, Packet *p);
	const char *port_count() const	{ return "-/-"; }
//	Packet *pull(int port);
	int initialize(ErrorHandler *errh);
};

/*
const char *class_name() const;	// return your element's name
void push(int i, Packet *);	// process push request on input i
Packet *pull(int i);		// process pull request on output i
const char *processing() const; // return processing code
*/
CLICK_ENDDECLS
#endif
