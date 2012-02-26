/*  
 *  This file is part of CCN-Click.
 * 
 *  CCN-Click is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CCN-Click is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CCN-Click.  If not, see <http://www.gnu.org/licenses/>.
 */

	
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
