#include <click/config.h>
#include "producer.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include "ccn_packets.hh"
#include <iostream>

EXPORT_ELEMENT(Producer);
ELEMENT_REQUIRES(packets);
using namespace std;

Producer::Producer()
{

}


Producer *Producer::clone() const
{
	return new Producer;
}

const char *Producer::processing() const
{
	return AGNOSTIC;
}


void Producer::push(int port, Packet *p)
{

	p->kill();
}

/**
 * incoming ?
 */
Packet *Producer::pull(int port)
{

	return input(0).pull();
}

int Producer::initialize(ErrorHandler *errh)
{
	cout << "Producer initialized!" << endl;
	
	const char *name = "/a/b/c";

	while(1)
	{
		
		Packet *p = create_interest(name, true);
		output(0).push(p);
		sleep(1);
	}
	return 0;
}

Packet *Producer::simple_action(Packet *p)
{
	click_chatter("Forwarding received packet!\n");
	return 0;
}

	
ELEMENT_REQUIRES(packets)
