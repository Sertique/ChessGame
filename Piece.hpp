#ifndef PIECE_HPP
#define PIECE_HPP
#include <raylib.h>
#include <utility>

using namespace std;

class Piece
{
  public:
    Piece();
  protected:
    Color m_colorPiece;
    pair<int, int> m_pieceMoove[16];
    Image m_pieceImage;
};

class King : public Piece
{
  public:
    King(Color colorPiece);
  private:
    // moove limit
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
