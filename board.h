#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

typedef struct Board {
    Piece* board[8][8];
} Board;

struct Player;

void board_init(Board* b);
void board_clear(Board* b);
void board_place_player(Board* b, struct Player* p);
void board_print(Board* b);
int board_empty(Board* b, int x, int y);
int board_enemy(Board* b, int x, int y, Color color);

#endif