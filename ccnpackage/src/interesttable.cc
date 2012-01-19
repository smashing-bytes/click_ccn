#include <click/config.h>
#include "interesttable.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

EXPORT_ELEMENT(InterestTable);


InterestTable::InterestTable()
{

}


InterestTable *InterestTable::clone() const
{
	return new InterestTable;
}

const char *InterestTable::processing() const
{
	return AGNOSTIC;
}

void InterestTable::push(int port, Packet *p)
{
	click_chatter("Int Handler\n");
	p->kill();
}
/*
Packet *InterestTable::pull(int port)
{
	return input(0).pull();
}
*/
int InterestTable::initialize(ErrorHandler *errh)
{
    errh->message("Testing PIT");
    return 0;
}

	
