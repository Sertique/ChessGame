/* À transformer en "librairie" pour pouvoir transformer chaque lettre en chiffre */

#include "utilitaires.hpp"

using namespace std;


string lettre(int nb)
{
  switch (nb)
  {
    case 0:
      return "A";
      break;
    case 1:
      return "B";
      break;
    case 2:
      return "C";
      break;
    case 3:
      return "D";
      break;
    case 4:
      return "E";
      break;
    case 5:
      return "F";
      break;
    case 6:
      return "G";
      break;
    case 7:
      return "H";
      break;
    case 8:
      return "I";
      break;
    case 9:
      return "J";
      break;
    case 10:
      return "K";
      break;
    case 11:
      return "L";
      break;
    case 12:
      return "M";
      break;
    case 13:
      return "N";
      break;
    case 14:
      return "O";
      break;
    case 15:
      return "P";
      break;
    case 16:
      return "Q";
      break;
    case 17:
      return "R";
      break;
    case 18:
      return "S";
      break;
    case 19:
      return "T";
      break;
    case 20:
      return "U";
      break;
    case 21:
      return "V";
      break;
    case 22:
      return "W";
      break;
    case 23:
      return "X";
      break;
    case 24:
      return "Y";
      break;
    case 25:
      return "Z";
      break;
    default:
      return "ERROR";
  }
}

unsigned int coordinateOneTroughTwoDimension(int arrayNumberColumns, unsigned int currentPositionRow, unsigned int currentPositionColumn)
{
  return arrayNumberColumns * currentPositionRow + currentPositionColumn;
}

