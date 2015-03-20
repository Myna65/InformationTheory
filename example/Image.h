#ifndef IMAGE_H
#define IMAGE_H

struct Pixel;
struct Image;

#include <vector>

struct Pixel
{
	unsigned char r,g,b;
	bool operator==(const Pixel& p) const {return p.r==r&&p.b==b&&p.g==g;}
	bool operator!=(const Pixel& p) const {return !(p==*this);}
};

struct Image
{
		unsigned int width, height;
		std::vector<Pixel> colours;
};

#endif
