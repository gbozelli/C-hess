#include <stdio.h>
#include <string.h>
#include "player.h"

void player_init(Player* p, const char* name, Color color) {
    strcpy(p->name, name);
    p->color = color;
    p->count = 0;

    int row_pawns = color == WHITE ? 6 : 1;
    int row_back = color == WHITE ? 7 : 0;

    for (int i = 0; i < 8; i++)
        piece_init(&p->pieces[p->count++], PAWN, row_pawns, i, color);

    piece_init(&p->pieces[p->count++], ROOK, row_back, 0, color);
    piece_init(&p->pieces[p->count++], KNIGHT, row_back, 1, color);
    piece_init(&p->pieces[p->count++], BISHOP, row_back, 2, color);
    piece_init(&p->pieces[p->count++], QUEEN, row_back, 3, color);
    piece_init(&p->pieces[p->count++], KING, row_back, 4, color);
    piece_init(&p->pieces[p->count++], BISHOP, row_back, 5, color);
    piece_init(&p->pieces[p->count++], KNIGHT, row_back, 6, color);
    piece_init(&p->pieces[p->count++], ROOK, row_back, 7, color);
}

void player_print_pieces(Player* p) {
    printf("Peças de %s:\n", p->name);
    for (int i = 0; i < p->count; i++)
        printf("%s ", p->pieces[i].symbol);
    printf("\n");
}