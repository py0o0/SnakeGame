#include "function.h"

void add_item(){
    int n,x,y;
    n=x=y=0;
    srand(time(NULL)); 
    int cnt = rand() % 4;
  
  while(n<3){
    x = rand()%30;
    y = rand()%30;

    if(map[stage_level][x][y] == 0){
        if(n<cnt){
            map[stage_level][x][y] = GROWTH;
            n++;
        }
        else if(n!=3&&n>=cnt){
            map[stage_level][x][y] = POISON;
            n++;
        }
    }
  }
  wrefresh(my_win);
}