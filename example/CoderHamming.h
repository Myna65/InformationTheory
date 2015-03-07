#ifndef CODERHAMMING_H
#define CODERHAMMING_H

class CoderTrivial;

#include "Coder.h"

class CoderHamming : public Coder
{
	public:
		CoderHamming(int, bool);
		virtual ~CoderHamming();
		virtual void encode(std::list<int>*);
		virtual void decode(std::list<int>*);
	private:
		int p;
		bool d;
};

#endif
