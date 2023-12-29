#include "Echiquier.hpp"
#include <raylib.h>
#include "Piece.hpp"

int Echiquier::m_cellSize(100); /* */ int Echiquier::get_cellSize() { return m_cellSize; }
Color Echiquier::get_Color(piece_color color) {
  if (color == White)
  {
    return WHITE;
  } else {
    return BLACK;
  }
}

Echiquier::Echiquier()
{
  pieceInitialization(king, White, 4, 0);

// Cells color initialization
  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      if ((i + j) % 2 == 0)
      { chessBoard[i * 8 + j].colorOfCell = Black;
      } else {
        chessBoard[i * 8 + j].colorOfCell = White;
      }
    }
  }

  /* Initialization of cells origin */
  int x(m_cellSize), y(m_cellSize * 8); // I begin to the first cell who are at the bottom of the window.
  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      chessBoard[Piece::get_positionZ(j, i)].xOrigin = x;
      chessBoard[Piece::get_positionZ(j, i)].yOrigin = y;
      chessBoard[Piece::get_positionZ(j, i)].cellSize = m_cellSize;
      x += 100;
    }
    x = m_cellSize;
    y -= 100;
  }
}


bool Echiquier::estPair(int x)
{
  return (x + 1) % 2;
}


void Echiquier::drawChessboard()
{
  for (int i(0) ; i < 64 ; i++)
  {
    DrawRectangle(chessBoard[i].xOrigin, chessBoard[i].yOrigin, chessBoard[i].cellSize, chessBoard[i].cellSize, Echiquier::get_Color(chessBoard[i].colorOfCell));
    DrawTexture(chessBoard[4].pieceContent->get_pieceTexture(), 500, 300, WHITE);
  }
}


void Echiquier::pieceInitialization(piece_type pieceType, piece_color colorPiece, unsigned int posX, unsigned int posY)
{
  string path;
  if (pieceType == king)
  {
    if (colorPiece == White)
    {
      path = "./chessPieceImage/wk.png";
    } else {
      path = "./chessPieceImage/bk.png";
    }
    chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new King(colorPiece, posX, posY, path.c_str());
  }
}
