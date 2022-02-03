#ifndef main_cpp
#define main_cpp

#include <math.h>
#include <tice.h>
#include <graphx.h>
#include "float2str.h"

#include "Shitty3D/Vector3D/def.h"
#include "Shitty3D/Quaternion3D/def.h"
#include "Shitty3D/Camera3D/def.h"


//Vertices make up a cube
static Vector3D vertices[8] =
{
    Vector3D(-1, -1, -1),
    Vector3D(-1, -1,  1),
    Vector3D(-1,  1, -1),
    Vector3D(-1,  1,  1),
    Vector3D( 1, -1, -1),
    Vector3D( 1, -1,  1),
    Vector3D( 1,  1, -1),
    Vector3D( 1,  1,  1)
};

static Vector3D workBuffer[8];
static int pixelBuffer[8][2];

static int edges[12][2] = 
{
    {0, 1},
    {2, 3},
    {0, 2},
    {1, 3},
    {4, 5},
    {6, 7},
    {4, 6},
    {5, 7},
    {0, 4},
    {1, 5},
    {2, 6},
    {3, 7}
};


int main(void) {
    
    
    Vector3D cameraPosition = Vector3D(-3, 0, 0);
    Quaternion3D cameraRotation = Quaternion3D(M_PI/2, Vector3D(0, 1, 0)) * Quaternion3D(-M_PI/2, Vector3D(0, 0, 1));

    Camera3D camera = Camera3D(cameraPosition, cameraRotation, 0.75);

    Quaternion3D currentRotation = Quaternion3D();
    Quaternion3D stepRotation = Quaternion3D(M_PI/50, Vector3D(0, 0, 1)) * Quaternion3D(M_PI/39, Vector3D(0, 1, 0));

    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetColor(0);

    do {
        gfx_FillScreen(255);
        
        for (int i = 0; i < 8; i++) {
            workBuffer[i] = vertices[i];
            workBuffer[i] = currentRotation.rotate(workBuffer[i]);
            workBuffer[i] = camera.projectPoint(workBuffer[i]);

            pixelBuffer[i][0] = int(160 * (1 + workBuffer[i].getx()));
            pixelBuffer[i][1] = int(120 * (1 + workBuffer[i].gety()));
        }

        for (int i = 0; i < 12; i++) {
            gfx_Line(pixelBuffer[edges[i][0]][0], pixelBuffer[edges[i][0]][1], pixelBuffer[edges[i][1]][0], pixelBuffer[edges[i][1]][1]);
        }

        gfx_SwapDraw();

        currentRotation = stepRotation * currentRotation;
    } while (!os_GetCSC());
    
    gfx_End();

    return 0;
}


#endif