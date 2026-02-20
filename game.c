#include <stdio.h>
#include "game.h"

void game_init(Game* g) {
    player_init(&g->p1, "celta", WHITE);
    player_init(&g->p2, "uno", BLACK);
    board_init(&g->board);
}

void game_play(Game* g) {
    board_clear(&g->board);
    board_place_player(&g->board, &g->p1);
    board_place_player(&g->board, &g->p2);
    board_print(&g->board);
}