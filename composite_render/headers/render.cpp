#include "raylib.h"
#include "raymath.h"

struct cube {
    Vector3 p[8] = {
        {1, 1, 1},
         {1, 1, -1},
          {1, -1, -1},
           {1, -1, 1},

        {-1, 1, 1},
         {-1, 1, -1},
          {-1, -1, -1},
           {-1, -1, 1}

        };

    int surface[12][3] = {{0,3,2}, {1,0,2}, {4,5,7}, {6,7,5}, {4,0,5}, {1,5,0}, {7,6,3}, {2,3,6}, {1,2,5}, {6,5,2}, {0,4,3}, {7,3,4}};     //defines the points at which a triangle is drawn
    Color color[12] = {GREEN, GREEN, RED, RED, ORANGE, ORANGE, PURPLE, PURPLE, DARKBROWN, DARKBROWN, DARKBLUE, DARKBLUE};
    int lines[12][2] = {};   //defines the points that a line should be drawn between

};

/*
struct Cube_2 {// points in order of render
    Vector3 points[120] = {{-1,-1,1}, {1,-1,1}, {1,-1,-1}, {-1,-1,-1}};
    
};
*/


void cube_render(cube Cube, Vector3 offset) {
    for (int i = 0; i < 12; i++) {
        DrawTriangle3D(Vector3Add(Cube.p[Cube.surface[i][0]], offset), Vector3Add(Cube.p[Cube.surface[i][1]], offset), Vector3Add(Cube.p[Cube.surface[i][2]], offset), Cube.color[i]);
    }
}


void render_tilemap(int map[16][16], Texture2D tiles[]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            DrawTexture(tiles[map[i][j]], i, j, WHITE);
        }
    }
}