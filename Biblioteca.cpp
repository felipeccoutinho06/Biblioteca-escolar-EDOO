#include "Biblioteca.hpp"
#include <iostream>

void Biblioteca::adicionarLivro(shared_ptr<Livro> livro) {
    livros.push_back(livro);
}

void Biblioteca::adicionarUsuario(shared_ptr<Usuario> usuario) {
    usuarios.push_back(usuario);
}

void Biblioteca::emprestarLivro(string isbn, int userId, string dataEmprestimo) {
    shared_ptr<Livro> livro = nullptr;
    shared_ptr<Usuario> usuario = nullptr;

    for (auto &l : livros) {
        if (l->getISBN() == isbn && l->estaDisponivel()) {
            livro = l;
            break;
        }
    }

    for (auto &u : usuarios) {
        if (u->getId() == userId) {
            usuario = u;
            break;
        }
    }

    if (livro && usuario) {
        livro->emprestar();
        emprestimos.emplace_back(livro, usuario, dataEmprestimo);
        cout << "Emprestimo realizado com sucesso!\n";
    } else {
        cout << "Livro indisponivel ou usuario nao encontrado.\n";
    }
}

void Biblioteca::devolverLivro(string isbn) {
    for (auto &l : livros) {
        if (l->getISBN() == isbn) {
            l->devolver();
            cout << "Livro devolvido com sucesso!\n";
            return;
        }
    }
    cout << "Livro nao encontrado.\n";
}

void Biblioteca::exibirEmprestimos() const {
    cout << "Emprestimos Ativos:\n";
    for (const auto &e : emprestimos) {
        e.exibirDetalhes();
        cout << "-------------------\n";
    }
}