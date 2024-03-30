// Sexta version del template para el Juego del Pngo Retro ---------
#include <iostream>
#include <raylib.h>

using namespace std;

// Definicion de variables y constantes para el juego -----------------
Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

// Clase Balon que se ira moviendo por el campo
class Ball {
public:
  float x, y;
  int speed_x, speed_y;
  int radius;

  void Draw() { DrawCircle(x, y, radius, Yellow); }
  void Update() {
    x += speed_x;
    y += speed_y;
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
      speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth() || x - radius <= 0) {
      speed_x *= -1;
    }
  }
};

// Clase de las paletas de jugador y sus metodos ------------------
class Paddle {
protected:
  void LimitMovement() {
    if (y <= 0) {
      y = 0;
    }
    if (y + height >= GetScreenHeight()) {
      y = GetScreenHeight() - height;
    }
  }

public:
  float x, y;
  float width, height;
  int speed;

  void Draw() {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
  }
  void Update() {
    if (IsKeyDown(KEY_UP)) {
      y = y - speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      y = y + speed;
    }
    LimitMovement();
  }
};

// Clase de las paletas de la CPU y su metodo Update ------------------
// En este caso heredamos las clases de la clase Paddle del jugador
// para dibujar y mover la barra de la CPU
class CpuPaddle : public Paddle {
public:
  void Update(int ball_y) {
    if (y + height / 2 > ball_y) {
      y = y - speed;
    }
    if (y + height / 2 <= ball_y) {
      y = y + speed;
    }
    LimitMovement();
  }
};

CpuPaddle cpu;
Ball ball;
Paddle player;

int main() {
  // Comenzamos el programa ------------------------------------------
  cout << endl;
  cout << "Starting the game ..." << endl;
  cout << endl;
  const int screen_width = 1280;
  const int screen_height = 800;
  ball.radius = 20;
  ball.x = screen_width / 2;
  ball.y = screen_height / 2;
  ball.speed_x = 7;
  ball.speed_y = 7;

  player.width = 25;
  player.height = 120;
  player.x = screen_width - player.width - 10;
  player.y = screen_height / 2 - player.height / 2;
  player.speed = 6;

  cpu.height = 120;
  cpu.width = 25;
  cpu.x = 10;
  cpu.y = screen_height / 2 - cpu.height / 2;
  cpu.speed = 6;

  InitWindow(screen_width, screen_height, "Mi Retro Pong Game!");
  SetTargetFPS(60);

  // Loop del juego -------------------------------------------------
  while (WindowShouldClose() == false) {
    BeginDrawing();
    // Updating
    ball.Update();
    player.Update();
    cpu.Update(ball.y);

    // Dibujando el NEW campo para pong
    ClearBackground(Dark_Green);
    DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
    DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    // Dibujando la pelota y las paletas
    ball.Draw();
    player.Draw();
    cpu.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
