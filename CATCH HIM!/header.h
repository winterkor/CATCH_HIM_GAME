#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "compat.h"

#define command PAUSE_CMD
#define clear   CLEAR_CMD
#define UP    'w'
#define DOWN  's'
#define LEFT  'a'
#define RIGHT 'd'
#define ENTER 13
#define SPACE 32
#define CATCH 'c'
#define ITEM  'e'
#define QUIT  'q'

typedef struct playerInfo {
    char item1, item2, item3;
    int score;
    int cur_i, cur_j;
    int shield;
    char name[50];
} PLAYER;

char l[10][50];
char sym[10] = {'D', 'S', 'B', 'T'};
PLAYER a[3];
char map[105][105], s[105][105];
int t, mp, p1 = 0, p2 = 0, boy_i, boy_j;
int board_wid = 0, board_hi = 0;

/* forward declarations for cross-file calls */
int  bomb(int n, char temp[105][105], int *i, int *j, char s[105][105]);
int  random_itemdrop(void);
int  select_item(int n, char temp[105][105]);
void use_item(char temp[105][105], char s, int n);
void collect_item(char map[105][105], char s[105][105], int i, int j, int n);
void replace_item(int player, char symbol);
void oboard(char s[105][105], int *board_hi, int *board_wid);
void victory(int n);

#endif
