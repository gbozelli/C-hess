#include <stdio.h>
#include "board.h"
#include "player.h"

void board_init(Board* b) {
    board_clear(b);
}

void board_clear(Board* b) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            b->board[i][j] = NULL;
}

void board_place_player(Board* b, Player* p) {
    for (int i = 0; i < p->count; i++)
        b->board[p->pieces[i].x][p->pieces[i].y] = &p->pieces[i];
}

void board_print(Board* b) {
    printf("    1  2  3  4  5  6  7  8\n");
    printf("   ------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", 8 - i);
        for (int j = 0; j < 8; j++) {
            if (b->board[i][j] == NULL) printf(" . ");
            else printf(" %s ", b->board[i][j]->symbol);
        }
        printf("| %d\n", 8 - i);
    }
    printf("   ------------------------\n");
    printf("    1  2  3  4  5  6  7  8\n");
}

int board_empty(Board* b, int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) return 0;
    return b->board[x][y] == NULL;
}

int board_enemy(Board* b, int x, int y, Color color) {
    if (x < 0 || x > 7 || y < 0 || y > 7) return 0;
    if (b->board[x][y] == NULL) return 0;
    return b->board[x][y]->color != color;
}