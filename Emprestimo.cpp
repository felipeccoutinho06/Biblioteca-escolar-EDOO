#include "Emprestimo.hpp"
#include <iostream>
using namespace std;

Emprestimo::Emprestimo() : livro(nullptr), usuario(nullptr), dataEmprestimo("") {}

Emprestimo::Emprestimo(Livro* l, Usuario* u, string data) : livro(l), usuario(u), dataEmprestimo(data) {}

void Emprestimo::exibirDetalhes() const {
    cout << "Livro: " << livro->getTitulo() << endl;
    cout << "Usuario: " << usuario->getNome() << endl;
    cout << "Data do Emprestimo: " << dataEmprestimo << endl;
}