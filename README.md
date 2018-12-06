# Sistema de Controle Acadêmico

> O devido sistema foi implementado pelo aluno Wallesson Cavalcante juntamente comigo com o propósito de compor parte da nota da disciplina de Fundamentos de Programação pela Universidade Federal do Ceará - Campus Quixadá.

### Finalidade do sistema
O sistema tem como propósito implementar algo que se assemelhe a um sistema profissional de controle acadêmico. O mesmo possui controle sobre alunos, disciplinas, matrículas e gerar relatórios.

### Funcionalidades básicas do sistema
1. O usuário pode cadastrar aluno.
2. O usuário pode remover aluno.
3. O usuário pode cadastrar disciplinas.
4. O usuário pode remover disciplinas.
5. O usuário pode matricular o aluno na disciplina.
6. O usuário pode emitir relatório de aprovados e reprovados.

### Restrições de implementação do sistema
* O sistema deve ser implementado usando a linguagem C.
* O sistema deve possuir  um sistema de arquivos que guarde o que foi alterado pelo usuário para que deva ter continuidade quando for executar novamente.
* O sistema deve armazenar os dados em structs durante o tempo de execução.

##### Instruções para execução
**Requisito:** possuir um compilador gcc instalado na máquina a ser executado.

	As instruções aqui apresentadas são mais voltadas para execução em terminais Linux, apesar de uma certa parte poder ser executadas no Windows também.
* Para que o sistema possa rodar, é necessário que todos os seus arquivos estejam na mesma estutura apresentada aqui, bem como completos e seguir as seguintes instruções:
    * Abra uma janela do terminal na pasta em que se encontra as classes do programa.
    * Compile os arquivos `*.c` com o seguinte comando:
        `gcc -c main.c Academico.c`.
    * Em seguinda, monte os arquivos `*.o` para formar o executável com o seguinte comando: 
        `gcc -o main main.o Academico.o`.
    * Ainda no terminal, execute o programa com a seguinte linha de comando:
        `./main`.   