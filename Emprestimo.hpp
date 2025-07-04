#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include "Livros.hpp"
#include "Usuario.hpp"
#include <iostream>
using namespace std;

// Classe que representa um empréstimo de livro
class Emprestimo {
private:
    Livro* livro;              // Ponteiro para o livro emprestado
    Usuario* usuario;          // Ponteiro para o usuário que fez o empréstimo
    string dataEmprestimo;     // Data em que o empréstimo foi realizado

public:
    // Construtor padrão
    Emprestimo();

    // Construtor com parâmetros (livro, usuário e data)
    Emprestimo(Livro* l, Usuario* u, string data);

    // Exibe os detalhes do empréstimo (livro, usuário e data)
    void exibirDetalhes() const;

    // Retorna o ponteiro para o usuário do empréstimo
    Usuario* getUsuario() const { return usuario; }
};

#endif