#include "function.h"

void sub_win(){

    wattron(sub1, COLOR_PAIR(8));
    wborder(sub1,'1','1','1','1','1','1','1','1');
    wattroff(sub1, COLOR_PAIR(8));
    mvwprintw(sub1,2,5,"Score Board (level %d)",stage_level);
    mvwprintw(sub1,4,1,"Body length : %d  /  %d  ( )",snake.size(),body_length);
    if(body_length>=goal[stage_level][0])
        mvwprintw(sub1,4,1,"Body length : %d  /  %d  (v)",snake.size(),body_length);

    mvwprintw(sub1,6,1,"Growth item : %d  ( )",growth_item);
    if(growth_item>=goal[stage_level][1])
        mvwprintw(sub1,6,1,"Growth item : %d  (v)",growth_item);
    
    mvwprintw(sub1,8,1,"Posion item : %d  ( )",posion_item);
    if(posion_item>=goal[stage_level][2])
        mvwprintw(sub1,8,1,"Posion item : %d  (v)",posion_item);
    
    mvwprintw(sub1,10,1,"Gate counter : %d  ( )",gate_cnt);
    if(gate_cnt>=goal[stage_level][3])
        mvwprintw(sub1,10,1,"Gate counter : %d  (v)",gate_cnt);

    wrefresh(sub1);

    wattron(sub2, COLOR_PAIR(8));
    wborder(sub2,'1','1','1','1','1','1','1','1');
    wattroff(sub2, COLOR_PAIR(8));
    mvwprintw(sub2,2,4,"Mission Board (level %d)",stage_level);
    mvwprintw(sub2,4,1,"Body length : %d ",goal[stage_level][0]);
    mvwprintw(sub2,4,1,"Body length : %d ",goal[stage_level][0]);
    mvwprintw(sub2,6,1,"Growth item : %d",goal[stage_level][1]);
    mvwprintw(sub2,8,1,"Posion item : %d",goal[stage_level][2]);
    mvwprintw(sub2,10,1,"Gate counter : %d",goal[stage_level][3]);

    wrefresh(sub2);

    if(body_length>=goal[stage_level][0]&&growth_item>=goal[stage_level][1]
    &&posion_item>=goal[stage_level][2]&&gate_cnt>=goal[stage_level][3])
        clear_stage=1;
}


void game_set(){
    
    nodelay(my_win,FALSE);
    if(stage_level<3){
    wattron(my_win, COLOR_PAIR(2));
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)
           mvwprintw(my_win,i,j,"1");
    
    wattroff(my_win, COLOR_PAIR(2));

    wattron(my_win, COLOR_PAIR(9));
    mvwprintw(my_win,14,12,"SUCESS");
    wattroff(my_win, COLOR_PAIR(9));
    wrefresh(my_win);
    }
    else{
        wattron(my_win, COLOR_PAIR(8));
        for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)
           mvwprintw(my_win,i,j,"1");
    
    wattroff(my_win, COLOR_PAIR(8));

    wattron(my_win, COLOR_PAIR(10));
    mvwprintw(my_win,14,10,"GAME CLEAR");
    wattroff(my_win, COLOR_PAIR(10));
    wrefresh(my_win);
    wgetch(my_win);
    endwin();
    exit(0);
    }

    clear_stage=growth_item=posion_item=gate_cnt=0;
    body_length=3;
    while(snake.size()!=3){
        snake.pop_back();
    }
    stage_level++;
    wrefresh(my_win);

    wgetch(my_win);
    nodelay(my_win,TRUE);
}

void gameover(){
  nodelay(my_win,FALSE);
  wattron(my_win, COLOR_PAIR(8));
  for(int i=0;i<30;i++)
    for(int j=0;j<30;j++)
        mvwprintw(my_win,i,j,"1");
    
    wattroff(my_win, COLOR_PAIR(8));

    wattron(my_win, COLOR_PAIR(10));
    mvwprintw(my_win,14,13,"FAIL");
    wattroff(my_win, COLOR_PAIR(10));
    wgetch(my_win);
    endwin();
    exit(0);
}

void set_up(){
    nodelay(my_win,FALSE);
    for(int i=0;i<30;i++){
for(int j=0;j<30;j++)
if(map[4][i][j] == 0){
        wattron(my_win, COLOR_PAIR(8));
        mvwprintw(my_win, i, j, "%d", map[stage_level][i][j]);
        wattroff(my_win, COLOR_PAIR(8));
      }
 else {
        wattron(my_win, COLOR_PAIR(1));
        mvwprintw(my_win, i, j, "%d", WALL);
        wattroff(my_win, COLOR_PAIR(1));
      }

}
wrefresh(my_win);
wgetch(my_win);
nodelay(my_win,TRUE);
}
