#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
using namespace emscripten;
#endif

int counter = 0;
int setNumiro(int numero) {
  counter = numero;
  return numero;
}

#define PARTICLES_ITERATION(i)                                                 \
  int i = 0;                                                                   \
  i < particles_quantity;                                                      \
  i++

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(my_module) { function("setNumiro", &setNumiro); }
#endif
// 800, 450,
int width = 800;
int height = 450;

typedef struct Particle {
  Vector2 pos;
  float velocityX;
  float velocityY;
  float radius;
  Color color;
} Particle;

int particles_quantity = 8;

Particle *parts = (Particle *)malloc(particles_quantity * sizeof(Particle));

float dt = (float)1 / (float)60;

void InitParticles(Particle *particles) {
  for (PARTICLES_ITERATION(i)) {
    particles[i].pos.x = 50 + i * 90;
    particles[i].pos.y = 50;
    particles[i].radius = 40;
    particles[i].color = YELLOW;
    // particles[i].velocityX = 50 + (rand() % 10) * 10;
    // particles[i].velocityY = 150 + (rand() % 10) * 10;
    particles[i].velocityX = 50 + (rand() % 10) * counter;
    particles[i].velocityY = 150 + (rand() % 10) * counter;
  }
}

void DrawParts(Particle *particles) {
  for (PARTICLES_ITERATION(i)) {
    DrawCircleV(particles[i].pos, particles[i].radius, particles[i].color);
    DrawPixelV(particles[i].pos, RED);
  }
}

void VelocityControlParticles(Particle *particles) {
  for (PARTICLES_ITERATION(i)) {
    if (particles[i].pos.x >= (40 + i * 90) + 10) {
      particles[i].velocityX *= -1;
    }
    if (particles[i].pos.x <= (40 + i * 90) - 10) {
      particles[i].velocityX *= -1;
    }

    if (particles[i].pos.y >= 60) {
      particles[i].velocityY *= -1;
    }
    if (particles[i].pos.y <= 40) {
      particles[i].velocityY *= -1;
    }
  }
}

void MovimentParticles(Particle *particles) {
  for (PARTICLES_ITERATION(i)) {
    particles[i].pos.y = particles[i].pos.y + particles[i].velocityY * dt;
    particles[i].pos.x = particles[i].pos.x + particles[i].velocityX * dt;
  }
}
void UpdateVelocity(Particle *particles) {
  for (PARTICLES_ITERATION(i)) {
    particles[i].velocityX = 50 + (rand() % 10) * counter;
    particles[i].velocityY = 150 + (rand() % 10) * counter;
  }
}

void UpdateDrawFrame() {
  printf("%d\n", counter);
  BeginDrawing();
  ClearBackground(SKYBLUE);
  UpdateVelocity(parts);
  VelocityControlParticles(parts);
  MovimentParticles(parts);
  DrawParts(parts);
  DrawFPS(0, 0);
  EndDrawing();
}

int main() {

  srand(time(NULL));
  InitParticles(parts);
  InitWindow(800, 450, "Particles Simulator - Raylib");
  SetTargetFPS(100);

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
  while (!WindowShouldClose()) {
    UpdateDrawFrame();
  }
#endif

  CloseWindow();
  return 0;
}
