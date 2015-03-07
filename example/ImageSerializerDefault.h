#ifndef IMAGESERIALIZERDEFAULT_H
#define IMAGESERIALIZERDEFAULT_H

class ImageSerializerDefault;

#include "ImageSerializer.h"

class ImageSerializerDefault : public ImageSerializer
{
	public:
		virtual std::list<int>* serialize(Image*);
		virtual Image* unserialize(std::list<int>*, unsigned int width=-1,unsigned int height=-1);
		virtual ~ImageSerializerDefault() {}
	private:
		void convertToBool(unsigned int, std::list<int>*);
		void convertToBool(unsigned char, std::list<int>*);
		unsigned char convertToChar(std::list<int>::iterator*);
		unsigned int convertToInt(std::list<int>::iterator*);
};

#endif
