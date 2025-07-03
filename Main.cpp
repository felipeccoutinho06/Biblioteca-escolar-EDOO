#include "Aluno.hpp"
#include "Professor.hpp"
#include "Biblioteca.hpp"
#include "Livros.hpp"
#include "dicionarios.hpp"
#include <iostream>
using namespace std;

// Assuming Biblioteca is a class that manages the library system
Biblioteca biblioteca;

int main() {
    Professor* prof1 = new Professor("Maria Silva", 1);
    Professor* prof2 = new Professor("João Souza", 2);
    biblioteca.adicionarUsuario(prof1);
    biblioteca.adicionarUsuario(prof2);

    Aluno* aluno1 = new Aluno("Ana Lima", 3);
    Aluno* aluno2 = new Aluno("Carlos Dias", 4);
    biblioteca.adicionarUsuario(aluno1);
    biblioteca.adicionarUsuario(aluno2);

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

    

    biblioteca.exibirLivros();
 
    while (true) {
        int userId;
        string isbn, dataEmprestimo;

        bool idValido = false;
    do {
        cout << "\nDigite o ID do usuario (ou -1 para sair): ";
        cin >> userId;
        if (userId == -1) return 0;
        idValido = biblioteca.idUsuarioExiste(userId);
        if (!idValido) {
            cout << "ID do usuario nao encontrado. Tente novamente.\n";
        }
    } while (!idValido);

        cout << "Deseja ver todos os seus emprestimos? (s/n): ";
        char verEmprestimos;
        cin >> verEmprestimos;
        if (verEmprestimos == 's' || verEmprestimos == 'S') {
            biblioteca.exibirEmprestimosDoUsuario(userId);
        }

        cout << "\nLista de livros disponíveis:\n";
        biblioteca.exibirLivros();
        cout << "\n";

        // Solicitar o ISBN e a data do empréstimo
        bool isbnValido;
        do {
            cout << "Digite o ISBN do livro: ";
            cin >> isbn;
            isbnValido = biblioteca.isbnLivroExiste(isbn);
            if (!isbnValido) {
                cout << "ISBN do livro nao encontrado. Tente novamente.\n";
            }
        } while (!isbnValido);

        cout << "Digite a data do emprestimo (YYYY-MM-DD): ";
        cin >> dataEmprestimo;

        // Chamar o método emprestarLivro
        biblioteca.emprestarLivro(isbn, userId, dataEmprestimo);

        cout << "\nDeseja realizar outra operacao? (s/n): ";
        char continuar;
        cin >> continuar;
        if (continuar != 's' && continuar != 'S') break;
    }

    // Libere memória se necessário (ex: delete usuariosDB[i])
    return 0;
}