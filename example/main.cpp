#include "Image.h"
#include "ImageLoaderPng.h"
#include "ImageSerializerDefault.h"
#include "CoderHamming.h"
#include "ChannelNoisy.h"

int main()
{
	Image* input;
	std::list<int>* s;
	ImageLoader* pngLoader = new ImageLoaderPng();
	ImageSerializer* serializer = new ImageSerializerDefault();
	Coder* coder = new CoderHamming(3,false);
	Channel* channel = new ChannelNoisy(0.01);
	
	input = pngLoader->load("input.png");
	s = serializer->serialize(input);
	coder->encode(s);
	channel->transfer(s);
	coder->decode(s);
	Image* output = serializer->unserialize(s, input->width, input->height);
	pngLoader->save(output,"output.png");
	
	delete pngLoader;
	delete input;
	delete serializer;
	delete channel;
	delete coder;
	delete s;
	delete output;
	
	return 0;
}
