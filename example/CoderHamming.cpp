#include "CoderHamming.h"

#include <cstdio>
#include <sstream>

CoderHamming::CoderHamming(int _p, bool _d) : p(_p),d(_d) {}

CoderHamming::~CoderHamming() {}

void CoderHamming::encode(std::list<unsigned int>* s)
{
	int l1=(1<<p)-p-1;
	int l2=l1+p;
	for(int i=s->size()%l1;i>0;i--)
	{
		s->push_back(0);
	}
	int c=s->size()/l1;
	std::list<unsigned int>::iterator it=s->begin();
	for(int i=0;i<c;i++)
	{
		std::list<unsigned int>::iterator it2=it;
		std::list<unsigned int>::iterator it3;
		for(int j=0;j<p;j++)
		{
			s->insert(it,1);
			for(int k=1;k<(1<<j);k++)
			{
				it++;
			}
		}
		std::advance(it2,-2);
		int c=0;
		for(int j=1;j<=l2;j++)
		{
		
			if(!(j & (j-1)))
			{
				it3=it2;
				it3++;
				unsigned int count=0;
				for(int k=j+1;k<=l2;k++)
				{
					if(k & (1<<c))
					{
						count+=*it3;
					} 
					it3++;
				}	
				(*it2)=count%2;
				c++;
			}
			else;
			it2++;
		}
	}
}

void CoderHamming::decode(std::list<unsigned int>* s)
{
	int l=(1<<p)-1;
	int p=0;
	int c=s->size()/l;
	std::list<unsigned int>::iterator it=s->begin();
	printf("%d\n",l);
	for(int i=0;i<c;i++)
	{
		std::list<unsigned int>::iterator it2=it,it3, it4;
		int c=0;
		int sum=0;
		for(int j=1;j<=l;j++)
		{
			
			if(!(j & (j-1)))
			{
				it3=it2;
				it3++;
				unsigned int count=0;
				for(int k=j+1;k<=l;k++)
				{
					if(k & (1<<c))
					{
						count+=*it3;
						//printf("c %d\n",*it3);
					} 
					it3++;
				}	
				//printf("b %d %d\n",*it2,count%2);
				if((*it2)!=count%2)
				{
					sum+=j;
					//if(sum==3)
						//printf("s %d %d\n",sum,j);
				}
				c++;
			}
			
			it2++;
		}
		
		if(sum!=0)
		{
			it4=it;
			p++;
			std::advance(it4, sum-1);
			(*it4)=!(*it4);
		}
		for(int j=1;j<=l;j++)
		{
			if(!(j & (j-1)))
			{
				it=s->erase(it);
			}
			else
			{
				it++;
			}
		}
	}
	printf("%d %d\n",c,p);
}
