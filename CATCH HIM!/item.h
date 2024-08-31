#include"bomb.h"

int select_item(int n,char temp[105][105]){
    char ar[2][4] = {"","<--"}, c=NULL;
    int tp=1,thp=0,fp=0;
    do{
        oboard(temp,&board_hi,&board_wid);
        printf("\nPLEASE SELECT ITEM: (select q to cancel)\n");
        printf("1 : %c %s\n",a[n].item1,ar[tp]);
        printf("2 : %c %s\n",a[n].item2,ar[thp]);
        printf("3 : %c %s\n",a[n].item3,ar[fp]);
        c=getch();
        system(clear);
        if(c==UP){
            if(thp==1){
                thp=0;tp=1;continue;
            }
            else  if(fp==1){
                thp=1;fp=0;continue;
            }
        }
        else if(c==DOWN){
            if(tp==1){
                tp=0;thp=1;continue;
            }
            else  if(thp==1){
                fp=1;thp=0;continue;
            }
        }
        else if(c==QUIT){
            return 1;
        }
    }while(c!=ENTER);
    if(tp==1){
        use_item(temp,a[n].item1,n);//use item
        a[n].item1='-';
    }
    else if(thp==1){
        use_item(temp,a[n].item2,n);//use item
        a[n].item2='-';
    }
    else if(fp==1){
        use_item(temp,a[n].item3,n);//use item
        a[n].item3='-';
    }
    system(clear);
    return 0;
}
void use_item(char temp[105][105],char s,int n){
    if(s=='D'){
        if(n==0) p1-=2;
        else if(n==1) p2-=2;
    }
    else if(s=='S'){
        a[n].shield+=3;
    }
    else if(s=='B'){
        if(n==0&&a[1].shield==0){
            printf("Send %s to initial point",a[1].name);
            temp[a[1].cur_i][a[1].cur_j]='.';
            a[1].cur_i=board_hi-2;
            a[1].cur_j=board_wid-2;
            temp[a[1].cur_i][a[1].cur_j]='2';
            Sleep(1000);
        }
        else if(n==1&&a[0].shield==0){
            printf("Send %s to initial point",a[0].name);
            temp[a[0].cur_i][a[0].cur_j]='.';
            a[0].cur_i=1;
            a[0].cur_j=1;
            temp[a[0].cur_i][a[0].cur_j]='1';
            Sleep(1000);
        }
        else{
            printf("This player have shield.You cannot do anything\n");
            if(a[n].item1=='-') a[n].item1='B';
            else if(a[n].item2=='-') a[n].item2='B';
            else if(a[n].item3=='-') a[n].item3='B';
        }
    }
    else if(s=='T'){
        if(n==0) p1-=3;
        else if(n==1) p2-=3;
    }
    else{
        printf("No item.\n");
        printf("wait for a while...\n");
        Sleep(2000);
        system(clear);
        select_item(n,temp);
    }
}
void collect_item(char map[105][105],char s[105][105],int i,int j,int n){
    if(s[i][j]>51&&s[i][j]<56){
        printf("%s found %s!!",a[n].name,l[s[i][j]-'0']);
        if(a[n].item1=='-') a[n].item1=sym[s[i][j]-'4'];
        else if(a[n].item2=='-') a[n].item2=sym[s[i][j]-'4'];
        else if(a[n].item3=='-') a[n].item3=sym[s[i][j]-'4'];
        else{
            replace_item(sym[s[i][j]-'4']);
        }
        s[i][j]='.';
        Sleep(1000);
        //do more in case full inventory
    }
}
void replace_item(char symbol){
    int n;
    printf("Select to replace the item :");
    scanf("%d",&n);
    if(n==1) a[n].item1=symbol;
    else if(n==2) a[n].item2=symbol;
    else if(n==3) a[n].item3=symbol;
}
