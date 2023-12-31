#include "Piece.hpp"
#include "Echiquier.hpp"
#include <raylib.h>

/* Static functions */
unsigned int Piece::get_positionZ(unsigned int X, unsigned int Y)
{
  return Y * 8 + X;
}

pair<unsigned int, unsigned int> Piece::get_positionXY(unsigned int Z)
{
  unsigned int X = Z % 8;
  unsigned int Y = (Z - X) / 8;
  return pair<unsigned int, unsigned int> (X, Y);
}


/* Non static functions */
Piece::Piece(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : m_colorPiece(colorPiece), m_positionZ(get_positionZ(X, Y))
{
  /* Movements of Knight */
  m_pieceMovements[0] = pair<int, int> (1, 2);
  m_pieceMovements[1] = pair<int, int> (2, 1);
  m_pieceMovements[2] = pair<int, int> (2, -1);
  m_pieceMovements[3] = pair<int, int> (1, -2);
  m_pieceMovements[4] = pair<int, int> (-1, -2);
  m_pieceMovements[5] = pair<int, int> (-2, -1);
  m_pieceMovements[6] = pair<int, int> (-2, 1);
  m_pieceMovements[7] = pair<int, int> (-1, 2);
  /* Movements of rook */
  m_pieceMovements[8] = pair<int, int> (0, 1);
  m_pieceMovements[9] = pair<int, int> (1, 0);
  m_pieceMovements[10] = pair<int, int> (0, -1);
  m_pieceMovements[11] = pair<int, int> (-1, 0);
  /* Movements of bishop */
  m_pieceMovements[12] = pair<int, int> (1, 1);
  m_pieceMovements[13] = pair<int, int> (1, -1);
  m_pieceMovements[14] = pair<int, int> (-1, -1);
  m_pieceMovements[15] = pair<int, int> (-1, 1);

  Image img = LoadImage(pathToImageFile.c_str());
  ImageResize(&img, Echiquier::get_cellSize(), Echiquier::get_cellSize());
  m_pieceImage = LoadTextureFromImage(img);
  UnloadImage(img);
}
Piece::~Piece() {};

Texture2D Piece::get_pieceTexture() { return m_pieceImage; }
int Piece::get_position() { return m_positionZ; }
unsigned int Piece::get_distance() { return m_distancePossible; }
piece_color Piece::get_color() { return m_colorPiece; }

void Piece::newPositionZ(unsigned int newPosZ)
{
  m_positionZ = newPosZ;
}


/* King */
King::King(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 8 ; i++)
  {
    m_kingMovements[i] = Piece::m_pieceMovements[i+8];
  }
  m_distancePossible = 1;
}
King::~King() {}

int King::get_nbPieceMovements() { return 8; }
pair<int, int> King::get_pieceMovements(int x) { return m_kingMovements[x]; }


/* Queen */
Queen::Queen(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 8 ; i++)
  {
    m_queenMovements[i] = Piece::m_pieceMovements[i+8];
  }
  m_distancePossible = 7;
}
Queen::~Queen() {}

int Queen::get_nbPieceMovements() { return 8; }
pair<int, int> Queen::get_pieceMovements(int x) { return m_queenMovements[x]; }

/* Rook */
Rook::Rook(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 4 ; i++)
  {
    m_rookMovements[i] = Piece::m_pieceMovements[i+8];
  }
  m_distancePossible = 7;
}
Rook::~Rook() {}

int Rook::get_nbPieceMovements() { return 4; }
pair<int, int> Rook::get_pieceMovements(int x) { return m_rookMovements[x]; }

/* Bishop */
Bishop::Bishop(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 4 ; i++)
  {
    m_bishopMovements[i] = Piece::m_pieceMovements[i+12];
  }
  m_distancePossible = 7;
}
Bishop::~Bishop() {}

int Bishop::get_nbPieceMovements() { return 4; }
pair<int, int> Bishop::get_pieceMovements(int x) { return m_bishopMovements[x]; }

/* Knight */
Knight::Knight(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 8 ; i++)
  {
    m_knightMovements[i] = m_pieceMovements[i];
  }
  m_distancePossible = 1;
}
Knight::~Knight() {}

int Knight::get_nbPieceMovements() { return 8; }
pair<int, int> Knight::get_pieceMovements(int x) { return m_knightMovements[x]; }

/* Pawn */
WhitePawn::WhitePawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  m_whitePawnMovements[0] = m_pieceMovements[8];
  m_whitePawnMovements[1] = pair<int, int> (0, 2);
  m_whitePawnMovements[2] = m_pieceMovements[12];
  m_whitePawnMovements[3] = m_pieceMovements[15];
  m_distancePossible = 1;
}
WhitePawn::~WhitePawn() {}

int WhitePawn::get_nbPieceMovements() { return 4; }
pair<int, int> WhitePawn::get_pieceMovements(int x) { return m_whitePawnMovements[x]; }

BlackPawn::BlackPawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  m_blackPawnMovements[0] = m_pieceMovements[10];
  m_blackPawnMovements[1] = pair<int, int> (0, -2);
  m_blackPawnMovements[2] = m_pieceMovements[13];
  m_blackPawnMovements[3] = m_pieceMovements[14];
  m_distancePossible = 1;
}
BlackPawn::~BlackPawn() {}

int BlackPawn::get_nbPieceMovements() { return 4; }
pair<int, int> BlackPawn::get_pieceMovements(int x) { return m_blackPawnMovements[x]; }
