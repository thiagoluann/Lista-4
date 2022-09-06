//Declaração das bibliotecas
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

//Protótipo da função do retangulo circunscrito
Ret *ret_circunscrito(Circ *c, float h);

//Protótipo da função do circulo interno
Circ *circ_interno(Ret *r);

int main(){ 
	
	//Declarando um ponteiro do tipo Circ e fazendo alocação dinâmica
    Circ *c = malloc(sizeof(Circ));
    
    //O raio está recebendo o valor 5
    c->raio = 5;
    
    //Declarando um ponteiro do tipo Ret e atribuindo a ela a função do retângulo circunscrito e colocando a altura como 3 
    Ret *r = ret_circunscrito(c, 3);
    
    //Imprimindo a base
    printf("Base: %.2f ", r->base); 
    
    //Imprimindo a altura
    printf("Altura: %.2f ", r->altura);
    
    //Fazendo a liberação de *c e *r
    free(c);
    free(r);
    return 0;
}

//Função que calcula o retângulo circunscrito
Ret *ret_circunscrito(Circ *c, float h){
    Ret *r = malloc(sizeof(Ret));
    r->base = 2 * sqrt(pow(c->raio, 2) - pow(h, 2));
    r->altura = h;
    return r;
}

//Função que calcula o circulo interno
Circ *circ_interno(Ret *r){
    Circ *c = malloc(sizeof(Circ));
    c->raio = sqrt(pow(r->base, 2) + pow(r->altura, 2)) / 2;
    return c;
}

