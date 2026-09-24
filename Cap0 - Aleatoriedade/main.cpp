#include <random>
#include <raylib.h>

using namespace std;

const int WIDTH = 400;
const int HEIGHT = 400;

class Walker {

private:
  int x;
  int y;

public:
  Walker() {

    this->x = WIDTH / 2;
    this->y = HEIGHT / 2;
  };

  void show() { DrawPixel(this->x, this->y, BLACK); }

  void step() {

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(-1, 1);

    int xstep = distrib(gen);
    int ystep = distrib(gen);

    this->x += xstep;
    this->y += ystep;
    
    /*
     
    int choice = distrib(gen);
    switch (choice) {

    case 0:
      this->x = ;
      break;

    case 1:
      this->x--;
      break;

    case 2:
      this->y++;
      break;

    case 3:
      this->y--;
      break;
    }
    */
    
  }
};

int main() {


  Walker walker;

  InitWindow(WIDTH, HEIGHT, "Exemplo de Render Texture");

  RenderTexture2D canvas = LoadRenderTexture(WIDTH, WIDTH);


  BeginTextureMode(canvas);
  ClearBackground(WHITE);
  EndTextureMode();

  while (!WindowShouldClose()) {


    BeginTextureMode(canvas);
  
    walker.show();
    walker.step();

    EndTextureMode();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTexture(canvas.texture, 0, 0, WHITE);

    EndDrawing();
  }

  UnloadRenderTexture(canvas);

  CloseWindow();

  return 0;
}
