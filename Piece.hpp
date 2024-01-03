#ifndef PIECE_HPP
#define PIECE_HPP
#include <raylib.h>
#include <utility>
#include <string>

using namespace std;
/* To create a mother class Pawn for WhitePawn and BlackPawn */


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


struct enPassant
{
    pair<bool, bool> isPossible;
    pair<pair<int, int>, pair<int, int>> xPieceWhoIsEating;
};

class Piece
{
  public:
    Piece(piece_color colorPiece, unsigned int X, unsigned Y, string pathToImageFile);
    static unsigned int get_positionZ(unsigned int X, unsigned int Y);
    static pair<unsigned int, unsigned int> get_positionXY(unsigned int Z);
    Texture2D get_pieceTexture();
    int get_position();
    piece_type get_pieceType();
    virtual ~Piece();
    virtual int get_nbPieceMovements() = 0;
    virtual pair<int ,int> get_pieceMovements(int x) = 0;
    unsigned int get_distance();
    piece_color get_color();
    void newPositionZ(unsigned int newPosZ);
    virtual bool get_eatEnPassant();
    virtual pair<pair<int, int>, pair<int, int>> get_XYeatEnPassant();
    virtual void modifyEatEnPassant(int nothing, int nothingY, bool nothingMore);
    virtual void resetEnPassant();
  protected:
    piece_color m_colorPiece;
    pair<int, int> m_pieceMovements[16];
    Texture2D m_pieceImage;
    piece_type m_pieceType;
    unsigned int m_positionZ; /* The position in an one dimension array */
    unsigned int m_distancePossible; /* The maximal distance that the piece can to do */
};

class King : public Piece
{
  public:
    King(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~King();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
  protected:
    pair<int, int> m_kingMovements[8];
};

class Queen : public Piece
{
  public:
    Queen(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Queen();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
  protected:
    pair<int, int> m_queenMovements[8];
};

class Rook : public Piece
{
  public:
    Rook(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Rook();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
  protected:
    pair<int, int> m_rookMovements[4];
};

class Bishop : public Piece
{
  public:
    Bishop(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Bishop();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
  protected:
    pair<int, int> m_bishopMovements[4];
};

class Knight : public Piece
{
  public:
    Knight(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~Knight();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
  protected:
    pair<int, int> m_knightMovements[8];
};

class WhitePawn : public Piece
{
  public:
    WhitePawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~WhitePawn();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
    virtual bool get_eatEnPassant();
    virtual pair<pair<int, int>, pair<int, int>> get_XYeatEnPassant();
    virtual void modifyEatEnPassant(int coordinateX, int coordinateY, bool firstMove);
    virtual void resetEnPassant();
  protected:
    pair<int, int> m_whitePawnMovements[4];
    enPassant m_eatEnPassant;
};

class BlackPawn : public Piece
{
  public:
    BlackPawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile);
    ~BlackPawn();
    virtual int get_nbPieceMovements();
    virtual pair<int, int> get_pieceMovements(int x);
    virtual bool get_eatEnPassant();
    virtual pair<pair<int, int>, pair<int, int>> get_XYeatEnPassant();
    virtual void modifyEatEnPassant(int coordinateX, int coordinateY, bool firstMove);
    virtual void resetEnPassant();
  protected:
    pair<int, int> m_blackPawnMovements[4];
    enPassant m_eatEnPassant;
};


struct Cell
{
  piece_color colorOfCell;
  int xOrigin, yOrigin;
  int cellSize;
  Piece *pieceContent = 0;
};
typedef struct Cell Cell ;

struct historyCoup
{
  int xDeparture, yDeparture;
  int xArrival, yArrival;
  piece_type pieceType;
  bool pieceEating;
  bool check;
  bool checkMat;
};



#endif // PIECE_HPP
