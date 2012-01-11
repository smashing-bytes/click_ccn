#include <click/config.h>
#include "fib.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

EXPORT_ELEMENT(Forwarding);


Forwarding::Forwarding()
{

}


Forwarding *Forwarding::clone() const
{
	return new Forwarding;
}

const char *Forwarding::processing() const
{
	return AGNOSTIC;
}

void Forwarding::push(int port, Packet *p)
{
	output(port).push(p);
}

Packet *Forwarding::pull(int port)
{
	return input(0).pull();
}

int Forwarding::initialize(ErrorHandler *errh)
{
    errh->message("Testing forwarder");
    return 0;
}

	
