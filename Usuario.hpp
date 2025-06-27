#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nome;
    int id;

public:
    Usuario(string n, int i);
    virtual int getLimiteEmprestimo() const = 0;
    string getNome() const;
    int getId() const;
    virtual ~Usuario() {}
};

#endif 