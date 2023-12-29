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

Texture2D Piece::get_pieceTexture()
{
  return m_pieceImage;
}

/* King */
King::King(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 8 ; i++)
  {
    m_kingMovements[i] = Piece::m_pieceMovements[i+8];
  }
}

King::~King() {}


/* Queen */
Queen::Queen(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 8 ; i++)
  {
    m_queenMovements[i] = Piece::m_pieceMovements[i+8];
  }
}
Queen::~Queen() {}

/* Rook */
Rook::Rook(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 4 ; i++)
  {
    m_rookMovements[i] = Piece::m_pieceMovements[i+8];
  }
}
Rook::~Rook() {}

/* Bishop */
Bishop::Bishop(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 4 ; i++)
  {
    m_bishopMovements[i] = Piece::m_pieceMovements[i+12];
  }
}
Bishop::~Bishop() {}

/* Knight */
Knight::Knight(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  for (int i(0) ; i < 8 ; i++)
  {
    m_knightMovements[i] = m_pieceMovements[i];
  }
}
Knight::~Knight() {}

/* Pawn */
WhitePawn::WhitePawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  m_whitePawnMovements[0] = m_pieceMovements[8];
  m_whitePawnMovements[1] = pair<int, int> (0, 2);
  m_whitePawnMovements[2] = m_pieceMovements[12];
  m_whitePawnMovements[3] = m_pieceMovements[15];
}
WhitePawn::~WhitePawn() {}

BlackPawn::BlackPawn(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile)
{
  m_blackPawnMovements[0] = m_pieceMovements[10];
  m_blackPawnMovements[1] = pair<int, int> (0, -2);
  m_blackPawnMovements[2] = m_pieceMovements[13];
  m_blackPawnMovements[3] = m_pieceMovements[14];
}
BlackPawn::~BlackPawn() {}
