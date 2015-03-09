#ifndef CODERTRIVIAL_H
#define CODERTRIVIAL_H

class CoderTrivial;

#include "Coder.h"

class CoderTrivial : public Coder
{
	public:
		virtual void encode(std::list<unsigned int>*);
		virtual void decode(std::list<unsigned int>*);
		virtual ~CoderTrivial();
};

#endif
