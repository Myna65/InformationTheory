#include "ImageSerializerDefault.h"

#include <cstdio>

void ImageSerializerDefault::convertToBool(unsigned int c, std::vector<bool>* bits)
{
	int j=3;
	for(unsigned int i=0xff000000;i!=0;i>>=8)
	{
		convertToBool((unsigned char)((c&i)>>(j*8)), bits);
		j--;
	}
}

void ImageSerializerDefault::convertToBool(unsigned char c, std::vector<bool>* bits)
{
	for(int i=0x80;i!=0;i>>=1)
	{
		bits->push_back( (c&i ? 1 :0));
	}
}

unsigned char ImageSerializerDefault::convertToChar(std::vector<bool>* bits, int* offset)
{
	unsigned char c=0;
	for(int i=0;i<8;i++)
	{
		c<<=1;
		c+=(*bits)[*offset];
		(*offset)++;
	}
	return c;
}

unsigned int ImageSerializerDefault::convertToInt(std::vector<bool>* bits, int* offset)
{
	unsigned int c=0;
	for(int i=0;i<4;i++)
	{
		c<<=8;
		c+=convertToChar(bits, offset);
	}
	return c;
}



std::vector<bool>* ImageSerializerDefault::serialize(Image* image)
{
	std::vector<bool>* bits = new std::vector<bool>;
	bits->reserve(64+24*image->width*image->height);
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

Image* ImageSerializerDefault::unserialize(std::vector<bool>* s)
{
	Image* output = new Image;
	output->width=output->height=0;
	int offset[1];
	offset[0]=0;
	output->width=convertToInt(s, offset);
	output->height=convertToInt(s, offset);
	output->colours.reserve(output->height*output->width);
	for(int i=0,d=output->width*output->height;i<d;i++)
	{
		Pixel p;
		p.r = convertToChar(s, offset);
		p.g = convertToChar(s, offset);
		p.b = convertToChar(s, offset);
		output->colours.push_back(p);
	}
	return output;
}
