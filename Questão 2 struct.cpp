

//QUESTÃO 2

#include<stdio.h> //declaração de biblioteca
#include<stdlib.h> //declaração de biblioteca


typedef struct Aluno{   // declaração da struct com o comando typedef que "renomeia" a estrutura
    int mat;  //declaração de variavel na struct 
    char nome[60]; //declaração de variavel na struct 
    char turma; //declaração de variavel na struct 
    float n1, n2, n3; //declaração de variavel na struct 
    float media; //declaração de variavel na struct 
}Aluno; // o nome da struct passa a ser Só Aluno

void matricula(int n, Aluno**alunos); // Protótipo da função que armazena os dados dos alunos
void lanca_notas(int n, Aluno**alunos); // Protótipo da função que armazena as notas dos alunos
void imprime_tudo(int n, Aluno** alunos); // Protótipo da função que imprime as informações dos alunos 
void imprime_turma(int n, Aluno** alunos, char turma); // Protótipo da função que imprime a média dos alunos
void imprime_turma_aprovados(int n,Aluno**alunos, char turma); // Protótipo da função que imprime a reprovação


int main(void){  // programa principal
    int i, n; //declaração de variavel
    Aluno**alunos; //declaração de variavel do tipo estrutura
    char turma; //declaração de variavel
    
    printf("Digite a quantidade de alunos:"); //solicita ao usuario a qtde de alunos
    scanf("%d", &n); // ler e armazena a qtde de alunos
    alunos=(Aluno**)malloc(n*sizeof(Aluno*)); // alocação do ponteiro dinamicamente
	
        matricula(n, alunos); // chamada da função 
        lanca_notas(n, alunos); // chamada da função
   		imprime_tudo(n, alunos); // chamada da função
   		imprime_turma( n, alunos, turma); // chamada da função
   		imprime_turma_aprovados(n,alunos,'a'); // chamada da função
   		free(alunos); //libera o vetor
        return 0; //fim programa
}

void matricula(int n, Aluno**alunos){  // função que recebe os dados dos alunos
        
    int j; //declaração de variavel
     if (j<0 || j>=n) { //compara se o indicie esta dentro ou fora do vetor declarado 
     printf("Indice fora do limite do vetor\n"); //exibe caso esteja
     exit(1); //finaliza programa
     }

        for(j=0;j<n;j++){ //laço de repetição que passa pela quantidade digitada de alunos 
    
    printf("\nDigite seu %d.o nome: ", j+1); //pedindo dados do usuario e armazendo-o de acordo com a quantidade digitade de pessoas no começo
    scanf(" %[^\n]",&alunos[j]->nome);
    printf("Digite sua %d.a turma: ", j+1); //pedindo dados do usuario e armazendo-o de acordo com a quantidade digitade de pessoas no começo
    scanf(" %[^\n]",&alunos[j]->turma);    
    printf("Digite sua %d.a matricula: ", j+1); //pedindo dados do usuario e armazendo-o de acordo com a quantidade digitade de pessoas no começo
    scanf("%d", &alunos[j]->mat);    
    }    
}
void lanca_notas(int n, Aluno**alunos){ // estrutura que lança as notas, pede ao usuario e a armazena
    int j;
   if (j<0 || j>=n) { //laço de repetição que verifica se tem o vetor dentro do indicie 
     printf("Indice fora do limite do vetor\n");
     exit(1);
     }
        for(j=0;j<n;j++){
    printf("Digite a %d.a nota: ", j+1); //solicita nota
    scanf(" %f",&alunos[j]->n1); //ler nota
    printf("Digite a %d.a nota: ", j+1); //solicita nota
    scanf(" %f",&alunos[j]->n2);   //ler nota
    printf("Digite a %d.a nota: ", j+1); //solicita nota
    scanf("%f", &alunos[j]->n3);    //ler nota
    alunos[j]->media=(alunos[j]->n1+alunos[j]->n2+alunos[j]->n3)/3; // calculo da media
    }
}
void imprime_tudo(int n, Aluno** alunos){ //função que recebe as medias e os dados dos alunos e a imprime
	   int j;
   if (j<0 || j>=n) {
     printf("Indice fora do limite do vetor\n"); // para saber se tem limite na memoria
     exit(1);
     }
        for(j=0;j<n;j++){
    printf("O nome do %d.o aluno = %s\n ", j+1,alunos[j]->nome );
    printf("A %d.a turma =%s:\n ", j+1, alunos[j]->turma);
    printf("A %d.a matricula= %d\n", j+1, alunos[j]->mat);
    printf("As notas = %.2f %.2f %.2f\n", alunos[j]->n1, alunos[j]->n2, alunos[j]->n3);
	printf("A %d.a Media = %.2f \n", j+1, alunos[j]->media);
}
}
void imprime_turma(int n, Aluno** alunos, char turma){ //função que mostra os dados da turma do aluno
		   int j;
   if (j<0 || j>=n) {
     printf("Indice fora do limite do vetor\n");
     exit(1);
     }
        for(j=0;j<n;j++){
    printf("O %d.o nome = %s\n ", j+1,alunos[j]->nome ); //imprime o nome
    printf("%d.a turma =%s\n ", j+1, alunos[j]->turma); //imprime turma
    printf("Matricula %d =%d \n", j+1, alunos[j]->mat); //imprime matricula
}
}
void imprime_turma_aprovados(int n, Aluno**alunos, char turma){ //função para mostrar a turma 
    int j;
    for(j=0;j<n;j++){
        if(alunos[j]!=NULL && alunos[j]->turma==turma){ //verifica se tem espaço
           if(alunos[j]->media>=7){ // verifica se a média é maior que 7, se for
                printf("\n Matricula:  %s \n", alunos[j]->mat); //apresenta a matricula
                printf("Nome: %s \n", alunos[j]->nome); //o nome
                printf("Media: %f \n, APROVADO \n", alunos[j]->media); //e a media
           }
        }
    }
}
