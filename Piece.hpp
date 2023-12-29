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
  Empty
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
    ~Piece();
  protected:
    piece_color m_colorPiece;
    pair<int, int> m_pieceMovements[16];
    Texture2D m_pieceImage;
    unsigned int m_positionZ; /* The position in an one dimension array */
};

class King : public Piece
{
  public:
    King(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~King();
  protected:
    pair<int, int> m_kingMovements[8];
};

class Queen : public Piece
{
  public:
    Queen(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Queen();
  protected:
    pair<int, int> m_queenMovements[8];
};

class Rook : public Piece
{
  public:
    Rook(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Rook();
  protected:
    pair<int, int> m_rookMovements[4];
};

class Bishop : public Piece
{
  public:
    Bishop(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Bishop();
  protected:
    pair<int, int> m_bishopMovements[4];
};

class Knight : public Piece
{
  public:
    Knight(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Knight();
  protected:
    pair<int, int> m_knightMovements[8];
};

class WhitePawn : public Piece
{
  public:
    WhitePawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~WhitePawn();
  protected:
    pair<int, int> m_whitePawnMovements[4];
};

class BlackPawn : public Piece
{
  public:
    BlackPawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~BlackPawn();
  protected:
    pair<int, int> m_blackPawnMovements[4];
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
