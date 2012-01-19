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
