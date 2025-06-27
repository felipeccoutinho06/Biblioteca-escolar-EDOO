#include "Livros.hpp"

Livro::Livro(string t, string a, string i, int q) : titulo(t), autor(a), ISBN(i), quantidade(q) {}

bool Livro::estaDisponivel() const {
    return quantidade > 0;
}

void Livro::emprestar() {
    if (quantidade > 0) quantidade--;
}

void Livro::devolver() {
    quantidade++;
}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getISBN() const {
    return ISBN;
}
