#ifndef IMAGELOADER_H
#define IMAGELOADER_H

class ImageLoader;

#include "Image.h"

class ImageLoader
{
	public:
		virtual Image* load(const char*) = 0;
		virtual void save(Image* ,const char*) = 0;
		virtual ~ImageLoader() {}
};


#endif
