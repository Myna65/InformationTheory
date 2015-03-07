#include "CoderHamming.h"

#include <iostream>

CoderHamming::CoderHamming(int _p, bool _d) : p(_p),d(_d) {}

CoderHamming::~CoderHamming() {}

void CoderHamming::encode(std::list<int>* s)
{
	int l1=(1<<p)-p-1;
	for(int i=s->size()%l1;i>0;i--)
	{
		s->push_back(0);
	}
	int c=s->size()/l1;
	std::list<int>::iterator it=s->begin();
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<p;j++)
		{
			for(int k=0;k<(1<<j);k++)
			{
				std::cout<<"k "<<k<<std::endl;
			}
		}
	}
}

void CoderHamming::decode(std::list<int>* s)
{
	
}
