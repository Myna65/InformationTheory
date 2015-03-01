#ifndef IMAGESERIALIZERDEFAULT_H
#define IMAGESERIALIZERDEFAULT_H

class ImageSerializerDefault;

#include "ImageSerializer.h"

class ImageSerializerDefault : public ImageSerializer
{
	public:
		virtual std::vector<bool>* serialize(Image*);
		virtual Image* unserialize(std::vector<bool>*);
		virtual ~ImageSerializerDefault() {}
	private:
		void convertToBool(unsigned int, std::vector<bool>*);
		void convertToBool(unsigned char, std::vector<bool>*);
		unsigned char convertToChar(std::vector<bool>* , int* );
		unsigned int convertToInt(std::vector<bool>* , int* );
};

#endif
