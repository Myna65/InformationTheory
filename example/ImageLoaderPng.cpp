#include "ImageLoaderPng.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <png.h>

Image* ImageLoaderPng::load(const char* filename)
{
		png_image image;
		
		memset(&image, 0, sizeof(image));
		image.version = PNG_IMAGE_VERSION;
		
		if(png_image_begin_read_from_file(&image, filename))
		{
			png_bytep buffer;
			
			image.format = PNG_FORMAT_RGB;
			
			buffer = (png_bytep) malloc(PNG_IMAGE_SIZE(image));
			
			if(buffer != NULL)
			{
				if(png_image_finish_read(&image, NULL, buffer, 0, NULL))
				{
					printf("%d %d %d\n", image.width, image.height, PNG_IMAGE_SIZE(image));
					
					Image* input = new Image();
					
					input->width = image.width;
					input->height = image.height;
					
					input->colours = std::vector<Pixel>(image.width*image.height);
					
					for(unsigned int i=0;i<image.height;i++)
					{
						for(unsigned int j=0;j<image.width;j++)
						{
							Pixel p;
							p.r = buffer[3*(i*image.width+j)];
							p.g = buffer[3*(i*image.width+j)+1];
							p.b = buffer[3*(i*image.width+j)+2];
							
							input->colours[i*image.width+j]=p;
						}
					}
					
					free(buffer);
					
					return input;
				}
				
				free(buffer);
			}
			
		}
		
		return 0;
}

void ImageLoaderPng::save(Image* output,const char* filename)
{
	png_image image;
		
	memset(&image, 0, sizeof(image));
	image.version = PNG_IMAGE_VERSION;
	image.width = output->width;
	image.height = output->height;
	image.format = PNG_FORMAT_RGB;
	
	png_bytep buffer;
		
	buffer = (png_bytep) malloc(PNG_IMAGE_SIZE(image));
	
	printf("%d %d %d\n", image.width, image.height, PNG_IMAGE_SIZE(image));
	
	
	if(buffer != NULL)
	{
		for(unsigned int i=0;i<image.height;i++)
		{
			for(unsigned int j=0;j<image.width;j++)
			{
				Pixel p = output->colours[i*image.width+j];
				buffer[3*(i*image.width+j)] = p.r;
				buffer[3*(i*image.width+j)+1] = p.g;
				buffer[3*(i*image.width+j)+2] = p.b;
			}
		}
		
		png_image_write_to_file(&image, filename, 0, buffer, 0, NULL);
			
		free(buffer);
		
	}
}
