#include "Usuario.hpp"

Usuario::Usuario(string n, int i) : nome(n), id(i) {}

string Usuario::getNome() const {
    return nome;
}

int Usuario::getId() const {
    return id;
}