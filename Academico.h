// Struct para armazenar os dados das Matricula associadas as disciplinas e ao aluno
typedef struct{
	int MatriculaAluno, Faltas;
	char CodigoDisciplina[11], NomeDisciplina[101], Semestre[16], Situacao[10], Motivo[30];
	double Nota[5], Media;
} CadastroMatricula;

// Struct para armazenar os dados das disciplinas
typedef struct{
	char Nome[101], Professor[101], Codigo[11];
	int CargaHoraria;
	
} CadastroDisciplina;

// Struct usada para armazenar os dados dos alunos
typedef struct{
	char Nome[101], Email[101];
	int Matri, Idade;
} CadastroAluno;


/*
 * Funções associadas a cada ítem do menú principal
 * Tem como finalidade a separação das funções procurando manter tudo organizado 
 */


// Parte do código responsável por salvar em arquivo todas as informações que foram alteradas em struct antes do programa ser encerrado;
// Recebe o tamanho de cada struct usada, bem como informações de matrícula atual e ponteiro das structs abertas
// Pode-se também optar por colocar uma chamada a essa função dentro do laço do menu, por exemplo. Com isso, toda vez que houver uma interação
//	no menu, as informações serão salvas de forma que não perca informações caso o programa seja encerrado de maneira brusca.
void Sair(int *TamanhoAluno, CadastroAluno *Aluno, int *MatriculaAluno, int *TamanhoDisciplina, CadastroDisciplina *Disciplina, int *TamanhoMatricula, CadastroMatricula *Matricula);


// Responsável por gerar os relatórios quando solicitados
void Relatorio(int quantidade, int *TamanhoMatricula, CadastroMatricula *matricula, int *TamanhoAluno, CadastroAluno *aluno);


// Responsável por lançar as notas de cada aluno de acordo com a disciplina na qual o mesmo está matriculado
CadastroMatricula* LancarNotas(int quantidade, int *TamanhoMatricula, CadastroMatricula *matricula, int *TamanhoAluno, CadastroAluno *aluno, int *TamanhoDisciplina, CadastroDisciplina *disciplina);


// Responsável por matricular um aluno em uma determinada disciplina
CadastroMatricula* Matricular(int quantidade, int *TamanhoMatricula, CadastroMatricula *matricula, int *TamanhoAluno, CadastroAluno *aluno, int *TamanhoDisciplina, CadastroDisciplina *disciplina);


// Responsável por remover uma determinada disciplina do banco de disciplinas
CadastroDisciplina* RemoverDisciplina(int quantidade, int *n, CadastroDisciplina *cadastro);


// Recebe como parâmetro uma quantidade que representa que será alterado uma disciplina;
// Um ponteiro n que indica o tamanho do meu vetor de estruturas;
// O meu vetor de estrutura para que possa ser alterado
CadastroDisciplina* CadastrarDisciplina(int quantidade, int *n, CadastroDisciplina *cadastro);


// Recebe como parâmetro uma quantidade que representa que será alterado um aluno;
// Um ponteiro n que indica o tamanho do meu vetor de estruturas;
// O meu vetor de estrutura para que possa ser alterado
CadastroAluno*  RemoverAluno(int quantidade, int *n, CadastroAluno *cadastro);


// Recebe como parâmetro uma quantidade que representa que será alterado um aluno;
// Um ponteiro n que indica o tamanho do meu vetor de estruturas;
// O meu vetor de estrutura para que possa ser alterado;
// Um ponteiro Matrícula para associar automáticamente um número de matrícula a cada aluno
CadastroAluno* CadastrarAluno(int quantidade, int *n, CadastroAluno *cadastro, int *Matricula);
