//Declara��o das bibliotecas
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

//Criando uma struct do tipo Retangulo
typedef struct retangulo{
    float base;
    float altura;
}Ret;

//Criando uma struct do tipo Circulo
typedef struct circulo{
    float raio;
}Circ;

//Prot�tipo da fun��o do retangulo circunscrito
Ret *ret_circunscrito(Circ *c, float h);

//Prot�tipo da fun��o do circulo interno
Circ *circ_interno(Ret *r);

int main(){ 
	
	//Declarando um ponteiro do tipo Circ e fazendo aloca��o din�mica
    Circ *c = malloc(sizeof(Circ));
    
    //O raio est� recebendo o valor 5
    c->raio = 5;
    
    //Declarando um ponteiro do tipo Ret e atribuindo a ela a fun��o do ret�ngulo circunscrito e colocando a altura como 3 
    Ret *r = ret_circunscrito(c, 3);
    
    //Imprimindo a base
    printf("Base: %.2f ", r->base); 
    
    //Imprimindo a altura
    printf("Altura: %.2f ", r->altura);
    
    //Fazendo a libera��o de *c e *r
    free(c);
    free(r);
    return 0;
}

//Fun��o que calcula o ret�ngulo circunscrito
Ret *ret_circunscrito(Circ *c, float h){
    Ret *r = malloc(sizeof(Ret));
    r->base = 2 * sqrt(pow(c->raio, 2) - pow(h, 2));
    r->altura = h;
    return r;
}

//Fun��o que calcula o circulo interno
Circ *circ_interno(Ret *r){
    Circ *c = malloc(sizeof(Circ));
    c->raio = sqrt(pow(r->base, 2) + pow(r->altura, 2)) / 2;
    return c;
}

