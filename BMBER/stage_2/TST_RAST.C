#include <stdio.h>
#include <osbind.h>

#include "raster.h"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define WHITE 0xFF;
#define BLACK 0x00;

int main() 
{
	char *base = (char *)Physbase();

	clear_screen(base);
	
	plot_hline(base, 3, 20, 10, 10, 0xFF);

	clear_screen(base);

	return 0;
}

