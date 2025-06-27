#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"

class Aluno : public Usuario {
public:
    Aluno(string n, int i) : Usuario(n, i) {}

    int getLimiteLivros() const override { return 3; }
};

#endif