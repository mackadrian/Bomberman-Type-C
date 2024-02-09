#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void clear_screen(char *base);

void plot_hline(char *base, unsigned short x1, unsigned short x2,
		unsigned short y, unsigned short length, unsigned char colour);
#endif
