/*  
 *  This file is part of CCN-.
 * 
 *  CCN- is free software: you can redistribute it and/or modify
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

	
#include <click/config.h>
#include "ccnclassifier.hh"
#include <click/args.hh>
#include <click/error.hh>
#include <click/llrpc.h>
#include "ccn_packets.hh"

EXPORT_ELEMENT(CCNClassifier);


CCNClassifier::CCNClassifier()
{

}


CCNClassifier *CCNClassifier::clone() const
{
	return new CCNClassifier;
}

const char *CCNClassifier::processing() const
{
	return AGNOSTIC;
}

void CCNClassifier::push(int port, Packet *p)
{
	uint8_t packetType;
	click_chatter("CCNClassifier\n");
	
	/*Get annotation byte to determine type of packet*/
	
	packetType = p->anno_u8(0);
	
	switch(packetType)
	{
		case CCN_INTEREST:
			output(0).push(p);
			break;
		case CCN_PERSISTENT_INTEREST:
			output(0).push(p);
			break;
		case CCN_CONTENT:
			output(2).push(p);
			break;
		default:
			p->kill();
		
	}
}
/*
Packet *InterestHandler::pull(int port)
{
	return input(0).pull();
}
*/
int CCNClassifier::initialize(ErrorHandler *errh)
{
    errh->message("Testing Classifier");
    return 0;
}

	
