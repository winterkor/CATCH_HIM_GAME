#include "header.h"

int start_display()
{
    int c;
    printf("\n");
    printf("%s\t\t____   _____   ____   ____   _____%s\n", C_BOLD C_RED, C_RESET);
    printf("%s\t\t|___     |     |___|  |___|    |%s\n",   C_BOLD C_RED, C_RESET);
    printf("%s\t\t___|     |     |   |  |   \\    |%s\n",  C_BOLD C_RED, C_RESET);
    printf("\t\t      Welcome to %sCATCH HIM!!%s\n\n\n\n", C_BOLD C_YELLOW, C_RESET);
    printf("\t\tPress %s1%s : Start Game\n", C_BOLD C_GREEN, C_RESET);
    printf("\t\tPress %s2%s : How to play\n", C_BOLD C_GREEN, C_RESET);
    printf("\t\t");
restart:
    c = getch();
    if (c != '1' && c != '2')
    {
        goto restart;
    }
    system(clear);
    return c;
}
void gamerule()
{
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
void countdown()
{
    printf("\t\t____\n");
    printf("\t\t    |\n");
    printf("\t\t____|\n");
    printf("\t\t    |\n");
    printf("\t\t____|\n");
    Sleep(1000); // wait for 1 second
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
void victory(int n)
{
    const char *col = (n == 0) ? C_BOLD C_RED : C_BOLD C_BLUE;
    system(clear);
    printf("\n\n");
    printf("%s              ___________\n", col);
    printf("             '._==_==_=_.'\n");
    printf("             .-\\:      /-.\n");
    printf("            | (|:.     |) |\n");
    printf("             '-|:.     |-'\n");
    printf("               \\::.    /\n");
    printf("                '::. .'\n");
    printf("                  ) (\n");
    printf("                _.' '._\n");
    printf("               `\"\"\"\"\"\"\"`%s\n\n", C_RESET);
    printf("        %s****  %s WINS!  ****%s\n\n", col, a[n].name, C_RESET);
    printf("        %sFinal stats:%s\n", C_BOLD, C_RESET);
    printf("          %sPlayer 1 (%s):%s %d turns taken\n", C_RED, a[0].name, C_RESET, p1);
    printf("          %sPlayer 2 (%s):%s %d turns taken\n", C_BLUE, a[1].name, C_RESET, p2);
    printf("\n        %sCONGRATULATIONS!%s\n\n", C_BOLD C_YELLOW, C_RESET);
}
