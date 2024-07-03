
#include "function.h"

void make_s(){  
    int s_location[4][1][2] = { 
    {{14, 14}},  
    {{14, 14}},
    {{10, 20}},
    {{14, 14}}
  };
   snake.clear();
  
  for(int i=0;i<3;i++)
    snake.push_back(SNAKE(s_location[stage_level][0][1],s_location[stage_level][0][0]+i)); 
  map[stage_level][snake[0].x][snake[0].y] = HEAD;  
  for(int i=1; i<3; i++)
    map[stage_level][snake[i].x][snake[i].y] = BODY; 
  map_set();
  nodelay(my_win,FALSE);
  wgetch(my_win);
  nodelay(my_win,TRUE);

}

void set_direction(){ 

    int ch = wgetch(my_win);
    switch(ch){
        case KEY_UP:
         if(head_direction==DOWN)
            gameover();
         
         head_direction=UP; 
         break;

         case KEY_DOWN:
         if(head_direction==UP)
           gameover();
         head_direction=DOWN;
         break;

         case KEY_RIGHT:
         if(head_direction==LEFT)
            gameover();
         
         head_direction=RIGHT; 
         break;

         case KEY_LEFT:
         if(head_direction==RIGHT) 
            gameover();

         head_direction=LEFT;
         break;
    }
    
}

void move_s(){
    int next_x= snake[0].x + dx[head_direction][1];
    int next_y= snake[0].y + dx[head_direction][0];
    

  
    if(map[stage_level][next_x][next_y]==WALL||map[stage_level][next_x][next_y]==Immune_WALL||map[stage_level][next_x][next_y]==BODY) 
        gameover();
    

   
    else if(map[stage_level][next_x][next_y]==GROWTH){  
       growth_item++;
       snake.insert(snake.begin(),SNAKE(next_x,next_y));
       map[stage_level][snake[0].x][snake[0].y]=HEAD; 
       map[stage_level][snake[1].x][snake[1].y]=BODY;
       check_body(); 
       wrefresh(my_win);
    }


    else if(map[stage_level][next_x][next_y]==POISON){  

       if(snake.size()==3) 
        gameover();
       

       posion_item++;
       snake.insert(snake.begin(),SNAKE(next_x,next_y));
       map[stage_level][snake[snake.size()-1].x][snake[snake.size()-1].y]=0; 
       snake.pop_back();
       map[stage_level][snake[snake.size()-1].x][snake[snake.size()-1].y]=0; 
       snake.pop_back();      
       map[stage_level][snake[0].x][snake[0].y] = HEAD;
       map[stage_level][snake[1].x][snake[1].y] = BODY;
       wrefresh(my_win);
    }

    
    else if(map[stage_level][next_x][next_y]==GATE){
      if(next_x==gate[0].x&&next_y==gate[0].y)
         out_gate=1;
      
      else if(next_x==gate[1].x&&next_y==gate[1].y)
         out_gate=0;


      gate_direction();
      gnext_x=gate[out_gate].x+dx[head_direction][1];
      gnext_y=gate[out_gate].y+dx[head_direction][0];
      map[stage_level][snake[snake.size()-1].x][snake[snake.size()-1].y]=0; 
      snake.pop_back();
      snake.insert(snake.begin(), SNAKE(gnext_x, gnext_y));
      map[stage_level][snake[0].x][snake[0].y] = HEAD;
      map[stage_level][snake[1].x][snake[1].y] = BODY;
      wrefresh(my_win);
      gate_pass=1;
    }

    else{
      
         map[stage_level][snake[snake.size()-1].x][snake[snake.size()-1].y]=0; 
         snake.pop_back();
         snake.insert(snake.begin(), SNAKE(next_x, next_y));
         map[stage_level][snake[0].x][snake[0].y] = HEAD;
         map[stage_level][snake[1].x][snake[1].y] = BODY;
         wrefresh(my_win);
    }

    if(snake[snake.size()-1].x==gnext_x&&snake[snake.size()-1].y==gnext_y){ 
       map[stage_level][gate[0].x][gate[0].y] = WALL;
       map[stage_level][gate[1].x][gate[1].y] = WALL;
       gate_cnt++;
       gate.clear();
       gnext_x=gnext_y=0;
       gate_pass=0;
    }

    

}


void check_body(){
   if(snake.size()>body_length)
      body_length=snake.size();
}

