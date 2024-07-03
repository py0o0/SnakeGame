
#include "function.h"

void color_init(){
  // 글씨 배경 순서
  init_color(COLOR_GRAY, 200, 200, 200);      // 회색으로 설정
  init_color(COLOR_MINT, 200, 700, 700); 
  init_pair(1, COLOR_GRAY, COLOR_GRAY);       // Wall
  init_pair(2, COLOR_BLACK, COLOR_BLACK); // Immune Wall
  init_pair(3, COLOR_BLUE, COLOR_BLUE);       // Snake Head
  init_pair(4, COLOR_MINT, COLOR_MINT);       // Snake Body
  init_pair(5, COLOR_GREEN, COLOR_GREEN);     // Growth Item
  init_pair(6, COLOR_RED, COLOR_RED);         // Poison Item
  init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);   // Gate
  init_pair(8, COLOR_WHITE, COLOR_WHITE);     // Blank
  init_pair(9, COLOR_WHITE, COLOR_BLACK);
  init_pair(10, COLOR_BLACK, COLOR_WHITE);
}

void map_set(){


for(int i=0;i<30;i++){
for(int j=0;j<30;j++)
if(map[stage_level][i][j] == 0){
        wattron(my_win, COLOR_PAIR(8));
        mvwprintw(my_win, i, j, "%d", map[stage_level][i][j]);
        wattroff(my_win, COLOR_PAIR(8));
      }
 else if(map[stage_level][i][j] == WALL){
        wattron(my_win, COLOR_PAIR(1));
        mvwprintw(my_win, i, j, "%d", WALL);
        wattroff(my_win, COLOR_PAIR(1));
      }
else if(map[stage_level][i][j] == Immune_WALL){
        wattron(my_win, COLOR_PAIR(2));
        mvwprintw(my_win, i, j, "%d", Immune_WALL);
        wattroff(my_win, COLOR_PAIR(2));
      }
    else if(map[stage_level][i][j] == HEAD){
        wattron(my_win, COLOR_PAIR(3));
        mvwprintw(my_win, i, j, "%d", HEAD);
        wattroff(my_win, COLOR_PAIR(3));
      }
    else if(map[stage_level][i][j] == BODY){
        wattron(my_win, COLOR_PAIR(4));
        mvwprintw(my_win, i, j, "%d", BODY);
        wattroff(my_win, COLOR_PAIR(4));
      }
     else if(map[stage_level][i][j] == GROWTH){
        wattron(my_win, COLOR_PAIR(5));
        mvwprintw(my_win, i, j, "%d", GROWTH);
        wattroff(my_win, COLOR_PAIR(5));
      }  
      else if(map[stage_level][i][j] == POISON){
        wattron(my_win, COLOR_PAIR(6));
        mvwprintw(my_win, i, j, "%d", POISON);
        wattroff(my_win, COLOR_PAIR(6));
      }  
     else if(map[stage_level][i][j] == GATE){
        wattron(my_win, COLOR_PAIR(7));
        mvwprintw(my_win, i, j, "%d", GATE);
        wattroff(my_win, COLOR_PAIR(7));
      }         
}
wrefresh(my_win);
}


void item_gate_clear(){
  for(int i=0;i<30;i++)
      for(int j=0; j<30; j++){
          if(map[stage_level][i][j] == GROWTH || map[stage_level][i][j] == POISON)
             map[stage_level][i][j] = 0;
          if(map[stage_level][i][j] == GATE&&gate_pass==0)
             map[stage_level][i][j] = WALL;
            } 
            if(gate_pass==0)
            gate.clear();
}





