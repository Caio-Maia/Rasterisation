# Pipeline Gráfico - Introduction To Computer Graphics
A code that makes geometric transformations using the pipeline made as an activity of the course of introduction to computer graphics in 2020.

---

### Exercício 1: Escala

No primeiro exercício, é solicitado a alteração da escala dos triângulos. O tamanho deles são alterados de forma que **(x,y,z) = (1/3, 3/2, 1)**. Com isso, modificamos a matriz identidade model para: 
	
```C
model_array[16] = {0.3f, 0.0f, 0.0f, 0.0f, 
                   0.0f, 1.5f, 0.0f, 0.0f, 
                   0.0f, 0.0f, 1.0f, 0.0f, 
                   0.0f, 0.0f, 0.0f, 1.0f};
```

<p align="center">
  <img src="https://imgur.com/7nnVqmT.png?1">
</p>

---

### Exercício 2: Translação

O exercício pede para transladar os triangulos em **x**, sendo **x = 1**. Para transladar foi alterado a matriz principal(dos vertices), somando o valor anterior mais 1 nas colunas de **X**. Lembrando que a glm implementa matrizes internamente no formato *column major*. Logo a Matriz fica:
	
```C
vertices[] = { 0.75f, -0.5f, -0.1f, 0.75f, 0.0f, 0.0f,
               1.25f,  0.5f, -0.1f, 0.75f, 0.0f, 0.0f,
               1.75f, -0.5f, -0.1f, 0.75f, 0.0f, 0.0f,
               0.25f, -0.5f, -0.4f, 0.0f, 0.0f, 0.75f, 
               0.75f,  0.5f, -0.4f, 0.0f, 0.0f, 0.75f,
               1.25f, -0.5f, -0.4f, 0.0f, 0.0f, 0.75f}; 
```

<p align="center">
  <img src="https://imgur.com/uDpoxfb.png?1">
</p>

---

### Exercício 3: Projeção Perspectiva

Nesse exercício foi preciso modificar projeção do objeto, para isso foi alterado a matriz de projeção(M*Projection*). Usando a matriz entregue, só foi preciso substituir **d** pelo valor dado(*d = 1/2*). Logo temos a matriz:
	
```C
proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                  0.0f, 1.0f, 0.0f, 0.0f, 
                  0.0f, 0.0f, 1.0f, -2.0f, 
                  0.0f, 0.0f, 0.5f, 1.0f};
```

<p align="center">
  <img src="https://imgur.com/QHeCrzh.png?1">
</p>

---

### Exercício 4: Posição da Câmera

Nesse exercício, tivemos que alterar a "câmera" do programa, para isso foi calculado a matriz *view* por meio da formula **M*view* = B*t* . T**. Com isso em mente, tivemos que achar as matrizes **Bt** e **T** pelos seguintes cálculos:

*Informações:*

**posição** = (−1/10, 1/10, 1/4)
**Up** = (0, 1, 0)
**lookat** = (0, 0, 0)
</br>
</br>
*Cálculos:*

**direção** = lookat - posição
**direção** = (0, 0, 0) - (-1/10, 1/10, 1/4) = (1/10, -1/10, -1/4)

**Zc** = - direção/|direção| = -(1/10, -1/10, -1/4) / raiz(33)/20 = (-2/raiz(33), 2/raiz(33), 5/raiz(33))

**Xc** = up x Zc / |up x Zc| = (5/raiz(33), 0, 2/raiz(33)) / raiz(29/33) = (5/raiz(29), 0, 2/raiz(29)) = (0.92847, 0, 0.37139)

**Yc** = Zc x Xc / |Zc x Xc| = (4/raiz(957), raiz(29/33), -10/raiz(957)) / 1 = (4/raiz(957), raiz(29/33), -10/raiz(957)) = (0.12930, 0.93743, -0.32325)


Formando as matrizes e calculando o resultado teremos:
	
<pre>
	    Bt = ┌                                ┐
	         │ 0.92847     0      0.37139   0 │
	         │ 0.12930  0.93743  -0.32325   0 │
	         │-0.34815  0.34815   0.87038   0 │
	         │    0        0         0      1 │
	         └                                ┘

	    T = ┌                ┐
	        │ 1  0  0   0.10 │
	        │ 0  1  0  -0.10 │
	        │ 0  0  1  -0.25 │
	        │ 0  0  0    1   │
	        └                ┘
	        
	    Mview = Bt . T 
	
	    Mview = ┌                                        ┐
	            │ 0.92847     0      0.37139  -0.0000005 │
	            │ 0.12930  0.93743  -0.32325  -0.0000005 │
	            │-0.34815  0.34815   0.87038  -0.2872250 │
	            │    0        0         0         1      │
	            └                                        ┘
</pre>


Como resultado teremos a seguinte matriz view no codigo:
	
```C
view_array[16] = { 0.92847f,  0.12930f, -0.34815f,  0.0f, 
                   0.0f,  0.93743f,  0.34815f,  0.0f, 
                   0.37139f, -0.32325f,  0.87038f,  0.0f, 
                   -0.0000005f,  -0.0000005f, -0.2872250f,  1.0f};
```

<p align="center">
  <img src="https://imgur.com/Kdd2PO0.png?1">
</p>

---

### Exercício 5: Transformações Livres

Nesse exercício é preciso fazer modificações em todas as matrizes *(Mmodel, Mview e Mprojection)*. Além disso poderia criar geometrias diferentes, então fiz dois triângulos que juntos formaram um quadrado. Os vértices ficaram:

```C
vertices[] = {-0.5f,  0.5f, -0.4f, 1.0f, 0.0f, 0.0f,
               0.5f,  0.5f, -0.4f, 0.0f, 1.0f, 0.0f,
               0.5f, -0.5f, -0.4f, 0.0f, 0.0f, 1.0f,
              -0.5f, -0.5f, -0.4f, 1.0f, 1.0f, 1.0f,
              -0.5f,  0.5f, -0.4f, 1.0f, 0.0f, 0.0f,
               0.5f, -0.5f, -0.4f, 0.0f, 0.0f, 1.0f};
```

<p align="center">
  <img src="https://imgur.com/KTn3J0K.png?1">
</p>

Então para **Matriz model**, dobrei seu tamanho em x, transformando o antigo "quadrado" em um retângulo:

```C
model_array[16] = {2.0f, 0.0f, 0.0f, 0.0f, 
                   0.0f, 1.0f, 0.0f, 0.0f, 
                   0.0f, 0.0f, 1.0f, 0.0f, 
                   0.0f, 0.0f, 0.0f, 1.0f};
```

<p align="center">
  <img src="https://imgur.com/BKAHNiq.png?1">
</p>

Após isso alterei a distância do centro de projeção, **d**, para 1/4 deixando a **Matriz Projection** da seguinte forma:

```C
proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                  0.0f, 1.0f, 0.0f, 0.0f, 
                  0.0f, 0.0f, 1.0f, -4.0f, 
                  0.0f, 0.0f, 0.25f, 1.0f};
```

<p align="center">
  <img src="https://imgur.com/dVyEpr5.png?1">
</p>

Para a **Matriz View** coloquei as seguintes variáveis e calculei:

*Informações:*

**posição** = (1/2, 1/2, 1/4)
**Up** = (0, 2, 0)
**lookat** = (0, 0, 0)
</br>
</br>
*Cálculos:*

**direção** = lookat - posição
**direção** = (0, 0, 0) - (1/2, 1/2, 1/4) = (-1/2, -1/2, -1/4)

**Zc** = - direção/|direção| = (-1/2, -1/2, -1/4) / |(-1/2, -1/2, -1/4)| = (-2/3, -2/3, -1/3) = (-0.66666, -0.66666, -0.33333)

**Xc** = up x Zc / |up x Zc| = ((0, 2, 0) x (-2/3, -2/3, -1/3)) / |(0, 2, 0) x (-2/3, -2/3, -1/3)| = (-1/raiz(5), 0, 2/raiz(5)) = (-0.4472135955, 0, 0.89442)

**Yc** = Zc x Xc / |Zc x Xc| = ((-2/3, -2/3, -1/3) x (-1/raiz(5), 0, 2/raiz(5))) / |((-2/3, -2/3, -1/3) x (-1/raiz(5), 0, 2/raiz(5)))| = (-4/3raiz(5), raiz(5)/3, -2/3raiz(5)) = (-0.59628, 0.74535, -0.298142397)
</br>
</br>
*Matrizes:*

<pre>
	    Bt = ┌                                         ┐
	         │-0.4472135955     0      0.89442       0 │
	         │-0.59628       0.74535  -0.298142397   0 │
	         │-0.66666      -0.66666  -0.33333       0 │
	         │    0             0         0          1 │
	         └                                         ┘

	    T = ┌               ┐
	        │ 1  0  0  0.50 │
	        │ 0  1  0  0.50 │
	        │ 0  0  1  0.25 │
	        │ 0  0  0   1   │
	        └               ┘
	        
	    Mview = Bt . T 
	
	    Mview = ┌                                          ┐
	            │ -0.44721      0      0.89442  -0.0000017 │
	            │ -0.59628   0.74535  -0.29814  -0.0000005 │
	            │ -0.66666  -0.66666  -0.33333  -0.7499925 │
	            │    0          0         0         1      │
	            └                                          ┘
</pre>

Por fim, temos o seguinte resultado:

<p align="center">
  <img src="https://imgur.com/Doajokc.png?1">
</p>

---

### Dificuldades e Possíveis Melhorias

Maior dificuldade em resolver as atividades foram a visualização mental de onde ficaria projetado o objeto. Também foi encontrado difculdade pela matriz ser transposta, o que levava a pequenos enganos durante a implementação. Pensei em fazer outras coisas na ultima atividade, como tentar criar um cubo, porém imaginei que isso poderia mudar bastante o codigo original, então optei somenta pela criação de um quadrilátero utilizando dois triângulos.

#### Referências:

< Slides do Prof. Christian Azambuja Pagot > (Geometric Transformations, Modeling and View Transform) </br>
<a href="http://www.opengl-tutorial.org/beginners-tutorials/"> OpenGL Tutorial for beginners </a> </br>
<a href="https://pt.symbolab.com/"> Symbolab - Calculadora usada para facilitar os calculos das matrizes e dos vetores </a> </br>
