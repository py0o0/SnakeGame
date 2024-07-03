#pragma once

#include <ncurses.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include <string>
#include <vector>
#include <unistd.h> 
#include "map.h"
using namespace std;

#define COLOR_GRAY 8
#define COLOR_MINT 9

const int BLANK = 0;
const int WALL = 1;
const int Immune_WALL = 2;
const int HEAD = 3;
const int BODY = 4;
const int GROWTH = 5;
const int POISON = 6;
const int GATE = 7;

const int UP = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;

class SNAKE{
  public:
  SNAKE();
  SNAKE(int a, int b);
  
  public:
  int x, y;
};
SNAKE::SNAKE() : x(0) ,y(0)
{
}
SNAKE::SNAKE(int a, int b) : x(a), y(b)
{
}

void map_set();
void color_init();
void item_gate_clear();

void make_s();
void set_direction();
void move_s();
void check_body();

void add_item();

void add_gate();
void gate_direction();

void sub_win();
void game_set();
void gameover();
void set_up();

vector<SNAKE> snake;
vector<SNAKE> gate;

WINDOW *my_win,*sub1,*sub2;

int head_direction,stage_level,growth_item,posion_item,g_flag,out_gate,gate_cnt,gnext_x,gnext_y;
int clear_stage,gate_pass,body_length=3;
int dx[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int goal[4][4] = {{4,1,0,0},{4,1,1,1},{5,3,1,1},{5,3,1,2}};


