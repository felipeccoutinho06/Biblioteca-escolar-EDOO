#include <map>
#include <string>
#include "Livros.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"

// Dicionários simulando tabelas do banco de dados
std::map<std::string, Livro> livrosDB;      // chave: ISBN
std::map<int, Usuario*> usuariosDB;         // chave: ID do usuário
std::map<int, Emprestimo> emprestimosDB;    // chave: ID do empréstimo

// Funções CRUD para Livro
void cadastrarLivro(const Livro& livro) {
    livrosDB[livro.getISBN()] = livro;
}

Livro* buscarLivro(const std::string& isbn) {
    auto it = livrosDB.find(isbn);
    if (it != livrosDB.end()) return &(it->second);
    return nullptr;
}

void atualizarQuantidadeLivro(const std::string& isbn, int novaQuantidade) {
    auto it = livrosDB.find(isbn);
    if (it != livrosDB.end()) it->second.setQuantidade(novaQuantidade);
}

void removerLivro(const std::string& isbn) {
    livrosDB.erase(isbn);
}

// Funções CRUD para Usuario (exemplo: buscar por ID)
Usuario* buscarUsuario(int id) {
    auto it = usuariosDB.find(id);
    if (it != usuariosDB.end()) return it->second;
    return nullptr;
}

// Funções CRUD para Emprestimo (exemplo: remover)
void removerEmprestimo(int idEmprestimo) {
    emprestimosDB.erase(idEmprestimo);
}

// Implemente funções semelhantes para criar, atualizar e buscar usuários e empréstimos.