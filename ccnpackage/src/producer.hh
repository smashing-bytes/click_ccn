#ifndef _PRODUCER_HH_
#define PRODUCER_HH_
#include <click/element.hh>

CLICK_DECLS

class Producer : public Element
{
public:

	Producer();
	const char* class_name() const	{ return "Producer"; }
	Producer *clone() const;
	const char *processing() const;
	void push(int port, Packet *p);
	const char *port_count() const	{ return "-/-"; }
	Packet *pull(int port);
	int initialize(ErrorHandler *errh);
	Packet *simple_action(Packet *p);
};

/*
const char *class_name() const;	// return your element's name
void push(int i, Packet *);	// process push request on input i
Packet *pull(int i);		// process pull request on output i
const char *processing() const; // return processing code
*/
CLICK_ENDDECLS
#endif
