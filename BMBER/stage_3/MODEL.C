#include "model.h"

/*----- FUNCTION: move_bomber_man_up -----
Purpose:	Increments bomberman's position up by 1 pixel.
*/
void move_bomberman_up(Bomberman *bomberman)
{
	bomberman->y += 1;
}

/*----- FUNCTION: move_bomber_man_left -----
Purpose:	Increments bomberman's position down by 1 pixel.
*/
void move_bomber_down(Bomberman *bomberman)
{
	bomberman->y -= 1;
}

/*----- FUNCTION: move_bomber_man_right -----
Purpose:	Increments bomberman's position right by 1 pixel.
*/
void move_bomberman_right(Bomberman *bomberman)
{
	bomberman->x += 1;
}

/*----- FUNCTION: move_bomber_man_left -----
Purpose:	Increments bomberman's position left by 1 pixel.
*/
void move_bomberman_left(Bomberman *bomberman)
{
	bomberman->x -= 1;
}

/*----- FUNCTION: place_bomb -----
Purpose:	Places bomb on Bomberman's current position. Sets a timer of 5 seconds before detonating.
*/
void place_bomb(Bomb *bomb, Bomberman *bomberman)
{
	bomberman->x = bomb->x;
	bomberman->y = bomb->y;
	bomb->timer = 5;
	bomb->x = bomb->width;
	bomb->y = bomb->length;
	
}

/*----- FUNCTION: move_enemy -----
Purpose:	Moves the enemy in a up/down and left/right throughout the stage.
*/
void move_enemy(Enemy *enemy)
{
	enemy->x += enemy->delta_x;
	enemy->y += enemy->delta_y;
}


void player_vs_bomb_col(Bomberman *bomberman, Bomb *bomb){
	/*work*/
}
