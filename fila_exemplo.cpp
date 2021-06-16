/*
    Programa para impelementrar fila com alocação dinâmica de memória.

    Prgrama exemplo de implementação das rotinas básicas de um estrutura de dados do tipo FILA, com:
    - Função Enfileirar()
    - Função Desenfileirar()
    - Função Vazia()
    - Função Exibir()
*/
#include <iostream>
#include <cstring>
using namespace std;

// Estrutura para a fila dinâmica.
struct t_fila {
    int dado;
    struct t_fila *prox;
};

// Assinatura das funções.
void Chegada(struct t_fila *, char); //enfileirar
void Atendido(struct t_fila *); //desenfileirar
int S_Paciente(struct t_fila *); //vazia
void Mostrar(struct t_fila *); //exibir

// Início do programa principal.
int main(void)
{
    char opcao, pausa;
    char Paciente[10];
    // Criação da fila (cabeça = minha_fila)
    struct t_fila minha_fila;
    minha_fila.prox = NULL;

    do
    {
        system("clear");
        cout << "===========================================" << endl;
        cout << "====================| |====================" << endl;
        cout << "=============|Amaral Peitoral|=============" << endl;
        cout << "====================| |====================" << endl;
        cout << "====================| |====================" << endl;
        cout << "====================| |====================" << endl;
        cout << "===========================================" << endl;
        cout << " Controle de Atendimento " << endl;
        cout << "........................................." << endl;
        cout << " 1 - Chegada" << endl;
        cout << " 2 - Atendido" << endl;
        cout << " 3 - Mostrar" << endl;
        cout << " 0 - Fechar Programa" << endl;
        cout << "........................................." << endl;
        cout << " Escolha uma opção: ";
        cin >> opcao;
        switch (opcao)
        {
        case '1':
            cout << "Nome do Paciente: ";   //digite o valor
            cin >> Paciente;  //valor 
            Chegada(&minha_fila, Paciente);
            break;
        case '2':
            if (S_Paciente(&minha_fila))
                cout << "Sem Pacientes p/ Consulta!" << endl;
            else
            {
                Paciente = Atendido(&minha_fila);
                cout << Paciente << endl;
                cout << "Atendido!" << endl;
            }
            break;
        case '3':
            if (S_Paciente(&minha_fila))
                cout << "Sem Pacientes p/ Consulta!" << endl;
            else
                Mostrar(&minha_fila);
            break;
        }
        cout << "Digite 1 e tecle <Enter>!";
        cin >> pausa;
    } while (opcao != '0');
    return 0;
}

void Chegada(struct t_fila *ptr_fila, char Paciente)
{
    struct t_fila *novo, *elemento;
    novo = new t_fila;
    //Verificar se fila está cheia.
    if (novo == NULL)
        cout << "Lotado de Pacientes!";
    else
    {
        if (ptr_fila->prox == NULL)
        {
            novo->dado = Paciente;
            novo->prox = NULL;
            ptr_fila->prox = novo;
        }
        else
        {
            novo->dado = Paciente;
            novo->prox = NULL;
            elemento = ptr_fila;
            while(elemento->prox != NULL)
                elemento = elemento->prox;
            elemento->prox = novo;
        }
        cout << "Chegada de Paciente!" << endl;
    }
}

void Mostrar(struct t_fila *ptr_fila)
{
    struct t_fila *elemento;
    elemento = ptr_fila->prox;
    while (elemento != NULL)
    {
        cout << elemento->dado << endl;
        elemento = elemento->prox;
    }
    cout << "-----------------" << endl;
}

void Atendido(struct t_fila *ptr_fila)
{
    struct t_fila *elemento;
    int valor;
    elemento = ptr_fila->prox;
    valor = elemento->dado;
    ptr_fila->prox = elemento->prox;
    delete elemento;
    return valor;
}

int S_Paciente(struct t_fila *ptr_fila)
{
    if (ptr_fila->prox == NULL)
        return 1;
    else
        return 0;
}
