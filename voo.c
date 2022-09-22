#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sVoo{
	char origem[11];
	char destino[11];
	int vagasTotal;
	int vagasPreenchidas;
	
}Voo;
typedef struct sPassageiro{
	char cpf[15];
	char nome[15];
}Passageiro;
typedef struct sVenda{
	int idVoo;
	int idPassageiro;
	int status;
}Venda;
void encontraCPF(Voo *voo,Passageiro *passageiro,Venda *venda,int nVoo,int nPassageiro,int nVenda,char *cpf){
	int i;
	int conta=0;
	Passageiro p;
	Voo v;
	for(i=0;i<=nVenda;i++){
		
		p=passageiro[venda[i].idPassageiro];
		v=voo[venda[i].idVoo];
		if(!strcmp(cpf,p.cpf)){
			printf("Voo de: %s\nAte: %s\n",v.origem,v.destino);
			printf("---------------\n");
			conta++;
		}
		
	}
	if(conta==0){
		printf("Nao existem voo's para o CPF!!!");
		printf("---------------\n");
	}
	
	
}
int realizaVenda(Voo *voo,Passageiro *passageiro,Venda *venda,int nVoo,int nPassageiro,int nVenda,int idPassageiro,int idVoo){
	
	
	nVenda++;
	
	if((idVoo-1)>nVoo){
		printf("Voo Invalido!!!");
		return 0;
	}
	if(voo[idVoo-1].vagasPreenchidas+1>voo[idVoo-1].vagasTotal){
		printf("Não ha vagas!!!");
		return 0;
	}
	venda[nVenda].idVoo=idVoo-1;
	venda[nVenda].idPassageiro=idPassageiro;
	venda[nVenda].status=1;
	voo[idVoo-1].vagasPreenchidas++;
	return 1;
	
}

void infoVoo(Voo *voo,int nVoo){
	int i;
	for(i=0;i<=nVoo;i++){
		printf("Voo %d:\n",i+1);
		printf("Origem: %s -> Destino: %s\n",voo[i].origem,voo[i].destino);
		printf("Poltronas Livres: %d\n",(voo[i].vagasTotal-voo[i].vagasPreenchidas));
		printf("---------------\n\n");
	}
	
}
void infoVooPassageiro(Voo *voo,Passageiro *passageiro,Venda *venda,int nVoo,int nPassageiro,int nVenda,int idVoo){
	Passageiro p;
	int i;
	if((idVoo-1)>nVoo){
		printf("Voo Invalido!!!");
		return;
	}
	
	printf("Voo %d:\n",idVoo);
	printf("Origem: %s -> Destino: %s\n",voo[idVoo-1].origem,voo[idVoo-1].destino);
	printf("Poltronas Livres: %d\n",(voo[idVoo-1].vagasTotal-voo[idVoo-1].vagasPreenchidas));
	
	printf("---------------\n\n");
	
	for(i=0;i<=nVenda;i++){
		p=passageiro[venda[i].idPassageiro];
		if(venda[i].status==1&&venda[i].idVoo==(idVoo-1)){
			printf("\tCPF %s:\n",p.cpf);
			printf("\tNome: %s\n",p.nome);
			printf("\t---------------\n\n");
		}
	}
	
	
}
void cancelaBilhete(Voo *voo,Passageiro *passageiro,Venda *venda,int nVoo,int nPassageiro,int nVenda,char *cpf){
	int i;
	int conta=0;
	Passageiro p;
	
	for(i=0;i<=nVenda;i++){
		
		p=passageiro[venda[i].idPassageiro];
		
		if(!strcmp(cpf,p.cpf)){
			venda[i].status=0;
			voo[venda[i].idVoo].vagasPreenchidas--;
			conta++;
		}
		
	}
	if(conta==0){
		printf("Nao existem voo's para o CPF!!!");
		printf("---------------\n");
	}
}
void menu(){
	printf("##### COMPANHIA AEREA #####\n");
	printf("Menu de Opcoes:\n");
	printf("0 - Cadastrar um novo Voo\n"
		   "1 - Visualizar Informacoes de Voos\n"
		   "2 - Realizar Vendas de Bilhetes\n"
		   "3 - Consultas Bilhetes Vendidos\n"
		   "4 - Cancelar Bilhetes\n"
		   "5 - Relatorio de Passageiros por Voo\n"
		   "6 - Encerrar o Sistema\n"
		  );
}
int main(){
	int op;
	int idVoo;
	char cpf[15];
	int nVoo=-1,nPassageiros=-1,nVendas=-1;
	Voo *voo;
	Passageiro *passageiro;
	Venda *venda;

	do{
		menu();
		printf("Digite a opcao:");
		scanf("%d",&op);
		switch(op){
			case 0:
				if(nVoo!=-1){
					voo=(Voo*) realloc(voo,(nVoo+2)*sizeof(Voo));
				}else{
					voo=(Voo*) malloc(sizeof(Voo));
				}
				if(voo==NULL){
					printf("Erro ao alocar memoria");
					exit(1);
				}
				nVoo++;
				printf("Origem do Voo:");
				scanf("%s",voo[nVoo].origem);
				printf("Destino do Voo:");
				scanf("%s",voo[nVoo].destino);
				printf("Vagas:");
				scanf("%d",&voo[nVoo].vagasTotal);
				voo[nVoo].vagasPreenchidas=0;
				break;
			case 1:
				infoVoo(voo,nVoo);
				break;
			case 2:
				if(nPassageiros!=-1){
					passageiro=(Passageiro*) realloc(passageiro,(nPassageiros+2)*sizeof(Passageiro));
				}else{
					passageiro=(Passageiro*) malloc(sizeof(Passageiro));
				}
				if(passageiro==NULL){
					printf("Erro ao alocar memoria");
					exit(1);
				}
				if(nVendas!=-1){
					venda=(Venda*) realloc(venda,(nVendas+2)*sizeof(Venda));
				}else{
					venda=(Venda*) malloc(sizeof(Venda));
				}
				if(venda==NULL){
					printf("Erro ao alocar memoria");
					exit(1);
				}
				nPassageiros++;
				printf("Nome: ");
				scanf("%s",passageiro[nPassageiros].nome);
				printf("CPF: ");
				fflush(stdin);
				scanf("%s",passageiro[nPassageiros].cpf);
				printf("Digite o id do Voo: ");
				scanf("%d",&idVoo);
				if(realizaVenda(voo,passageiro,venda,nVoo,nPassageiros,nVendas,nPassageiros,idVoo)){
					nVendas++;
				}
				break;
			case 3:
				printf("CPF: ");
				scanf("%s",cpf);
				encontraCPF(voo,passageiro,venda,nVoo,nPassageiros,nVendas,cpf);
				break;
			case 4:
				printf("CPF: ");
				scanf("%s",cpf);
				cancelaBilhete(voo,passageiro,venda,nVoo,nPassageiros,nVendas,cpf);
				break;
			case 5:
				printf("Id Voo: ");
				scanf("%d",&idVoo);
				infoVooPassageiro(voo,passageiro,venda,nVoo,nPassageiros,nVendas,idVoo);
				
				break;

		}
		/*#ifdef __linux__ 
			system("clear");
		#elif _WIN32
			system("cls");
		#else
			system("cls");
		#endif*/
	}while(op!=6);
	
	
	return 0;

}
