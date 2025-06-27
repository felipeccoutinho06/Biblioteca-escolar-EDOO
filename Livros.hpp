#ifndef LIVRO_H
#define LIVRO_H

#include <string>
using namespace std;

class Livro {
private:
    string titulo;
    string autor;
    string ISBN;
    int quantidade;

public:
    Livro(string t, string a, string i, int q);
    bool estaDisponivel() const;
    void emprestar();
    void devolver();
    string getTitulo() const;
    string getISBN() const;
};