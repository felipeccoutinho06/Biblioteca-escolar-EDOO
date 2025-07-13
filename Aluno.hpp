#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"

// Classe Aluno, derivada de Usuario
class Aluno : public Usuario {
public:
    // Construtor que chama o construtor da classe base Usuario
    Aluno(string n, int i) : Usuario(n, i) {}

    // Sobrescreve o método para definir o limite de livros para aluno
    int getLimiteLivros() const override { return 3; }
};

#endif
