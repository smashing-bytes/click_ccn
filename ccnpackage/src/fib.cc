#include <click/config.h>
#include "fib.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include <iostream>

EXPORT_ELEMENT(Forwarding);

using namespace std;

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
	click_chatter("Forwarding received packet! %s\n", p->data());
	click_chatter("Annotation byte at offset 0 is: %d\n", p->anno_u8(0));
	output(0).push(p);
	//p->kill();
}

/**
 * incoming ?
 */
Packet *Forwarding::pull(int port)
{

	return input(0).pull();
}

int Forwarding::initialize(ErrorHandler *errh)
{

	return 0;
}



	
