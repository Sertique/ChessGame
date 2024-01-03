#ifndef DEF_ECHIQUIER
#define DEF_ECHIQUIER

#include <raylib.h>
#include "Piece.hpp"
#include <vector>

// class Piece;

class Echiquier {

  public:
    Echiquier(unsigned int windowWidth, unsigned int windowHeight);
    void drawChessboard();
    bool estPair(int x);
    static int get_cellSize();
    static Color get_Color(piece_color color);
    void pInit(piece_type pieceType, piece_color colorPiece, unsigned int positionX, unsigned int positionY); /* Name : pieceInitialization */
    void pieceMovementsWriting(Piece &piece);
    void cellSelection(int xMouse, int yMouse);
    void drawMovements();
    void pieceSelection(int xMouse, int yMouse);
    bool selectionEqualToMovement();
    void pieceDeplacement(unsigned int startCoordinateZ, unsigned int arrivalCoordinateZ);
    void addMoveToHistory(int coordinateArrivalZ, int coordinateDepartureZ, piece_type type, bool pieceEat, bool check, bool checkMat);
    void changePlayer();
    void drawHistory();
    void drawCellGrid(int x, int y, int cellWidth, int cellHeight);
    void drawTopCellHistory(bool secondColumn);
    bool IsPossibleEnPassant();
    string historyMoveString(historyCoup &movement);
    bool da();

  private:
    static int m_cellSize;
    static int m_circlePosition;
    unsigned int m_windowWidth, m_windowHeight;
    Cell chessBoard[64];
    vector<int> m_pieceMovements;
    int m_selectedCell;
    int m_previousCell;
    bool m_isSelected;
    vector<historyCoup> m_moveHistory; 
    piece_color m_colorPlayer;
    unsigned int m_startGridX, m_startGridY;
    pair<int, int> m_cellDimensions;

};


#endif // !ECHIQUIER
