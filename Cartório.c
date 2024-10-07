#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando irforma��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,",");//escreve dentro do aqruivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Cadastra o nome do usu�rio
	scanf("%s",nome);//refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,nome);//salva o nome do cliente
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Cadastra o sobrenome do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo 
	fprintf(file,sobrenome);//salva o srenome do usu�rio
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//cadastra o cargo do usu�rio
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,cargo);//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//inico da cria��o da consulta 
	 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//consultar o CPF 
	scanf("%s",cpf);//% refere-se a string
	
	FILE *file;//acessar o arquivo
	file = fopen(cpf,"r");//computador ler o arquivo "r" significa ler 
	
	if(file == NULL)//Se arquivo n�o for localizado 
	{
		printf("N�o foi possisvel abrir o arquivo, n�o localizado!.\n");// arquivo n�o localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//se o aqruivo for localizado
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//S�o as informa��es do usu�rio se for localizado
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n");//dar espa�o entre as palavras
	}
	
	system("pause");//pausar o sistema
	//fim da cria��o da consulta
		
}

int deletar()
{
	//inicio da cria��o deletar 
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//consultar o usu�rio que for deletar
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);//remover o arquivo desejado
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//computador ler o arquivo "r" siginifica ler
	
	if(file == NULL)//Se arquivo n�o for localizado
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");//arquivo n�o localizado
		fclose(file);
		system("pause");//pausar o sistema
	}

}

int main()
    
{
	int opcao=0; //Definindo as V�riaveis	
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
    	system("cls");
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu	
       printf("Escolha a op��o desejada do menu:\n\n");	
   	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar  Nomes\n"); 
	   printf("\t4 - sair do sistema\n\n");
	   printf("op��o:");//Fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	   system("cls");//respons�vel por limpar a tela
	   
	   
	   switch(opcao) // inicio da sele��o do menu
	   {
	      case 1:
	      registro();//chamada de fun��es
		  break;
		  
		  case 2:
		  consulta();
		  break;
		  
		  case 3:
		  deletar();
		  break;
		  
		  case 4:
		  printf("obrigado por utiliar o sistema!\n");
		  return 0;
		  break;	
		  
		  
		  default:
		  printf("Essa op��o n�o est� disponivel!\n");
		  system("pause");
		  break;
	
	   }//fim da sele��o do menu

   }
}
