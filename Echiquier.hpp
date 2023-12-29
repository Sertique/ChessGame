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
    static int get_cellSize();
    static Color get_Color(piece_color color);
    void pieceInitialization(piece_type pieceType, piece_color colorPiece, unsigned int positionX, unsigned int positionY);

  private:
    static int m_cellSize;
    Cell chessBoard[64];
    Texture2D m_chessBoardTexture[64]; // To be deleted



};


#endif // !ECHIQUIER
