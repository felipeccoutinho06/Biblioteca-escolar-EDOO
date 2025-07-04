#include "Livros.hpp"

// Construtor com parâmetros: inicializa título, ISBN e quantidade
Livro::Livro(string t, string i, int q) {
    titulo = t;
    isbn = i;
    quantidade = q;
}

// Retorna o título do livro
string Livro::getTitulo() const {
    return titulo;
}

// Retorna o ISBN do livro
string Livro::getISBN() const {
    return isbn;
}

// Verifica se há exemplares disponíveis para empréstimo
bool Livro::estaDisponivel() const {
    return quantidade > 0;
}

// Realiza o empréstimo de um exemplar (diminui a quantidade)
void Livro::emprestar() {
    quantidade--;
}

// Devolve um exemplar (aumenta a quantidade)
void Livro::devolver() {
    quantidade++;
}

// Define a quantidade de exemplares disponíveis
void Livro::setQuantidade(int q) {
    quantidade = q;
}