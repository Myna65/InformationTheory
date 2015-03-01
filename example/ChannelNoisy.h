#ifndef CHANNELNOISY_H
#define CHANNELNOISY_H

class ChannelNoisy;

#include "Channel.h"

class ChannelNoisy : public Channel
{
	public:
		ChannelNoisy(float);
		virtual void transfer(std::vector<bool>*);
		virtual ~ChannelNoisy() {}
	private:
		float err;
};

#endif
