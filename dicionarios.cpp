#include "Livros.hpp"     // Inclui a definição da classe Livro
#include "Usuario.hpp"    // Inclui a definição da classe Usuario
#include "Emprestimo.hpp" // Inclui a definição da classe Emprestimo

// Definição dos limites para arrays estáticos
const int MAX_LIVROS = 100;
const int MAX_USUARIOS = 100;
const int MAX_EMPRESTIMOS = 100;

// Arrays estáticos para armazenar dados
Livro livrosDB[MAX_LIVROS];
int totalLivrosDB = 0;

Usuario* usuariosDB[MAX_USUARIOS];
int totalUsuariosDB = 0;

Emprestimo emprestimosDB[MAX_EMPRESTIMOS];
int totalEmprestimosDB = 0;

// Adiciona um novo livro ao array, se ainda houver espaço
void cadastrarLivro(const Livro& livro) {
    if (totalLivrosDB < MAX_LIVROS) {
        livrosDB[totalLivrosDB] = livro;
        totalLivrosDB++;
    }
}

// Retorna um ponteiro para o livro no array com o ISBN correspondente
Livro* buscarLivro(const std::string& isbn) {
    for (int i = 0; i < totalLivrosDB; i++) {
        if (livrosDB[i].getISBN() == isbn) {
            return &livrosDB[i];
        }
    }
    return nullptr;
}

// Atualiza a quantidade de exemplares de um livro específico
void atualizarQuantidadeLivro(const std::string& isbn, int novaQuantidade) {
    Livro* livro = buscarLivro(isbn);
    if (livro) {
        livro->setQuantidade(novaQuantidade);
    }
}

// Remove um livro do array, substituindo pela última posição
void removerLivro(const std::string& isbn) {
    for (int i = 0; i < totalLivrosDB; i++) {
        if (livrosDB[i].getISBN() == isbn) {
            livrosDB[i] = livrosDB[totalLivrosDB - 1];
            totalLivrosDB--;
            break;
        }
    }
}

// Retorna um ponteiro para o usuário com o ID correspondente
Usuario* buscarUsuario(int id) {
    for (int i = 0; i < totalUsuariosDB; i++) {
        if (usuariosDB[i]->getId() == id) {
            return usuariosDB[i];
        }
    }
    return nullptr;
}

// Remove um empréstimo do array, substituindo pela última posição
void removerEmprestimo(int indice) {
    if (indice >= 0 && indice < totalEmprestimosDB) {
        emprestimosDB[indice] = emprestimosDB[totalEmprestimosDB - 1];
        totalEmprestimosDB--;
    }
}
