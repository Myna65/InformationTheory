#include "ImageSerializerDefault.h"

#include <cstdio>

void ImageSerializerDefault::convertToBool(unsigned int c, std::list<int>* bits)
{
	int j=3;
	for(unsigned int i=0xff000000;i!=0;i>>=8)
	{
		convertToBool((unsigned char)((c&i)>>(j*8)), bits);
		j--;
	}
}

void ImageSerializerDefault::convertToBool(unsigned char c, std::list<int>* bits)
{
	for(int i=0x80;i!=0;i>>=1)
	{
		bits->push_back( (c&i ? 1 :0));
	}
}

unsigned char ImageSerializerDefault::convertToChar(std::list<int>::iterator* bits)
{
	unsigned char c=0;
	for(int i=0;i<8;i++)
	{
		c<<=1;
		c+=*(*bits);
		(*bits)++;
	}
	return c;
}

unsigned int ImageSerializerDefault::convertToInt(std::list<int>::iterator* bits)
{
	unsigned int c=0;
	for(int i=0;i<4;i++)
	{
		c<<=8;
		c+=convertToChar(bits);
	}
	return c;
}



std::list<int>* ImageSerializerDefault::serialize(Image* image)
{
	std::list<int>* bits = new std::list<int>;
	//bits->reserve(64+24*image->width*image->height);
	convertToBool(image->width, bits);
	convertToBool(image->height, bits);
	for(int i=0,d=image->width*image->height;i<d;i++)
	{
		Pixel p = image->colours[i];
		convertToBool(p.r, bits);
		convertToBool(p.g, bits);
		convertToBool(p.b, bits);
	}
	return bits;
}

Image* ImageSerializerDefault::unserialize(std::list<int>* s)
{
	Image* output = new Image;
	output->width=output->height=0;
	std::list<int>::iterator it = s->begin();
	output->width=convertToInt(&it);
	output->height=convertToInt(&it);
	output->colours.reserve(output->height*output->width);
	for(int i=0,d=output->width*output->height;i<d;i++)
	{
		Pixel p;
		p.r = convertToChar(&it);
		p.g = convertToChar(&it);
		p.b = convertToChar(&it);
		output->colours.push_back(p);
	}
	return output;
}
