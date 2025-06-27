#include "Emprestimo.hpp"
#include <iostream>

Emprestimo::Emprestimo(shared_ptr<Livro> l, shared_ptr<Usuario> u, string data) : livro(l), usuario(u), dataEmprestimo(data) {}

void Emprestimo::exibirDetalhes() const {
    cout << "Livro: " << livro->getTitulo() << endl;
    cout << "Usuario: " << usuario->getNome() << endl;
    cout << "Data do Emprestimo: " << dataEmprestimo << endl;
}