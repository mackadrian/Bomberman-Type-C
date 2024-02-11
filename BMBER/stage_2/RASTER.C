#include "raster.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

/*
----- FUNCTION: clear_screen -----
Purpose: clears the screen
Parameters: base (unsigned short frame buffer)
*/
void clear_screen(UINT16 *base)
{
	UINT16 *end = base + (SCREEN_WIDTH * SCREEN_HEIGHT);
	while (base < end)
	{
		*base++ = 0x0000;
	}
}

/*
----- FUNCTION: plot_vline -----
Purpose: plots a vertical line in the given y1 and x position.
		y1 to y2 plots the length of the vertical line.
Parameters: base (unsigned short frame buffer),
			x (horizontal position),
			y1 (beginning length of the vert. line),
			y2 (ending length of the vert. line)
*/
void plot_vline(UINT16 *base, int x, int y1, int y2)
{
	UINT16 *loc = base + (y1 * 40) + (x >> 4);
	int i, length;

	if (y1 >= SCREEN_HEIGHT || y2 >= SCREEN_HEIGHT || x >= SCREEN_WIDTH)
	{
		return;
	}

	if (y1 > y2)
	{
		int temp = y1;
		y1 = y2;
		y2 = temp;
	}

	length = y2 - y1;
	for (i = 0; i < length; i++)
	{
		*(loc + (y1 + i) * 40 + (x >> 4)) |= 1 << 7 - ((x & 7));
	}
}

/*
----- FUNCTION: plot_hline -----
Purpose: plots a horizontal line in the given x1 and y position.
	 x1 to x2 plots the length of the horizontal line.
Parameters:	base (unsigned short frame buffer),
			x1 (beginning length of the hor. line),
			y (vertical position),
			x2 (ending length of the hor. line)
*/
void plot_hline(UINT16 *base, int x1, int y, int x2)
{
	UINT16 *loc = base + (y * 40) + (x1 >> 4);
	int i, length, l_shift, r_shift;

	if (x1 >= SCREEN_WIDTH || x2 >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
	{
		return;
	}

	if (x1 > x2)
	{
		int temp = x1;
		x1 = x2;
		x2 = temp;
	}

	length = x2 - x1;
	l_shift = x1 % 16;
	r_shift = (16 - ((length - (16 - l_shift)) % 16));

	if (l_shift > 0)
	{
		*loc |= 0xFFFF >> l_shift;
		loc++;
	}

	for (i = 0; i < ((length - l_shift) >> 4) && (loc < (base + ((y + 1) * 40))); i++)
	{
		*loc++ = 0xFFFF;
	}

	if (loc < base + ((y + 1) * 40) && r_shift > 0)
	{
		*loc |= 0xFFFF << r_shift;
	}
}

/*
----- FUNCTION: plot_bitmap16 -----
Purpose: To plot out a 16x16 bitmap array into the screen.
Parameters:	base (unsigned short frame buffer),
			x (horizontal coordinate),
			y (vertical coordinate).
			bitmap (unsigned short bitmap array),
			height (height of the bitmap),
			width (width of the bitmap)
*/
void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap,
				   unsigned int height)
{
	UINT16 *loc = base + (y * 40) + (x >> 4);
	int i, shift;

	if (x <= SCREEN_WIDTH || y <= SCREEN_HEIGHT)
	{
		return;
	}

	shift = x % 16;

	if (shift > 0)
	{
		for (i = 0; i < SCREEN_HEIGHT && loc < base; i++)
		{
			*loc |= bitmap[i] >> shift;
			loc += 40;
		}
		loc = loc - (40 * SCREEN_HEIGHT) + 1;
		for (i = 0; i < SCREEN_HEIGHT && loc < base; i++)
		{
			*loc = (bitmap[i] << 16 - shift);
			loc += 40;
		}
	}
	else
	{
		for (i = 0; i < SCREEN_HEIGHT; i++)
		{
			*loc |= bitmap[i];
			loc += 40;
		}
	}
}
