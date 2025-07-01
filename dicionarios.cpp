#include "Livros.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"

const int MAX_LIVROS = 100;
const int MAX_USUARIOS = 100;
const int MAX_EMPRESTIMOS = 100;

Livro livrosDB[MAX_LIVROS];
int totalLivrosDB = 0;

Usuario* usuariosDB[MAX_USUARIOS];
int totalUsuariosDB = 0;

Emprestimo emprestimosDB[MAX_EMPRESTIMOS];
int totalEmprestimosDB = 0;

void cadastrarLivro(const Livro& livro) {
    if (totalLivrosDB < MAX_LIVROS) {
        livrosDB[totalLivrosDB] = livro;
        totalLivrosDB++;
    }
}

Livro* buscarLivro(const std::string& isbn) {
    for (int i = 0; i < totalLivrosDB; i++) {
        if (livrosDB[i].getISBN() == isbn) {
            return &livrosDB[i];
        }
    }
    return nullptr;
}

void atualizarQuantidadeLivro(const std::string& isbn, int novaQuantidade) {
    Livro* livro = buscarLivro(isbn);
    if (livro) {
        livro->setQuantidade(novaQuantidade);
    }
}

void removerLivro(const std::string& isbn) {
    for (int i = 0; i < totalLivrosDB; i++) {
        if (livrosDB[i].getISBN() == isbn) {
            livrosDB[i] = livrosDB[totalLivrosDB - 1];
            totalLivrosDB--;
            break;
        }
    }
}

Usuario* buscarUsuario(int id) {
    for (int i = 0; i < totalUsuariosDB; i++) {
        if (usuariosDB[i]->getId() == id) {
            return usuariosDB[i];
        }
    }
    return nullptr;
}

void removerEmprestimo(int indice) {
    if (indice >= 0 && indice < totalEmprestimosDB) {
        emprestimosDB[indice] = emprestimosDB[totalEmprestimosDB - 1];
        totalEmprestimosDB--;
    }
}

