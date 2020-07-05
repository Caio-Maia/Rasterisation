#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"


typedef struct RGB {
    double red;
    double green;
    double blue
}RGB;

typedef struct LOCAL {
    int x;
    int y;
    RGB color;
}LOCAL;

void MyGlDraw(void);

void PutPixel(struct LOCAL ponto);

void DrawLine(LOCAL ponto1, LOCAL ponto2);

void DrawTriangle(LOCAL ponto1, LOCAL ponto2, LOCAL ponto3);

#endif  // MYGL_H
