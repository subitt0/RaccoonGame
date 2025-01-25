#pragma once

#include "basic.h"

typedef struct Enemy {
	int x, y;
} Enemy;

typedef struct Pos {
	int x;
	int y;
}Pos;

int game();

void gameInit();

void gameUpdate();

void gameRender();

void putPlayer(int x, int y, char* ch);
void erasePlayer(int x, int y);
void eraseEnemy(Enemy*e);

void EnemyMove(Enemy* e);
void EnemyAttack();
void remove_stage();
void remove_stage2();
void jump();
void drop();
void eat_item();
void eat_life();
void spike();
void game_over();
void enemyStart();
void teleport(int x,int y);

void stage();
void show_life();
void score_UI();
void manual();
void finish();