#include "Aluno.hpp"
#include "Professor.hpp"
#include "Biblioteca.hpp"
#include "Livros.hpp"
#include "dicionarios.hpp"
#include <iostream>
using namespace std;

// Instancia o objeto principal da biblioteca
Biblioteca biblioteca;

int main() {
    // Criação e cadastro de professores
    Professor* prof1 = new Professor("Maria Silva", 1);
    Professor* prof2 = new Professor("João Souza", 2);
    biblioteca.adicionarUsuario(prof1);
    biblioteca.adicionarUsuario(prof2);

    // Criação e cadastro de alunos
    Aluno* aluno1 = new Aluno("Ana Lima", 3);
    Aluno* aluno2 = new Aluno("Carlos Dias", 4);
    biblioteca.adicionarUsuario(aluno1);
    biblioteca.adicionarUsuario(aluno2);

    // Cadastro de livros na biblioteca
    biblioteca.adicionarLivro(new Livro("História 1", "ISBN001", 5));
    biblioteca.adicionarLivro(new Livro("História 2", "ISBN002", 3));
    biblioteca.adicionarLivro(new Livro("História 3", "ISBN003", 4));
    biblioteca.adicionarLivro(new Livro("Matemática 1", "ISBN004", 2));
    biblioteca.adicionarLivro(new Livro("Matemática 2", "ISBN005", 6));
    biblioteca.adicionarLivro(new Livro("Matemática 3", "ISBN006", 2));
    biblioteca.adicionarLivro(new Livro("Português 1", "ISBN007", 5));
    biblioteca.adicionarLivro(new Livro("Português 2", "ISBN008", 3));
    biblioteca.adicionarLivro(new Livro("Português 3", "ISBN009", 4));
    biblioteca.adicionarLivro(new Livro("Geografia 1", "ISBN010", 2));
    biblioteca.adicionarLivro(new Livro("Geografia 2", "ISBN011", 3));
    biblioteca.adicionarLivro(new Livro("Geografia 3", "ISBN012", 2));
    biblioteca.adicionarLivro(new Livro("Ciências 1", "ISBN013", 1));
    biblioteca.adicionarLivro(new Livro("Ciências 2", "ISBN014", 2));
    biblioteca.adicionarLivro(new Livro("Ciências 3", "ISBN015", 4));

    // Exibe todos os livros cadastrados no início
    biblioteca.exibirLivros();
 
    // Loop principal do sistema
    while (true) {
        int userId;
        string isbn, dataEmprestimo;

        // Validação do ID do usuário (só prossegue se for válido ou -1 para sair)
        bool idValido = false;
        do {
            cout << "\nDigite o ID do usuario (ou -1 para sair): ";
            cin >> userId;
            if (userId == -1) return 0; // Encerra o programa
            idValido = biblioteca.idUsuarioExiste(userId);
            if (!idValido) {
                cout << "ID do usuario nao encontrado. Tente novamente.\n";
            }
        } while (!idValido);

        // Oferece ao usuário a opção de ver seus empréstimos
        cout << "Deseja ver todos os seus emprestimos? (s/n): ";
        char verEmprestimos;
        cin >> verEmprestimos;
        if (verEmprestimos == 's' || verEmprestimos == 'S') {
            biblioteca.exibirEmprestimosDoUsuario(userId);
        }

        // Menu de operações para o usuário
        cout << "\nO que deseja fazer?\n";
        cout << "1 - Emprestar livro\n";
        cout << "2 - Devolver livro\n";
        cout << "Escolha uma opcao: ";
        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            // Exibe os livros disponíveis para o usuário
            cout << "\nLista de livros disponíveis:\n";
            biblioteca.exibirLivros(userId);
            cout << "\n";

            // Solicita o ISBN do livro e valida
            bool isbnValido;
            do {
                cout << "Digite o ISBN do livro: ";
                cin >> isbn;
                isbnValido = biblioteca.isbnLivroExiste(isbn);
                if (!isbnValido) {
                    cout << "ISBN do livro nao encontrado. Tente novamente.\n";
                }
            } while (!isbnValido);

            // Solicita a data do empréstimo
            cout << "Digite a data do emprestimo (YYYY-MM-DD): ";
            cin >> dataEmprestimo;

            // Realiza o empréstimo
            biblioteca.emprestarLivro(isbn, userId, dataEmprestimo);
        } else if (opcao == 2) {
            // Exibe os empréstimos atuais do usuário
            cout << "\nSeus emprestimos atuais:\n";
            biblioteca.exibirEmprestimosDoUsuario(userId);

            // Solicita o ISBN do livro a ser devolvido
            cout << "Digite o ISBN do livro que deseja devolver: ";
            cin >> isbn;
            biblioteca.devolverLivro(isbn, userId);
        } else {
            cout << "Opcao invalida.\n";
        }

        // Pergunta se o usuário deseja realizar outra operação
        cout << "\nDeseja realizar outra operacao? (s/n): ";
        char continuar;
        cin >> continuar;
        if (continuar != 's' && continuar != 'S') break;
    }

    // Libere memória se necessário (ex: delete usuariosDB[i])
    return 0;
}