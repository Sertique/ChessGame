#include "raylib.h"

// À ne pas lancer car fait lagguer l'ordinateur

int main()
{
  const int windowWidth(800);
  const int windowHeigth(450);

  InitWindow(windowWidth, windowHeigth, "Test Window");
  SetTargetFPS(30);

  Texture2D array[32];

  Image wp = LoadImage("/test");
  ImageResize(Image *image, int newWidth, int newHeight)
  array[0] = LoadTextureFromImage(wp);

  while (!WindowShouldClose())
  {
    BeginDrawing();

    ClearBackground(LIGHTGRAY);
    //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
  }
  CloseWindow();

  return 0;
}
