#include "ChannelNoisy.h"

#include <ctime>
#include <cstdlib>

ChannelNoisy::ChannelNoisy(float _err) : err(_err){}

void ChannelNoisy::transfer(std::vector<bool>* s)
{
	srand(time(NULL));
	for(int i=0,d=s->size();i<d;i++)
	{
		if((float)rand()/RAND_MAX<err)
		{
			(*s)[i]=!(*s)[i];
		}
	}
}

