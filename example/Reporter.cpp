#include "Reporter.h"

#include <cstdio>

Reporter::Reporter(int w, int h) 
{
	img= new Image;
	img->width=w;
	img->height=h;
	Pixel v;
	v.r=0;
	v.g=255;
	v.b=0;
	img->colours=std::vector<Pixel>(w*h,v);
}
void Reporter::registerCorrection(int pos)
{
	pos-=64;
	pos/=24;
	Pixel p;
	p.r=255;
	p.g=255;
	p.b=0;
	pos=std::max(pos,0);
	img->colours[pos]=p;
}
void Reporter::registerError(int pos)
{
}
void Reporter::compare(Image* in , Image* out)
{
	int s=in->width*in->height;
	Pixel p;
	p.r=255;
	p.b=0;
	p.g=0;
	for(int i=0;i<s;i++)
	{
		if(in->colours[i]!=out->colours[i])
		{
			img->colours[i]=p;
		}
	}
}
Image* Reporter::report()
{
	return img;
}
