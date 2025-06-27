#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

class Professor : public Usuario {
public:
    Professor(string n, int i) : Usuario(n, i) {}

    int getLimiteLivros() const override { return 5; }
};

#endif