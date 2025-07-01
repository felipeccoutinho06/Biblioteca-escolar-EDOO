#ifndef LIVROS_HPP
#define LIVROS_HPP

#include <iostream>
using namespace std;

class Livro {
private:
    string titulo;
    string isbn;
    int quantidade;

public:
    Livro() : titulo(""), isbn(""), quantidade(0) {} // Construtor padrão
    Livro(string t, string i, int q);

    string getTitulo() const;
    string getISBN() const;
    bool estaDisponivel() const;

    void emprestar();
    void devolver();

    void setQuantidade(int q);
};

#endif