#include "Biblioteca.hpp"
#include <iostream>
using namespace std;

// Destrutor: libera a memória dos livros e usuários cadastrados
Biblioteca::~Biblioteca() {
    for (int i = 0; i < totalLivros; i++) {
        delete livros[i];
    }
    for (int i = 0; i < totalUsuarios; i++) {
        delete usuarios[i];
    }
}

// Adiciona um novo livro ao acervo, se houver espaço
void Biblioteca::adicionarLivro(Livro* livro) {
    if (totalLivros < TAMANHO_MAXIMO) {
        livros[totalLivros] = livro;
        totalLivros++;
    } else {
        cout << "Limite de livros atingido.\n";
    }
}

// Adiciona um novo usuário à biblioteca, se houver espaço
void Biblioteca::adicionarUsuario(Usuario* usuario) {
    if (totalUsuarios < TAMANHO_MAXIMO) {
        usuarios[totalUsuarios] = usuario;
        totalUsuarios++;
    } else {
        cout << "Limite de usuarios atingido.\n";
    }
}

// Realiza o empréstimo de um livro para um usuário
void Biblioteca::emprestarLivro(string isbn, int userId, string dataEmprestimo) {
    Livro* livro = nullptr;
    Usuario* usuario = nullptr;

    // Procura o livro disponível pelo ISBN
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->getISBN() == isbn && livros[i]->estaDisponivel()) {
            livro = livros[i];
            break;
        }
    }

    // Procura o usuário pelo ID
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            usuario = usuarios[i];
            break;
        }
    }

    // Se encontrou livro e usuário válidos
    if (livro && usuario) {
        // Verifica se o usuário já pegou este livro
        if (usuario->jaPegouLivro(isbn)) {
            cout << "Este usuario ja pegou este livro antes.\n";
            return;
        }

        // Verifica se o usuário pode pegar mais livros
        if (!usuario->podePegarMais()) {
            cout << "Este usuario atingiu o limite de livros emprestados.\n";
            return;
        }

        // Faz o empréstimo
        livro->emprestar();         // <-- Diminui a quantidade do livro
        usuario->registrarLivro(isbn);

        emprestimos[totalEmprestimos] = Emprestimo(livro, usuario, dataEmprestimo);
        totalEmprestimos++;

        cout << "Emprestimo realizado com sucesso!\n";
        emprestimos[totalEmprestimos - 1].exibirDetalhes();
    } else {
        cout << "Livro indisponivel ou usuario nao encontrado.\n";
    }
}

// Realiza a devolução de um livro por um usuário
void Biblioteca::devolverLivro(string isbn, int userId) {
    Livro* livro = nullptr;
    Usuario* usuario = nullptr;

    // Procura o livro pelo ISBN
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->getISBN() == isbn) {
            livro = livros[i];
            break;
        }
    }

    // Procura o usuário pelo ID
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            usuario = usuarios[i];
            break;
        }
    }

    // Se encontrou livro e usuário válidos
    if (livro && usuario) {
        livro->devolver();           // Devolve o exemplar ao acervo
        usuario->removerLivro(isbn); // Remove o livro da lista do usuário
        
        // 3) Remove o empréstimo do array emprestimos[]
        for (int i = 0; i < totalEmprestimos; i++) {
            // Agora podemos acessar emprestimos[i].livro e emprestimos[i].usuario
            if (emprestimos[i].livro == livro && emprestimos[i].usuario == usuario) {
                emprestimos[i] = emprestimos[totalEmprestimos - 1];
                totalEmprestimos--;
                break;
            }
        }
        
        cout << "Livro devolvido com sucesso!\n";
    } else {
        cout << "Livro ou usuario nao encontrado.\n";
    }
}

// Exibe todos os empréstimos ativos da biblioteca
void Biblioteca::exibirEmprestimos() const {
    cout << "Emprestimos Ativos:\n";
    for (int i = 0; i < totalEmprestimos; i++) {
        emprestimos[i].exibirDetalhes();
        cout << "-------------------\n";
    }
}

// Verifica se um usuário com o ID informado existe
bool Biblioteca::idUsuarioExiste(int userId) const {
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            return true; // ID encontrado
        }
    }
    return false; // ID não encontrado
}

// Verifica se um livro com o ISBN informado existe
bool Biblioteca::isbnLivroExiste(const string& isbn) const {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->getISBN() == isbn) {
            return true; // ISBN encontrado
        }
    }
    return false; // ISBN não encontrado
}

// Exibe todos os livros cadastrados, indicando se estão disponíveis para o usuário
void Biblioteca::exibirLivros(int userId) const {
    cout << "\nLivros cadastrados:\n";
    Usuario* usuario = nullptr;
    // Procura o usuário pelo ID (se fornecido)
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i]->getId() == userId) {
            usuario = usuarios[i];
            break;
        }
    }
    // Exibe cada livro, mostrando se está disponível para o usuário
    for (int i = 0; i < totalLivros; i++) {
        bool disponivel = livros[i]->estaDisponivel();
        // Se o usuário já pegou o livro, marca como indisponível para ele
        if (usuario && usuario->jaPegouLivro(livros[i]->getISBN())) {
            disponivel = false;
        }
        cout << livros[i]->getTitulo() << " (ISBN: " << livros[i]->getISBN()
             << ", Disponivel: " << (disponivel ? "Sim" : "Nao") << ")\n";
    }
}

// Exibe todos os empréstimos feitos por um usuário específico
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