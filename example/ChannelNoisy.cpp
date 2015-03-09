#include "ChannelNoisy.h"

#include <ctime>
#include <cstdlib>

ChannelNoisy::ChannelNoisy(float _err) : err(_err){}

void ChannelNoisy::transfer(std::list<unsigned int>* s)
{
	srand(time(NULL));
	for(std::list<unsigned int>::iterator it=s->begin();it!=s->end();it++)
	{
		if((float)rand()/RAND_MAX<err)
		{
			(*it)=!(*it);
		}
	}
}

