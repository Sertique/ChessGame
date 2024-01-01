#include <raylib.h>
#include "Echiquier.hpp"

using namespace std;

int main()
{

  const int windowWidth(1600), windowHeigth(900); /* Format : 16:9 */
  int xMouse, yMouse;
  
  InitWindow(windowWidth, windowHeigth, "Chessgame");
  SetTargetFPS(30);

  Echiquier chessBoard(windowWidth, windowHeigth);

  while (!WindowShouldClose())
  {
    BeginDrawing();

    chessBoard.drawChessboard();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      xMouse = GetMouseX();
      yMouse = GetMouseY();
      chessBoard.pieceSelection(xMouse, yMouse);
    }

    chessBoard.drawMovements();
    chessBoard.drawHistory();
    
    ClearBackground(LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();

  return 0;
}
