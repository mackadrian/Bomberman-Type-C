#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void clear_screen(UINT32 *base);
void plot_vline(UINT32 *base, int x, int y, int length);
void plot_hline(UINT32 *base, int x, int y, int length);
void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap,
				   unsigned int height);
#endif
