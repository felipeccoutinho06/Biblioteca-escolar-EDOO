#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <memory>
#include "Livro.h"
#include "Usuario.h"
#include "Aluno.h"
#include "Professor.h"
#include "Emprestimo.h"

using namespace std;

class Biblioteca {
private:
    vector<shared_ptr<Livro>> livros;
    vector<shared_ptr<Usuario>> usuarios;
    vector<Emprestimo> emprestimos;

public:
    void adicionarLivro(shared_ptr<Livro> livro);
    void adicionarUsuario(shared_ptr<Usuario> usuario);
    void emprestarLivro(string isbn, int userId, string dataEmprestimo);
    void devolverLivro(string isbn);
    void exibirEmprestimos() const;
};

#endif