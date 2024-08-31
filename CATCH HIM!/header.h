#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define command "pause"
#define clear "cls"
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define ENTER 13
#define SPACE 32
#define CATCH 'c'
#define ITEM 'e'
#define QUIT 'q'
//initialize variable
typedef struct playerInfo{
    char item1,item2,item3;
    int score;
    int cur_i,cur_j;
    int shield;
    char name[50];
}PLAYER;
char l[10][50];
char sym[10]={'D','S','B','T'};
//l[5].name={"Blank","Double","Shield","Push Back","Triple"};
//l[5].sym={'.','D','S','B','T'};
PLAYER a[3];
char map[105][105],s[105][105];
int i,t,mp,p1=0,p2=0,boy_i,boy_j;
char dir;
int board_wid=0,board_hi=0;
