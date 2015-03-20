#ifndef CODER_H
#define CODER_H

class Coder;

#include "Reporter.h"
#include <list>

class Coder
{
	public:
		virtual void encode(std::list<unsigned int>*) = 0;
		virtual void decode(std::list<unsigned int>*, Reporter* = 0) = 0;
		virtual ~Coder(){}
};

#endif
