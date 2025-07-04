#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

// Classe Professor, derivada de Usuario
class Professor : public Usuario {
public:
    // Construtor que chama o construtor da classe base Usuario
    Professor(string n, int i) : Usuario(n, i) {}

    // Sobrescreve o método para definir o limite de livros para professor
    int getLimiteLivros() const override { return 5; }
};

#endif