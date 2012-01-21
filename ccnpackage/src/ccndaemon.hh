#ifndef _CCNDAEMON_HH_
#define _CCNDAEMON_HH_
#include <click/element.hh>
CLICK_DECLS

class CCNDaemon : public Element
{
	public:

	CCNDaemon();
	const char* class_name() const { return "CCNDaemon"; }
	CCNDaemon *clone() const;
	const char *processing() const;
	void push(int port, Packet *p);
	const char *port_count() const	{ return "-/-"; }
//	Packet *pull(int port);
};

/*
const char *class_name() const;	// return your element's name
void push(int i, Packet *);	// process push request on input i
Packet *pull(int i);		// process pull request on output i
const char *processing() const; // return processing code
*/
CLICK_ENDDECLS
#endif
 
