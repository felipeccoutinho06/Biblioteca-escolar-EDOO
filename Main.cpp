// Exemplo de cadastro de professores, alunos e livros
// ...existing code...
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Livros.hpp"
#include "dicionarios.hpp" // Inclua apenas se for um arquivo de teste, evite incluir .cpp em produção

int main() {
    // Criando professores
    Professor* prof1 = new Professor("Maria Silva", 1);
    Professor* prof2 = new Professor("João Souza", 2);
    usuariosDB[prof1->getId()] = prof1;
    usuariosDB[prof2->getId()] = prof2;

    // Criando alunos
    Aluno* aluno1 = new Aluno("Ana Lima", 3);
    Aluno* aluno2 = new Aluno("Carlos Dias", 4);
    usuariosDB[aluno1->getId()] = aluno1;
    usuariosDB[aluno2->getId()] = aluno2;

    // Criando 15 livros escolares
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

    // Exemplo de exibição simples
    cout << "Professores cadastrados:\n";
    for (auto& [id, usuario] : usuariosDB) {
        if (dynamic_cast<Professor*>(usuario))
            cout << usuario->getNome() << " (ID: " << usuario->getId() << ")\n";
    }
    cout << "\nAlunos cadastrados:\n";
    for (auto& [id, usuario] : usuariosDB) {
        if (dynamic_cast<Aluno*>(usuario))
            cout << usuario->getNome() << " (ID: " << usuario->getId() << ")\n";
    }
    cout << "\nLivros cadastrados:\n";
    for (auto& [isbn, livro] : livrosDB) {
        cout << livro.getTitulo() << " (ISBN: " << isbn << ", Quantidade: " << livro.estaDisponivel() << ")\n";
    }

    // Libere a memória dos usuários
    for (auto& [id, usuario] : usuariosDB) {
        delete usuario;
    }
    usuariosDB.clear();

    return 0;
}
// ...existing code...