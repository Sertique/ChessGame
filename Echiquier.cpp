#include "Echiquier.hpp"
#include "Piece.hpp"
#include <iostream>
#include <raylib.h>
#include <string>
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

Echiquier::Echiquier(unsigned int windowWidth, unsigned int windowHeight) : m_colorPlayer(White), m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_cellDimensions(100, 24)
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

  if (piece.get_pieceType() == pawn)
  {
    int row(Piece::get_positionXY(piece.get_position()).second);
    if (piece.get_color() == White && row != 1)
    {
      banMovements[1] = true;
    } else if (piece.get_color() == Black && row != 6)
    {
      banMovements[1] = true;
    }
  }

  for (int i(1) ; i <= piece.get_distance() ; i++) /* Répète suivant la distance possible */
  {
    for (int j(0) ; j < nbMovements ; j++)
    {
      if (!banMovements[j] && piece.get_pieceType() != pawn) /* Bans directions who are occupied */
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
      } else if (!banMovements[j] && piece.get_pieceType() == pawn)
      {
        p = piece.get_pieceMovements(j);
        currentPos = Piece::get_positionXY(piece.get_position());
        xArrival = currentPos.first + p.first;
        yArrival = currentPos.second + p.second;
        if (xArrival >= 0 && xArrival < 8 && yArrival >= 0 && yArrival < 8)
        {
          arrivalCell = Piece::get_positionZ(xArrival, yArrival);
          vector<string>::iterator it(m_moveHistory.end() - 1); /* À modifier pour rendre le code propre */

          if (j < 2 && chessBoard[arrivalCell].pieceContent == nullptr)
          {
            m_pieceMovements.push_back(arrivalCell);
          } else if (j > 1 && chessBoard[arrivalCell].pieceContent != nullptr && chessBoard[arrivalCell].pieceContent->get_color() != m_colorPlayer)
          {
            m_pieceMovements.push_back(arrivalCell);
          } else if (j > 1 && chessBoard[arrivalCell].pieceContent == nullptr && IsPossibleEnPassant() /* && (char)(*it)[0] == static_cast<char>('a' + currentPos.first) */) /* La dernière condition fait crasher */
          {
            m_pieceMovements.push_back(arrivalCell);
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
  Color pointColor(BLUE);
  for (it = m_pieceMovements.begin() ; it != m_pieceMovements.end() ; it++)
  {
    if (chessBoard[*it].pieceContent != nullptr)
    {
      pointColor = RED;
    } else { pointColor = BLUE; }
    DrawCircle(chessBoard[*it].xOrigin + m_circlePosition, chessBoard[*it].yOrigin + m_circlePosition, 10, pointColor);
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
      changePlayer();
    } else if (selection != nullptr && chessBoard[m_selectedCell].pieceContent->get_color() == m_colorPlayer)
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

    addMoveToHistory(arrivalCoordinateZ, startCoordinateZ, chessBoard[arrivalCoordinateZ].pieceContent->get_pieceType(), false);

  } else if (chessBoard[arrivalCoordinateZ].pieceContent->get_color() != chessBoard[startCoordinateZ].pieceContent->get_color())
  {
    delete chessBoard[arrivalCoordinateZ].pieceContent;
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);

    addMoveToHistory(arrivalCoordinateZ, startCoordinateZ, chessBoard[arrivalCoordinateZ].pieceContent->get_pieceType(), true);

  } else {
    cout << "Impossible movement" << endl;
  }
}


void Echiquier::addMoveToHistory(int coordinateArrivalZ, int coordinateDepartureZ, piece_type type, bool isPieceEat)
{ /* Without : check / check mat information */
  pair<int, int> coorDep(Piece::get_positionXY(coordinateDepartureZ)), coorArr(Piece::get_positionXY(coordinateArrivalZ));
  string pieceLetter(""), markPieceEat("");
  switch (type) {
    case rook:
      pieceLetter = "R";
      break;
    case knight:
      pieceLetter = "N";
      break;
    case bishop:
      pieceLetter = "B";
      break;
    case king:
      pieceLetter = "K";
      break;
    case queen:
      pieceLetter = "Q";
      break;
    default:
      break;
  }
  if (isPieceEat)
  {
    markPieceEat = "x";
  }

  string move(pieceLetter + static_cast<char>('a' + coorDep.first) + to_string(coorDep.second + 1) + markPieceEat + static_cast<char>('a' + coorArr.first) + to_string(coorArr.second + 1));

  m_moveHistory.push_back(move);
}

void Echiquier::changePlayer()
{
  if (m_colorPlayer == White)
  {
    m_colorPlayer = Black;
  } else {
    m_colorPlayer = White;
  }
}

void Echiquier::drawHistory()
{
  int basicWidth(m_cellSize * 10), basicHeight(100);
  unsigned int numberCase(m_moveHistory.size()), i(0);
  m_startGridX = basicWidth, m_startGridY = basicHeight;
  vector<string>::iterator it(m_moveHistory.begin());
  bool secondColumn(false);

  secondColumn = m_moveHistory.size() > 66;
  drawTopCellHistory(secondColumn);

  if (m_moveHistory.size() != 0)
  {
    for (it = m_moveHistory.begin() ; it != m_moveHistory.end() ; it++)
    {
      drawCellGrid(m_startGridX, m_startGridY, m_cellDimensions.first, m_cellDimensions.second);
      DrawText(it->c_str(), m_startGridX + 2, m_startGridY + 2, m_cellDimensions.second - 4, BLACK);
      i++;

      if (i % 2 == 1)
      {
        m_startGridX += 100;
      } else {
        m_startGridX = basicWidth;
        m_startGridY += 24;
      }

      if (secondColumn && i == 66)
      {
        basicWidth += 300;
        m_startGridX = basicWidth;
        m_startGridY = basicHeight;
      }
    }
  }
}


void Echiquier::drawCellGrid(int x, int y, int cellWidth, int cellHeight)
{
  DrawLine(x, y, x + cellWidth, y, BLACK);
  DrawLine(x, y + cellHeight, x + cellWidth, y + cellHeight, BLACK);
  DrawLine(x, y, x, y + cellHeight, BLACK);
  DrawLine(x + cellWidth, y, x + cellWidth, y + cellHeight, BLACK);
}

void Echiquier::drawTopCellHistory(bool secondColumn)
{
  int gapBtw(m_cellSize * 3);
  int nbColumns(1);

  if (secondColumn) { nbColumns = 2; }

  for (int i(0) ; i < nbColumns ; i++)
  {
  drawCellGrid(m_startGridX + gapBtw * i, m_startGridY - m_cellDimensions.second, m_cellDimensions.first, m_cellDimensions.second);
  DrawText("White", m_startGridX + m_cellDimensions.first / 4 + gapBtw * i, m_startGridY - m_cellDimensions.second + 2, m_cellDimensions.second - 4, BLACK);
  drawCellGrid(m_startGridX + m_cellDimensions.first + gapBtw * i, m_startGridY - m_cellDimensions.second, m_cellDimensions.first, m_cellDimensions.second);
  DrawText("Black", m_startGridX + m_cellDimensions.first + m_cellDimensions.first / 4 + gapBtw * i, m_startGridY - m_cellDimensions.second + 2, m_cellDimensions.second - 4, BLACK);
  }

}

bool Echiquier::IsPossibleEnPassant() /* To modify */
{
  // vector<string>::iterator it(m_moveHistory.end());
  // it--;
  //
  // if (it->size() == 4 && (int)(*it)[1] == (int)(*it)[3] - 2) /* Fait crasher le jeu */
  // {
  //   return true;
  // }
  return false;
}
