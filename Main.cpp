#include "Aluno.hpp"
#include "Professor.hpp"
#include "Livros.hpp"
#include "dicionarios.hpp"
#include <iostream>
using namespace std;

int main() {
    Professor* prof1 = new Professor("Maria Silva", 1);
    Professor* prof2 = new Professor("João Souza", 2);
    usuariosDB[totalUsuariosDB++] = prof1;
    usuariosDB[totalUsuariosDB++] = prof2;

    Aluno* aluno1 = new Aluno("Ana Lima", 3);
    Aluno* aluno2 = new Aluno("Carlos Dias", 4);
    usuariosDB[totalUsuariosDB++] = aluno1;
    usuariosDB[totalUsuariosDB++] = aluno2;

    cadastrarLivro(Livro("História 1", "ISBN001", 5));
    cadastrarLivro(Livro("História 2", "ISBN002", 3));
    cadastrarLivro(Livro("História 3", "ISBN003", 4));
    cadastrarLivro(Livro("Matemática 1", "ISBN004", 2));
    cadastrarLivro(Livro("Matemática 2", "ISBN005", 6));
    cadastrarLivro(Livro("Matemática 3", "ISBN006", 2));
    cadastrarLivro(Livro("Português 1", "ISBN007", 5));
    cadastrarLivro(Livro("Português 2", "ISBN008", 3));
    cadastrarLivro(Livro("Português 3", "ISBN009", 4));
    cadastrarLivro(Livro("Geografia 1", "ISBN010", 2));
    cadastrarLivro(Livro("Geografia 2", "ISBN011", 3));
    cadastrarLivro(Livro("Geografia 3", "ISBN012", 2));
    cadastrarLivro(Livro("Ciências 1", "ISBN013", 1));
    cadastrarLivro(Livro("Ciências 2", "ISBN014", 2));
    cadastrarLivro(Livro("Ciências 3", "ISBN015", 4));

    cout << "Professores cadastrados:\n";
    for (int i = 0; i < totalUsuariosDB; i++) {
        if (dynamic_cast<Professor*>(usuariosDB[i]))
            cout << usuariosDB[i]->getNome() << " (ID: " << usuariosDB[i]->getId() << ")\n";
    }

    cout << "\nAlunos cadastrados:\n";
    for (int i = 0; i < totalUsuariosDB; i++) {
        if (dynamic_cast<Aluno*>(usuariosDB[i]))
            cout << usuariosDB[i]->getNome() << " (ID: " << usuariosDB[i]->getId() << ")\n";
    }

    cout << "\nLivros cadastrados:\n";
    for (int i = 0; i < totalLivrosDB; i++) {
        cout << livrosDB[i].getTitulo() << " (ISBN: " << livrosDB[i].getISBN()
             << ", Disponível: " << (livrosDB[i].estaDisponivel() ? "Sim" : "Não") << ")\n";
    }

    for (int i = 0; i < totalUsuariosDB; i++) {
        delete usuariosDB[i];
    }

    return 0;
}