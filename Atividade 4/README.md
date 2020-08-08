# Vertex Shader
A code made to familiarize with the lighting models traditionally used in rasterization: ambient, diffuse and specular using the vertex shader.

---

### Exercício 1: Implementação do Modelo de Reflexão Difuso

Nesse exercício foi pedido para modificar o vertex shader para que fosse incluso o modelo difuso. Então foi feito o calculo do vetor normal **N** (depois das transformações feitas pela matriz *Model*), e também foi feito o calculo do vetor **L** que é responsável por apontar o vértice para a fonte de luz. Então os calculos ficaram o seguinte:

```C
vec3 L = normalize(I_p_pos  - (model_mat * vec4(obj_spc_vertex_pos , 1.0)).xyz);
vec3 N = normalize(mat3(transpose(inverse(model_mat))) * obj_spc_N);
```

Após isso deve-se mudar o cálculo do modelo de iluminação do ambiente para que fique: **I = IaKa + IpKd(L.N)**. Assim temos:

```C
I = I_a * k_a + I_p * k_d * dot(L, N);
```

Resultado:

<p align="center">
  <img src="https://imgur.com/odcFho7.png?1">
</p>

---

### Exercício 2: Implementação do Modelo de Reflexão Especular

Nesse exercício ele pede para que adicione o modelo *especular*. Então foi calculado o vetor **R**, para a reflexão da luz **L**, e também foi calculado o vetor da câmera **V**. Ficou assim:

```C
vec3 R = -reflect(L, N);
vec3 V = normalize(cam_pos  - (model_mat * vec4(obj_spc_vertex_pos , 1.0)).xyz);
```

Então, devemos também mudar os calculos para o modelo de iluminação para: **I = IaKa + Ip(Kd(L.N) + Ks(R.V)^n)**, sendo **n = 64**. Logo temos: </br>
**OBS:** geralmente para calcular a potência é usado a função **pow()**, porém por algum motivo ela não estva funcionando corretamente, então foi calculado "manualmente", multiplicando varias vezes mesma variavel, no caso, **(R.V)**.

```C
I = I_a * k_a + I_p * (k_d * dot(L, N) + k_s * dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)*dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)*dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)*dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)*dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)*dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)*dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V)* dot(R, V));
```

Resultado:

<p align="center">
  <img src="https://imgur.com/9V5Rcm1.png?1">
</p>

---

### Dificuldades: 

A única dificuldade na hora de implementar, foi a questão do **pow()**, tive que pensar algum tempo por que não estava funcionando, e acabei levando a essa forma mais "manual"(porém nada bonita) de calcular.

#### Referências:

< Slides e Aulas do Prof. Christian Azambuja Pagot > (Reflection Models) </br>
<a href="https://www.shaderific.com/glsl-functions"> glsl Functions </a> </br>





