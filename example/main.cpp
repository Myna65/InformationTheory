#include "Image.h"
#include "ImageLoaderPng.h"
#include "ImageSerializerDefault.h"
#include "CoderHamming.h"
#include "CoderTrivial.h"
#include "ChannelNoisy.h"

int main()
{
	Image* input;
	std::list<unsigned int>* s1,*s2;
	ImageLoader* pngLoader = new ImageLoaderPng();
	ImageSerializer* serializer = new ImageSerializerDefault();
	Coder* coder1 = new CoderTrivial();
	Coder* coder2 = new CoderHamming(2,false);
	Channel* channel = new ChannelNoisy(0.48);
	
	input = pngLoader->load("input.png");
	s1 = serializer->serialize(input);
	s2 = serializer->serialize(input);
	coder1->encode(s1);
	coder2->encode(s2);
	channel->transfer(s1);
	channel->transfer(s2);
	coder1->decode(s1);
	coder2->decode(s2);
	Image* output1 = serializer->unserialize(s1, input->width, input->height);
	Image* output2 = serializer->unserialize(s2, input->width, input->height);
	pngLoader->save(output1,"output1.png");
	pngLoader->save(output2,"output2.png");
	
	delete pngLoader;
	delete input;
	delete serializer;
	delete channel;
	delete coder1;
	delete coder2;
	delete s1;
	delete s2;
	delete output1;
	delete output2;
	
	return 0;
}
