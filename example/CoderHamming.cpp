#include "CoderHamming.h"



CoderHamming::CoderHamming(int _p, bool _d) : p(_p),d(_d) {}

void CoderHamming::encode(std::list<int>* s)
{
	int l=(1<<p)-p-1;
	for(int i=s->size()%l;i>0;i--)
	{
		s->push_back(0);
	}
	int c=s->size()/l;
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<p;j++)
		{
			for(int k=0;k<(1<<d);k++)
			{

			}
		}
	}
}

void CoderHamming::decode(std::list<int>* s)
{
	
}
