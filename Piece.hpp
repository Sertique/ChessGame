#ifndef PIECE_HPP
#define PIECE_HPP
#include "raylib.h"

class Piece
{
  public:
    Piece();
  private:
    Color colorPiece;
};


struct Cell
{
  Color colorOfCell;
  int xOrigin;
  int yOrigin;
  int cellSize;
  Piece *pieceContent = 0;
};
typedef struct Cell Cell ;


#endif // PIECE_HPP
