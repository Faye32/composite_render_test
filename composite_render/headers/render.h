//struct cube;
#include "raylib.h"
#ifndef CUBE_H
#define CUBE_H

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

#endif

void cube_render(cube, Vector3);
void render_tilemap();