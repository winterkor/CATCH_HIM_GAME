#include "display_screen.h"

int line = 0;
void player_name()
{
    for (int i = 1; i <= 2; i++)
    {
        printf("Enter your name %dP : ", i);
        scanf("%49s", a[i - 1].name);
    }
    Sleep(1000);
    system(clear);
}
int select_map()
{
    int i = 0;
    do {
        printf("Select map (1-4): ");
        if (scanf("%d", &i) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            i = 0;
        }
    } while (i < 1 || i > 4);
    system(clear);
    return i;
}
void createboard(char temp[105][105], int *board_wid, int *board_hi, int mp, char s[105][105])
{
    FILE *fp = NULL;
    int i, j;
    line = 0;
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
    if (fscanf(fp, "%d %d\n", board_hi, board_wid) != 2) {
        fprintf(stderr, "Bad map header in map%d.txt (expected: <rows> <cols>)\n", mp);
        fclose(fp);
        exit(1);
    }
    if (*board_hi < 3 || *board_hi > 105 || *board_wid < 3 || *board_wid > 105) {
        fprintf(stderr, "Map dimensions out of range: %d x %d (must be 3..105)\n",
                *board_hi, *board_wid);
        fclose(fp);
        exit(1);
    }
    // read the entire map
    while (fgets(temp[line], 105, fp))
    {
        size_t len = strlen(temp[line]);
        while (len > 0 && (temp[line][len - 1] == '\n' || temp[line][len - 1] == '\r'))
            temp[line][--len] = '\0';
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
static const char *cell_color(char c)
{
    switch (c) {
        case '1': return C_BOLD C_RED;
        case '2': return C_BOLD C_BLUE;
        case '?': return C_BOLD C_YELLOW;
        case 'D': case 'S': case 'B': case 'T': return C_GREEN;
        case '#': return C_CYAN;
        case '*': return C_DIM;
        default:  return "";
    }
}

static void print_item_slot(char it)
{
    if (it == '-')
        printf("[-]");
    else
        printf("[%s%c%s]", C_GREEN, it, C_RESET);
}

static void print_hud_line(int line)
{
    switch (line) {
        case 0:
            printf("%s== Player 1: %s ==%s", C_BOLD C_RED, a[0].name, C_RESET);
            break;
        case 1:
            printf("   Items: ");
            print_item_slot(a[0].item1);
            print_item_slot(a[0].item2);
            print_item_slot(a[0].item3);
            printf("  Shield: %d", a[0].shield);
            break;
        case 2:
            printf("   Turns taken: %d", p1);
            break;
        case 3:
            break;
        case 4:
            printf("%s== Player 2: %s ==%s", C_BOLD C_BLUE, a[1].name, C_RESET);
            break;
        case 5:
            printf("   Items: ");
            print_item_slot(a[1].item1);
            print_item_slot(a[1].item2);
            print_item_slot(a[1].item3);
            printf("  Shield: %d", a[1].shield);
            break;
        case 6:
            printf("   Turns taken: %d", p2);
            break;
        default: break;
    }
}

#define HUD_ROWS 7

void oboard(char s[105][105], int *board_hi, int *board_wid)
{
    int max_lines = (*board_hi > HUD_ROWS) ? *board_hi : HUD_ROWS;
    for (int i = 0; i < max_lines; i++)
    {
        if (i < *board_hi) {
            for (int j = 0; j < *board_wid; j++) {
                char c = s[i][j];
                const char *col = cell_color(c);
                if (col[0])
                    printf("%s%c%s", col, c, C_RESET);
                else
                    printf("%c", c);
            }
        } else {
            for (int j = 0; j < *board_wid; j++)
                printf(" ");
        }
        printf("   ");
        if (i < HUD_ROWS)
            print_hud_line(i);
        printf("\n");
    }
}
void find_boy(int *m, int *n, char s[105][105], int *board_wid, int *board_hi)
{
    *m = -1;
    *n = -1;
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
    if (*m < 0) {
        fprintf(stderr, "Map has no boy ('?') character.\n");
        exit(1);
    }
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
