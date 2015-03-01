#ifndef IMAGELOADERPNG_H
#define IMAGELOADERPNG_H

class ImageLoaderPng;

#include "ImageLoader.h"

class ImageLoaderPng : public ImageLoader
{
	public:
		virtual Image* load(const char*);
		virtual void save(Image* , const char*);
		virtual ~ImageLoaderPng() {}
};


#endif
