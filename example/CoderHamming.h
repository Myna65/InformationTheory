#ifndef CODERHAMMING_H
#define CODERHAMMING_H

class CoderTrivial;

#include "Coder.h"

class CoderHamming : public Coder
{
	public:
		CoderHamming(int, bool);
		virtual ~CoderHamming();
		virtual void encode(std::list<unsigned int>*);
		virtual void decode(std::list<unsigned int>*, Reporter* = 0);
	private:
		int p;
		bool d;
};

#endif
