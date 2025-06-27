#include "Professor.hpp"

Professor::Professor(string n, int i) : Usuario(n, i) {}

int Professor::getLimiteEmprestimo() const {
    return 5;
}