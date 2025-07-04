#ifndef LIVROS_HPP
#define LIVROS_HPP

#include <iostream>
using namespace std;

// Classe que representa um livro na biblioteca
class Livro {
private:
    string titulo;      // Título do livro
    string isbn;        // ISBN do livro (identificador único)
    int quantidade;     // Quantidade de exemplares disponíveis

public:
    // Construtor padrão
    Livro() : titulo(""), isbn(""), quantidade(0) {}

    // Construtor com parâmetros
    Livro(string t, string i, int q);

    // Retorna o título do livro
    string getTitulo() const;

    // Retorna o ISBN do livro
    string getISBN() const;

    // Verifica se há exemplares disponíveis para empréstimo
    bool estaDisponivel() const;

    // Realiza o empréstimo de um exemplar (diminui a quantidade)
    void emprestar();

    // Devolve um exemplar (aumenta a quantidade)
    void devolver();

    // Define a quantidade de exemplares disponíveis
    void setQuantidade(int q);
};

#endif