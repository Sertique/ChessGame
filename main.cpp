#include "raylib.h"
#include "Echiquier.hpp"

int main()
{
  Echiquier chessBoard;

  const int windowWidth(1600); // Format : 16:9
  const int windowHeigth(900);
  
  InitWindow(windowWidth, windowHeigth, "Chessgame");
  SetTargetFPS(30);

  // Texture2D array[32];
  //
  // Image wp = LoadImage("/test");
  // ImageResize(Image *image, int newWidth, int newHeight)
  // array[0] = LoadTextureFromImage(wp);


  while (!WindowShouldClose())
  {
    BeginDrawing();

    ClearBackground(LIGHTGRAY);
    //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    chessBoard.drawChessboard();
    EndDrawing();
  }
  CloseWindow();

  return 0;
}
