#ifndef CHANNEL_H
#define CHANNEL_H

class Channel;

#include <list>

class Channel
{
	public:
		virtual void transfer(std::list<int>*) = 0;
		virtual ~Channel() {}
};

#endif
