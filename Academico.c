#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Academico.h"


/*
 * Funções associadas a cada ítem do menú principal
 * Tem como finalidade a separação das funções procurando manter tudo organizado 
 */

void Sair(int *TamanhoAluno, CadastroAluno *Aluno, int *MatriculaAluno, int *TamanhoDisciplina, CadastroDisciplina *Disciplina, int *TamanhoMatricula, CadastroMatricula *Matricula){
	// Salva as informações da struct CadastroAluno para o arquivo CadastroAluno.txt
	FILE *FileAluno = fopen("Dados/CadastroAluno.txt", "w");
	
	if (FileAluno == 0) {
	printf("Erro: nao foi possivel abrir arquivo!");
		return;
	}

	fprintf(FileAluno,"%d\n%d\n", *TamanhoAluno, *MatriculaAluno);

	int i;
	for (i = 0; i < *TamanhoAluno; i++)
		fprintf(FileAluno, "%d\n%s\n%d\n%s\n", Aluno[i].Matri, Aluno[i].Nome, Aluno[i].Idade, Aluno[i].Email);

	fclose(FileAluno);
	
	
	// Salva as informações da struct CadastroDisciplina para o arquivo CadastroDisciplina.txt
	FILE *FileDisciplina = fopen("Dados/CadastroDisciplina.txt", "w");
	
	if (FileDisciplina == 0) {
	printf("Erro: nao foi possivel abrir arquivo!");
		return;
	}

	fprintf(FileDisciplina,"%d\n", *TamanhoDisciplina);

	for (i = 0; i < *TamanhoDisciplina; i++)
		fprintf(FileDisciplina, "%s\n%s\n%s\n%d\n", Disciplina[i].Nome, Disciplina[i].Codigo, Disciplina[i].Professor, Disciplina[i].CargaHoraria);

	fclose(FileDisciplina);
	
	
	// Salva as informações da struct CadastroMatricula para o arquivo CadastroMatricula.txt
	FILE *FileMatricula = fopen("Dados/CadastroMatricula.txt", "w");
	
	if (FileMatricula == 0) {
	printf("Erro: nao foi possivel abrir arquivo!");
		return;
	}

	fprintf(FileMatricula,"%d\n", *TamanhoMatricula);

	for (i = 0; i < *TamanhoMatricula; i++)
		fprintf(FileMatricula, "%s\n%s\n%d\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%s\n%d\n%s\n%s\n", Matricula[i].CodigoDisciplina, 
		Matricula[i].NomeDisciplina, Matricula[i].MatriculaAluno, Matricula[i].Nota[0], Matricula[i].Nota[1], Matricula[i].Nota[2], 
		Matricula[i].Nota[3], Matricula[i].Nota[4], Matricula[i].Media , Matricula[i].Semestre, Matricula[i].Faltas, Matricula[i].Situacao, 
		Matricula[i].Motivo);

	fclose(FileMatricula);
} 


void Relatorio(int quantidade, int *TamanhoMatricula, CadastroMatricula *matricula, int *TamanhoAluno, CadastroAluno *aluno){
	int i, j, OpcaoAssociacao = 0, OpcaoPesquisa = 0, MatriculaDoAluno, Encontrou = 0;
	char NomeDoAluno[101], CodigoDaDisciplina[11];
	
	while(quantidade == 1){
		
		printf("Escolha a opção do relatório\n1 - Por aluno\t2 - Por disciplina\n");
		scanf("%d", &OpcaoPesquisa);
		
		if(OpcaoPesquisa == 1){
			printf("Digite a matrícula do aluno: ");
			scanf("%d", &MatriculaDoAluno);
			
			for(i = 0; i < *TamanhoMatricula; ++ i){
				if(matricula[i].MatriculaAluno == MatriculaDoAluno){
					
					for(j = 0; j <= *TamanhoAluno; ++ j){
						if(MatriculaDoAluno == aluno[j].Matri)	strcpy(NomeDoAluno, aluno[j].Nome);
					}
					
					printf("Nome:\t%s\nDisciplina:\t%s\nSemestre:\t%s\nMedia:\t%.2f\nFaltas em horas:\t%d\nSituação:\t%s\nMotivo:\t%s\n\n\n", 
					NomeDoAluno, matricula[i].NomeDisciplina, matricula[i].Semestre, matricula[i].Media, matricula[i].Faltas,
					matricula[i].Situacao, matricula[i].Motivo);
					Encontrou = 1;
				}
			}
		}
		
		
		else if(OpcaoPesquisa == 2){
			printf("Digite o código da disciplina: ");
			scanf(" %10[^\n]", CodigoDaDisciplina);
			
			for(i = 0; i < *TamanhoMatricula; ++ i){
				if(strcmp(matricula[i].CodigoDisciplina, CodigoDaDisciplina) == 0){
					for(j = 0; j <= *TamanhoAluno; ++ j){
						if(matricula[i].MatriculaAluno == aluno[j].Matri)	strcpy(NomeDoAluno, aluno[j].Nome);
					}
					
					printf("Nome:\t%s\nDisciplina:\t%s\nSemestre:\t%s\nMedia:\t%.2f\nFaltas em horas:\t%d\nSituação:\t%s\nMotivo:\t%s\n\n\n", 
					NomeDoAluno, matricula[i].NomeDisciplina, matricula[i].Semestre, matricula[i].Media, matricula[i].Faltas,
					matricula[i].Situacao, matricula[i].Motivo);
					Encontrou = 1;
				}
			}
		}
		
		else	printf("Opção inválida! Tente novamente.\n");
		
		if(Encontrou == 0)	printf("Nenhum dado encontrado para essa pesquisa, tente novamente.\n");
		
		printf("Deseja ver o relatório de outro aluno agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &OpcaoAssociacao);
		
		if(OpcaoAssociacao != 1)	quantidade = 0;
		OpcaoPesquisa = Encontrou = 0;
	}
	
	
	system("cls || clear");
	return;
}

CadastroMatricula* LancarNotas(int quantidade, int *TamanhoMatricula, CadastroMatricula *matricula, int *TamanhoAluno, CadastroAluno *aluno, int *TamanhoDisciplina, CadastroDisciplina *disciplina){
	char CodigoDaDisciplina[11], NomeDaDisciplina[101], NomeDoAluno[101], OpcaoSemestre[16];
	int i, MatriculaDoAluno, OpcaoContinuarNota = 1, OpcaoAssociacao = 0, OpcaoConfirmacao = 0, PosicaoDisciplina = -1, PosicaoAluno = -1, PosicaoMatricula = -1, cont = 1;
	float NotaAluno, SomaNotas = 0.0, CalculoPorcentagemFaltas = 0.0;
	
	while(quantidade == 1){
	
		printf("Digite a matrícula do aluno que você deseja atribuir as notas e faltas: ");
		scanf("%d", &MatriculaDoAluno);
		
		printf("Digite o código da disciplina: ");
		scanf(" %10[^\n]", CodigoDaDisciplina);
		
		printf("Qual o semestre do aluno: ");
		scanf(" %15[^\n]", OpcaoSemestre);
		
		for(i = 0; i < *TamanhoDisciplina; ++ i){
			if(strcmp(disciplina[i].Codigo, CodigoDaDisciplina) == 0){
				 strcpy(NomeDaDisciplina, disciplina[i].Nome);
				 PosicaoDisciplina = i;
			}
		}
		
		for(i = 0; i < *TamanhoAluno; ++ i){
			if(MatriculaDoAluno == aluno[i].Matri){
				 strcpy(NomeDoAluno, aluno[i].Nome);
				 PosicaoAluno = i;
			}
		}
		
		for(i = 0; i <= *TamanhoDisciplina + 1; ++ i){
			if((strcmp(matricula[i].Semestre, OpcaoSemestre) == 0) && (strcmp(matricula[i].CodigoDisciplina, CodigoDaDisciplina) == 0) && (matricula[i].MatriculaAluno == MatriculaDoAluno)){
				 PosicaoMatricula = i;
			}
		}
		
		if(PosicaoDisciplina == -1 && PosicaoAluno != -1)	printf("Código da disciplina inválido!\n");
		else if(PosicaoDisciplina != -1 && PosicaoAluno == -1)	printf("Matrícula do aluno inválida!\n");
		else if(PosicaoDisciplina == -1 && PosicaoAluno == -1)	printf("Código da disciplina e matrícula do aluno inválida!\n");
		else if(PosicaoMatricula == -1)	printf("Aluno não associado a essa disciplina no semestre especeificado!\n");
		else{
			while(OpcaoContinuarNota == 1 && cont <= 5){
				printf("Digite a %dª nota do(a) aluno %s: ", cont, aluno[PosicaoAluno].Nome);
				scanf("%f", &NotaAluno);
				
				SomaNotas += NotaAluno;
				
				if(cont <= 4){
					printf("Deseja cadastrar outra nota?\n1 - Sim\t2 - Não\n");
					scanf("%d", &OpcaoConfirmacao);
				}				
				
				matricula[PosicaoMatricula].Nota[cont - 1] = NotaAluno;
				cont ++;
				
				if(OpcaoConfirmacao != 1)	OpcaoContinuarNota = 0;
			}
			
			for(i = cont - 1; i <= 5; ++ i)	matricula[PosicaoMatricula].Nota[i] = -1;
			
			printf("Digite o total de faltas em horas do(a) aluno %s: ", aluno[PosicaoAluno].Nome);
			scanf("%d", &matricula[PosicaoMatricula].Faltas);
			
			matricula[PosicaoMatricula].Media = SomaNotas / (cont - 1);
		}
		
		//Parte responsável por definir se o aluno esta aprovado ou reprovado
		CalculoPorcentagemFaltas = 100 * matricula[PosicaoMatricula].Faltas / disciplina[PosicaoDisciplina].CargaHoraria;
		
		if(CalculoPorcentagemFaltas >= 25.0){
			strcpy(matricula[PosicaoMatricula].Situacao, "Reprovado");
			strcpy(matricula[PosicaoMatricula].Motivo, "Faltas");
		}
		else if(matricula[PosicaoMatricula].Media == 7.0){
			strcpy(matricula[PosicaoMatricula].Situacao, "Aprovado");
			strcpy(matricula[PosicaoMatricula].Motivo, "Nota igual à média");
		}
		else if(matricula[PosicaoMatricula].Media > 7.0){
			strcpy(matricula[PosicaoMatricula].Situacao, "Aprovado");
			strcpy(matricula[PosicaoMatricula].Motivo, "Notas acima da média");
		}
		else{
			strcpy(matricula[PosicaoMatricula].Situacao, "Reprovado");
			strcpy(matricula[PosicaoMatricula].Motivo, "Notas baixas");
		}
		
		
		printf("Deseja cadastrar as notas e faltas de outro aluno agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &OpcaoAssociacao);
		
		if(OpcaoAssociacao != 1)	quantidade = 0;
		cont = OpcaoConfirmacao = OpcaoContinuarNota = 1;
		SomaNotas = 0.0;
	}
	
	system("cls || clear");
	return matricula;
}

CadastroMatricula* Matricular(int quantidade, int *TamanhoMatricula, CadastroMatricula *matricula, int *TamanhoAluno, CadastroAluno *aluno, int *TamanhoDisciplina, CadastroDisciplina *disciplina){
	
	int OpcaoAssociacao = 0, OpcaoConfirmacao = 0, i, PosicaoDisciplina = -1, PosicaoAluno = -1, MatriculaDoAluno;
	char CodigoDaDisciplina[11], NomeDaDisciplina[101], NomeDoAluno[101], SemestreCadastro[16];
	
	
	while(quantidade == 1){
		printf("Digite o código da disciplina: ");
		scanf(" %10[^\n]", CodigoDaDisciplina);
		
		printf("Digite a matrícula do aluno: ");
		scanf(" %d", &MatriculaDoAluno);
		
		printf("Informe qual o semestre: ");
		scanf(" %15[^\n]", SemestreCadastro);
		
		
		for(i = 0; i <= *TamanhoDisciplina; ++ i){
			if(strcmp(disciplina[i].Codigo, CodigoDaDisciplina) == 0){
				 strcpy(NomeDaDisciplina, disciplina[i].Nome);
				 PosicaoDisciplina = i;
			}
		}
		
		for(i = 0; i <= *TamanhoAluno; ++ i){
			if(MatriculaDoAluno == aluno[i].Matri){
				 strcpy(NomeDoAluno, aluno[i].Nome);
				 PosicaoAluno = i;
			}
		}
		
		if(PosicaoDisciplina == -1 && PosicaoAluno != -1)	printf("Código da disciplina inválido!\n");
		else if(PosicaoDisciplina != -1 && PosicaoAluno == -1)	printf("Matrícula do aluno inválida!\n");
		else if(PosicaoDisciplina == -1 && PosicaoAluno == -1)	printf("Código da disciplina e matrícula do aluno inválida!\n");
		else{
			printf("Deseja matricular o aluno %s na disciplina de %s?\n1 - Sim\t2 - Não\n", NomeDoAluno, NomeDaDisciplina);
			scanf("%d", &OpcaoConfirmacao);
			
			if(OpcaoConfirmacao == 1){
				if(*TamanhoMatricula == 0){
					matricula = (CadastroMatricula*) malloc(sizeof(CadastroMatricula));
				}
				else{
					matricula = (CadastroMatricula*) realloc(matricula, (*TamanhoMatricula + 1) * sizeof(CadastroMatricula));
				}
				if(matricula == 0){
					printf("Erro ao alterar tamanho da estrutura!\n");
					system("cls || clear");
					return 0;
				}
				
				strcpy(matricula[*TamanhoMatricula].CodigoDisciplina, CodigoDaDisciplina);
				strcpy(matricula[*TamanhoMatricula].NomeDisciplina, disciplina[PosicaoDisciplina].Nome);
				matricula[*TamanhoMatricula].MatriculaAluno = MatriculaDoAluno;
				matricula[*TamanhoMatricula].Nota[0] = -1;
				matricula[*TamanhoMatricula].Nota[1] = -1;
				matricula[*TamanhoMatricula].Nota[2] = -1;
				matricula[*TamanhoMatricula].Nota[3] = -1;
				matricula[*TamanhoMatricula].Nota[4] = -1;
				matricula[*TamanhoMatricula].Media = -1;
				strcpy(matricula[*TamanhoMatricula].Semestre, SemestreCadastro);
				matricula[*TamanhoMatricula].Faltas = 0;
				strcpy(matricula[*TamanhoMatricula].Situacao, "Pendente");
				strcpy(matricula[*TamanhoMatricula].Motivo, "Pendente");
				printf("\nAssociação concluída com sucesso!\n\n");
			}
		}
		PosicaoDisciplina = PosicaoAluno = -1;
		
		printf("Deseja associar outro aluno a disciplina agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &OpcaoAssociacao);
		
		*TamanhoMatricula += 1;
		
		if(OpcaoAssociacao != 1) quantidade = 0;
		
	}
	
	system("cls || clear");
	return matricula;
}

CadastroDisciplina* RemoverDisciplina(int quantidade, int *n, CadastroDisciplina *cadastro){
	int i, OpcaoConfirmacao = 0, OpcaoRemocao = 0, PosicaoRemocao = -1;
	char CodigoRemover[11], NomeDisciplinaRemover[101];
	
	while(quantidade == 1){
		
		printf("Entre com o código da disciplina que você quer remover: \n");
		scanf("\n%100[^\n]", CodigoRemover);
		
		for(i = 0; i < *n; ++ i){
			if(strcmp(cadastro[i].Codigo, CodigoRemover) == 0){
				 strcpy(NomeDisciplinaRemover, cadastro[i].Nome);
				 PosicaoRemocao = i;
			}
		}
		
		if(PosicaoRemocao == -1)	printf("Disciplina não encontrado!\n");
		else {
			printf("Deseja realmente remover a disciplina \"%s\"?\n1 - Sim\t2-Não\n", NomeDisciplinaRemover);
			scanf("%d", &OpcaoConfirmacao);
			
			if(OpcaoConfirmacao == 1){
				cadastro[PosicaoRemocao] = cadastro[*n - 1];
				cadastro = (CadastroDisciplina*) realloc(cadastro, (*n - 1) * sizeof(CadastroDisciplina));
				if(cadastro == 0){
					printf("Erro ao remover disciplina!\n\n");
					system("cls || clear");
					return 0;
				}
				*n -= 1;
				printf("\nDisciplina removida com sucesso!\n\n");
			}
		}
		
		printf("Deseja remover outra disciplina agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &OpcaoRemocao);
		PosicaoRemocao = -1;
		
		if(OpcaoRemocao != 1) quantidade = 0;
		
	}
	
	
	system("cls || clear");
	return cadastro;
}


// Recebe como parâmetro uma quantidade que representa que será alterado uma disciplina;
// Um ponteiro n que indica o tamanho do meu vetor de estruturas;
// O meu vetor de estrutura para que possa ser alterado
CadastroDisciplina* CadastrarDisciplina(int quantidade, int *n, CadastroDisciplina *cadastro){
	
	int Opcao = 0;
	
	while(quantidade == 1){
		if(*n == 0){
			cadastro = (CadastroDisciplina*) malloc(sizeof(CadastroDisciplina));
		}
		else{
			cadastro = (CadastroDisciplina*) realloc(cadastro, (*n + 1) * sizeof(CadastroDisciplina));
		}
		
		if(cadastro == 0){
			printf("Erro ao cadastrar disciplina!\n\n");
			system("cls || clear");
			return 0;
		}

		
		printf("Digite o nome da disciplina: ");
		scanf("\n%100[^\n]", cadastro[*n].Nome);
		
		printf("Digite o código da disciplina: ");
		scanf("\n%10[^\n]", cadastro[*n].Codigo);
		
		printf("Digite o nome do professor da disciplina: ");
		scanf("\n%100[^\n]", cadastro[*n].Professor);
		
		printf("Digite a carga horária da disciplina em horas: ");
		scanf("\n%d", &cadastro[*n].CargaHoraria);
		
		printf("Deseja cadastrar outra disciplina agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &Opcao);
		
		if(Opcao != 1) quantidade = 0;
		
		*n += 1;
	}
	
	
	system("cls || clear");
	return cadastro;
}


// Recebe como parâmetro uma quantidade que representa que será alterado um aluno;
// Um ponteiro n que indica o tamanho do meu vetor de estruturas;
// O meu vetor de estrutura para que possa ser alterado
CadastroAluno*  RemoverAluno(int quantidade, int *n, CadastroAluno *cadastro){
	int MatriculaRemover, i, OpcaoConfirmacao = 0, OpcaoRemocao = 0, PosicaoRemocao = -1;
	char NomeAlunoRemover[101];
	
	while(quantidade == 1){
		
		printf("Entre com a matrícula do aluno que você quer remover: \n");
		scanf("%d", &MatriculaRemover);
		
		for(i = 0; i < *n; ++ i){
			if(cadastro[i].Matri == MatriculaRemover){
				 strcpy(NomeAlunoRemover, cadastro[i].Nome);
				 PosicaoRemocao = i;
			}
		}
		
		if(PosicaoRemocao == -1)	printf("Aluno não encontrado!\n\n");
		else {
			printf("Deseja realmente remover o aluno \"%s\"?\n1 - Sim\t2-Não\n", NomeAlunoRemover);
			scanf("%d", &OpcaoConfirmacao);
			
			if(OpcaoConfirmacao == 1){
				cadastro[PosicaoRemocao] = cadastro[*n - 1];
				cadastro = (CadastroAluno*) realloc(cadastro, (*n - 1) * sizeof(CadastroAluno));
				if(cadastro == 0){
					printf("Erro ao remover aluno!\n");
					system("cls || clear");
					return 0;
				}
				*n -= 1;
				printf("\nAluno removido com sucesso!\n\n");
			}
		}
		
		printf("Deseja remover outro aluno agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &OpcaoRemocao);
		
		if(OpcaoRemocao != 1) quantidade = 0;
		
	}
	
	
	system("cls || clear");
	return cadastro;
}


// Recebe como parâmetro uma quantidade que representa que será alterado um aluno;
// Um ponteiro n que indica o tamanho do meu vetor de estruturas;
// O meu vetor de estrutura para que possa ser alterado;
// Um ponteiro Matrícula para associar automáticamente um número de matrícula a cada aluno
CadastroAluno* CadastrarAluno(int quantidade, int *n, CadastroAluno *cadastro, int *Matricula){
	
	int Opcao = 0;
	
	while(quantidade == 1){
		if(*n == 0){
			cadastro = (CadastroAluno*) malloc(sizeof(CadastroAluno));
		}
		else{
			cadastro = (CadastroAluno*) realloc(cadastro, (*n + 1) * sizeof(CadastroAluno));
		}
		if(cadastro == 0){
			printf("Erro ao cadastrar aluno!\n\n");
			system("cls || clear");
			return 0;
		}

		cadastro[*n].Matri = *Matricula;
		
		printf("Digite o nome do aluno: ");
		scanf(" %100[^\n]", cadastro[*n].Nome);
		
		printf("Digite a idade do aluno: ");
		scanf("%d", &cadastro[*n].Idade);
		
		printf("Digite o e-mail do aluno: ");
		scanf(" %100[^\n]", cadastro[*n].Email);
		
		printf("\nAluno cadastrado com sucesso!\nMatrícula: %d\nNome: %s\nIdade: %d\nE-mail: %s\n\n",cadastro[*n].Matri, cadastro[*n].Nome, cadastro[*n].Idade, cadastro[*n].Email);
		
		printf("Deseja casatrar outro aluno agora?\n1 - Sim\t2 - Não\n");
		scanf("%d", &Opcao);
		
		if(Opcao != 1) quantidade = 0;
		
		*n += 1;
		*Matricula += 1;
	}
	
	system("cls || clear");
	return cadastro;
}
