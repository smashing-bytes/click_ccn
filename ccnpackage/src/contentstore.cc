#include <click/config.h>
#include "contentstore.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>

EXPORT_ELEMENT(ContentStore);


ContentStore::ContentStore()
{

}


ContentStore *ContentStore::clone() const
{
	return new ContentStore;
}

const char *ContentStore::processing() const
{
	return AGNOSTIC;
}

void ContentStore::push(int port, Packet *p)
{
	click_chatter("ContentStore\n");
	p->kill();
}
/*
Packet *InterestHandler::pull(int port)
{
	return input(0).pull();
}
*/
int ContentStore::initialize(ErrorHandler *errh)
{
    errh->message("Testing ContentStore");
    return 0;
}

	
