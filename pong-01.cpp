// Primera y segunda version del template para el Juego del Pngo Retro ---------
#include <iostream>
#include <raylib.h>

using namespace std;

// Definicion de variables y constantes para el juego -----------------
Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int main() {
  // Comenzamos el programa ------------------------------------------
  cout << endl;
  cout << "Starting the game ..." << endl;
  cout << endl;
  const int screen_width = 1280;
  const int screen_height = 800;

  InitWindow(screen_width, screen_height, "Mi Retro Pong Game!");
  SetTargetFPS(60);

  // Loop del juego -------------------------------------------------
  while (WindowShouldClose() == false) {
    BeginDrawing();
    // Dibujando el NEW campo para pong
    ClearBackground(Dark_Green);
    DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
    DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    // Dibujando la pelota
    DrawCircle(screen_width / 2, screen_height / 2, 20, WHITE);
    DrawRectangle(10, screen_height / 2 - 60, 25, 120, WHITE);
    DrawRectangle(screen_width - 35, screen_height / 2 - 60, 25, 120, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
