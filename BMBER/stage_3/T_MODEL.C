#include <stdio.h>
#include <osbind.h>
#include "model.h"

int main()
{
    Bomberman player = {33, 65, 0, 0, 3};
    Bomb tst_bomb = {33+1, 65+1, 96, 96, 3};
    Enemy enemy = {320, 224, 0, 0};
    Brick brick1 = {192, 64};
    Brick brick2 = {33, 64};
    Brick brick3 = {160, 320};

    Model testGame = 
    {
        {352, 224, 0, 0, 3},    /*player*/
        {

            {33, 65, 0, 0},         /*enemy0*/
            {576, 65, 0, 0},
            {33, 352, 0, 0,},
            {576, 322, 0, 0},
            {192, 224, 0, 0},
            {448, 224, 0, 0},       /*enemy5*/
        },

        {
            {352, 160},             /*brick0*/
            {352, 288},
            {256 , 224},
            {384 , 224},            /*brick3*/
        },
        
        {96, 8, 240},
        {320 , 8, 0},
        {512, 8, 3}
    };

    printf("\033E\033f\n");
    Cnecin();

    /*
    printf("player initialized...\n");
    printf("x = %u, y = %u\n", player.x, player.y);
    printf("delta_x = %u, delta_y = %u\n", player.delta_x, player.delta_y);
    printf("lives = %u\n", player.max_lives); 
    
    printf("\n");
    printf("bomb initialized...\n");
    printf("x = %u, y = %u\n", tst_bomb.x, tst_bomb.y);
    printf("width = %u, length = %u\n", tst_bomb.width, tst_bomb.length);
    printf("timer = %u\n", tst_bomb.timer);

    printf("\n");
    printf("enemy initialized...\n");
    printf("x = %u, y = %u\n", enemy.x, enemy.y);
    printf("delta_x = %u, delta_y = %u\n", enemy.delta_x, enemy.delta_y);

    printf("\n");
    printf("bricks initialized...\n");
    printf("x = %u, y = %u\n", brick1.x, brick1.y);
    printf("x = %u, y = %u\n", brick2.x, brick2.y);
    printf("x = %u, y = %u\n", brick3.x, brick3.y);
    */

    printf("\n");
    printf("snapshot initialized...\n");
    printf("bomberman.x = %u, bomberman.y = %u\n", testGame.bomberman.x, testGame.bomberman.y);
    printf("bomberman.dx = %u, bomberman.dy = %u\n", testGame.bomberman.delta_x, testGame.bomberman.delta_y);
    printf("lives = %u\n", testGame.bomberman.max_lives);

    printf("\n");
    printf("enemy0.x = %u, enemy0.y = %u\n", testGame.enemy[0].x, testGame.enemy[0].y);
    printf("enemy0.dx = %u, enemy0.dy = %u\n", testGame.enemy[0].delta_x, testGame.enemy[0].delta_y);

    printf("\n");
    printf("brick2.x = %u, brick2.y = %u\n", testGame.brick[2].x, testGame.brick[2].y);

    printf("\n");
    printf("timer.x = %u, timer.y = %u\n", testGame.timer.x, testGame.timer.y);
    printf("time_countdown = %u\n", testGame.timer.time_countdown);

    printf("\n");
    printf("score.x = %u, score.y = %u\n", testGame.score.x, testGame.score.y);
    printf("score = %u\n", testGame.score.score);

    return 0;
}
