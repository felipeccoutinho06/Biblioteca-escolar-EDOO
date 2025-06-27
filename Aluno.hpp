#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.hpp"

class Aluno : public Usuario {
public:
    Aluno(string n, int i);
    int getLimiteEmprestimo() const override;
};

#endif