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
  /* Moove of Knight */
  m_pieceMoove[0] = pair<int, int> (1, 2);
  m_pieceMoove[1] = pair<int, int> (2, 1);
  m_pieceMoove[2] = pair<int, int> (2, -1);
  m_pieceMoove[3] = pair<int, int> (1, -2);
  m_pieceMoove[4] = pair<int, int> (-1, -2);
  m_pieceMoove[5] = pair<int, int> (-2, -1);
  m_pieceMoove[6] = pair<int, int> (-2, 1);
  m_pieceMoove[7] = pair<int, int> (-1, 2);
  /* Moove of rock */
  m_pieceMoove[8] = pair<int, int> (0, 1);
  m_pieceMoove[9] = pair<int, int> (1, 0);
  m_pieceMoove[10] = pair<int, int> (0, -1);
  m_pieceMoove[11] = pair<int, int> (-1, 0);
  /* Moove of bishop */
  m_pieceMoove[12] = pair<int, int> (1, 1);
  m_pieceMoove[13] = pair<int, int> (1, -1);
  m_pieceMoove[14] = pair<int, int> (-1, -1);
  m_pieceMoove[15] = pair<int, int> (-1, 1);

  Image img = LoadImage(pathToImageFile.c_str());
  ImageResize(&img, Echiquier::get_cellSize(), Echiquier::get_cellSize());
  m_pieceImage = LoadTextureFromImage(img); // Plante ici
  UnloadImage(img);

};

Texture2D Piece::get_pieceTexture()
{
  return m_pieceImage;
}

/* King */
King::King(piece_color colorPiece, unsigned int X, unsigned int Y, string pathToImageFile) : Piece(colorPiece, X, Y, pathToImageFile) {};
