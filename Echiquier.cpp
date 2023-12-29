#include "Echiquier.hpp"
#include <raylib.h>
#include "tools/utilitaires.hpp"

Echiquier::Echiquier() : m_cellSize(100)
{

// Cells color initialization
  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      if ((i + j) % 2 == 0)
      { chessBoard[i * 8 + j].colorOfCell = BLACK;
      // if (estPair(i) && estPair(j))
      // {
      //   chessBoard[i * 8 + j].colorOfCell = BLACK;
      // } else if (estPair(i) && !estPair(j))
      // {
      //   chessBoard[i * 8 + j].colorOfCell = WHITE;
      // } else if (!estPair(i) && estPair(j))
      // {
      //   chessBoard[i * 8 + j].colorOfCell = WHITE;
      // } else {
      //   chessBoard[i * 8 + j].colorOfCell = BLACK;
      // }    
      } else {
        chessBoard[i * 8 + j].colorOfCell = WHITE;
      }
    }
  }

  /* Initialization of cells origin */
  int x(m_cellSize), y(m_cellSize * 8); // I begin to the first cell who are at the bottom of the window.
  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      chessBoard[coordinateOneTroughTwoDimension(8, i, j)].xOrigin = x;
      chessBoard[coordinateOneTroughTwoDimension(8, i, j)].yOrigin = y;
      chessBoard[coordinateOneTroughTwoDimension(8, i, j)].cellSize = m_cellSize;
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
    DrawRectangle(chessBoard[i].xOrigin, chessBoard[i].yOrigin, chessBoard[i].cellSize, chessBoard[i].cellSize, chessBoard[i].colorOfCell);
  }
}
