#ifndef PLAYER_H
#define PLAYER_H

#include "piece.h"

typedef struct Player {
    char name[50];
    Color color;
    Piece pieces[16];
    int count;
} Player;

void player_init(Player* p, const char* name, Color color);
void player_print_pieces(Player* p);

#endif