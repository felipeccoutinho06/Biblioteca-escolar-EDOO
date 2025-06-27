#include "Usuario.hpp"

bool Usuario::jaPegouLivro(string isbn) const {
    for (int i = 0; i < totalLivros; i++) {
        if (livrosPegos[i] == isbn) {
            return true;
        }
    }
    return false;
}

void Usuario::registrarLivro(string isbn) {
    if (totalLivros < getLimiteLivros()) {
        livrosPegos[totalLivros] = isbn;
        totalLivros++;
    }
}

void Usuario::removerLivro(string isbn) {
    for (int i = 0; i < totalLivros; i++) {
        if (livrosPegos[i] == isbn) {
            // Substitui pelo último e diminui a quantidade
            livrosPegos[i] = livrosPegos[totalLivros - 1];
            totalLivros--;
            break;
        }
    }
}