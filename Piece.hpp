#ifndef PIECE_HPP
#define PIECE_HPP
#include <raylib.h>
#include <utility>
#include <string>

using namespace std;


enum piece_type
{
  rook,
  knight,
  bishop,
  king,
  queen,
  pawn,
  empty
};
typedef enum piece_type piece_type;

enum piece_color
{
  White,
  Black
};

class Piece
{
  public:
    Piece(piece_color colorPiece, unsigned int X, unsigned Y, string pathToImageFile);
    static unsigned int get_positionZ(unsigned int X, unsigned int Y);
    static pair<unsigned int, unsigned int> get_positionXY(unsigned int Z);
    Texture2D get_pieceTexture();
  protected:
    piece_color m_colorPiece;
    pair<int, int> m_pieceMoove[16];
    Texture2D m_pieceImage;
    unsigned int m_positionZ; /* The position in an one dimension array */
};

class King : public Piece
{
  public:
    King(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
  protected:
    // Moove limite
};


struct Cell
{
  piece_color colorOfCell;
  int xOrigin;
  int yOrigin;
  int cellSize;
  Piece *pieceContent = 0;
};
typedef struct Cell Cell ;



#endif // PIECE_HPP
