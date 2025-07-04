#ifndef DICIONARIOS_HPP
#define DICIONARIOS_HPP

#include <string>        // Usado para manipular strings
#include "Livros.hpp"    // Declarações da classe Livro
#include "Usuario.hpp"   // Declarações da classe Usuario
#include "Emprestimo.hpp"// Declarações da classe Emprestimo

// Máximos permitidos para cada tipo de entidade
extern const int MAX_LIVROS;
extern const int MAX_USUARIOS;
extern const int MAX_EMPRESTIMOS;

// Arrays globais para armazenar livros, usuários e empréstimos
extern Livro livrosDB[];
extern int totalLivrosDB;

extern Usuario* usuariosDB[];
extern int totalUsuariosDB;

extern Emprestimo emprestimosDB[];
extern int totalEmprestimosDB;

// Funções para gerenciar livros
void cadastrarLivro(const Livro& livro);
Livro* buscarLivro(const std::string& isbn);
void atualizarQuantidadeLivro(const std::string& isbn, int novaQuantidade);
void removerLivro(const std::string& isbn);

// Funções para gerenciar usuários e empréstimos
Usuario* buscarUsuario(int id);
void removerEmprestimo(int indice);

#endif