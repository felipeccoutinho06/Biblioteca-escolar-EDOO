
# 📚 Sistema de Biblioteca Escolar – EDOO

Projeto desenvolvido em C++ com foco nos princípios da **Programação Orientada a Objetos (POO)**. O sistema simula uma biblioteca escolar com funcionalidades de cadastro de livros e usuários, empréstimos e devoluções.

---

## 🚀 Funcionalidades

- Cadastro de **livros**
- Cadastro de **alunos** e **professores**
- Empréstimo e devolução de livros
- Respeito ao limite de livros por tipo de usuário
- Visualização de empréstimos por usuário
- Exibição de livros disponíveis

---

## 🧱 Estrutura do Projeto

| Arquivo              | Descrição                                                  |
|----------------------|------------------------------------------------------------|
| `Main.cpp`           | Função principal e interface de linha de comando           |
| `Usuario.hpp/cpp`    | Classe base abstrata para usuários                         |
| `Aluno.hpp`          | Subclasse de `Usuario`, limite de 3 livros                 |
| `Professor.hpp`      | Subclasse de `Usuario`, limite de 5 livros                 |
| `Livros.hpp`         | Classe que representa um livro da biblioteca               |
| `Emprestimo.hpp/cpp` | Classe que gerencia um empréstimo individual               |
| `Biblioteca.hpp/cpp` | Classe que centraliza toda a lógica do sistema             |
| `dicionarios.hpp/cpp`| Arrays auxiliares (não usados diretamente no fluxo atual)  |

---

## 🧬 Conceitos de POO Aplicados

- **Encapsulamento**: atributos privados, métodos públicos
- **Herança**: `Aluno` e `Professor` herdam de `Usuario`
- **Polimorfismo**: uso de ponteiros para `Usuario` com métodos virtuais
- **Abstração**: `Usuario` é uma classe abstrata com método virtual puro

---

## 💻 Como Compilar e Executar

1. Compile com g++ (ou outro compilador C++):
   ```bash
   g++ *.cpp -o biblioteca
   ```

2. Execute o programa:
   ```bash
   ./biblioteca
   ```

> 💡 O sistema roda via **terminal**, com menus interativos para empréstimos e devoluções.

---

## 📌 Exemplo de Uso

```text
Digite o ID do usuario (ou -1 para sair): 3
Deseja ver todos os seus emprestimos? (s/n): s
Nenhum emprestimo encontrado para este usuario.

O que deseja fazer?
1 - Emprestar livro
2 - Devolver livro
Escolha uma opcao: 1

Digite o ISBN do livro: ISBN002
Digite a data do emprestimo (YYYY-MM-DD): 2025-07-13
Emprestimo realizado com sucesso!
```


---
## 👥 Membros da Equipe

- Arthur de Sá Tenório
- Davi Peixoto Freire Falcão
- Felipe Costa Coutinho
- João Hibernon Carneiro Leão de Araújo Lima

