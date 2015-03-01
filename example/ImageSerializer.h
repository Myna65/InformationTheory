#ifndef IMAGESERIALIZER_H
#define IMAGESERIALIZER_H

class ImageSerializer;

#include <vector>
#include "Image.h"

class ImageSerializer
{
	public:
		virtual std::vector<bool>* serialize(Image*) = 0;
		virtual Image* unserialize(std::vector<bool>*) = 0;
		virtual ~ImageSerializer(){}
};

#endif
