#ifndef CHANNEL_H
#define CHANNEL_H

class Channel;

#include <vector>

class Channel
{
	public:
		virtual void transfer(std::vector<bool>*) = 0;
		virtual ~Channel() {}
};

#endif
