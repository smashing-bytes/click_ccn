#ifndef _FACE_HH_
#define _FACE_HH_

#include <click/config.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>


class Face
{
	typedef struct in_addr in_addr;
	
private:
	bool local;
	pid_t pid;
	in_addr ip;
	unsigned short port;
public:
	Face();
	void setIP(in_addr ip) { this->ip = ip; }
	void setPID(pid_t pid) { this->pid = pid; }
	void setPort(unsigned short port) { this->port = port; }
	pid_t getPID() { return this->pid; }
	in_addr getIP() { return this->ip; }
	unsigned short getPort() { return this->port; }
	bool isLocal() { return this->local; }
};

#endif
