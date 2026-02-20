#include <string.h>
#include "piece.h"
#include "board.h"

void piece_init(Piece* p, PieceType type, int x, int y, Color color) {
    p->x = x;
    p->y = y;
    p->color = color;
    p->type = type;
    p->moved = 0;

    if (type == PAWN) strcpy(p->symbol, color == WHITE ? "♙" : "♟");
    if (type == ROOK) strcpy(p->symbol, color == WHITE ? "♖" : "♜");
    if (type == KNIGHT) strcpy(p->symbol, color == WHITE ? "♘" : "♞");
    if (type == BISHOP) strcpy(p->symbol, color == WHITE ? "♗" : "♝");
    if (type == QUEEN) strcpy(p->symbol, color == WHITE ? "♕" : "♛");
    if (type == KING) strcpy(p->symbol, color == WHITE ? "♔" : "♚");
}

int piece_valid_moves(Piece* p, Board* board, int moves[64][2]) {
    int count = 0;
    int nx;

    if (p->type == PAWN) {
        int dir = p->color == WHITE ? -1 : 1;
        nx = p->x + dir;
        if (board_empty(board, nx, p->y)) {
            moves[count][0] = nx;
            moves[count++][1] = p->y;
            if (!p->moved && board_empty(board, p->x + 2 * dir, p->y)) {
                moves[count][0] = p->x + 2 * dir;
                moves[count++][1] = p->y;
            }
        }
        if (board_enemy(board, p->x + dir, p->y - 1, p->color)) {
            moves[count][0] = p->x + dir;
            moves[count++][1] = p->y - 1;
        }
        if (board_enemy(board, p->x + dir, p->y + 1, p->color)) {
            moves[count][0] = p->x + dir;
            moves[count++][1] = p->y + 1;
        }
    }

    return count;
}