#include <click/config.h>
#include "ccnclassifier.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include "ccn_packets.hh"

EXPORT_ELEMENT(CCNClassifier);


CCNClassifier::CCNClassifier()
{

}


CCNClassifier *CCNClassifier::clone() const
{
	return new CCNClassifier;
}

const char *CCNClassifier::processing() const
{
	return AGNOSTIC;
}

void CCNClassifier::push(int port, Packet *p)
{
	uint8_t packetType;
	click_chatter("CCNClassifier\n");
	
	/*Get annotation byte to determine type of packet*/
	
	packetType = p->anno_u8(0);
	
	switch(packetType)
	{
		case CCN_INTEREST:
			output(0).push(p);
			break;
		case CCN_PERSISTENT_INTEREST:
			output(0).push(p);
			break;
		case CCN_CONTENT:
			output(2).push(p);
			break;
		default:
			p->kill();
		
	}
}
/*
Packet *InterestHandler::pull(int port)
{
	return input(0).pull();
}
*/
int CCNClassifier::initialize(ErrorHandler *errh)
{
    errh->message("Testing Classifier");
    return 0;
}

	
