/* Name: 	Mack Bautista
   Email:	mbaut981@mtroyal.ca
   Course: 	COMP2659 Marc's Section
   Instructor:	Marc Schroeder

   Purpose: A raster graphics library to handle the graphics of the
	    "Bomberman" game. 

*/
 
#include "raster.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define WHITE 0xFF
#define BLACK 0x00
/*
----- FUNCTION: clear_screen -----
Purpose: To remove past plotted objects within the screen for redrawing 
         objects with updated positions.


*/
void clear_screen(char *base) 
{
	int x, y;
	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			int offset = y * SCREEN_WIDTH + x;
			if (offset >= 0 && offset < SCREEN_HEIGHT * SCREEN_WIDTH)
			{
				*(base + offset) = WHITE;
			}
		}
	}
}

/*
----- FUNCTION: clear_region -----
Purpose: 

*/
/* [TO DO] */





/*
----- FUNCTION: plot_hline -----
Purpose:

*/

void plot_hline (char *base, unsigned short x1, unsigned short x2,
		unsigned short y, unsigned short length, unsigned char colour )
{
	unsigned int offset;
	int i;

	if (x1 >= SCREEN_WIDTH || x2 >= SCREEN_WIDTH || y>= SCREEN_HEIGHT)
	{
		return;
	}

	if (x2 - x1 + 1 > length)
	{
		length = x2 - x1 + 1;
	}

	offset = (y * SCREEN_WIDTH) + x1;

	for (i = 0; i < length; i++)
	{
		unsigned int current_offset = offset + i;
		if (current_offset < SCREEN_WIDTH * SCREEN_HEIGHT)
		{
			base[current_offset] = colour;
		} else {
			break;
		}
	}
}
