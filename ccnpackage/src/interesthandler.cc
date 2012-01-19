#include <click/config.h>
#include "interesthandler.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

EXPORT_ELEMENT(InterestHandler);


InterestHandler::InterestHandler()
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

void InterestHandler::push(int port, Packet *p)
{
	click_chatter("Int Handler\n");
	p->kill();
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

	
