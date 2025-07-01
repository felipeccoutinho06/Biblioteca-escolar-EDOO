#include "Emprestimo.hpp"
#include <iostream>
using namespace std;

Emprestimo::Emprestimo() : livro(nullptr), usuario(nullptr), dataEmprestimo("") {}
Emprestimo::Emprestimo(Livro* l, Usuario* u, string data) : livro(l), usuario(u), dataEmprestimo(data) {}
void Emprestimo::exibirDetalhes() const {
    cout << "Livro: " << livro->getTitulo() << " | ISBN: " << livro->getISBN() << endl;
    cout << "Usuario: " << usuario->getNome() << " | ID: " << usuario->getId() << endl;
    cout << "Data de Emprestimo: " << dataEmprestimo << endl;
}