#ifndef IMAGESERIALIZER_H
#define IMAGESERIALIZER_H

class ImageSerializer;

#include <list>
#include "Image.h"

class ImageSerializer
{
	public:
		virtual std::list<int>* serialize(Image*) = 0;
		virtual Image* unserialize(std::list<int>*, unsigned int width=-1,unsigned int height=-1) = 0;
		virtual ~ImageSerializer(){}
};

#endif
