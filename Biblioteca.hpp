#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Livros.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"

const int TAMANHO_MAXIMO = 100; // Número máximo de livros, usuários e empréstimos

// Classe que representa a biblioteca
class Biblioteca {
private:
    Livro* livros[TAMANHO_MAXIMO];         // Vetor de ponteiros para os livros cadastrados
    Usuario* usuarios[TAMANHO_MAXIMO];     // Vetor de ponteiros para os usuários cadastrados
    Emprestimo emprestimos[TAMANHO_MAXIMO];// Vetor de empréstimos realizados

    int totalLivros = 0;                   // Quantidade atual de livros cadastrados
    int totalUsuarios = 0;                 // Quantidade atual de usuários cadastrados
    int totalEmprestimos = 0;              // Quantidade atual de empréstimos realizados

public:
    ~Biblioteca(); // Destrutor

    // Verifica se um livro com o ISBN informado existe
    bool isbnLivroExiste(const string& isbn) const;

    // Verifica se um usuário com o ID informado existe
    bool idUsuarioExiste(int userId) const;
    
    // Adiciona um novo livro à biblioteca
    void adicionarLivro(Livro* livro);

    // Adiciona um novo usuário à biblioteca
    void adicionarUsuario(Usuario* usuario);

    // Exibe todos os empréstimos de um usuário específico
    void exibirEmprestimosDoUsuario(int userId) const;

    // Realiza o empréstimo de um livro para um usuário
    void emprestarLivro(string isbn, int userId, string dataEmprestimo);

    // Realiza a devolução de um livro por um usuário
    void devolverLivro(string isbn, int userId);

    // Exibe todos os empréstimos da biblioteca
    void exibirEmprestimos() const;

    // Exibe todos os livros cadastrados (ou os disponíveis para um usuário)
    void exibirLivros(int userId = -1) const;
};

#endif