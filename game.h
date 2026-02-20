#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"

typedef struct {
    Player p1;
    Player p2;
    Board board;
} Game;

void game_init(Game* g);
void game_play(Game* g);

#endif