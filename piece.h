#ifndef PIECE_H
#define PIECE_H

typedef enum { WHITE, BLACK } Color;
typedef enum { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING } PieceType;

typedef struct {
    int x, y;
    Color color;
    PieceType type;
    int moved;
    char symbol[4];
} Piece;

struct Board;

void piece_init(Piece* p, PieceType type, int x, int y, Color color);
int piece_valid_moves(Piece* p, struct Board* board, int moves[64][2]);

#endif