#include "raylib.h"
#include "raymath.h"
#include "./headers/render.h"
#include "./headers/rotate3d.h"
#include <math.h>
#include <array>


void return_to_desktop() {
    CloseWindow();
    exit(0);
}


int main() {

    Vector2 rect = {32,32};

    //test cube
    cube p1, p2;

    Camera3D camera = { 0 };
    camera.position = (Vector3){0.0f, 25.0f, 0.0f };     // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Vector3 offset1 = {0,0,0};
    Vector3 offset2 = {5,5,0};

    //list of maps
    


    //new window
    InitWindow(512, 512, "Composite Render");
        SetTargetFPS(16);

        SetCameraMode(camera, CAMERA_FREE);

        Texture2D grass1 = LoadTexture("./tiles/cobble1.png");

    while (!WindowShouldClose()) {
        
        BeginDrawing();

        ClearBackground(WHITE);

        for (int i = 0; i < 512; i += rect.x) {
            for (int j = 0; j < 512; j += rect.y) {
                DrawTexture(grass1, i, j, WHITE);
            }
        }

        UpdateCamera(&camera);

        //rotation test
        rotate(PI/32, 1, p1.p);
        rotate(PI/32, 2, p2.p);
        //rotate(PI/64, 2, p1.p);
        //rotate(PI/48, 3, p1.p);



        BeginMode3D(camera);

        //cube_render(p1.p, offset1);
        //cube_render(p2.p, offset2);

        cube_render(p1, offset1);
        cube_render(p2, offset2);

        DrawGrid(10, 1.0f);

        EndMode3D();

        EndDrawing();
        
    }

    CloseWindow();

    return 0;
}

