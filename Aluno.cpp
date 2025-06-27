#include "Aluno.hpp"

Aluno::Aluno(string n, int i) : Usuario(n, i) {}

int Aluno::getLimiteEmprestimo() const {
    return 3;
}