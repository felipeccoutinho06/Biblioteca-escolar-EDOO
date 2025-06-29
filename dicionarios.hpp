#ifndef DICIONARIOS_HPP
#define DICIONARIOS_HPP

#include <map>
#include <string>
#include "Livros.hpp"
#include "Usuario.hpp"
#include "Emprestimo.hpp"

extern std::map<std::string, Livro> livrosDB;
extern std::map<int, Usuario*> usuariosDB;
extern std::map<int, Emprestimo> emprestimosDB;

void cadastrarLivro(const Livro& livro);
Livro* buscarLivro(const std::string& isbn);
void atualizarQuantidadeLivro(const std::string& isbn, int novaQuantidade);
void removerLivro(const std::string& isbn);

Usuario* buscarUsuario(int id);
void removerEmprestimo(int idEmprestimo);

#endif