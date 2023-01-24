#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() // função responsavel por cadastrar usuarios
{
	//inicio criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final criação de variáveis/string
	
	printf ("Digite o CPF a ser cadastrado: "); //coletando informações do usuario
	scanf("%s", cpf); // salvando resposta do usuario
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados 
	file = fopen(arquivo, "w");  // o "w" significa escrever no arquivo
	fprintf(file,cpf); //Escrever o nome do arquivo como CPF
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo,"a");//Solicitando ao computador escrever uma virgula entre as informações
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("Pause");
	
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// r de read
	
	if(file == NULL)
	fclose(file);
{
	printf("Não foi localizado. \n");
}
	
	while(fgets(conteudo,200, file) != NULL)//esse eu nao entendo
{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
}
	
	system("pause");
	
	
	
}

int deleta()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//r de read
	
	if(file== NULL)
	{
		printf(" Usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}





int main () //Definindo variáveis
{
    int opcao=0; // Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;) // Definindo repetição
{

     system("cls");
     
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf(" Cartório da EBAC \n\n"); //Início do Menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf ("\t2 - Consultar nomes\n");
	printf ("\t3 - Deletar nomes\n\n"); 
	printf ("Opção: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando informações
	
	system("cls"); // responsavel por limpar a tela
	
	switch(opcao) //inicio da seleção do menu
{
	    case 1:
	    registro (); //chama de funções
     	break;
     	
     	case 2:
     	consulta ();
     	break;
     	
     	case 3:
     	deleta();
     	break;
     	
     	default:
     	printf("Essa opção não está disponível!\n");
     	system("pause");
	    break;
	}
	
	
	 
	 
}	 
}

