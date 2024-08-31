#include"item.h"

int main(){
    //initialize item
    strcpy(l[4],"Double");
    strcpy(l[5],"Shield");
    strcpy(l[6],"Push Back");
    strcpy(l[7],"Triple");
    t=start_display();//start game
    if(t==50){
        gamerule(); //show game rule
    }
    player_name();//input player's name
    mp=select_map();//select the map
    countdown();//countdown the time
    createboard(map,&board_wid,&board_hi,mp,s);//create board from .txt files
    find_boy(&boy_i,&boy_j,map,&board_wid,&board_hi);//find the initial position of the boy
//    printf("%d %d",boy_i,boy_j);Sleep(2000);
    //set up the value of each
    a[0].cur_i=1,a[0].cur_j=1;//player 1 position
    a[1].cur_i=board_hi-2,a[1].cur_j=board_wid-2;//player 2 position
    a[0].score=0;//player 1 score
    a[1].score=0;//player 2 score
    a[0].item1='-',a[0].item2='-',a[0].item3='-';//player 1 item
    a[1].item1='-',a[1].item2='-',a[1].item3='-';//player 2 item
//    printf("%d %d",board_wid,board_hi);
    while(a[0].score<1&&a[1].score<1){
        system(clear);
        oboard(map,&board_hi,&board_wid);//out put board
        if(p1<=p2){
            move_pla(0,map,&a[0].cur_i,&a[0].cur_j);//move the player 1
            collect_item(map,s,a[0].cur_i,a[0].cur_j,0);//check that if player 1 collect item or not
            p1++;
        }
        else if(p1>p2){
            move_pla(1,map,&a[1].cur_i,&a[1].cur_j);//move player 2
            collect_item(map,s,a[1].cur_i,a[1].cur_j,1);//check that if player 2 collect item or not
            p2++;
        }
        if(check_win(map,&boy_i,&boy_j)) break;//check that if someone who can catch the boy
        boy_run(map,&boy_i,&boy_j);//the boy run away from player
//        printf("%d %d",boy_i,boy_j);
//        Sleep(2000);
    }
return 0;
}
