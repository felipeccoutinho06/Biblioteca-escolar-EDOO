#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include "Livros.hpp"
#include "Usuario.hpp"
#include <iostream>
using namespace std;

class Emprestimo {
private:
    Livro* livro;
    Usuario* usuario;
    string dataEmprestimo;

public:
    Emprestimo();
    Emprestimo(Livro* l, Usuario* u, string data);
    void exibirDetalhes() const;
    Usuario* getUsuario() const { return usuario; }
};

#endif
