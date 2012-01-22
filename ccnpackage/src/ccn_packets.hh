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

	
 #ifndef _CCN_PACKETS_HH_
 #define _CCN_PACKETS_HH_
 
 /**
  * Custom packet declaration
  * 
  * 
  * 
  */

#include <click/config.h>
#include <click/packet.hh>
  

#define INTEREST_SIZE_MAX 575 //bytes
#define CONTENT_SIZE_MAX 575 

#define CCN_INTEREST 0
#define CCN_PERSISTENT_INTEREST 1
#define CCN_CONTENT 2


enum packet_types
{
	INT,
	PINT,
	DATA
};

Packet *create_packet(const void *data, unsigned short type);


Packet *create_interest(const char *name, bool persistent);
Packet *create_content(unsigned char *name, unsigned char *data);
#endif
