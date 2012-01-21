#include <click/config.h>
#include "ccndaemon.hh"
#include <iostream>
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include "ccn_packets.hh"

EXPORT_ELEMENT(CCNDaemon);

using namespace std;

CCNDaemon::CCNDaemon()
{

}


CCNDaemon *CCNDaemon::clone() const
{
	return new CCNDaemon;
}

const char *CCNDaemon::processing() const
{
	return AGNOSTIC;
}

void CCNDaemon::push(int port, Packet *p)
{
	cout << p->data() << endl;
	output(0).push(p);
}



	
