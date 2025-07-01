#ifndef DICIONARIOS_HPP
#define DICIONARIOS_HPP

#include <string>
#include "Livros.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"

extern const int MAX_LIVROS;
extern const int MAX_USUARIOS;
extern const int MAX_EMPRESTIMOS;

extern Livro livrosDB[];
extern int totalLivrosDB;

extern Usuario* usuariosDB[];
extern int totalUsuariosDB;

extern Emprestimo emprestimosDB[];
extern int totalEmprestimosDB;


void cadastrarLivro(const Livro& livro);
Livro* buscarLivro(const std::string& isbn);
void atualizarQuantidadeLivro(const std::string& isbn, int novaQuantidade);
void removerLivro(const std::string& isbn);

Usuario* buscarUsuario(int id);
void removerEmprestimo(int indice);

#endif