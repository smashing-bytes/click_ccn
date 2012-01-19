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
