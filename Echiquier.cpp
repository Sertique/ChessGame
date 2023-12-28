#include "Echiquier.hpp"
#include <raylib.h>
// #include <string>
#include <iostream>

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

// Initialization of cells origin
  int x(m_cellSize);
  int y(m_cellSize);
  for (int i(8) ; i > 0 ; i--)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      chessBoard[i * 8 - j].xOrigin = x;
      chessBoard[i * 8 - j].yOrigin = y;
      chessBoard[i * 8 - j].cellSize = m_cellSize; // Allow to have a large side at the right + one side at the top
      x += 100;
      std::cout << i << " : " << j << " : " << i * 8 - j << " = " << chessBoard[i*8-j].xOrigin << " : " << chessBoard[i*8+j].yOrigin << std::endl;
    }
    x = 100;
    y += 100;
  }
}


bool Echiquier::estPair(int x)
{
  return (x + 1) % 2;
}


void Echiquier::drawChessboard()
{
  //std::string j = "0a1a2a3a4a5a6a7a8a9a0b1b2b3b4B5B6B7B8B9B0C1C2C3C4C5C6C7C8C9C0D1D2D3D4D5D6D7D8D9D0E1E2E3E4E5E6E7E8E9E0F1F2F3F4F5F6F7F8F9F";
  for (int i(0) ; i < 64 ; i++)
  {
    // g = (j[i * 2] + j[i * 2 +1]);
    // t = g;
    DrawRectangle(chessBoard[i].xOrigin, chessBoard[i].yOrigin, chessBoard[i].cellSize, chessBoard[i].cellSize, chessBoard[i].colorOfCell);
    //DrawText(, chessBoard[i].xOrigin + 20, chessBoard[i].yOrigin + 20, 12, BLUE);
  }
}
