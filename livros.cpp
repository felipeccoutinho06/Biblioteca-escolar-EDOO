#include "Livros.hpp"

Livro::Livro(string t, string i, int q) {
    titulo = t;
    isbn = i;
    quantidade = q;
}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getISBN() const {
    return isbn;
}

bool Livro::estaDisponivel() const {
    return quantidade > 0;
}

void Livro::emprestar() {
    quantidade--;
}

void Livro::devolver() {
    quantidade++;
}

void Livro::setQuantidade(int q) {
    quantidade = q;
}