#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Livros.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"

const int TAMANHO_MAXIMO = 100;

class Biblioteca {
private:
    Livro* livros[TAMANHO_MAXIMO];
    Usuario* usuarios[TAMANHO_MAXIMO];
    Emprestimo emprestimos[TAMANHO_MAXIMO];

    int totalLivros = 0;
    int totalUsuarios = 0;
    int totalEmprestimos = 0;

public:
    ~Biblioteca();
    bool isbnLivroExiste(const string& isbn) const;
    bool idUsuarioExiste(int userId) const;
    
    void adicionarLivro(Livro* livro);
    void adicionarUsuario(Usuario* usuario);

    void emprestarLivro(string isbn, int userId, string dataEmprestimo);
    void devolverLivro(string isbn, int userId);

    void exibirEmprestimos() const;
};

#endif