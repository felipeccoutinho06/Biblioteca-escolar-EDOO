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
    Emprestimo() : livro(nullptr), usuario(nullptr), dataEmprestimo("") {}

    Emprestimo(Livro* l, Usuario* u, string data) : livro(l), usuario(u), dataEmprestimo(data) {}

    void exibirDetalhes() const {
        cout << "Livro: " << livro->getTitulo() << " | ISBN: " << livro->getISBN() << endl;
        cout << "Usuario: " << usuario->getNome() << " | ID: " << usuario->getId() << endl;
        cout << "Data de Emprestimo: " << dataEmprestimo << endl;
    }
};

#endif