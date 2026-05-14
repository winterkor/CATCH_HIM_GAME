#include "move.h"
int bomb(int n, char temp[105][105], int *i, int *j, char s[105][105])
{
    char a;
    char bom = 0;
    int r;
    printf("\n%s===== BOMB MODE =====%s\n", C_BOLD C_YELLOW, C_RESET);
    printf("Pick direction to bomb (w/a/s/d), or q to cancel\n");
    r = random_itemdrop(); // random item when we destroy the box
    if (r == 3)
        a = 46;
    else if (r == 4)
        a = 68;
    else if (r == 5)
        a = 83;
    else if (r == 6)
        a = 66;
    else if (r == 7)
        a = 84;
    bom = 0;
    bom = getch();
    if (bom == DOWN && temp[*i + 1][*j] == '*')
    {
        temp[*i + 1][*j] = a;
        s[*i + 1][*j] = r + '0';
        printf("BOMB!!!\n");
        Sleep(750);
    }
    else if (bom == UP && temp[*i - 1][*j] == '*')
    {
        temp[*i - 1][*j] = a;
        s[*i - 1][*j] = r + '0';
        printf("BOMB!!!\n");
        Sleep(750);
    }
    else if (bom == LEFT && temp[*i][*j - 1] == '*')
    {
        temp[*i][*j - 1] = a;
        s[*i][*j - 1] = r + '0';
        printf("BOMB!!!\n");
        Sleep(750);
    }
    else if (bom == RIGHT && temp[*i][*j + 1] == '*')
    {
        temp[*i][*j + 1] = a;
        s[*i][*j + 1] = r + '0';
        printf("BOMB!!!\n");
        Sleep(750);
    }
    else if (bom == QUIT)
    {
        return 1;
    }
    else
    {
        printf("Please try again\n");
        printf("Wait for a while...\n");
        Sleep(1000);
        system(clear);
        oboard(temp, &board_hi, &board_wid);
        return bomb(n, temp, i, j, s);
    }
    return 0;
}
int random_itemdrop()
{
    return rand() % 5 + 3;
}
