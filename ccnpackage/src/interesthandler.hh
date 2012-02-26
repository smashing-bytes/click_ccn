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

	
#ifndef _INTERESTHANDLER_HH_
#define _INTERESTHANDLER_HH_
#include <click/config.h>
#include <click/element.hh>
#include <click/hashtable.hh>
#include <click/vector.hh>
#include "face.hh"
CLICK_DECLS

class InterestHandler : public Element
{
	private:
	HashTable<const char * , Vector<Face*> > *pit;
	bool contains(const char *content_name, const char *intname);
	public:

	InterestHandler();
	~InterestHandler();
	const char* class_name() const { return "InterestHandler"; }
	InterestHandler *clone() const;
	const char *processing() const;
	void push(int port, Packet *p);
	const char *port_count() const	{ return "-/-"; }
//	Packet *pull(int port);
	int initialize(ErrorHandler *errh);
	void printPIT();
};

/*
const char *class_name() const;	// return your element's name
void push(int i, Packet *);	// process push request on input i
Packet *pull(int i);		// process pull request on output i
const char *processing() const; // return processing code
*/
CLICK_ENDDECLS
#endif
