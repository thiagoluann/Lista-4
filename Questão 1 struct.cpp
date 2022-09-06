//Declaração das bibliotecas
#include<stdio.h>
#include<stdlib.h>

//Struct do tipo ingresso
typedef struct ingresso{
	
	//Variável dotipo float para armazenar o preço do ingresso
    float preco;
    
    //Variável do tipo char para armazenar o local da atração
    char local[40];
    
    //Variável dobtipo char para armazenar a atração
    char atracao[50];;
}Ingresso;

//Protótipo da função para preencher os campos da estrutura
void preenche(Ingresso* i);

//Protótipo da função para imprimir os campos preencheidos
void imprime (Ingresso* i);

//Protóyipo da função que altera o preço
void altera_preco(Ingresso* i, float valor);

//Protótipo da função para imprimir a atrção mais cara e mais barata
void imprime_menor_maior_preco(int n, Ingresso* vet);

 
int main(){

	//Declaração de variáveis do tipo int
    int n, i;

	//Solicitando ao usuário a quantidade de filmes que ele quer saber a informação
    printf("Quer saber a informacao de quantos filmes: ");

	//Lendo o valor inserido
    scanf("%d", &n);

	//Criando um vetor de tamanho n do tipo Ingresso
    Ingresso vet[n];
	
	//laço para preencher os campos do vetor
    for(i = 0; i < n; i++){
    	
    	//Chamando a função que preenche os dados
        preenche(&vet[i]);
    }
    
	//Chamando a função que altera o preço do ingresso e adicionando mais R$20,00 ao primeiro valor inserido 										    
	altera_preco(&vet[0], 20);

	//Laço para imprimir os campos do vetor
    for(i = 0; i < n; i++){
    	
    	////Chamando a função que imprime os dados
        imprime(&vet[i]);
    }

	//Chamando a função que imprimr o maior e o menor preço
    imprime_menor_maior_preco(n, vet);

return 0;
}

//Função que preenche os campos da struct
void preenche(Ingresso* i){

	
    printf("Digite a atracao: ");

    scanf(" %[^\n]", i->atracao);

    printf("Digite o preco do ingresso: ");

    scanf("%f", &i->preco);

    printf("Digite o local da atracao: ");

    scanf(" %[^\n]", i->local);

}

//Função que imprime os campos da struct
void imprime (Ingresso* i){

    printf("Atracao: %s.  Ingresso: %.2f reais.  Local: %s.  \n",i->atracao, i->preco, i->local);
}

//Função que altera o preço do ingresso
void altera_preco(Ingresso* i, float valor){

    i->preco = i->preco + valor;
}

//Função para imprimir o ingresso mais caro e o mais barato
void imprime_menor_maior_preco(int n, Ingresso* vet){

	//Declarando variáveis do tpo int e inicializando as variáveis "maior" e "menor" com 0
    int i, maior = 0, menor = 0;

	//Etrutura de decisão que calcula o maior e o menor ingresso
    for(i = 0; i < n; i++){
        if(vet[i].preco > vet[maior].preco){
            maior = i;
        }

        if(vet[i].preco < vet[menor].preco){
            menor = i; 
        }

    }
    
    //Exibindo a atração mais cara e a mais barata
    printf("Ingresso mais caro: %s.  Ingresso mais barato %s.\n ", vet[maior].atracao, vet[menor].atracao);
}
