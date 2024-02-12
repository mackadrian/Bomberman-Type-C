#include <stdio.h>
#include <osbind.h>

#include "raster.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

int main()
{
	int x, y, i;
	UINT32 *base = Physbase();
	printf("\033E\033f\n");

	Cnecin();
	/*plot_hline*/
	plot_hline(base, 33, 96, 640 - 32);
	Cnecin();
	plot_hline(base, 33, 128, 640 - 32);
	Cnecin();
	plot_hline(base, 33, 160, 640 - 32);
	Cnecin();
	plot_hline(base, 33, 192, 640 - 32);
	Cnecin();
	plot_hline(base, 33, 224, 640 - 32);
	Cnecin();

	/*plot_vline*/
	plot_vline(base, 33, 96, 400 - 36);
	Cnecin();
	plot_vline(base, 65, 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97, 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97 + 16, 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97 + (16*2), 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97 + (16*3), 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97 + (16*4), 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97 + (16*5), 96, 400 - 36);
	Cnecin();
	plot_vline(base, 97 + (16*6), 96, 400 - 36);
	Cnecin();
	
	clear_screen(base);
	return 0;
}
