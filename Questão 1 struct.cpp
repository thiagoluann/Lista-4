//Declara��o das bibliotecas
#include<stdio.h>
#include<stdlib.h>

//Struct do tipo ingresso
typedef struct ingresso{
	
	//Vari�vel dotipo float para armazenar o pre�o do ingresso
    float preco;
    
    //Vari�vel do tipo char para armazenar o local da atra��o
    char local[40];
    
    //Vari�vel dobtipo char para armazenar a atra��o
    char atracao[50];;
}Ingresso;

//Prot�tipo da fun��o para preencher os campos da estrutura
void preenche(Ingresso* i);

//Prot�tipo da fun��o para imprimir os campos preencheidos
void imprime (Ingresso* i);

//Prot�yipo da fun��o que altera o pre�o
void altera_preco(Ingresso* i, float valor);

//Prot�tipo da fun��o para imprimir a atr��o mais cara e mais barata
void imprime_menor_maior_preco(int n, Ingresso* vet);

 
int main(){

	//Declara��o de vari�veis do tipo int
    int n, i;

	//Solicitando ao usu�rio a quantidade de filmes que ele quer saber a informa��o
    printf("Quer saber a informacao de quantos filmes: ");

	//Lendo o valor inserido
    scanf("%d", &n);

	//Criando um vetor de tamanho n do tipo Ingresso
    Ingresso vet[n];
	
	//la�o para preencher os campos do vetor
    for(i = 0; i < n; i++){
    	
    	//Chamando a fun��o que preenche os dados
        preenche(&vet[i]);
    }
    
	//Chamando a fun��o que altera o pre�o do ingresso e adicionando mais R$20,00 ao primeiro valor inserido 										    
	altera_preco(&vet[0], 20);

	//La�o para imprimir os campos do vetor
    for(i = 0; i < n; i++){
    	
    	////Chamando a fun��o que imprime os dados
        imprime(&vet[i]);
    }

	//Chamando a fun��o que imprimr o maior e o menor pre�o
    imprime_menor_maior_preco(n, vet);

return 0;
}

//Fun��o que preenche os campos da struct
void preenche(Ingresso* i){

	
    printf("Digite a atracao: ");

    scanf(" %[^\n]", i->atracao);

    printf("Digite o preco do ingresso: ");

    scanf("%f", &i->preco);

    printf("Digite o local da atracao: ");

    scanf(" %[^\n]", i->local);

}

//Fun��o que imprime os campos da struct
void imprime (Ingresso* i){

    printf("Atracao: %s.  Ingresso: %.2f reais.  Local: %s.  \n",i->atracao, i->preco, i->local);
}

//Fun��o que altera o pre�o do ingresso
void altera_preco(Ingresso* i, float valor){

    i->preco = i->preco + valor;
}

//Fun��o para imprimir o ingresso mais caro e o mais barato
void imprime_menor_maior_preco(int n, Ingresso* vet){

	//Declarando vari�veis do tpo int e inicializando as vari�veis "maior" e "menor" com 0
    int i, maior = 0, menor = 0;

	//Etrutura de decis�o que calcula o maior e o menor ingresso
    for(i = 0; i < n; i++){
        if(vet[i].preco > vet[maior].preco){
            maior = i;
        }

        if(vet[i].preco < vet[menor].preco){
            menor = i; 
        }

    }
    
    //Exibindo a atra��o mais cara e a mais barata
    printf("Ingresso mais caro: %s.  Ingresso mais barato %s.\n ", vet[maior].atracao, vet[menor].atracao);
}
