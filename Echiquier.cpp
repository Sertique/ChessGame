#include "Echiquier.hpp"
#include <raylib.h>
#include "Piece.hpp"
#include <iostream>
#include <vector>

int Echiquier::m_cellSize(100); /* */ int Echiquier::get_cellSize() { return m_cellSize; }

Color Echiquier::get_Color(piece_color color) {
  if (color == White) { return WHITE;
  } else { return BLACK; }
}

// Color Echiquier::get_inverseColor(piece_color color) {
//   if (color == W hite) { return BLACK;
//   } else { return WHITE; }
// }

Echiquier::Echiquier()
{
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
      chessBoard[Piece::get_positionZ(j, i)].pieceContent = nullptr;
      x += 100;
    }
    x = m_cellSize;
    y -= 100;
  }
/* Piece initialization  / je garde la position de la ligne (Y) pour permettre les promotions */
  pInit(king, White, 4, 0);
  pInit(queen, White, 3, 0);
  pInit(bishop, White, 2, 0);
  pInit(bishop, White, 5, 0);
  pInit(knight, White, 1, 0);
  pInit(knight, White, 6, 0);
  pInit(rook, White, 0, 0);
  pInit(rook, White, 7, 0);



  pInit(king, Black, 4, 7);
  pInit(queen, Black, 3, 7);
  pInit(bishop, Black, 2, 7);
  pInit(bishop, Black, 5, 7);
  pInit(knight, Black, 1, 7);
  pInit(knight, Black, 6, 7);
  pInit(rook, Black, 0, 7);
  pInit(rook, Black, 7, 7);

}


bool Echiquier::estPair(int x)
{
  return (x + 1) % 2;
}


void Echiquier::drawChessboard()
{
  vector<int> coordinatesPieceToDraw;
  vector<int>::iterator it;

  for (int i(0) ; i < 64 ; i++)
  {
    DrawRectangle(chessBoard[i].xOrigin, chessBoard[i].yOrigin, chessBoard[i].cellSize, chessBoard[i].cellSize, Echiquier::get_Color(chessBoard[i].colorOfCell));
    if (chessBoard[i].pieceContent != nullptr)
    {
      coordinatesPieceToDraw.push_back(i);
    }
  }

  for (it = coordinatesPieceToDraw.begin() ; it != coordinatesPieceToDraw.end() ; it++)
  {
    DrawTexture(chessBoard[*it].pieceContent->get_pieceTexture(), chessBoard[*it].xOrigin, chessBoard[*it].yOrigin, WHITE);
  }
  
}


void Echiquier::pInit(piece_type pieceType, piece_color colorPiece, unsigned int posX, unsigned int posY)
{
  string path;
  if (pieceType == king) /* KING */ {
    if (colorPiece == White) {
      path = "./chessPieceImage/wk.png";
    } else {
      path = "./chessPieceImage/bk.png";
    }
    chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new King(colorPiece, posX, posY, path);
  } else if (pieceType == queen) /* QUEEN */ {
    if (colorPiece == White) {
      path = "./chessPieceImage/wq.png";
    } else {
      path = "./chessPieceImage/bq.png";
    }
    chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new Queen(colorPiece, posX, posY, path);
  } else if (pieceType == rook) { /* ROOK */
    if (colorPiece == White) {
      path = "./chessPieceImage/wr.png";
    } else {
      path = "./chessPieceImage/br.png";
    }
    chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new Rook(colorPiece, posX, posY, path);
  } else if (pieceType == bishop) { /* BISHOP */
    if (colorPiece == White) {
        path = "./chessPieceImage/wb.png";
    } else {
      path = "./chessPieceImage/bb.png";
    }
    chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new Bishop(colorPiece, posX, posY, path);
    } else if (pieceType == knight) { /* KNIGHT */
      if (colorPiece == White) {
        path = "./chessPieceImage/wn.png";
      } else {
        path = "./chessPieceImage/bn.png";
      }
    chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new Knight(colorPiece, posX, posY, path);
    } else if (pieceType == pawn) { /* PAWN */
      if (colorPiece == White) {
        path = "./chessPieceImage/wp.png";
        chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new WhitePawn(colorPiece, posX, posY, path);
      } else {
        path = "./chessPieceImage/bp.png";
        chessBoard[Piece::get_positionZ(posX, posY)].pieceContent = new BlackPawn(colorPiece, posX, posY, path);
      }
   } else {
    std::cout << "Pas de pièce initialisée" << std::endl;
  }
}


