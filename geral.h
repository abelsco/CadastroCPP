#ifndef GERAL_H
#define GERAL_H
#include <iostream>
#include <fstream>
#include <list>

template <class T>
class No
{
public:
    T valor;
    No *prox;

    No (T valor);
};

template <class T>
class ListaEncadeada
{
private:
    No <T> *cabeca;
public:
    ListaEncadeada();

    ~ListaEncadeada();

    void insere(T &valor);
    bool remover(T &valor);
    T buscar(T valor);
};


class pessoa{
protected:
    std::string nome, email;
    int cod;
public:
    pessoa(std::string novoNome,std::string novoEmail, int cod);
    virtual void cadastro(std::ofstream &arq) = 0;
    int getCod();

};

class cliente : public pessoa{
protected:
    std::string produtoCliente;
    double preco;
public:
    cliente(std::string nome, std::string email, std::string produto, int cod,double preco);
    void cadastro(std::ofstream &arq);
};

class funcionario : public pessoa
{
protected:
    std::string cpfFuncionario;
public:
    funcionario(std::string nome,std::string email,std::string cpf,int cod);
    void cadastro(std::ofstream &arq);
};

class administrador : public funcionario {
protected:
    std::string senhaAdministrador;
public:
    administrador(std::string nome,std::string email,std::string cpf, std::string senha,int cod);
    void cadastro(std::ofstream &arq);
};

/*template <class T>
void busca(std::list<T> lista, T elemento, int cod );*/

/*template <class T1, class T2>
void busca(T1 lista, T2 elemento, int cod );*/

template <class T>
void busca(T lista, int cod );


#endif // GERAL_H
