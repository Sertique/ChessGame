#ifndef DEF_ECHIQUIER
#define DEF_ECHIQUIER

#include "raylib.h"
#include "Piece.hpp"

// class Piece;

class Echiquier {

  public:
    Echiquier();
    void drawChessboard();
    bool estPair(int x);

  private:
    unsigned int m_cellSize;
    Cell chessBoard[64];
    Texture2D m_chessBoardTexture[64];



};


#endif // !ECHIQUIER
