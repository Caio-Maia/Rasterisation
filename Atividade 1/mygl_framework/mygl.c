#include "mygl.h"


void DrawLine(LOCAL ponto1, LOCAL ponto2){
    int mdx=abs(ponto2.x - ponto1.x); 
    int mdy=abs(ponto2.y - ponto1.y);
    int dx = ponto2.x - ponto1.x;
    int dy = ponto2.y - ponto1.y;

    LOCAL pontoVar = ponto1;

    if(mdx>mdy) {

        int d = mdy - mdx/2; //variável de decisão
        int incrE = mdy; 
        int incrSE = mdy-mdx;
        double var[3] = {0,0,0};

        var[0] = (ponto2.color.red - ponto1.color.red) / mdx;
        var[1] = (ponto2.color.green - ponto1.color.green) / mdx;
        var[2] = (ponto2.color.blue - ponto1.color.blue) / mdx;

        if(dx > 0 && dy > 0) {

            for(;pontoVar.x<ponto2.x;pontoVar.x++){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.y++;
                }
            }
        }
        else if(dx < 0 && dy > 0) {

            for(;pontoVar.x>ponto2.x;pontoVar.x--){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.y++;
                }
            }
        }
        else if(dx < 0 && dy < 0) {

            for(;pontoVar.x>ponto2.x;pontoVar.x--){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.y--;
                }
            }
        }
        else if(dx > 0 && dy < 0) {

            for(;pontoVar.x<ponto2.x;pontoVar.x++){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.y--;
                }
            }
        }
    }
    if(mdy>mdx){

        int d = mdx - mdy/2; //variável de decisão
        int incrE = mdx; 
        int incrSE = mdx-mdy;
        double var[3] = {0,0,0};

        var[0] = (ponto2.color.red - ponto1.color.red) / mdy;
        var[1] = (ponto2.color.green - ponto1.color.green) / mdy;
        var[2] = (ponto2.color.blue - ponto1.color.blue) / mdy;

        if(dx > 0 && dy > 0){

            for(;pontoVar.y<ponto2.y;pontoVar.y++){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.x++;
                }
            }
        }
        else if(dx < 0 && dy > 0) {

            for(;pontoVar.y<ponto2.y;pontoVar.y++){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.x--;
                }
            }
        }
        else if(dx < 0 && dy < 0) {

            for(;pontoVar.y>ponto2.y;pontoVar.y--){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.x--;
                }
            }
        }
        else if(dx > 0 && dy < 0) {

            for(;pontoVar.y>ponto2.y;pontoVar.y--){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
                if(d<=0) 
                    d+=incrE; 
                else {
                    d+=incrSE;
                    pontoVar.x++;
                }
            }
        }
    }
    if(dx == 0) {
        double var[3] = {0,0,0};

        var[0] = (ponto2.color.red - ponto1.color.red) / mdy;
        var[1] = (ponto2.color.green - ponto1.color.green) / mdy;
        var[2] = (ponto2.color.blue - ponto1.color.blue) / mdy;

        if(ponto1.y > ponto2.y) {
            for(;pontoVar.y>ponto2.y;pontoVar.y--){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
            }
        }
        else {
            for(;pontoVar.y<ponto2.y;pontoVar.y++){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
            }
        }
    }
    if(dy == 0) {
        double var[3] = {0,0,0};

        var[0] = (ponto2.color.red - ponto1.color.red) / mdx;
        var[1] = (ponto2.color.green - ponto1.color.green) / mdx;
        var[2] = (ponto2.color.blue - ponto1.color.blue) / mdx;

        if(ponto1.x > ponto2.x){
            for(;pontoVar.x>ponto2.x;pontoVar.x--){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
            }
        }
        else {
            for(;pontoVar.x<ponto2.x;pontoVar.x++){
                PutPixel(pontoVar);
                pontoVar.color.red += var[0];
                pontoVar.color.green += var[1];
                pontoVar.color.blue += var[2];
            }
        }
    } 
}

void PutPixel(struct LOCAL ponto)
{
    fb_ptr[4 * ponto.x + ponto.y * IMAGE_WIDTH * 4] = ponto.color.red;
    fb_ptr[4 * ponto.x + ponto.y * IMAGE_WIDTH * 4 + 1] = ponto.color.green;
    fb_ptr[4 * ponto.x + ponto.y * IMAGE_WIDTH * 4 + 2] = ponto.color.blue;
    fb_ptr[4 * ponto.x + ponto.y * IMAGE_WIDTH * 4 + 3] = 1;
}

void DrawTriangle(LOCAL ponto1, LOCAL ponto2, LOCAL ponto3) {
    DrawLine(ponto1, ponto2);
    DrawLine(ponto2, ponto3);
    DrawLine(ponto3, ponto1);
}

void MyGlDraw(void)
{
    // Codigos de teste (alguns foram colocados no github)

    // Variveis de Cor RGB
    RGB cor1 = {255, 0, 0};
    RGB cor2 = {0, 0, 255};
    RGB cor3 = {153, 0, 153};

    // Variavel de ponto, contendo informações: x, y e "cor"
    LOCAL ponto = {100, 100, cor1};

    // Chamada da função
    PutPixel(ponto);

    // 1 octante
    //LOCAL ponto1 = {0, 0, cor1};
    //LOCAL ponto2 = {400, 10, cor2};
    //DrawLine(ponto1, ponto2);

    // 2 octante
    //LOCAL ponto1 = {0, 0, cor1};
    //LOCAL ponto2 = {100, 600, cor1};
    //DrawLine(ponto1, ponto2);

    // 3 octante
    //LOCAL ponto1 = {0, 500, cor1};
    //LOCAL ponto2 = {100, 0, cor2};
    //DrawLine(ponto1, ponto2);

    // 4 octante
    //LOCAL ponto1 = {500, 0, cor1};
    //LOCAL ponto2 = {0, 200, cor2};
    //DrawLine(ponto1, ponto2);

    // 7 octante p1 = (0,510), p2 = (200,0)
    //LOCAL ponto1 = {0, 510, cor1};
    //LOCAL ponto2 = {200, 0, cor2};
    //DrawLine(ponto1, ponto2);

    // Triangulo
    //LOCAL ponto1 = {0, 450, cor1};
    //LOCAL ponto2 = {255, 0, cor2};
    //LOCAL ponto3 = {510, 450, cor3};
    //DrawTriangle(ponto1, ponto2, ponto3);


}