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
	Enemy enemies[10];
	Brick bricks[50];
	Timer timer;
	ScoreCounter score;
	LifeCounter life_counter;
} Model;

#endif
