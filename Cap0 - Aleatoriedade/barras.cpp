#include <random>
#include <raylib.h>

#define COUNTS 20

using namespace std;

const int WIDTH = 400;
const int HEIGHT = 400;

int main() {

  InitWindow(WIDTH, HEIGHT, "Distribuicao de numeros aleatorios");

  SetTargetFPS(30);

  int randomCounts[COUNTS] = { 0 };

  Color colors[COUNTS] ={ 0 }; 

  for (int i = 0; i < COUNTS; i++) {
    colors[i]  = (Color){(unsigned char) GetRandomValue(10, 130), (unsigned char) GetRandomValue(80, 190), (unsigned char) GetRandomValue(100, 200),255};
  }



  while (!WindowShouldClose()) {
    
    int index = GetRandomValue(0, COUNTS);

    randomCounts[index]++;

    BeginDrawing();

      ClearBackground(RAYWHITE);

      const int w = WIDTH / COUNTS;

      for (size_t i = 0; i < COUNTS; i++) {
        DrawRectangle(i * w, HEIGHT- randomCounts[i], w-1, randomCounts[i], colors[i]);
      }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
