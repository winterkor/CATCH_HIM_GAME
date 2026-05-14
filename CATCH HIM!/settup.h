#include "display_screen.h"

int line = 0;
void player_name()
{
    for (int i = 1; i <= 2; i++)
    {
        printf("Enter your name %dP : ", i);
        scanf("%s", a[i - 1].name);
    }
    Sleep(1000);
    system(clear);
}
int select_map()
{
    int i;
    printf("Select map : ");
    scanf("%d", &i);
    system(clear);
    return i;
}
void createboard(char temp[105][105], int *board_wid, int *board_hi, int mp, char s[105][105])
{
    FILE *fp = NULL;
    int i, j;
    if (mp == 1)
        fp = fopen("map1.txt", "r");
    else if (mp == 2)
        fp = fopen("map2.txt", "r");
    else if (mp == 3)
        fp = fopen("map3.txt", "r");
    else if (mp == 4)
        fp = fopen("map4.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open map file (mp=%d)\n", mp);
        exit(1);
    }
    fscanf(fp, "%d %d\n", board_hi, board_wid);
    // read the entire map
    while (fgets(temp[line], *board_wid + 50, fp))
    {
        size_t len = strlen(temp[line]);
        if (len > 0 && temp[line][len - 1] == '\n')
            temp[line][len - 1] = '\0';
        line++;
    }
    //    printf("%d %d\n",*board_wid,*board_hi);
    for (i = 0; i < *board_hi; i++)
    {
        for (j = 0; j < *board_wid; j++)
        {
            s[i][j] = temp[i][j];
        }
    }
    //    check the value
    //        for(int i=0;i<*board_hi;i++){
    //        for(int j=0;j<*board_wid;j++){
    //            printf("%c",s[i][j]);
    //        }printf("\n");
    //    }
    //    Sleep(10000);
    fclose(fp);
}
void oboard(char s[105][105], int *board_hi, int *board_wid)
{
    for (int i = 0; i < *board_hi; i++)
    {
        for (int j = 0; j < *board_wid; j++)
        {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}
void find_boy(int *m, int *n, char s[105][105], int *board_wid, int *board_hi)
{
    for (int i = 0; i < *board_hi; i++)
    {
        for (int j = 0; j < *board_wid; j++)
        {
            if (s[i][j] == '?')
            {
                *m = i;
                *n = j;
            }
        }
    }
    //    printf("%d %d",*m,*n);
}
int check_win(char map[105][105], int *m, int *n)
{
    if (map[*m][*n] == '1')
    {
        victory(0);
        return 1;
    }
    else if (map[*m][*n] == '2')
    {
        victory(1);
        return 1;
    }
    else
        return 0;
}
