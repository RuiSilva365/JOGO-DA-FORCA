//LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

//MACROS
#define WORD_SIZE 25

//GLOBAL VARIABLES


char PALAVRA_SECRETA[WORD_SIZE];
char CATEGORIA_SECRETA[WORD_SIZE];
int LEVEL=1;
int tentativas=1;




typedef struct PALAVRA
{
	char nome[40];
	char categoria[40];
}PALAVRA;


//INICIO ANIMAÇÕES
void AnimacaoPrincipal()
{
	printf(" _____________________________________             ___\n"); 
	printf("|                                    |            |   |\n");
	printf("|       JOGO                         |            |  ( )  \n");
	printf("|             DA                     |            |  -|-\n");
	printf("|                 FORCA              |            | _/ \\_  \n");
	printf("|                       EXTREME      |          __|_____\n");
    printf("|____________________________________|\n");
	
}

void AnimacaoIG(int alive)
{      
	switch(alive)
	 {
	 
	 	case 4:
	 			printf("\n\n");
				printf("\t ___\n");
				printf("\t|   |\n");
				printf("\t|  ( )\n");
				printf("\t|    \n");
				printf("\t|\n");
				printf("\t|\n");
				printf("\t|________\n");
	
	 		break;
	 	case 3:
	 			printf("\n\n");
				printf("\t ___\n");
				printf("\t|   |\n");
				printf("\t|  ( )\n");
				printf("\t|   |    \n");
				printf("\t|\n");
				printf("\t|\n");
				printf("\t|________\n");
	 		break;
	 	case 2:
	 			printf("\n\n");
				printf("\t ___\n");
				printf("\t|   |\n");
				printf("\t|  ( )\n");
				printf("\t|  -|- \n");
				printf("\t|\n");
				printf("\t|\n");
				printf("\t|________\n");
	
	 		break;
	 	case 1:
	 			printf("\n\n");
				printf("\t ___\n");
				printf("\t|   |\n");
				printf("\t|  ( )\n");
				printf("\t|  -|- \n");
				printf("\t|  / \\ \n");
				printf("\t|\n");
				printf("\t|________\n");
	
	 		
	 		break;
	 	case 0:
	 			printf("\n\n");
				printf("\t ___\n");
				printf("\t|   |\n");
				printf("\t|  ( )\n");
				printf("\t|  -|- \n");
				printf("\t| _/ \\_  \n");
				printf("\t|        \n");
				printf("\t|________\n");
				printf("\n\n");
	 			printf("\n\tP-E-R-D-E-S-T-E!!!!");
	 		break;
	 }
}


//^^FIM ANIMAÇÕES^^

//inicio FUções de ficheiros


int contagemPALAVRAS()
{
	int contadorPalavras=0;
	char c;
	PALAVRA palavra;
	
	FILE * fp_counter;
	fp_counter= fopen("PALAVRAS.txt","r");
	if(fp_counter==NULL)
	{
		printf("\nSem palavras na base da dados.\n");
	}
	
	for(c= getc(fp_counter); c !=EOF;c= getc(fp_counter))
		if(c=='\n') contadorPalavras= contadorPalavras +1;
		
 return contadorPalavras;
  fclose(fp_counter); 
	
}


void WrittingDataWORD()
{
	
	FILE * fp_WORD;
	PALAVRA palavra;
	
	fp_WORD= fopen("PALAVRAS.txt","a");
	
	 if(fp_WORD==NULL)
	  {
	  	fp_WORD= fopen("PALAVRAS.txt","w");
	  }
	  
	fflush(stdin);
	printf("\nIntroduza a palavra a adicionar ao jogo:");
	gets(palavra.nome);
	
	fprintf(fp_WORD,palavra.nome);
	fprintf(fp_WORD,"\n");
	

	
	
	
	
	fclose(fp_WORD);

}


void WrittingDataCAT()
{
	
	FILE * fp_CAT;
	PALAVRA palavra;
	
	fp_CAT= fopen("CAT.txt","a");
	
	 if(fp_CAT==NULL)
	  {
	  	fp_CAT= fopen("CAT.txt","w");
	  }
	  
	fflush(stdin);
	printf("\nIntroduza a categoria da palavra:");
	gets(palavra.categoria);
	
	fprintf(fp_CAT,palavra.categoria);
	fprintf(fp_CAT,"\n");
	
	
	
	
	fclose(fp_CAT);
	
	MENUINICIAL();
}

int Aleatorio()
{
	int contador=0;
	int r=0;
		contador= contagemPALAVRAS();
	srand(time(0));
	r = (rand() % (contador) + 1);
	
	return r;
}

void ReadingRandomData()
{

	int i=0,k=0;
	int contador,random=0;
	int contadorLinhas=0;
	int ch;
	char linha[100];
	
	PALAVRA palavra;
	

	FILE * fp_LeituraP;
	FILE * fp_LeituraC;
	
		
	fp_LeituraP= fopen("PALAVRAS.txt","r");
	
	fp_LeituraC= fopen("CAT.txt","r");
	
	if(fp_LeituraP == NULL || fp_LeituraC==NULL)
	{
		printf("\nSem Dados disponíveis. Volte a tentar mais tarde.");
		MENUINICIAL();
	}
	
	
	random=Aleatorio();

	

for (i = 0; i < random; i++)
 {
 	
  fscanf(fp_LeituraP, "%s", PALAVRA_SECRETA);
  
 }

for (k = 0; k < random; k++)
 {
  fgets(CATEGORIA_SECRETA, 100, fp_LeituraC);
  
 }
 
fclose(fp_LeituraP);
fclose(fp_LeituraC);
 
 
}
	

void Ocultar()
{
	
	
	int i=0;
	system("cls");
	printf("\n\t\t%s",CATEGORIA_SECRETA);
	AnimacaoIG(1);
	printf("\n\t\t");
	
	
	for(i=0;i<strlen(PALAVRA_SECRETA);i++)
		{
			printf(" _");
			
		}
		sleep(2);
}




void JOGO()
{
	char c;
	int tentativas;
	int vidas=3;
	int i=0,k=0,m=0,n=0;
	int check,check2=0;
	
	  ReadingRandomData();
	char *string=(char *) malloc(sizeof(tentativas));
	char *palavra=(char *) malloc(sizeof(strlen(PALAVRA_SECRETA)));
	
	 Ocultar();
	 printf("\n A palavra é composta por %i letras. Boa Sorte.\n", strlen(PALAVRA_SECRETA));
	
	
		for(k=0;k<strlen(PALAVRA_SECRETA);k++)
			 {
			 	palavra[k]='_';
			 }	
	
	 while(vidas!=0)	
	  {
	 
  
		AnimacaoIG(vidas);
		check2=1;
		
		printf("\nIntroduza a letra:");
		check2=1;
		fflush(stdin);
		if(tentativas==0) 
		{
			c=getchar();
		}
		
	
		
		else
		{
			while(check2==1)
			{
				c=getchar();
				
				for(m=0;m<tentativas;m++)
				{
					if(string[m]==c) 
					 {
					 	printf("\nCarater já introduzido. TENTE OUTRA VEZ.\n");
					 	check2=1;
					 }
					 
					 else
					check2=0;  
					 
				}
			}
		}
		
			
		tentativas++;
		
		
		strncat(string,&c,1);

		
		int m=0;
		check=0;
		for(m=0;m<strlen(PALAVRA_SECRETA);m++)
		{
			if(PALAVRA_SECRETA[m]==c)
			{
				 palavra[m]=c;
		 	     check=1;
			}
			
			
		}	
	
	
			 

		if(check==1)
		{
			 printf("\nCORRETO! A PALAVRA SECRETA CONTÉM A LETRA %c\nCONSTRUÇÃO:%s\nLETRAS:%s\n", c,palavra,string);
		}	
	
	 	 if(check==0)
		{
			printf("\nINCORRETO! A PALAVRA SECRETA NÃO CONTÉM A LETRA %c",c);
			vidas--;
			printf("\nVidas: %i\nConstrução:%s;\nTOTAL \nLETRAS:%s",vidas,palavra,string);
		}
	
			else if(strcmp(palavra,PALAVRA_SECRETA)==0)
			{
				system("cls");
			printf("\n _______  _______  _                 _______          ");
			printf("\n(  ____ \\(  ___  )( (    /||\\     /|(  ___  )|\\     /|");
			printf("\n| (    \\/| (   ) ||  \\  ( || )   ( || (   ) || )   ( |");
			printf("\n| |      | (___) ||   \\ | || (___) || |   | || |   | |");
			printf("\n| | ____ |  ___  || (\\ \\) ||  ___  || |   | || |   | |");
			printf("\n| | \\_  )| (   ) || | \\   || (   ) || |   | || |   | |");
			printf("\n| (___) || )   ( || )  \\  || )   ( || (___) || (___) |");
			printf("\n(_______)|/     \\||/    )_)|/     \\|(_______)(_______)");
			printf("\n\t\t\t\tNÍVEL-->%i\n",LEVEL);
			LEVEL++;
			sleep(3);
			MENUINICIAL();
			}
			
	 }

	system("cls");
	printf("\n _______  _______  _______  ______   _______          ");
	printf("\n(  ____ )(  ____ \\(  ____ )(  __  \\ (  ____ \\|\\     /|");
	printf("\n| (    )|| (    \\/| (    )|| (  \\  )| (    \\/| )   ( |");
	printf("\n| (____)|| (__    | (____)|| |   ) || (__    | |   | |");
	printf("\n|  _____)|  __)   |     __)| |   | ||  __)   | |   | |");
	printf("\n| (      | (      | (\\ (   | |   ) || (      | |   | |");
	printf("\n| )      | (____/\\| ) \\ \\__| (__/  )| (____/\\| (___) |");
	printf("\n|/       (_______/|/   \\__/(______/ (_______/(_______)");
	printf("\n");
}
	 





 
int MENUINICIAL()
{
	int opc_1;
	int counter;
	
	counter= contagemPALAVRAS();

	printf("\nTotal de palavras: %i",counter);
	printf("\n\n");
	printf("Selecione a sua opção:");
	printf("\n1-JOGAR");
	printf("\n2-Adicionar Palavra");
	printf("\n3-Verificar Lista de Palavras[ADMIN]");
	printf("\n4-SAIR");
	printf("\nOpção pretendida ->");
	do{
		scanf("%i", &opc_1);
		
		
	switch(opc_1)
		{
			case 1:	
					JOGO();	
				break;
			case 2:
				WrittingDataWORD();
				WrittingDataCAT();
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				printf("\nVamos sentir a tua falta!");
				return 0;
				break;
			default: printf("Opção não reconhecida,volte a tentar");
		}
	}while(opc_1>4);
}



int main() 
{
 	 int num1;
 	 MessageBox(NULL,"Preparado para jogar?","Entrando no jogo",MB_YESNO);

	AnimacaoPrincipal();
	setlocale(LC_ALL,"Portuguese");
	system("COLOR 09");
	MENUINICIAL();


	
	return 0;
}





