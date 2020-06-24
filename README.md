# Rasterisation - Introduction To Computer Graphics
A code that uses the Bresenham algorithm for rasterization of points and lines made as an activity of the course of introduction to computer graphics in 2020.

---

### Colocar um pixel - PutPixel();
  Função onde um pixel será gerado na tela. Nela receberemos o ponto como parametro (x, y) e sua cor (rgb) atraves de uma struct do tipo LOCAL para guardar essas informações, e utilizando o ponteiro **fb_ptr**.
  
```C
RGB cor1 = {255, 0, 0};
LOCAL ponto = {100, 100, cor1};
PutPixel(ponto);
```

<p align="center">
  <img src="https://i.imgur.com/T2jckZh.png?1">
</p>

---

### Desenhar uma linha - DrawLine();
  Nesta função, recebemos dois pontos/pixels, então é utilizado o algoritmo de bresenham:
  
```C
int mdx=abs(ponto2.x - ponto1.x); 
int mdy=abs(ponto2.y - ponto1.y);
int dx = ponto2.x - ponto1.x;
int dy = ponto2.y - ponto1.y;
int d = mdy - mdx/2;
int incrE = mdy; 
int incrSE = mdy-mdx;
LOCAL pontoVar = ponto1;
for(;pontoVar.x<ponto2.x;pontoVar.x++){
    PutPixel(pontoVar);
    if(d<=0) 
        d+=incrE; 
    else {
        d+=incrSE;
        pontoVar.y++;
    }
}
```

Porém, o algoritmo so permite a criação de linhas entre 0º e 45º(um octano), então teve que ser criado uma adaptação para que o algoritmo funcionasse em todos os octanos. Então, utilizando como base os argumentos para cada octano:
<p align="center">
  <img width="436" height="367" src="https://imgur.com/kGY0JqB.png?1">
</p>
Foi possivel utilizar o algoritmo para cada caso dos octanos e alterar expressões para adaptar o codigo. Abaixo tem um exemplo usado para no caso do terceiro octano:

```C
if (mdx > mdy && dx < 0 && dy > 0) {

    int d = mdy - mdx / 2; 
    int incrE = mdy;
    int incrSE = mdy - mdx;
    for (; pontoVar.x > ponto2.x; pontoVar.x--) {
        PutPixel(pontoVar);
        if (d <= 0)
            d += incrE;
        else {
            d += incrSE;
            pontoVar.y++;
        }
    }
}
```

Pode-se ver que neste caso so foi preciso alterar o comportamento de **x** dentro do *for*, mas para cada caso teremos que fazer outras alterações como no calculo da variavel de decisão(*d*), assim, com a seguinte entrada:

```C
LOCAL ponto1 = {0, 0, cor1};
LOCAL ponto2 = {100, 600, cor1};
RGB cor1 = {255, 0, 0};
DrawLine(ponto1, ponto2);
```

Tivemos o seguinte resultado:

<p align="center">
  <img src="https://imgur.com/ofBazUd.png?1">
</p>

---

### Desenhar um Triângulo - DrawTriangle();
Agora é feito algo mais simples, para fazer o triângulo só precisamos de três retas, logo so precisamos chamar a função **DrawLine()** três vezes, relacionando os pontos recebidos, assim ficamos com o seguinte codigo:

```C
DrawLine(ponto1, ponto2);
DrawLine(ponto2, ponto3);
DrawLine(ponto3, ponto1);
```
Com a entrada abaixo, teremos o seguinte resultado:

```C
RGB cor1 = {255, 0, 0};
LOCAL ponto1 = {0, 450, cor1};
LOCAL ponto2 = {255, 0, cor1};
LOCAL ponto3 = {510, 450, cor1};
DrawTriangle(ponto1, ponto2, ponto3);
```
<p align="center">
  <img src="https://imgur.com/lpnPz0E.png?1">
</p>

---

### Interpolação linear de Cores
Para fazer isso, utilizei um *Array* na função **DrawLine()** de tamanho 3, chamado **var**, nele eu calculei a variação de cada cor para cada pixel andado utilizando a seguinte ideia: var = (corFinal - corInicial) / maiordistancia;

```C
var[0] = (ponto2.color.red - ponto1.color.red) / mdx;
var[1] = (ponto2.color.green - ponto1.color.green) / mdx
var[2] = (ponto2.color.blue - ponto1.color.blue) / mdx;
```
Neste caso utilizei o modulo de **X** como distância pela reta andar mais em **X** do que em **Y**. Após isso só precisamos adicionar cada variação a sua cor, então teremos o seguinte resultado:

```C
RGB cor1 = {255, 0, 0};
RGB cor2 = {0, 0, 255};
RGB cor3 = {153, 0, 153};
LOCAL ponto1 = {0, 450, cor1};
LOCAL ponto2 = {255, 0, cor2};
LOCAL ponto3 = {510, 450, cor3};
DrawTriangle(ponto1, ponto2, ponto3);
```

<p align="center">
  <img src="https://imgur.com/nbybADT.png?1">
</p>

---

### Possiveis melhorias?

A adaptação do algoritmo de Bresenham para a criação de linhas em todos os octantes foi a parte mais dificil, mas poderia ser melhorado como a redução da quantidade de *if*'s no codigo, e também poderia ter separado a interpolação linear em uma função diferente para o melhor entendimento de quem fosse ler o codigo, uma ideia legal também seria a criação de um algoritmo para preencher por dentro das formas criadas, talvez calculando área.

#### Referencias:

< Slides sobre rasterização do Prof. Christian Azambuja Pagot > </br>
<a href="https://en.wikipedia.org/wiki/Bresenham's_line_algorithm"> Bresenham's Line Algorithm Wiki </a> </br>
FOLEY, JAMES. D. Computer Graphics: Principles and Practice. Second Edition in C

