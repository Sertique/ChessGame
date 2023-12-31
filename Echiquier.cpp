#include "Echiquier.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

int Echiquier::m_cellSize(100); /* */ int Echiquier::get_cellSize() { return m_cellSize; } /* */ int Echiquier::m_circlePosition(m_cellSize / 2);
/* À modifier pour qu'elles ne soient plus static */

Color Echiquier::get_Color(piece_color color) { /* Color for the chessboard image */
  if (color == White) { return GRAY;
  } else { return BROWN; }
}

// Color Echiquier::get_inverseColor(piece_color color) {
//   if (color == W hite) { return BLACK;
//   } else { return WHITE; }
// }

Echiquier::Echiquier()
{
/* Cells initialization */
  int x(m_cellSize), y(m_cellSize * 8); // I begin to the first cell who are at the bottom of the window.
  for (int i(0) ; i < 8 ; i++)
  {
    for (int j(0) ; j < 8 ; j++)
    {
      if ((i + j) % 2 == 0)
      { chessBoard[i * 8 + j].colorOfCell = Black;
      } else {
        chessBoard[i * 8 + j].colorOfCell = White;
      }
      chessBoard[Piece::get_positionZ(j, i)].xOrigin = x; /* Origins initialization */
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
  pInit(pawn, White, 0, 1);
  pInit(pawn, White, 1, 1);
  pInit(pawn, White, 2, 1);
  pInit(pawn, White, 3, 1);
  pInit(pawn, White, 4, 1);
  pInit(pawn, White, 5, 1);
  pInit(pawn, White, 6, 1);
  pInit(pawn, White, 7, 1);

  pInit(king, Black, 4, 7);
  pInit(queen, Black, 3, 7);
  pInit(bishop, Black, 2, 7);
  pInit(bishop, Black, 5, 7);
  pInit(knight, Black, 1, 7);
  pInit(knight, Black, 6, 7);
  pInit(rook, Black, 0, 7);
  pInit(rook, Black, 7, 7);
  pInit(pawn, Black, 0, 6);
  pInit(pawn, Black, 1, 6);
  pInit(pawn, Black, 2, 6);
  pInit(pawn, Black, 3, 6);
  pInit(pawn, Black, 4, 6);
  pInit(pawn, Black, 5, 6);
  pInit(pawn, Black, 6, 6);
  pInit(pawn, Black, 7, 6);

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

void Echiquier::pieceMovementsWriting(Piece &piece)
{
  pair<int, int> p, currentPos;
  int arrivalCell, xArrival, yArrival; 
  const int nbMovements(piece.get_nbPieceMovements());
  bool banMovements[nbMovements];

  for (int i(0) ; i < nbMovements ; i++)
  {
    banMovements[i] = false;
  }

  m_pieceMovements.clear();
  cout << "New piece :" << endl;

  for (int i(1) ; i <= piece.get_distance() ; i++) /* Répète suivant la distance possible */
  {
    for (int j(0) ; j < nbMovements ; j++)
    {
      if (!banMovements[j]) /* Bans directions who are occupied */
      {
        p = piece.get_pieceMovements(j);
        currentPos = Piece::get_positionXY(piece.get_position());
        xArrival = currentPos.first + p.first * i;
        yArrival = currentPos.second + p.second * i;

        if (xArrival >= 0 && xArrival < 8 && yArrival >= 0 && yArrival < 8)
        {
          arrivalCell = Piece::get_positionZ(xArrival, yArrival);

          if (chessBoard[arrivalCell].pieceContent == nullptr)
          {
            m_pieceMovements.push_back(arrivalCell);
          } else if (chessBoard[arrivalCell].pieceContent->get_color() != piece.get_color())
          {
            m_pieceMovements.push_back(arrivalCell);
            banMovements[j] = true;
          } else {
            banMovements[j] = true;
          }
        }
      }
    }
  }
}

void Echiquier::cellSelection(int xMouse, int yMouse)
{
  xMouse = xMouse - (xMouse % 100);
  yMouse = yMouse - (yMouse % 100);
  m_isSelected = false;
  m_previousCell = m_selectedCell;

  for (int i(0) ; i < 64 ; i++ )
  {
    if (xMouse == chessBoard[i].xOrigin && yMouse == chessBoard[i].yOrigin)
    {
      m_selectedCell = i;
      m_isSelected = true;
    }
  }

  if (!m_isSelected)
  { 
    m_selectedCell = -1;
    cout << "No cell selected." << endl; 
  }
}


void Echiquier::drawMovements()
{
  vector<int>::iterator it;
  for (it = m_pieceMovements.begin() ; it != m_pieceMovements.end() ; it++)
  {
    DrawCircle(chessBoard[*it].xOrigin + m_circlePosition, chessBoard[*it].yOrigin + m_circlePosition, 10, BLUE);
  }
}

bool Echiquier::selectionEqualToMovement()
{
  bool t(false);
  vector<int>::iterator it;
  for (it = m_pieceMovements.begin() ; it != m_pieceMovements.end() ; it++)
  {
    if (m_selectedCell == *it)
    {
      t =  true;
    }
  }
  return t;
}

void Echiquier::pieceSelection(int xMouse, int yMouse)
{
  cellSelection(xMouse, yMouse);
  if (m_isSelected)
  {
    Piece *selection(chessBoard[m_selectedCell].pieceContent);
    if (selectionEqualToMovement())
    {
      pieceDeplacement(m_previousCell, m_selectedCell);
      m_pieceMovements.clear();
    } else if (selection != nullptr)
    {
      pieceMovementsWriting(*selection);
    } else {
      m_pieceMovements.clear();
    }
  }
}

void Echiquier::pieceDeplacement(unsigned int startCoordinateZ, unsigned int arrivalCoordinateZ)
{
  if (chessBoard[arrivalCoordinateZ].pieceContent == nullptr)
  {
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);
  } else if (chessBoard[arrivalCoordinateZ].pieceContent->get_color() != chessBoard[startCoordinateZ].pieceContent->get_color())
  {
    delete chessBoard[arrivalCoordinateZ].pieceContent;
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);
  } else {
    cout << "Impossible movement" << endl;
  }
}
