#include "map.cpp"
#include "snake.cpp"
#include "item.cpp"
#include "gate.cpp"
#include "ui.cpp"

int main(){                                                              
    initscr();
    start_color(); 
    color_init();   
    noecho(); 
    curs_set(FALSE); 
    
    
    my_win=newwin(30,30,0,0);
    wrefresh(my_win);

    keypad(my_win, TRUE); 
        
    sub1=newwin(13,30,0,35);
    sub2=newwin(13,30,16,35);

    nodelay(my_win,TRUE);
    set_up();

    while(1){
       head_direction = LEFT;                                                                            
       sub_win();
       make_s();
       map_set();
        while(1){
            item_gate_clear();
            map_set();
            add_item();
            add_gate();
            map_set();
            for(int i=0;i<50;i++){
                set_direction();
                move_s();
                map_set();
                sub_win();
                if(clear_stage)
                   break;
                usleep(150000);
            }
          if(clear_stage)
            break;
        }
        game_set();
    }    
    return 0;
    
}
