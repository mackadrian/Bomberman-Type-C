#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void clear_screen(UINT16 *base);
void plot_vline(UINT16 *base, int x, int y1, int y2);
void plot_hline(UINT16 *base, int x1, int y, int x2);
void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap,
				   unsigned int height);
#endif
