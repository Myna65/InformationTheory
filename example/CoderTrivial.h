#ifndef CODERTRIVIAL_H
#define CODERTRIVIAL_H

class CoderTrivial;

#include "Coder.h"

class CoderTrivial : public Coder
{
	public:
		virtual void encode(std::list<int>*);
		virtual void decode(std::list<int>*);
		virtual ~CoderTrivial();
};

#endif
