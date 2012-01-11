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
	output(0).push(p);
}

Packet *InterestHandler::pull(int port)
{
	return input(0).pull();
}

int InterestHandler::initialize(ErrorHandler *errh)
{
    errh->message("Testing forwarder");
    return 0;
}

	
