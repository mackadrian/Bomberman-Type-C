#ifndef MODEL_H
#define MODEL_H

typedef struct
{
	unsigned int x, y;
	int delta_x, delta_y, max_lives;
} Bomberman;

typedef struct
{
	unsigned int x, y;
	int width, length, timer;
} Bomb;

typedef struct
{
	unsigned int x, y;
	int delta_x, delta_y;
} Enemy;

typedef struct
{
	unsigned int x, y;
} Brick;

typedef struct
{
	unsigned int x, y;
	int time_countdown;
} Timer;

typedef struct
{
	int x, y, score;
} ScoreCounter;

typedef struct
{
	unsigned int x, y;
	int life_counter;
} LifeCounter;

typedef struct
{
	Bomberman bomberman;
	Enemy enemy[6];
	Brick brick[4];
	Timer timer;
	ScoreCounter score;
	LifeCounter life_counter;
} Model;

void move_bomberman_up(Bomberman *bomberman);
void move_bomber_down(Bomberman *bomberman);
void move_bomberman_right(Bomberman *bomberman);
void move_bomberman_left(Bomberman *bomberman);
void place_bomb(Bomb *bomb, Bomberman *bomberman);
void move_enemy(Enemy *enemy);
void player_to_bomb_col(Bomberman *bomberman, Bomb *bomb);
void brick_to_bomb_col(Brick *brick, Bomb *bomb);
void enemy_to_bomb_col(Enemy *enemy, Bomb *bomb);
void player_to_brick_col(Bomberman *bombeerman, Brick *brick);
void enemy_to_brick_col(Enemy *enemy, Brick *brick);



#endif
