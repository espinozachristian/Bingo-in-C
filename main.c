#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void sorteio_num(int *sorteio,int n);
void ler_aposta(int *aposta,int n);
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);
void bubblesort2(int *v, int n);

int main(int argc, char *argv[]) {
	int na;
	int ns=20;
	int *sorteio = malloc(sizeof(int)*ns);
	int *aposta = malloc(sizeof(int)*na);
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
	
	printf("Digite a quantidade de numeros que gostaria de apostar!\n");
	printf("Voce pode escolher apostar de 1 a 20 numeros por vez\n");
	scanf("%d",&na);
	
	int vetorapostafinal;
	ler_aposta(aposta,na);
	sorteio_num(sorteio,ns);
	vetorapostafinal=compara_aposta(aposta,sorteio,&qntd,na,ns);
	printf("\t*****************************************\n");
	printf("\t**                Numeros            **\n");
	printf("\t**             	Sorteados           **\n");
	printf("\t**                                     **\n");
	printf("\t*****************************************\n");
	printf("\n");
	int i = 0;
	bubblesort2(sorteio,ns);
	for (i = 0; i < ns; i++){
		if(i % 5 == 0){
   			printf("\n");
		   }
	printf("\t%d ", *(sorteio+i));
	}
	if(qntd > 0){
	printf("\n\n\n");
	printf("\t*****************************************\n");
	printf("\t**            PARABENS!!               **\n");
	printf("\t**               Voce                  **\n");
	printf("\t**        Acertou: %d numeros.         **\n",qntd);
	printf("\t*****************************************\n");
	printf("\n");
	
	printf("Os numeros Acertados Foram:\n");
   	for(i=0;i< qntd;i++){
   		if(i % 5 == 0){
   			printf("\n");
		   }
   		printf("%d  ",(vetorapostafinal+i));
	   }
	}else{
	printf("\n\n\n");
	printf("\t*****************************************\n");
	printf("\t**            Que Azar!!!               **\n");
	printf("\t**             Voce nao                 **\n");
	printf("\t**        Acertou Nenhum Numero         **\n",qntd);
	printf("\t*****************************************\n");
	printf("\n");
	}
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
                if ( *(aposta+i) < 0 || *(aposta+i)>100 ||  *(aposta+i) == *(aposta+j) ){
                printf("*******************************************\n");
                printf("*                 Erro                    *\n");
				printf("*    Numero digitado ja foi apostado      *\n");
				printf("*         Ou Acima do permitido           *\n");
				printf("*             para se apostar             *\n");
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
				if(*(aposta+i)== *(sorteio+j)){
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
	return *resultante;
}

void bubblesort2(int *v, int n)
{
	int aux, i, j, trocou=1;
	for (i=0; i<n-1 && trocou; i++) {
		trocou=0;   /*inicialmente nenhuma troca foi feita */
		for (j=0; j<n-1-i; j++)
		   if (v[j] > v[j+1]) {
			trocou=1; /* houve troca */
			aux=v[j];
			v[j]=v[j+1];
			v[j+1]=aux;
		   }
	}
}
