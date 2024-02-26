#include "raster.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/*
----- FUNCTION: clear_screen -----
Purpose: clears the screen
Parameters: base (unsigned long frame buffer)
*/
void clear_screen(UINT32 *base)
{
	UINT32 *end = base + ((SCREEN_WIDTH * SCREEN_HEIGHT) / 32);
	while (base < end)
	{
		*base++ = 0x00000000;
	}
}

/*
----- FUNCTION: plot_vline -----
Purpose: plots a vertical line in the given y1 and x position.
		length is added to the chosen y position.
Parameters: base (unsigned long frame buffer),
			x (horizontal position),
			y1 (beginning length of the vert. line),
			y2 (ending length of the vert. line)
*/
void plot_vline(UINT32 *base, int x, int y, int length)
{
	int i;

	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || length >= SCREEN_HEIGHT)
	{
		return;
	}

	for (i = 0; i < length; i++)
	{
		*(base + (y + i) * 20 + (x >> 5)) |= 0xFFFFFFFF;
	}
}

/*
----- FUNCTION: plot_hline -----
Purpose: plots a horizontal line in the given x1 and y position.
		length is added to the chosen x position.
Parameters:	base (unsigned long frame buffer),
			x1 (beginning length of the hor. line),
			y (vertical position),
			x2 (ending length of the hor. line)
*/
void plot_hline(UINT32 *base, int x, int y, int length)
{
	int i, j, l_shift, r_shift;
	UINT32 *loc = base + (y * 20) + (x >> 5);

	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || length >= SCREEN_WIDTH)
	{
		return;
	}

	l_shift = x % 32;
	r_shift = (32 - ((length - (32 - l_shift)) % 32));

	if (l_shift > 0)
	{
		*loc |= 0xFFFFFFFFF >> l_shift;
		loc++;
	}

	for (i = 0; i < ((length - l_shift) >> 5) && (loc < (base + ((y + 1) * 20))); i++)
	{
		*loc++ = 0xFFFFFFFFF;
	}

	if (loc < base + ((y + 1) * 20) && r_shift > 0)
	{
		*loc |= 0xFFFFFFFF << r_shift;
	}
}

/*
----- FUNCTION: plot_bitmap32 -----
Purpose: To plot out a 32x32 bitmap array into the screen.
Parameters:	base (unsigned long frame buffer),
			x (horizontal coordinate),
			y (vertical coordinate).
			bitmap (unsigned short bitmap array),
			height (height of the bitmap),
			width (width of the bitmap)
*/
void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, int height)
{
	int i, loc, shift;
	loc = ((y * 20) + (x >> 5));

	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
	{
		return;
	}

	for (i = 0; i < height; i++)
	{
		*(base + loc + (20 * i)) = bitmap[i] >> (x & 31);
		*(base + loc + (20 * i) + 1) = bitmap[i] << 32 - (x & 31);
	}
}
