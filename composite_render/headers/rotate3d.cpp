#include "raylib.h"
#include "raymath.h"

Vector3* rotate(float angle, int axis, Vector3 p[]) {
    //define rotation matricies
    Matrix rotx, roty, rotz;

        //define rotx
    rotx.m0 = 1; rotx.m1 = 0; rotx.m2 = 0; rotx.m3 = 0;
    rotx.m4 = 0; rotx.m5 = cos(angle); rotx.m6 = -1 * sin(angle); rotx.m7 = 0;
    rotx.m8 = 0; rotx.m9 = sin(angle); rotx.m10 = cos(angle); rotx.m11 = 0;
    rotx.m12 = 0; rotx.m13 = 0; rotx.m14 = 0; rotx.m15 = 1;

        //define roty
    roty.m0 = cos(angle); roty.m1 = 0; roty.m2 = sin(angle); roty.m3 = 0;
    roty.m4 = 0; roty.m5 = 1; roty.m6 = 0; roty.m7 = 0;
    roty.m8 = -1 * sin(angle); roty.m9 = 0; roty.m10 = cos(angle); roty.m11 = 0;
    roty.m12 = 0; roty.m13 = 0; roty.m14 = 0; roty.m15 = 1;

        //define rotz
    rotz.m0 = cos(angle); rotz.m1 = -1 * sin(angle); rotz.m2 = 0; rotz.m3 = 0;
    rotz.m4 = sin(angle); rotz.m5 = cos(angle); rotz.m6 = 0; rotz.m7 = 0;
    rotz.m8 = 0; rotz.m9 = 0; rotz.m10 = 1; rotz.m11 = 0;
    rotz.m12 = 0; rotz.m13 = 0; rotz.m14 = 0; rotz.m15 = 1;


    switch (axis) {
        case 1:
            for (int i = 0; i < 8; i++) {
                p[i] = Vector3Transform(p[i], rotx);
            }
        break;
        
        case 2:
            for (int i = 0; i < 8; i++) {
                p[i] = Vector3Transform(p[i], roty);
            }
        break;

        case 3:
            for (int i = 0; i < 8; i++) {
                p[i] = Vector3Transform(p[i], rotz);
            }
        break;
    }

    Vector3* p0 = p;

    return p0;
}