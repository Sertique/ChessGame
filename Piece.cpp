#include "Piece.hpp"

Piece::Piece() {
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
};

/* King */
King::King(Color colorPiece) : Piece() 
{};
