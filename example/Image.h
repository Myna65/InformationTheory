#ifndef IMAGE_H
#define IMAGE_H

struct Pixel;
struct Image;

#include <vector>

struct Pixel
{
	unsigned char r,g,b;
};

struct Image
{
		unsigned int width, height;
		std::vector<Pixel> colours;
};

#endif
