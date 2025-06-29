#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
using namespace std;

class Livro {
private:
    string titulo;
    string isbn;
    int quantidade;

public:
    Livro(string t, string i, int q);

    string getTitulo() const;
    string getISBN() const;
    bool estaDisponivel() const;

    void emprestar();
    void devolver();

    void setQuantidade(int q); // Método adicionado
};

#endif