//Nome completo: Igor Ribeiro de lima martins
// Matr�cula: UC21103937
 // Curso: Ci�ncias da Computa��o


#include<stdio.h> //Biblioteca para acrescentar Scanf e Printf.
#include<locale.h>//Biblioteca para permitir o uso de acentua��o e modificar a linguagem.
#include<string.h> //Biblioteca para utilizar string.
#include<stdlib.h> //Biblioteca para utilizar o algoritmo para limpar a tela.
#include<ctype.h> //Biblioteca Utilizar fun��es para convers�o de mai�sculas e min�sculas.
#include<stdbool.h> //Biblioteca para adicionar booleanos.

int main() {        //Inicio do codigo.
	setlocale(LC_ALL, "Portuguese"); // algoritmo que altera a linguagem do codigo.

	char* limparBuffer; //Utilizado para limpar o Buffer
	char nomeFilme[30], sexo[2];
	int sessao, pessoas, contador = 0, masculino = 0, feminino = 0, idade, crianca = 0, adolescente = 0, adulto = 0, idoso = 0, 
		masculinoMaior = 0, femininoMaior = 0;
	bool validacao = false;

	do {

		printf("Por favor digite a quantidade de sess�es?:  "); //Apresenta��o da pergunta na tela do usuario.
		scanf("%i", &sessao); // Recebe o dado do usuario.
		scanf("%c", &limparBuffer);

		if (sessao != 2) {
			printf("Quantidade invalida de sess�o! Tente novamente!\n"); //Caso seja invalido o dado utilizado pelo usuario.
		}

	} while (sessao != 2); // Repetir quando o dado for invalido.

	system("cls"); 

	do {

		printf("Digite o nome do filme que gostaria de assistir!.\n"); //Escolha de um filme feita pela o usuario.
		fflush(stdin); //Utilizado para limpar o "lixo" da memoria.
		fgets(nomeFilme, 30, stdin); // Recebe o nome do filme fornecido pelo usuario.
		strtok(nomeFilme, "\n"); // limpar o buffer do Fgets. 

		if (strlen(nomeFilme) == 30 - 1)  // Vai limpar caso usuario exceda a quantidade de letras.
		{
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF);

		}

		if (strcmp(nomeFilme, "") == 0) { //Vai validar o nome do filme do usuario.
			printf("Nome do filme invalido! Tente novamente outro nome por favor! \n");
		}

	} while (strcmp(nomeFilme, "") == 0); //Repetir  enquanto o nome do filme for invalido.

	system("cls");

	do {

		printf("Digite a quantidade de pessoas que assistiram o filme?:  \n"); //Pergunta feita ao usuario.
		scanf("%i", &pessoas); //Entrada  da resposta do usuario.
		scanf("%c", &limparBuffer); 

		if (pessoas < 10) {
			printf("Quantidade invalida de pessoas!! Tente novamente outro valorA!\n"); //Verifica se a resposta do usuario foi valida.
		}


	} while (pessoas < 10); //Repetir enquanto o usuario cometer o mesmo equivoco.

	system("cls");

	for (contador = 0; contador < pessoas; contador++) { //Estrutura de repeti��o que ir� realizar a quantidade de vezes que foi informado pelo usuario.
		
		while (validacao != true)
		{
			printf("Digite o sexo 'M'ou'F': \n"); //Pergunta feita ao usuario.
			fgets(sexo, 2, stdin); //Entrada do dado feita pelo usuario.
			strtok(sexo, "\n"); // limpar o buffer do Fgets. 

			if (strlen(sexo) == 1)  // Vai limpar caso usuario exceda a quantidade de letras.
			{
				char ch;
				while ((ch = getchar()) != '\n' && ch != EOF);

			}

			if (strcmp(sexo, "M") == 0 || strcmp(sexo, "m") == 0) { // Validar se o sexo � masculino.
				masculino++; //Variav�l para contabilizar a quantidade de pessoas do sexo masculino.
				validacao = true;
			}
			else if (strcmp(sexo, "F") == 0 || strcmp(sexo, "f") == 0) { //Validade se o sexo do usuario � feminino.
				feminino++; //Variav�l para contabilizar a quantidade de pessoas do sexo feminino.
				validacao = true;
			}
			else {
				printf("Op��o invalida, tente novamente outra op��o.\n"); //Nenhuma das op��es.
				validacao = false;
			}
		}
			
		system("cls");
		validacao = false;

		while (validacao != true)
		{
			printf("Digite sua idade!: \n"); //Pergunta feita ao usuario.
			scanf("%i", &idade);// Entrada do dado do usuario.
			scanf("%c", &limparBuffer); // Scanf para limpar o buffer.

			if ((idade >= 3) && (idade <= 13)) { //Validar se a idade entra nesta classifica��o.
				crianca++;  //Variav�l para contabilizar a quantidade de crian�as.
				validacao = true;
			}
			else if ((idade >= 14) && (idade <= 17)) {//Validar se a idade entra nesta classifica��o.
				adolescente++; //Variav�l para contabilizar a quantidade de adolescentes.
				validacao = true;


			}
			else if ((idade >= 18) && (idade <= 64)) {//Validar se a idade entra nesta classifica��o.
				adulto++; //Variav�l para contabilizar a quantidade de adultos.
				validacao = true;
			}
			else if ((idade >= 65) && (idade <= 100)) {//Validar se a idade entra nesta classifica��o.
				idoso++; //Variav�l para contabilizar a quantidade de idosos.
				validacao = true;
			}
			else if ((idade < 3) && (idade > 100)) {//Validar se a idade entra nesta classifica��o.
				printf("Numero de idade invalido, Por favor tente outro numero.\n");
				validacao = true;
			}


			if ((idade >= 18) && strcmp(sexo, "M") == 0) { // Validar se a pessoa � do sexo masculino e tamb�m � maior de idade.
				masculinoMaior++;
			}
			else if ((idade >= 18) && strcmp(sexo, "F") == 0) { // Validar se a pessoa � do sexo femino e tamb�m � maior de idade.
				femininoMaior++;
			}
			else if ((idade >= 18) && strcmp(sexo, "m") == 0) { // Validar se a pessoa � do sexo masculino e tamb�m � maior de idade.
				masculinoMaior++;
			}
			else if ((idade >= 18) && strcmp(sexo, "f") == 0) { // Validar se a pessoa � do sexo femino e tamb�m � maior de idade.
				femininoMaior++;
			}
		}
			
		system("cls");
		validacao = false;
	}


	system("cls");  //algoritmo utilizado para limpar a tela.
	printf("Filme: %s \n", nomeFilme); //Aqui o nome do filme � apresentado ao usuario.
	printf("Quantidade de pessoas do sexo Feminino que estavam presentes na sess�o: %i \n", feminino); // mostra quantidade de pessoas do sexo feminino que estavam na sess�o.
	printf("Quantidade de pessoas do sexo Masculino que estavam presentes na sess�o: %i \n", masculino); //Quantidade de pessoas do sexo masculino que estavam na sess�o.
	printf("Quantidade de criancas que assistiram ao filme: %i \n", crianca); //Quantidade de crian�as que estavam na sess�o.
	printf("Quantidade de adolescentes que assistiram ao filme: %i \n", adolescente); //Quantidade de adolescentes que estavam na sess�o. 
	printf("Quantidade de adultos que assistiram ao filme: %i \n", adulto); //Quantidade de adultos que estavam na sess�o.
	printf("Quantidade de idosos que assistiram ao filme: %i \n", idoso); //Quantidade de idosos que estavam na sess�o.
	printf("Quantidade de pessoas maiores de idade do sexo masculino que assistiram ao filme: %i \n", masculinoMaior); //Quantidade de pessoas do sexo masculino maiores de idade que estavam na sess�o.
	printf("Quantidade de pessoas maiores de idade do sexo feminino que assistiram ao filme: %i \n", femininoMaior); //Quantidade de  pessoas do sexo feminino maiores de idade que estavam na sess�o.



	return 0;  //Final do codigo
}
