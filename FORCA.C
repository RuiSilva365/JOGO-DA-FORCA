
//LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <winuser.h>

//MACROS
#define WORD_SIZE 25
#define KEY "root"
#define USER_MAX 50

//GLOBAL VARIABLES


char PALAVRA_SECRETA[WORD_SIZE];
char CATEGORIA_SECRETA[WORD_SIZE];
int LEVEL=1;
int tentativas=1;
int linha=1;



typedef struct PALAVRA
{
	int id;
	char nome[40];
	char categoria[40];
	char dica[100];
}PALAVRA;

typedef struct USER
{
	char level[5];
	char nome[40];
}USER;


typedef struct ADMIN
{
	 char ID[15];
	char pass[15];
}ADMIN;

void PermissaoUtilizador()
{
	printf("\n\n-----------------------------------\n");
	system("pause");
	system("cls");

}

void LOG_Visual()
{
	printf("\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~        LOG   IN           ~\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	
	
}



void REG_Visual()
{
	printf("\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~        REGISTO           ~\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}



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
				printf("\t\t\t ___\n");
				printf("\t\t\t|   |\n");
				printf("\t\t\t|  ( )\n");
				printf("\t\t\t|  -|- \n");
				printf("\t\t\t| _/ \\_  \n");
				printf("\t\t\t|        \n");
				printf("\t\t\t|________\n");
				printf("\n\n");
	 		break;
	 		
	 	case 9:
	 			printf("\n\n");
				printf("\t\t\t\t ___\n");
				printf("\t\t\t\t|   |\n");
				printf("\t\t\t\t|  ( )\n");
				printf("\t\t\t\t|  -|- \n");
				printf("\t\t\t\t|  / \\ \n");
				printf("\t\t\t\t|\n");
				printf("\t\t\t\t|________\n");
	 }
}


//^^FIM ANIMAÇÕES^^


ADMIN list[USER_MAX]; //DEFINE UM ARRAY GLOBAL, TAMANHO DE USER_MAX

void writeToFile(ADMIN u)
{
    FILE *fw = fopen("admin.txt","a+");
    fprintf(fw,u.ID);
    fprintf(fw,"\t");
    fprintf(fw,u.pass);
    fprintf(fw,"\n");
    
    fclose(fw);
}


int exist(ADMIN u)
{
    int i;
    for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].ID ,u.ID) && 0==strcmp(list[i].pass,u.pass))
        {
            return 1;
        }
    }
    return -1;
}


void REGISTAR()
{
	char nome_pessoa[10];
    char name[10];
    char senha[10];
    char password[10];
    ADMIN admin;
    int i;
    
    REG_Visual();
    
    printf("\nIntroduza o seu nome: ");
    scanf("%s",nome_pessoa);
  
  	printf("\nIntroduza a chave de segurança:");
  	scanf("%s", senha);
  
  if(strcmp(KEY,senha)!=0)
  	{
  		system("COLOR 40");
  		printf("\n\t\t\a\a ALARME DE SEGURANÇA!");
  		printf("\n\tChave de segurança,não reconhecida");
  		printf("\n...A retornar ao menu Principal.");
		PermissaoUtilizador();
		MENUINICIAL();
  		
	}
  
    else
    {
	

    printf("Insira um ID, %s:",nome_pessoa);
    scanf("%s",name);
    strcpy(admin.ID , name);

    // determine whether there has been a registered user
    for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].ID ,name))
        {
            printf("UTILIZADOR JÁ EXISTENTE");
            sleep(2);
            
        }
    }

    printf("Introduza a password:");
    scanf("%s",password);
    strcpy(admin.pass , password);
    
    
    
    writeToFile(admin);
   }
}

ADMIN login()
{
    char name[10];
    char password[10];
    ADMIN lg;
    
    LOG_Visual();
    
    printf("Introduza o ID:");
    scanf("%s",name);
    strcpy(lg.ID , name);
    printf("Introduza a password:");
    scanf("%s",password);
    strcpy(lg.pass,password);
    return lg;
}



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



int contagemSCORE()
{
	int contadorSCORE=0;
	char c;
	USER user;
	
	FILE * fp_counter;
	fp_counter= fopen("SCORE.dat","rb");
	if(fp_counter==NULL)
	{
		fp_counter=fopen("SCORE.dat","wb+");
	}
	
	else
	{
		while(!feof(fp_counter))
			{
				fread(&user,sizeof (struct USER),1,fp_counter);	
				contadorSCORE++;
			}
	}
		
 	return contadorSCORE-1;
  fclose(fp_counter); 
	
}




void ListagemHighScore(struct USER **userSort,int cont)
{
	int i=0,j=0,k=0;
	USER *temp= (struct USER*) malloc (sizeof(USER));
	

	
	
	for(i=0;i<cont;++i)
	{
		for(j=i+1;j<cont;++j)
		 {
		 	if(strcmp((*userSort+i)->level,(*userSort+j)->level)<0)
		 		{
		 			strcpy(temp->nome,(*userSort+i)->nome);
		 			strcpy(temp->level,(*userSort+i)->level);
		 			
		 			strcpy((*userSort+i)->nome,(*userSort+j)->nome);
		 			strcpy((*userSort+i)->level,(*userSort+j)->level);
		 			
		 			strcpy((*userSort + j)->nome, temp->nome);
		 			strcpy((*userSort + j)->level, temp->level);
				}
		 }
	}
	
	
}


void MostrarScore()
{
		USER *user;
		FILE *ptrForReadFile;
		ptrForReadFile = fopen("SCORE.dat", "rb");
		const int contador= contagemSCORE();
		user=(struct USER *) malloc(contador * sizeof(USER));
		int i=0;
	//Verificação abertura ficheiro
	if (ptrForReadFile == NULL)
	{
		printf("\n\n-------------------------------------\nERRO!Sem registos para mostrar.");
		return;
	}
	
	else
	{
	
	
		while (i <=  contador - 1) // Enquanto ficheiro não terminar:
		{
			fread((user+ i), sizeof(struct USER), 1, ptrForReadFile);
			i++;
	
		}	
		
	ListagemHighScore(&user,contador);
	i=0;
	while (i <= contador - 1)
		{
			//printf barra principal
			printf("\t\t\t====================================================================\n");
			printf("\t\t\t|                       EXIBIÇÃO DOS HIGHSCORE                     |\n");
			printf("\t\t\t====================================================================\n");
			printf("\nNOME: %s", (user+ i)->nome);
			printf("\t\tNÍVEL-> %s", (user + i)->level);
			PermissaoUtilizador();
			i++;
		}
	}
	fclose(ptrForReadFile);

	  
}


void printWORDS()
{
	
	FILE * fp;
	fp=fopen("PALAVRAS.txt","r");
	const int num_palavras=contagemPALAVRAS();
	char PALAVRA[30];
	int i=0;
	
	for(i=0;i<num_palavras;i++)
		{
			fscanf(fp, "%s", PALAVRA);
			printf("\n%s",PALAVRA);
		}
	
	fclose(fp);
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


void WrittingDataSCORE()
{
	FILE * fp_SCORE;
	USER  user;
	char nome[30];
	int * fp=NULL;
	fp=&LEVEL;
	
	fp_SCORE= fopen("SCORE.dat","ab");
	
	 if(fp_SCORE==NULL)
	  {
	  	fp_SCORE= fopen("SCORE.dat","wb");
	  }
	  
	fflush(stdin);
	printf("\nIntroduza o seu username:");
	fgets(user.nome,30,stdin);

	 itoa(*fp,user.level,10);
	
	fwrite(&user,sizeof (struct USER),1,fp_SCORE);
	
	

	fclose(fp_SCORE);
	
	printf("\n\n-----------------------------------\nUser adicionado com sucesso.");	
	sleep(2);
	
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
	printf("\n\t\t\t\t");
	puts(strupr(CATEGORIA_SECRETA));
	AnimacaoIG(9);
	printf("\n\n\n\t\t\t\t");
	for(i=0;i<strlen(PALAVRA_SECRETA);i++)
		{
			printf(" _");
			
		}
		
	printf("\n\n\n");
}



void JOGO()
{
	char c;
	int tentativas;
	int vidas=3;
	int i=0,k=0,m=0,n=0;
	int check,check2=0;
	int num_ok=0;
	int resto=0;
	
	  ReadingRandomData();
	  
	char *string=(char *) malloc(sizeof(tentativas));
	char *palavra=(char *) malloc(sizeof(strlen(PALAVRA_SECRETA)));
	
	 Ocultar();
	 printf("\n A palavra é composta por %i letras. Boa Sorte.\n", strlen(PALAVRA_SECRETA));
	 PermissaoUtilizador();
	 
	
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
	
		

	
			while(check2==1 || c==0x0A)
			{
				c=getchar();
				check2=0;
				
				for(m=0;m<2 *tentativas;m++) //2 * por causa dos espaços 
				
				{
					if(string[m]==c) 
					 {
					 	printf("\nCarater já introduzido. TENTE OUTRA VEZ.\n");
					 	check2=1;
					 	c=getchar();
					 }
						 
				}
				
				
				
			}
		
		
			
		tentativas++;
		
		
		strncat(string,&c,1);
		strncat(string," ",1);

		
		int m=0;
		check=0;
		for(m=0;m<strlen(PALAVRA_SECRETA);m++)
		{
			if(PALAVRA_SECRETA[m]==c)
			{
				 palavra[m]=c;
				 num_ok++;
		 	     check=1;
			}
			
			
		}	
	
		resto=strlen(PALAVRA_SECRETA) - num_ok;
		
			 

		if(check==1)
		{
			printf("\nCORRETO! A PALAVRA SECRETA  CONTÉM A LETRA %c",c);
			 printf("\nCONSTRUÇÃO:%s\t\t\tCarateres inseridos:%s\nNº letras restantes:%i\t\tVIDAS--->%i\n",palavra,string,resto,vidas);
		}	
	
	 	 if(check==0)
		{
			vidas--;
			 printf("\nINCORRETO! A PALAVRA SECRETA NÃO CONTÉM A LETRA %c",c);
			 printf("\nCONSTRUÇÃO:%s\t\t\tCarateres inseridos:%s\nNº letras restantes:%i\t\tVIDAS--->%i\n",palavra,string,resto,vidas);
		}
		
			else if(strcmp(palavra,PALAVRA_SECRETA)==0)
			{
				system("cls");
				system("COLOR 20");
			printf("\n _______  _______  _                 _______          ");
			printf("\n(  ____ \\(  ___  )( (    /||\\     /|(  ___  )|\\     /|");
			printf("\n| (    \\/| (   ) ||  \\  ( || )   ( || (   ) || )   ( |");
			printf("\n| |      | (___) ||   \\ | || (___) || |   | || |   | |");
			printf("\n| | ____ |  ___  || (\\ \\) ||  ___  || |   | || |   | |");
			printf("\n| | \\_  )| (   ) || | \\   || (   ) || |   | || |   | |");
			printf("\n| (___) || )   ( || )  \\  || )   ( || (___) || (___) |");
			printf("\n(_______)|/     \\||/    )_)|/     \\|(_______)(_______)");
			LEVEL++;
			printf("\n\t\t\t\tNÍVEL-->%i\n",LEVEL);
			PermissaoUtilizador();
			MENUINICIAL();
			
			}
		
	 
		}
	system("cls");
	system("COLOR 40");
	printf("\n _______  _______  _______  ______   _______          ");
	printf("\n(  ____ )(  ____ \\(  ____ )(  __  \\ (  ____ \\|\\     /|");
	printf("\n| (    )|| (    \\/| (    )|| (  \\  )| (    \\/| )   ( |");
	printf("\n| (____)|| (__    | (____)|| |   ) || (__    | |   | |");
	printf("\n|  _____)|  __)   |     __)| |   | ||  __)   | |   | |");
	printf("\n| (      | (      | (\\ (   | |   ) || (      | |   | |");
	printf("\n| )      | (____/\\| ) \\ \\__| (__/  )| (____/\\| (___) |");
	printf("\n|/       (_______/|/   \\__/(______/ (_______/(_______)");
	printf("\n");
	printf("\n\t\t\t\tNÍVEL-->%i\n",LEVEL);
	AnimacaoIG(vidas);
	PermissaoUtilizador();
	MENUINICIAL();
	}
	 
	 
	 
	 
int MENU_RECONHECIMENTO()
{
	int opc_1;
	
	system("cls");
	printf("\n");
	printf("\nIntroduza a opção pretendida: \n");
	printf("1-LOGIN\n");
	printf("2-REGISTAR\n");
	printf("0-SAIR\n");
	do
	{
		scanf("%i", &opc_1);
	
	}while(opc_1>=3);
	
	return opc_1;
}

 

void ACESSO()
{
	
	ADMIN test[USER_MAX];
    FILE *fp = fopen("admin.txt","r");
    int i=0;
    ADMIN u;
    if(fp==NULL)
    {
      	REGISTAR();
    }
    for(i=0; i<USER_MAX; i++)
    {
        char uname[10];
        char upassword[10];
        fscanf(fp,"%s%s",uname,upassword);

        strcpy(list[i].ID , uname);
        strcpy(list[i].pass , upassword);
    }

    int choice =MENU_RECONHECIMENTO();
    if(1 == choice)
    {
        system("cls");
        u=login();
        if(1 == exist(u))
        {
        	system("COLOR 20"),
            printf("Login Bem Sucedido\n\n");
            PermissaoUtilizador();
            MENU_ADMIN();
        }
        else
        {
        	system("COLOR 40");
            printf("Dados errados!\nA voltar ao Menu Principal");
            PermissaoUtilizador();
            MENUINICIAL();
        }

    }
    else if(2 == choice)
    {
        system("cls");
        REGISTAR();
    }
	
}





void apagarPALAVRA()
{
	
}

int MENU_ADMIN()
{
	int opc_2;
	
	
	printf("\n");
	printf("Introduza a opção pretendida:\n");
	printf("1.Verificar Registos Palavras\n");
	printf("2.Introduzir nova palavra\n");
	printf("3.Voltar ao Menu Inicial\n");
	printf("0.SAIR\n");
	
	do
	{
	
		scanf("%d", &opc_2);

	
	switch(opc_2)
	{
		case 1:
			system ("cls");
			printWORDS();
			PermissaoUtilizador();
			MENU_ADMIN();
			break;
		case 2:
			WrittingDataWORD();
			WrittingDataCAT();
			MENU_ADMIN();
			break;
		case 3:
			MENUINICIAL();
			break;
		case 0:
			return 0;
			break;
	default: 	
		printf("\nOpção não reconhecida, tente outra vez.\n");
		break;
	}
	
	}while (opc_2>4);
	
}

 
int MENUINICIAL()
{
		system("COLOR 09");
		system("cls");
		
	int opc_1;
	int counter, counter_1;
	USER *user;
	
	counter= contagemPALAVRAS();
	counter_1=contagemSCORE();
		AnimacaoPrincipal();
	printf("\nTotal de palavras: %i",counter);
	printf("\n\n");
	printf("Selecione a sua opção:");
	printf("\n1-JOGAR");
	printf("\n2-Verificar Lista de HIGHSCORE");
	printf("\n3-Secção ADMIN");
	printf("\n0-SAIR");
	printf("\nOpção pretendida->");
	do{
		scanf("%i", &opc_1);
		
		
	switch(opc_1)
		{
			case 1:	
					JOGO();	
				break;
			case 2:
				MostrarScore();
				break;
			case 3:
				ACESSO();
				break;
			case 0:
				WrittingDataSCORE();
				system("cls");
				printf("\nVamos sentir a tua falta!");
				sleep(2);
				return 0;
				break;
			default: printf("Opção não reconhecida,volte a tentar");
		}
	}while(opc_1>4);
}



int main() 
{
 	 int num1;
	system("COLOR 09");
	setlocale(LC_ALL,"Portuguese");
	MENUINICIAL();


	
	return 0;
}


