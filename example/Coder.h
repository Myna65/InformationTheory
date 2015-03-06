#ifndef CODER_H
#define CODER_H

class Coder;

#include <list>

class Coder
{
	public:
		virtual void encode(std::list<int>*) = 0;
		virtual void decode(std::list<int>*) = 0;
};

#endif
