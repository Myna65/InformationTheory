#ifndef IMAGESERIALIZER_H
#define IMAGESERIALIZER_H

class ImageSerializer;

#include <list>
#include "Image.h"

class ImageSerializer
{
	public:
		virtual std::list<int>* serialize(Image*) = 0;
		virtual Image* unserialize(std::list<int>*) = 0;
		virtual ~ImageSerializer(){}
};

#endif
