#include "interesthandler.hh"
#include <iostream>
#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

using namespace std;

EXPORT_ELEMENT(InterestHandler);
CLICK_DECLS

InterestHandler::InterestHandler()
{
	pit = new HashTable<const unsigned char *, Vector<Face*> >();
}

InterestHandler::~InterestHandler()
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

void InterestHandler::printPIT()
{
	HashTable<const unsigned char *, Vector<Face*> >::iterator it;
	for(it = pit->begin(); it; ++it)
	{
		cout << it.key() << "\n";
		
	}
		
	
}
void InterestHandler::push(int port, Packet *p)
{
	/*Check packet annotation*/
	uint8_t type = p->anno_u8(0);
	if(type == 0 || type == 1)
	{
		/*Construct face list*/
		Vector<Face*> faceList;
		faceList.push_back(new Face());
		
		pit->set(p->data(), faceList);
	}
	
	printPIT();
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

CLICK_ENDDECLS
