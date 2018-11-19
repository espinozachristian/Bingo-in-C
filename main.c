#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sorteio_num(int *sorteio,int n);
void ler_aposta(int *aposta,int n);
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);

int main(int argc, char *argv[]) {
	int n =20;
	int *sorteio = malloc(sizeof(int)*n);
	int *aposta = malloc(sizeof(int)*n);
	int qntd=0;

	
	printf("\t****************************************\n");
	printf("\t**          Bem Vindo ao Sorteio      **\n");
	printf("\t**        Criado por : Vermillionz    **\n");
	printf("\t**          Trabalho para P2          **\n");
	printf("\t****************************************\n");
	printf("\n");

	
	printf("\t*****************************************\n");
	printf("\t**                                     **\n");
	printf("\t**             	Regras                 **\n");
	printf("\t**                                     **\n");
	printf("\t*****************************************\n");
	printf("\n");
	
	printf("\t*******************************************\n");
	printf("\t*1- Voce tera ate 20 numeros para apostar *\n");
	printf("\t*2- Voce nao pode aposta o mesmo numero   *\n");
	printf("\t*3- Voce pode escolher Numeros entre 0-100*\n");
	printf("\t*******************************************\n");
	printf("\n");
	

	
	ler_aposta(aposta,n);
	sorteio_num(sorteio,n);
	compara_aposta(aposta,sorteio,&qntd,n,n);
	int i =0;
	printf("\n"); 	
	return 0;
}

void sorteio_num(int *sorteio,int n){
	int i,j,tmp =0;
	srand(time(NULL));

	for(i=0;i<n;i++){
		*(sorteio+i) = rand() % 101;	
	}
	printf("\n");
	 for (i = 0; i < n; i++) {
        int repetido = 0;
	   do{
       	    *(sorteio+i)= rand() % 101;
            repetido = 1;
            for (j = 0; j < i; j++) {
                if (*(sorteio+i) == *(sorteio+j)) 
				repetido = 0;
            }        
	   }while(!repetido);
	   	if(i % 5 == 0) 
        printf("%d ", *(sorteio+i));
    }
}


void ler_aposta(int *aposta,int n){
	int i ,j,aux;
	int repetido = 0;
	for(i=0;i<n;i++){
		do{
			printf("Digite o %d numero a ser apostado:",(i+1));
			scanf("%d",aposta+i);
            repetido = 1;
            for (j = 0; j < i; j++){
                if ( *(aposta+i) == *(aposta+j) ){
                printf("*******************************************\n");
                printf("*                 Erro                    *\n");
				printf("*    Numero digitado ja foi apostado      *\n");
				printf("*                                         *\n");
				printf("*******************************************\n");
				printf("\n"); 
				repetido = 0;
				 }
            	}        
	   	}while(!repetido);  
	}

}


int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	int i,j,a;
	for(i=0;i<na;i++){
		for(j=0;j <na;j++){
				if( *(aposta+i)== *(sorteio+j)){
			*qtdacertos = *qtdacertos+1;
			}
		}
	}
	int *resultante = malloc(*qtdacertos * sizeof(int) );
	j=0;
	int k =0;
	for(i=0;i<na;i++){
		for(j=0;j <na;j++){
				if( *(aposta+i)== *(sorteio+j)){
			*(resultante+k) = *(sorteio+j);
			k++;
			
		}
		}
	}
	printf("\n numero de acertos...... %d\n\n", *qtdacertos);
	printf("Os numeros Acertados Foram:\n");
   	for(i=0;i< *qtdacertos;i++){
   		if(i % 5 == 0)
   		printf("%d    ",*(resultante+i));
	   }
}
