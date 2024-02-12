#include <stdio.h>
#include <osbind.h>

#include "raster.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define STAGE_WIDTH 400
#define STAGE_HEIGHT 144

int main()
{
	int x, y, i;
	UINT32 *base = Physbase();
	printf("\033E\033f\n");

	Cnecin();
	/*plot_hline*/
	plot_hline(base, 1, 200, 639);
	Cnecin();
	plot_hline(base, 0, 100, 640);
	Cnecin();
	plot_hline(base, 35, 399, 578);
	Cnecin();
	plot_hline(base, 35, 300, 36);
	Cnecin();

	/*plot_vline*/
	plot_vline(base, 316, 1, 399);
	Cnecin();
	plot_vline(base, 100, 1, 400);
	Cnecin();
	plot_vline(base, 35, 35, 271);
	Cnecin();
	plot_vline(base, 78, 100, 300);
	Cnecin();
	
	clear_screen(base);
	

	/*
	printf("Plotting 16x16 bitmap.\n");
	Cnecin();
	plot_bitmap16(base, 1, 1, player, 256);
	Cnecin();
	*/

	clear_screen(base);
	return 0;
}
