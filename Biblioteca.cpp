#include "Biblioteca.hpp"
#include <iostream>
using namespace std;

Biblioteca::~Biblioteca() {
    for (int i = 0; i < totalLivros; i++) {
        delete livros[i];
    }
    for (int i = 0; i < totalUsuarios; i++) {
        delete usuarios[i];
    }
}

void Biblioteca::adicionarLivro(Livro* livro) {
    if (totalLivros < TAMANHO_MAXIMO) {
        livros[totalLivros] = livro;
        totalLivros++;
    } else {
        cout << "Limite de livros atingido.\n";
    }
}

void Biblioteca::adicionarUsuario(Usuario* usuario) {
    if (totalUsuarios < TAMANHO_MAXIMO) {
        usuarios[totalUsuarios] = usuario;
        totalUsuarios++;
    } else {
        cout << "Limite de usuarios atingido.\n";
    }
}

void Biblioteca::emprestarLivro(string isbn, int userId, string dataEmprestimo) {
    Livro* livro = nullptr;
    Usuario* usuario = nullptr;

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->getISBN() == isbn && livros[i]->estaDisponivel()) {
            livro = livros[i];
            break;
        }
    }

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            usuario = usuarios[i];
            break;
        }
    }

    if (livro && usuario) {
        if (usuario->jaPegouLivro(isbn)) {
            cout << "Este usuario ja pegou este livro antes.\n";
            return;
        }

        if (!usuario->podePegarMais()) {
            cout << "Este usuario atingiu o limite de livros emprestados.\n";
            return;
        }

        livro->emprestar();
        usuario->registrarLivro(isbn);

        emprestimos[totalEmprestimos] = Emprestimo(livro, usuario, dataEmprestimo);
        cout << "Emprestimo realizado com sucesso!\n";
        emprestimos[totalEmprestimos].exibirDetalhes(); // <-- Adicione esta linha aqui
        totalEmprestimos++;
        
        cout << "Emprestimo realizado com sucesso!\n";
    } else {
        cout << "Livro indisponivel ou usuario nao encontrado.\n";
    }
}

void Biblioteca::devolverLivro(string isbn, int userId) {
    Livro* livro = nullptr;
    Usuario* usuario = nullptr;

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->getISBN() == isbn) {
            livro = livros[i];
            break;
        }
    }

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            usuario = usuarios[i];
            break;
        }
    }

    if (livro && usuario) {
        livro->devolver();
        usuario->removerLivro(isbn);
        cout << "Livro devolvido com sucesso!\n";
    } else {
        cout << "Livro ou usuario nao encontrado.\n";
    }
}

void Biblioteca::exibirEmprestimos() const {
    cout << "Emprestimos Ativos:\n";
    for (int i = 0; i < totalEmprestimos; i++) {
        emprestimos[i].exibirDetalhes();
        cout << "-------------------\n";
    }
}

bool Biblioteca::idUsuarioExiste(int userId) const {
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            return true; // ID encontrado
        }
    }
    return false; // ID não encontrado
}

bool Biblioteca::isbnLivroExiste(const string& isbn) const {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->getISBN() == isbn) {
            return true; // ISBN encontrado
        }
    }
    return false; // ISBN não encontrado
}

void Biblioteca::exibirLivros(int userId) const {
    cout << "\nLivros cadastrados:\n";
    Usuario* usuario = nullptr;
    if (userId != -1) {
        for (int i = 0; i < totalUsuarios; i++) {
            if (usuarios[i]->getId() == userId) {
                usuario = usuarios[i];
                break;
            }
        }
    }
    for (int i = 0; i < totalLivros; i++) {
        bool disponivel = livros[i]->estaDisponivel();
        if (usuario && usuario->jaPegouLivro(livros[i]->getISBN())) {
            disponivel = false;
        }
        cout << livros[i]->getTitulo() << " (ISBN: " << livros[i]->getISBN()
             << ", Disponível: " << (disponivel ? "Sim" : "Não") << ")\n";
    }
}

void Biblioteca::exibirEmprestimosDoUsuario(int userId) const {
    bool encontrou = false;
    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].getUsuario()->getId() == userId) {
            emprestimos[i].exibirDetalhes();
            encontrou = true;
        }
    }
    if (!encontrou) {
        cout << "Nenhum emprestimo encontrado para este usuario.\n";
    }
}