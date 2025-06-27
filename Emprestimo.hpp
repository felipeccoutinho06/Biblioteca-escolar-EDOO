#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <memory>
#include <string>
#include "Livros.hpp"
#include "Usuario.hpp"

using namespace std;

class Emprestimo {
private:
    shared_ptr<Livro> livro;
    shared_ptr<Usuario> usuario;
    string dataEmprestimo;

public:
    Emprestimo(shared_ptr<Livro> l, shared_ptr<Usuario> u, string data);
    void exibirDetalhes() const;
};

#endif