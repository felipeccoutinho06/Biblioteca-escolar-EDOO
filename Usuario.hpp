#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
using namespace std;

class Usuario {
protected:
    string nome;
    int id;
    string livrosPegos[10]; // Controle por ISBN (máximo 10 livros por segurança)
    int totalLivros = 0;

public:
    Usuario(string n, int i) : nome(n), id(i) {} // Construtor com nome e ID

    string getNome() const { return nome; }// Método para obter o nome do usuário
    int getId() const { return id; }// Método para obter o ID do usuário

    virtual int getLimiteLivros() const { return 3; } // Limite padrão

    bool jaPegouLivro(string isbn) const;// Verifica se o usuário já pegou um livro pelo ISBN

    bool podePegarMais() const { return totalLivros < getLimiteLivros(); }  // Verifica se o usuário pode pegar mais livros
 
    void registrarLivro(string isbn); // Registra o ISBN do livro que o usuário pegou

    void removerLivro(string isbn); // Remove o registro do livro pelo ISBN
};

#endif