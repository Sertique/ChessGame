#ifndef DEF_ECHIQUIER
#define DEF_ECHIQUIER

#include <raylib.h>
#include "Piece.hpp"
#include <vector>

// class Piece;

class Echiquier {

  public:
    Echiquier();
    void drawChessboard();
    bool estPair(int x);
    static int get_cellSize();
    static Color get_Color(piece_color color);
    void pInit(piece_type pieceType, piece_color colorPiece, unsigned int positionX, unsigned int positionY); /* Name : pieceInitialization */
    void pieceMovementsWriting(Piece &piece);
    void cellSelection(int xMouse, int yMouse);
    void drawMovements();
    void pieceSelection(int xMouse, int yMouse);

  private:
    static int m_cellSize;
    static int m_circlePosition;
    Cell chessBoard[64];
    vector<int> m_pieceMovements;
    int m_selectedCell;
    bool m_isSelected;

};


#endif // !ECHIQUIER
