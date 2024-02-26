#include <stdio.h>
#include <osbind.h>

#include "raster.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

const UINT32 test_bitmap[32] = {
	0xFFFFFFFF,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xF000000F,
	0xFFFFFFFF,
};

int main()
{
	int x, y;
	int i = 0;
	UINT32 *base = Physbase();
	printf("\033E\033f\n");
	Cnecin();

	/*plot_hline*/
	while (i < 32)
	{
		plot_hline(base, 33, 64 + i, 543);
		plot_hline(base, 33, 128 + i, 543);
		plot_hline(base, 33, 192 + i, 543);
		plot_hline(base, 33, 256 + i, 543);
		plot_hline(base, 33, 320 + i, 543);
		i++;
	}

	Cnecin();
	/*plot_vline*/
	plot_vline(base, 33, 64, 286);
	Cnecin();
	plot_vline(base, 97, 64, 286);
	Cnecin();
	plot_vline(base, 161, 64, 286);
	Cnecin();
	plot_vline(base, 225, 64, 286);
	Cnecin();
	plot_vline(base, 289, 64, 286);
	Cnecin();
	plot_vline(base, 353, 64, 286);
	Cnecin();
	plot_vline(base, 417, 64, 286);
	Cnecin();
	plot_vline(base, 481, 64, 286);
	Cnecin();
	plot_vline(base, 545, 64, 286);
	Cnecin();
	clear_screen(base);

	/*plot_bitmap32*/
	Cnecin();
	plot_bitmap32(base, 0, 0, test_bitmap, 32);
	Cnecin();
	plot_bitmap32(base, 320, 0, test_bitmap, 32);
	Cnecin();
	plot_bitmap32(base, 320, 200, test_bitmap, 32);
	Cnecin();
	plot_bitmap32(base, 22, 300, test_bitmap, 32);
	Cnecin();
	plot_bitmap32(base, 400, 199, test_bitmap, 32);
	Cnecin();

	clear_screen(base);
	return 0;
}
