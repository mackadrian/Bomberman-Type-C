#include "model.h"

void move_bomberman_up(Bomberman *bomberman)
{
	bomberman->y += 1;
}

void move_bomber_down(Bomberman *bomberman)
{
	bomberman->y -= 1;
}

void move_bomberman_right(Bomberman *bomberman)
{
	bomberman->x += 1;
}

void move_bomberman_left(Bomberman *bomberman)
{
	bomberman->x -= 1;
}

void place_bomb(Bomb *bomb)
{
	


}


void move_enemy(Enemy *enemy)
{
	enemy->x += enemy->delta_x;
	enemy->y += enemy->delta_y;
}

