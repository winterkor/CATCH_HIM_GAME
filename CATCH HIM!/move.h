#include"settup.h"
void move_pla(int n,char temp[105][105],int *i,int *j){
    char dir;
    printf("\n\nPlayer%d-%s's turn\n",n+1,a[n].name);
    printf("Press the ASWD to move or space to destroy block\n");
    dir=getch();//input direction
//    printf("dir = %d\n",dir);
    if(dir==DOWN&&(temp[*i+1][*j]!='*'&&temp[*i+1][*j]!='#')){
        temp[*i][*j]='.';
        *i+=1;
//      printf("%d %d\n",i1,j1);
        temp[*i][*j]=n+49;
    }
    else if(dir==UP&&(temp[*i-1][*j]!='*'&&temp[*i-1][*j]!='#')){
        temp[*i][*j]='.';
        *i-=1;
        temp[*i][*j]=n+49;
    }
    else if(dir==RIGHT&&(temp[*i][*j+1]!='*'&&temp[*i][*j+1]!='#')){
        temp[*i][*j]='.';
        *j+=1;
        temp[*i][*j]=n+49;
    }
    else if(dir==LEFT&&(temp[*i][*j-1]!='*'&&temp[*i][*j-1]!='#')){
        temp[*i][*j]='.';
        *j-=1;
        temp[*i][*j]=n+49;
    }
    else if(dir==SPACE){//time to bomb it
        if(bomb(n,temp,i,j,s)){
            printf("Cancel to destroy the block\n");
            printf("Wait for a while...\n");
            Sleep(1000);
            system(clear);
            oboard(temp,&board_hi,&board_wid);
            move_pla(n,temp,i,j);
        }
    }
    else if(dir==ITEM){//open inventory
        system(clear);
        if(select_item(n,temp)){
            printf("Cancel to use item\n");
            printf("Wait for a while...\n");
            Sleep(1000);
            system(clear);
            oboard(temp,&board_hi,&board_wid);
            move_pla(n,temp,i,j);
        }
    }
    else{
        printf("Ouch!!Please press again.\n");
        printf("Wait for a while...\n");
        Sleep(1000);
        system(clear);
        oboard(temp,&board_hi,&board_wid);
        move_pla(n,temp,i,j);
    }
}
void boy_run(char temp[105][105],int *m,int *n){
    int g;
    int dx[8]={-1,-1,-1,1,1,1,0,0},dy[8]={0,-1,1,0,1,-1,1,-1};
    srand(time(0));
    g=rand()%8;
    printf("%d",g);
    if(temp[*m+dx[g]][*n+dy[g]]!='#'&&temp[*m+dx[g]][*n+dy[g]]!='*'&&temp[*m+dx[g]][*n+dy[g]]!='1'&&temp[*m+dx[g]][*n+dy[g]]!='2'){
        temp[*m+dx[g]][*n+dy[g]]='?';
        temp[*m][*n]='.';
        *m+=dx[g];*n+=dy[g];
    }
}
