#include <stdio.h>
#include <stdlib.h>
typedef struct sLivro{
	char autor[11];
	char titulo[11];
	int numeroPaginas;
	

}Livro;
void cadastro(Livro*livro){
	
	int i;
	for(i=0;i<2;i++){
		printf("Digite o autor:");
		gets(livro[i].autor);
		printf("Digite o titulo:");
		gets(livro[i].titulo);
		printf("Digite o numero de paginas:");
		scanf("%d",&livro[i].numeroPaginas);
	}
}
void imprime(Livro *livro){
	int i;
	for(i=0;i<2;i++){
		printf("Titulo:%s\n",livro[i].titulo);
		printf("Autor:%s\n",livro[i].autor);
		printf("Numero de paginas:%d\n",livro[i].numeroPaginas);
		
	}
}
int main(){
	Livro *livro;
	livro=(Livro*)malloc(250*sizeof(Livro));
	if(livro==NULL){
		exit(1);
	}
	cadastro(livro);
	imprime(livro);
	return 0;
	
}
