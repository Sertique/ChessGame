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
  int arrivalCellNumber, xArrival, yArrival; 
  const int nbMovements(piece.get_nbPieceMovements());
  bool banMovements[nbMovements];
  Piece *arrivalCell;

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
  piece.resetEnPassant();

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
          arrivalCellNumber = Piece::get_positionZ(xArrival, yArrival);
          arrivalCell = chessBoard[arrivalCellNumber].pieceContent;

          if (arrivalCell == nullptr)
          {
            m_pieceMovements.push_back(arrivalCellNumber);
          } else if (arrivalCell->get_color() != piece.get_color())
          {
            m_pieceMovements.push_back(arrivalCellNumber);
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
        vector<historyCoup>::iterator it(m_moveHistory.end() - 1);
        
        if (xArrival >= 0 && xArrival < 8 && yArrival >= 0 && yArrival < 8)
        {
          arrivalCellNumber = Piece::get_positionZ(xArrival, yArrival);
          arrivalCell = chessBoard[arrivalCellNumber].pieceContent;
          int less(0);
          if (piece.get_color() == White)
          {
            less = -1;
          } else {
            less = 1;
          }
          unsigned int arrivalCellLessOne = Piece::get_positionZ(xArrival, yArrival + less);
          Piece *opposingPiece(chessBoard[arrivalCellLessOne].pieceContent);

          if (j == 0 && arrivalCell == nullptr)
          {
            m_pieceMovements.push_back(arrivalCellNumber);
          } else if (j > 1 && arrivalCell != nullptr && arrivalCell->get_color() != m_colorPlayer)
          {
            m_pieceMovements.push_back(arrivalCellNumber);
          } else if (j > 1 && arrivalCell == nullptr && opposingPiece != nullptr && opposingPiece->get_pieceType() == pawn && opposingPiece->get_color() != piece.get_color()  && m_moveHistory.size() && it->pieceType == pawn && it->xArrival == xArrival)
          {
            m_pieceMovements.push_back(arrivalCellNumber);
            piece.modifyEatEnPassant(xArrival, yArrival, j == 2); 
            cout << xArrival << " : " << yArrival << endl;
          } else if (j == 1 && arrivalCell == nullptr && chessBoard[Piece::get_positionZ(xArrival, currentPos.second + piece.get_pieceMovements(0).second)].pieceContent == nullptr)
          {
            m_pieceMovements.push_back(arrivalCellNumber);
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
  Piece *arrivalCell(chessBoard[arrivalCoordinateZ].pieceContent);
  Piece *departureCell(chessBoard[startCoordinateZ].pieceContent);
  pair<pair<int, int>, pair<int, int>> cellEnPassant(departureCell->get_XYeatEnPassant());
  int xArrival(Piece::get_positionXY(arrivalCoordinateZ).first);

  if (arrivalCell == nullptr && departureCell->get_pieceType() != pawn)
  {
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);

    addMoveToHistory(arrivalCoordinateZ, startCoordinateZ, chessBoard[arrivalCoordinateZ].pieceContent->get_pieceType(), false, false, false); /* Changes that */

  } else if (chessBoard[arrivalCoordinateZ].pieceContent != nullptr && chessBoard[arrivalCoordinateZ].pieceContent->get_color() != chessBoard[startCoordinateZ].pieceContent->get_color())
  {
    delete chessBoard[arrivalCoordinateZ].pieceContent;
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);

    addMoveToHistory(arrivalCoordinateZ, startCoordinateZ, chessBoard[arrivalCoordinateZ].pieceContent->get_pieceType(), true, false, false);

  } else if (chessBoard[startCoordinateZ].pieceContent->get_pieceType() == pawn && chessBoard[startCoordinateZ].pieceContent->get_eatEnPassant() && (cellEnPassant.first.first == xArrival || cellEnPassant.second.first == xArrival) ) {
  
    chessBoard[arrivalCoordinateZ - 8].pieceContent = nullptr; /* The piece doesn't want to be deleted */
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);

    addMoveToHistory(arrivalCoordinateZ, startCoordinateZ, pawn, true, false, false);

  } else if (chessBoard[arrivalCoordinateZ].pieceContent == nullptr && chessBoard[startCoordinateZ].pieceContent->get_pieceType() == pawn)
  {
    chessBoard[arrivalCoordinateZ].pieceContent = chessBoard[startCoordinateZ].pieceContent;
    chessBoard[startCoordinateZ].pieceContent = nullptr;
    chessBoard[arrivalCoordinateZ].pieceContent->newPositionZ(arrivalCoordinateZ);

    addMoveToHistory(arrivalCoordinateZ, startCoordinateZ, pawn, false, false, false);

  }
  else {
    cout << "Impossible movement" << endl;
  }
}


void Echiquier::addMoveToHistory(int coordinateArrivalZ, int coordinateDepartureZ, piece_type type, bool isPieceEat, bool check, bool checkMat)
{
  pair<int, int> coorDep(Piece::get_positionXY(coordinateDepartureZ)), coorArr(Piece::get_positionXY(coordinateArrivalZ));
  
  historyCoup move;
  move.xDeparture = coorDep.first;
  move.yDeparture = coorDep.second;
  move.xArrival = coorArr.first;
  move.yArrival = coorArr.second;
  move.pieceType = type;
  move.pieceEating = isPieceEat;
  move.check = check;
  move.checkMat = checkMat;

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
  vector<historyCoup>::iterator it(m_moveHistory.begin());
  bool secondColumn(false);

  secondColumn = m_moveHistory.size() > 66;
  drawTopCellHistory(secondColumn);

  if (m_moveHistory.size() != 0)
  {
    for (it = m_moveHistory.begin() ; it != m_moveHistory.end() ; it++)
    {
      drawCellGrid(m_startGridX, m_startGridY, m_cellDimensions.first, m_cellDimensions.second);
      DrawText(historyMoveString(*it).c_str(), m_startGridX + 2, m_startGridY + 2, m_cellDimensions.second - 4, BLACK);
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

string Echiquier::historyMoveString(historyCoup &movement)
{
  string pieceLetter(""), markPieceEat(""), markCheckOrMat("");
  string coorDep(static_cast<char>('a' + movement.xDeparture) + to_string(movement.yDeparture + 1));
  string coorArr(static_cast<char>('a' + movement.xArrival) + to_string(movement.yArrival + 1));


  switch (movement.pieceType) {
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

  if (movement.pieceEating)
  {
    markPieceEat = "x";
  }

  if (movement.check)
  {
    markCheckOrMat = "+";
  } else if (movement.checkMat)
  {
    markCheckOrMat = "#";
  }

  return pieceLetter + coorDep + markPieceEat + coorArr + markCheckOrMat;
}

bool Echiquier::da() /* To verify and to test */
{
  cout << "da" << endl;
  return true;
}
