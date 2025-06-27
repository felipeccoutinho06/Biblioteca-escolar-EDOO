#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
using namespace std;

class Usuario {
protected:
    string nome;
    int id;
    string livrosPegos[10]; // Controle por ISBN (máximo 10 livros por segurança)
    int totalLivros = 0;

public:
    Usuario(string n, int i) : nome(n), id(i) {}

    string getNome() const { return nome; }
    int getId() const { return id; }

    virtual int getLimiteLivros() const { return 3; } // Limite padrão

    bool jaPegouLivro(string isbn) const;

    bool podePegarMais() const { return totalLivros < getLimiteLivros(); }

    void registrarLivro(string isbn);

    void removerLivro(string isbn);
};

#endif