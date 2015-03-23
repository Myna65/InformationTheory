#ifndef REPORTER_H
#define REPORTER_H

class Reporter;

#include "Image.h"

class Reporter
{
public:
	Reporter(int, int);
	void registerCorrection(int);
	void registerError(int);
	void compare(Image*, Image*);
	Image* report();
private:
	Image* img;
};

#endif
