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

	
#include "ccn_packets.hh"
#include <click/packet.hh>



Packet *create_packet(const void *data, unsigned short type)
{
	if(type > 2 || type < 0)
		return NULL;
		
	uint8_t value = type;
	
	
	Packet *p = Packet::make(data, CONTENT_SIZE_MAX);
	p->set_anno_u8(0, value);
	
	return p;
	
	
}

Packet *create_interest(const char *name, bool persistent)
{
	uint8_t type;
	if(persistent)
		type = CCN_PERSISTENT_INTEREST;
	else
		type = CCN_INTEREST;
	
	return create_packet(name, type);
}
	



ELEMENT_PROVIDES(packets)
