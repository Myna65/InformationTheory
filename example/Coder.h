#ifndef CODER_H
#define CODER_H

class Coder;

#include<istream>

class Coder
{
	public:
		virtual std::vector<bool> code(std::vector<bool>) = 0;
		virtual std::vector<bool> uncode(std::vector<bool>) = 0;
};

#endif
