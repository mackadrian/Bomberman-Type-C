#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void clear_screen(UINT32 *base);
void plot_vline(UINT32 *base, int x, int y1, int y2);
void plot_hline(UINT32 *base, int x1, int y, int x2);
void plot_bitmap16(UINT32 *base, int x, int y, const UINT32 *bitmap,
				   unsigned int height);
#endif
