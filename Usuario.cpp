#include "Usuario.hpp"

// Verifica se o usuário já pegou um livro com o ISBN informado
bool Usuario::jaPegouLivro(string isbn) const {
    for (int i = 0; i < totalLivros; i++) {
        if (livrosPegos[i] == isbn) { // Se encontrar o ISBN nos livros pegos
            return true; // Retorna verdadeiro
        }
    }
    return false; // Se não encontrar, retorna falso
}

// Registra um novo livro pego pelo usuário, se não atingiu o limite
void Usuario::registrarLivro(string isbn) {
    if (totalLivros < getLimiteLivros()) { // Verifica se pode pegar mais livros
        livrosPegos[totalLivros] = isbn;   // Adiciona o ISBN ao array
        totalLivros++;                     // Incrementa a quantidade de livros pegos
    }
}

// Remove um livro da lista de livros pegos pelo usuário
void Usuario::removerLivro(string isbn) {
    for (int i = 0; i < totalLivros; i++) {
        if (livrosPegos[i] == isbn) { // Se encontrar o ISBN
            // Substitui o livro removido pelo último da lista
            livrosPegos[i] = livrosPegos[totalLivros - 1];
            totalLivros--; // Diminui a quantidade de livros pegos
            break;         // Sai do loop após remover
        }
    }
}