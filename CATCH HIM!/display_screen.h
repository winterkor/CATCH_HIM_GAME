#include"header.h"

int start_display()
{
    int c;
    printf("\n");
    printf("\t\t____   _____   ____   ____   _____\n");
    printf("\t\t|___     |     |___|  |___|    |\n");
    printf("\t\t___|     |     |   |  |   \\    |\n");
    printf("\t\t      Welcome to CATCH HIM!!\n\n\n\n");
    printf("\t\tPress 1 : Start Game\n");
    printf("\t\tPress 2 : How to play\n");
    printf("\t\t");
    restart : c=getch();
    if(c!=49&&c!=50){
        goto restart;
    }
    system(clear);
    return c;
}
void gamerule(){
    printf("RULE\n");
    printf("This game is to catch a boy that will change");
    printf("his place after you get to him\n");
    printf("The things you have to do are race with your friend,\ndrop the bombs to make the blocks disappear but not any block that you can bomb,\nonly the special one, and walk along the map to get to the boy.");
    printf("The boy will run away from you\n");
    printf("* is destroyable block\n");
    printf("# is undestroyable block\n");
    printf(". is a path way\n\n");
    printf("There are many item\n");
    printf("D for walking 2 turns\n");
    printf("S for shield for 3 turns\n");
    printf("T for walking 3 turns\n");
    printf("B for sending another player to his/he initial point\n");
    system(command);
    system(clear);
}
void countdown(){
    printf("\t\t____\n");
    printf("\t\t    |\n");
    printf("\t\t____|\n");
    printf("\t\t    |\n");
    printf("\t\t____|\n");
    Sleep(1000);//wait for 1 second
    system(clear);
    printf("\t\t ____\n");
    printf("\t\t     |\n");
    printf("\t\t ____|\n");
    printf("\t\t|\n");
    printf("\t\t|____\n");
    Sleep(1000);
    system(clear);
    printf("\t\t    |\n");
    printf("\t\t    |\n");
    printf("\t\t    |\n");
    printf("\t\t    |\n");
    printf("\t\t    |\n");
    Sleep(1000);
    system(clear);
}
void victory(int n){
    system(clear);
    printf("%s wins\n",a[n].name);
    printf("CONGRATULATIONS!\n");
}
