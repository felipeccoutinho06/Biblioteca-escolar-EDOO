#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.hpp"

class Professor : public Usuario {
public:
    Professor(string n, int i);
    int getLimiteEmprestimo() const override;
};

#endif