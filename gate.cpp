#include "function.h"

void add_gate(){
    int x1,x2,y1,y2;
    x1=x2=y1=y2=0;
    srand(time(NULL)); 
    while(1){
        x1=rand()%30;
        y1=rand()%30;
        x2=rand()%30;
        y2=rand()%30;
        if(map[stage_level][x1][y1]==WALL&&map[stage_level][x2][y2]==WALL)
            if(x2!=x1||y2!=y1)
                break;
    }
    if(gate_pass==0){
    gate.push_back(SNAKE(x1,y1));
    gate.push_back(SNAKE(x2,y2));
    map[stage_level][x1][y1]=GATE;
    map[stage_level][x2][y2]=GATE;}
}



void gate_direction(){
    if(gate[out_gate].x==0)
        head_direction=DOWN;
    else if(gate[out_gate].x==29)
        head_direction=UP;
    else if(gate[out_gate].y==0)
        head_direction=RIGHT;        
    else if(gate[out_gate].y==29)
        head_direction=LEFT;

    else{
        if((map[stage_level][gate[out_gate].x-1][gate[out_gate].y]>0&&map[stage_level][gate[out_gate].x-1][gate[out_gate].y]<3)
        &&(map[stage_level][gate[out_gate].x+1][gate[out_gate].y]>0&&map[stage_level][gate[out_gate].x+1][gate[out_gate].y]<3)){
            if(head_direction==RIGHT||head_direction==UP)
                head_direction=RIGHT;
            else if(head_direction==LEFT||head_direction==DOWN)
                head_direction=LEFT;
            
        }
        else if((map[stage_level][gate[out_gate].x][gate[out_gate].y-1]>0&&map[stage_level][gate[out_gate].x][gate[out_gate].y+1]>0)){
            if(head_direction==RIGHT||head_direction==UP)
                head_direction=UP;
            else if(head_direction==LEFT||head_direction==DOWN)
                head_direction=DOWN;
            
        }
    } 

}