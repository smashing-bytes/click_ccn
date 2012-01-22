/*  
 *  This file is part of CCN-.
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

	
#include </config.h>
#include "ccndaemon.hh"
#include <iostream>
#include </args.hh>
#include </error.hh>
#include </llrpc.h>
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



	
