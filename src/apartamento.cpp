#include "apartamento.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;
/*
Mudanças no ultimo commit:
criado o construtor
algumas funções refeitas para usar os parâmetros
chamada de funções implementadas no .h

ideias:
vincular o pet e o veículo a um dono
colocar mais estatisticas
*/

//tem que testar esse construtor pra ver se ele funciona como o esperado
Apartamento::Apartamento(int max_Adm = 1, int max_Morador = 5, int max_Visitante = 10,
                         int max_Pet = 3, int max_Veiculo = 2)
{
    numeroAdm = max_Adm;
    numeroMoradores = max_Morador;
    numeroVisitantes = max_Visitante;
    numeroPets = max_Pet;
    numeroVeiculos = max_Veiculo;
}
//talvez seria interessante criar uma função que adiciona o tipo_pessoa pra usar aq e no editar pessoa
void Apartamento::inserir_pessoa(string nome, string data_nascimento, string tipo_pessoa)
{
    Pessoa pessoa;

    pessoa.nome = nome;
    pessoa.data_nascimento = data_nascimento;

    if (tipo_pessoa == "administradora")
    {
        pessoa.tipo_pessoa = administradora;
    }
    else if (tipo_pessoa == "moradora")
    {
        pessoa.tipo_pessoa = moradora;
    }
    else if (tipo_pessoa == "visitante")
    {
        pessoa.tipo_pessoa = visitante;
    }
}
//o mesmo vale pra essa...
void Apartamento::inserir_pet(string nome, string raca, string tipo)
{
    Pet pet;
    pet.nome = nome;
    pet.raca = raca;

    if (tipo == "cachorro")
    {
        pet.tipo_pet = cachorro;
    }
    else if (tipo == "gato")
    {
        pet.tipo_pet = cachorro;
    }
    else if (tipo == "passaro")
    {
        pet.tipo_pet = passaro;
    }
    else if (tipo == "outro")
    {
        pet.tipo_pet = outro;
    }
    pets_.push_back(pet);
}

void Apartamento::inserir_veiculo(string modelo, string placa, string tipo_veiculo)
{
    Veiculo veiculo;
    veiculo.modelo = modelo;
    veiculo.placa = placa;
    veiculo.tipo_veiculo = tipo_veiculo;
    veiculos_.push_back(veiculo);
}
void Apartamento::editar_pessoa(string nome_antigo, string nome_novo, string data_nascimento_antiga,
                                string data_nascimento_nova, string tipo_pessoa)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_antigo && (*it).data_nascimento == data_nascimento_antiga)
        {
            (*it).nome = nome_novo;
            (*it).data_nascimento = data_nascimento_nova;

            if (tipo_pessoa == "administradora")
            {
                (*it).tipo_pessoa = administradora;
            }
            else if (tipo_pessoa == "moradora")
            {
                (*it).tipo_pessoa = moradora;
            }
            else if (tipo_pessoa == "visitante")
            {
                (*it).tipo_pessoa = visitante;
            }
            break;
        }
    }
}
void Apartamento::editar_pet(string nome_pet, string nome_pet_novo, string raca_antiga,
                             string raca, string tipo)
{

    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if ((*it).nome == nome_pet && (*it).raca == raca_antiga)
        {
            (*it).nome = nome_pet_novo;
            (*it).raca = raca;

            if (tipo == "cachorro")
            {
                (*it).tipo_pet = cachorro;
            }
            else if (tipo == "gato")
            {
                (*it).tipo_pet = cachorro;
            }
            else if (tipo == "passaro")
            {
                (*it).tipo_pet = passaro;
            }
            else if (tipo == "outro")
            {
                (*it).tipo_pet = outro;
            }
            break;
        }
    }
}
void Apartamento::editar_veiculo(string placa_antiga, string placa_nova, string modelo, string tipo_veiculo)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if ((*it).placa == placa_antiga)
        {
            (*it).modelo = modelo;
            (*it).placa = placa_nova;
            (*it).tipo_veiculo = tipo_veiculo;

            break;
        }
    }
}

void Apartamento::excluir_pessoa(string nome_pessoa, string data_nascimento)
{
    for (auto it = pessoas_.begin(); it != pessoas_.end(); it++)
    {
        if ((*it).nome == nome_pessoa && (*it).data_nascimento == data_nascimento)
        {
            pessoas_.erase(it);
            break;
        }
    }
}

void Apartamento::excluir_pet(string nome_pet, string raca)
{
    for (auto it = pets_.begin(); it != pets_.end(); it++)
    {
        if ((*it).nome == nome_pet && (*it).raca == raca)
        {
            pets_.erase(it);
            break;
        }
    }
}

void Apartamento::excluir_veiculo(string placa)
{
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
        if ((*it).placa == placa)
        {
            veiculos_.erase(it);
        }
    }
}

void Apartamento::exibir_estatisticas()
{
    cout << "Quantidades de moradores do prédio: " << contar_moradores();
    cout << "Quantidade de visitantes: " << contar_visitantes();
    cout << "Quantidade de pets: " << pets_.size();
    cout << "Quantidade de veículos: " << veiculos_.size();

    /*
    Se tiver mais alguma coisa que vocês quiserem adicionar nessa função fiquem a vontade,
    lembrem de sempre usar o encapsulamento.
    */
}