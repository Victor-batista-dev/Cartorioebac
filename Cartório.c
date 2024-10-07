#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando irformação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,",");//escreve dentro do aqruivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Cadastra o nome do usuário
	scanf("%s",nome);//refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,nome);//salva o nome do cliente
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Cadastra o sobrenome do usuário
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo 
	fprintf(file,sobrenome);//salva o srenome do usuário
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,",");//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//cadastra o cargo do usuário
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file,cargo);//escreve dentro do arquivo
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//inico da criação da consulta 
	 
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//consultar o CPF 
	scanf("%s",cpf);//% refere-se a string
	
	FILE *file;//acessar o arquivo
	file = fopen(cpf,"r");//computador ler o arquivo "r" significa ler 
	
	if(file == NULL)//Se arquivo não for localizado 
	{
		printf("Não foi possisvel abrir o arquivo, não localizado!.\n");// arquivo não localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//se o aqruivo for localizado
	{
		printf("\nEssas são as informações do usuário: ");//São as informações do usuário se for localizado
		printf("%s", conteudo);//%s refere-se a string
		printf("\n\n");//dar espaço entre as palavras
	}
	
	system("pause");//pausar o sistema
	//fim da criação da consulta
		
}

int deletar()
{
	//inicio da criação deletar 
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");//consultar o usuário que for deletar
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);//remover o arquivo desejado
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//computador ler o arquivo "r" siginifica ler
	
	if(file == NULL)//Se arquivo não for localizado
	{
		printf("O usuário não se encontra no sistema!.\n");//arquivo não localizado
		fclose(file);
		system("pause");//pausar o sistema
	}

}

int main()
    
{
	int opcao=0; //Definindo as Váriaveis	
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
    	system("cls");
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cartório da EBAC ###\n\n"); //Inicio do menu	
       printf("Escolha a opção desejada do menu:\n\n");	
   	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar  Nomes\n"); 
	   printf("\t4 - sair do sistema\n\n");
	   printf("opção:");//Fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usuário
	
	   system("cls");//responsável por limpar a tela
	   
	   
	   switch(opcao) // inicio da seleção do menu
	   {
	      case 1:
	      registro();//chamada de funções
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
		  printf("Essa opção não está disponivel!\n");
		  system("pause");
		  break;
	
	   }//fim da seleção do menu

   }
}
