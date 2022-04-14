#include "raylib.h"

void render(Texture2D tile) {
    for(int i = 0; i < 512; i+=32) {
        for(int j = 0; j < 512; j+=32) {
            DrawTexture(tile, i, j, WHITE);
        }
    }
}

int main() {

    
    InitWindow(512, 512, "render test");

    Texture2D tile = LoadTexture("./tiles/cobble3.png");


    SetTargetFPS(16);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);


        //DrawRectangle(16,16,32,32,WHITE);
        render(tile);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}