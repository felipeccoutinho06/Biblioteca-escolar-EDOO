#include "Emprestimo.hpp"
#include <iostream>
using namespace std;

// Construtor padrão: inicializa os ponteiros como nulos e a data vazia
Emprestimo::Emprestimo() : livro(nullptr), usuario(nullptr), dataEmprestimo("") {}

// Construtor com parâmetros: inicializa com livro, usuário e data informados
Emprestimo::Emprestimo(Livro* l, Usuario* u, string data) : livro(l), usuario(u), dataEmprestimo(data) {}

// Exibe os detalhes do empréstimo (livro, usuário e data)
void Emprestimo::exibirDetalhes() const {
    cout << "Livro: " << livro->getTitulo() << " | ISBN: " << livro->getISBN() << endl;
    cout << "Usuario: " << usuario->getNome() << " | ID: " << usuario->getId() << endl;
    cout << "Data de Emprestimo: " << dataEmprestimo << endl;
}