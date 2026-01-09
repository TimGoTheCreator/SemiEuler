#include"conf.h"
#include"raylib.h"

int main() {
    InitWindow(800, 600, "SemiEuler");
    Particle earth(0, 0, 0, 0, 5.97e24);
    Particle moon(384400000, 0, 0, 1022, 7.35e22);
    SetTargetFPS(0); // run as fast as the cpu can :)

    double dt = 0.4;
    double simTime = 0.0;

    while (!WindowShouldClose()) {
        for(int i = 0; i < 10000; i++) {
            Gravity(earth, moon, dt);
            earth.x += earth.vx * dt;
            earth.y += earth.vy * dt;
            moon.x += moon.vx * dt;
            moon.y += moon.vy * dt;
            simTime += dt;
            }
        

        double scale = 1.5e6;
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle((int)(earth.x / scale) + 400, (int)(earth.y / scale) + 300, 10, BLUE);
        DrawCircle((int)(moon.x / scale) + 400, (int)(moon.y / scale) + 300, 5, GRAY);
        EndDrawing();
    }
}
