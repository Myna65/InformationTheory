#ifndef IMAGESERIALIZERDEFAULT_H
#define IMAGESERIALIZERDEFAULT_H

class ImageSerializerDefault;

#include "ImageSerializer.h"

class ImageSerializerDefault : public ImageSerializer
{
	public:
		virtual std::list<unsigned int>* serialize(Image*);
		virtual Image* unserialize(std::list<unsigned int>*, unsigned int width=-1,unsigned int height=-1);
		virtual ~ImageSerializerDefault() {}
	private:
		void convertToBool(unsigned int, std::list<unsigned int>*);
		void convertToBool(unsigned char, std::list<unsigned int>*);
		unsigned char convertToChar(std::list<unsigned int>::iterator*);
		unsigned int convertToInt(std::list<unsigned int>::iterator*);
};

#endif
