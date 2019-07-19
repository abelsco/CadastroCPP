#include "geral.h"
#include "mainwindow.h"
#include <fstream>
/*template <class T>
No::No(T &valor)
{
    this->valor = valor;
    this->prox = NULL;
}
template <class T>
ListaEncadeada::ListaEncadeada()
{
    this->cabeca = NULL;
}
ListaEncadeada:: ~ListaEncadeada()
{
    while(cabeca != NULL)
        remover(cabeca->valor);
}

cliente::cliente(std::string nome, std::string email, std::string produto):pessoa(nome,email)
{
    produtoCliente = produto;
}

funcionario::funcionario(std::string nome,std::string email,std::string cpf):pessoa(nome,email)
{
    cpfFuncionario = cpf;
}

administrador::administrador(std::string nome,std::string email,std::string cpf, std::string senha): funcionario(nome,email,cpf)
{
    senhaAdministrador = senha;
}

void ListaEncadeada:: insere(T &valor)
{
    No <T> *novo = new No <T>(valor);

    if(cabeca == NULL)
        cabeca = novo;
    else
    {
        No <T> *tmp = cabeca;
        while(tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
}
template <class T>
bool ListaEncadeada:: remover(T &valor)
{
    if(cabeca == NULL)
    {
        return false;
    }

    else
    {
        No <T> *NoAux = cabeca->prox;
        No <T> *NoAnterior = cabeca;

        if(cabeca->valor == valor)
        {
            cabeca = cabeca->prox;
        }

        while( NoAux != NULL )
        {
            if (NoAux->valor == valor)  //encontrou elemento procurado
            {
                NoAnterior->prox = NoAux->prox;
                delete NoAux;

            }
            NoAnterior = NoAux;
            NoAux = NoAux->prox;
            return true;

        }

        return false;   // elemento nao encontrado
    }
}
template <class T>
T ListaEncadeada:: buscar(T valor)
{
    if(cabeca == NULL)
    {
        return NULL;
    }
    else
    {

        No <T> *ptrAux = this->cabeca;
        while( ptrAux )
        {
            if (ptrAux->valor == valor) //encontrou elemento procurado
                return ptrAux->valor;

            ptrAux = ptrAux->prox;
        }

        return NULL;   // elemento nao encontrado
    }
}*/

cliente::cliente(std::string nome, std::string email, std::string produto, int cod,double preco):pessoa(nome,email,cod)
{
    produtoCliente = produto;
    this->preco = preco;
}
funcionario::funcionario(std::string nome,std::string email,std::string cpf,int cod):pessoa(nome,email,cod)
{
    cpfFuncionario = cpf;
}
administrador::administrador(std::string nome,std::string email,std::string cpf, std::string senha,int cod): funcionario(nome,email,cpf,cod)
{
    senhaAdministrador = senha;
}
pessoa::pessoa(std::string novoNome, std::string novoEmail, int cod)
{
    nome = novoNome;
    email = novoEmail;
    this->cod = cod;
}

int pessoa::getCod()
{
    return cod;
}

void cliente::cadastro(std::ofstream &arq)
{
    arq << "CLIENTE" << " COD: " << cod << std::endl;
    arq << "NOME: " << nome << std::endl;
    arq << "EMAIL: " << email << std::endl;
    arq << "PRODUTO: " << produtoCliente << std::endl;
    arq << "PRECO: " << preco << std::endl;
    arq << "===============" << std::endl;
}

void funcionario::cadastro(std::ofstream &arq)
{
    arq << "FUNCIONARIO"  << " COD: " << cod << std::endl;
    arq << "NOME: " << nome << std::endl;
    arq << "EMAIL: " << email << std::endl;
    arq << "CPF: "<< cpfFuncionario << std::endl;
    arq << "===============" << std::endl;
}

void administrador::cadastro(std::ofstream &arq)
{
    arq << "ADMINISTRADOR"  << " COD: " << cod << std::endl;
    arq << "NOME: " << nome << std::endl;
    arq << "EMAIL: " << email << std::endl;
    arq << "CPF: " << cpfFuncionario << std::endl;
    arq << "SENHA: " << senhaAdministrador << std::endl;
    arq << "===============" << std::endl;
}

/*template <class T>
void busca(std::list<T> lista, T elemento, int cod )
{
    typename std::list<T>::iterator iterador;

    for( iterador = lista.begin(); iterador != lista.end(); iterador++) {
        if(iterador->cod == cod)
            elemento = *iterador;
    }
}*/

/*template <class T1, class T2>
void busca(T1 lista, T2 elemento, int cod )
{
    typename T1::iterator iterador;

    for( iterador = lista.begin(); iterador != lista.end(); iterador++) {
        if(iterador->cod == cod)
            elemento = *iterador;
    }
}*/

template <class T>
void busca(T lista, int cod )
{
    /*typename T::iterator iterador;

    for( iterador = lista.begin(); iterador != lista.end(); iterador++) {
        if(iterador->getCod() == cod){}


    }*/
}
