#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Academico.h"



// Contém o menu principal e as chamadas para todas as funções, bem como
// a passagem dos parâmetros necessário para a realização de cada operação
int main(){
	int Opcao = 0, TamanhoAluno = 0, MatriculaAluno = 1, TamanhoDisciplina = 0, TamanhoMatricula = 0, i;
	
	CadastroAluno *CadAluno = 0;
	CadastroDisciplina *CadDisciplina = 0;
	CadastroMatricula * CadMatricula = 0;
	
	// Recupera os dados do aquivo CadastroAluno.txt para a struct CadastroAluno
	FILE *FileAluno = fopen("Dados/CadastroAluno.txt", "r");
	if (FileAluno != 0) {
		fscanf(FileAluno, "%d %d", &TamanhoAluno, &MatriculaAluno);
		CadAluno = (CadastroAluno*) malloc(TamanhoAluno * sizeof(CadastroAluno));
		
		i = 0;
		
		while (fscanf(FileAluno, "%d %100[^\n] %d %100[^\n] ", &CadAluno[i].Matri, CadAluno[i].Nome, &CadAluno[i].Idade, CadAluno[i].Email) == 4)
			++ i;
		fclose(FileAluno);
		
	}
	
	// Recupera os dados do aquivo CadastroDisciplina.txt para a struct CadastroDisciplinas
	FILE *FileDisciplina = fopen("Dados/CadastroDisciplina.txt", "r");
	if (FileDisciplina != 0) {
		fscanf(FileDisciplina, "%d ", &TamanhoDisciplina);
		CadDisciplina = (CadastroDisciplina*) malloc(TamanhoDisciplina * sizeof(CadastroDisciplina));
		
		
		i = 0;
		
		while (fscanf(FileDisciplina, "%100[^\n] %10[^\n] %100[^\n] %d ", CadDisciplina[i].Nome, CadDisciplina[i].Codigo, CadDisciplina[i].Professor, &CadDisciplina[i].CargaHoraria) == 4)
			++ i;
		fclose(FileDisciplina);
	}
	
	// Recupera os dados do aquivo CadastroMatricula.txt para a struct CadastroMatricula
	FILE *FileMatricula = fopen("Dados/CadastroMatricula.txt", "r");
	if (FileMatricula != 0) {
		fscanf(FileMatricula, "%d ", &TamanhoMatricula);
		CadMatricula = (CadastroMatricula*) malloc(TamanhoMatricula * sizeof(CadastroMatricula));
		
		
		i = 0;
		
		while (fscanf(FileMatricula, "%10[^\n] %100[^\n] %d %lf %lf %lf %lf %lf %lf %10[^\n] %d %10[^\n] %30[^\n] ", CadMatricula[i].CodigoDisciplina, 
		CadMatricula[i].NomeDisciplina, &CadMatricula[i].MatriculaAluno, &CadMatricula[i].Nota[0], &CadMatricula[i].Nota[1], 
		&CadMatricula[i].Nota[2], &CadMatricula[i].Nota[3], &CadMatricula[i].Nota[4], &CadMatricula[i].Media, CadMatricula[i].Semestre, 
		&CadMatricula[i].Faltas, CadMatricula[i].Situacao, CadMatricula[i].Motivo) == 13)
			++ i;
		fclose(FileMatricula);
	}
	
	do {
		printf("(1) Cadastrar aluno \n(2) Remover aluno \n(3) Cadastrar disciplina \n(4) Remover disciplinas "
			"\n(5) Matricular na disciplina \n(6) Lançar notas e faltas \n(7) Relatorio de aprovados e reprovados \n(8) Sair\n");
		scanf("%d", &Opcao);
		
		if(Opcao == 1)	CadAluno = CadastrarAluno(1, &TamanhoAluno, CadAluno, &MatriculaAluno);
		else if(Opcao == 2)	CadAluno = RemoverAluno(1, &TamanhoAluno, CadAluno);
		else if(Opcao == 3)	CadDisciplina = CadastrarDisciplina(1, &TamanhoDisciplina, CadDisciplina);
		else if(Opcao == 4)	CadDisciplina = RemoverDisciplina(1, &TamanhoDisciplina, CadDisciplina);
		else if(Opcao == 5)	CadMatricula = Matricular(1, &TamanhoMatricula, CadMatricula, &TamanhoAluno, CadAluno, &TamanhoDisciplina, CadDisciplina);
		else if(Opcao == 6)	CadMatricula = LancarNotas(1, &TamanhoMatricula, CadMatricula, &TamanhoAluno, CadAluno, &TamanhoDisciplina, CadDisciplina);
		else if(Opcao == 7)	Relatorio(1, &TamanhoMatricula, CadMatricula, &TamanhoAluno, CadAluno);
		else if(Opcao == 8)	Sair(&TamanhoAluno, CadAluno, &MatriculaAluno, &TamanhoDisciplina, CadDisciplina, &TamanhoMatricula, CadMatricula);
		else system("clear || cls");
			
	} while(Opcao != 8);
	
	return 0;
}
