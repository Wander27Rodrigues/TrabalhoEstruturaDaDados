/*
    Programa para impelementrar fila com alocação dinâmica de memória.

    Prgrama exemplo de implementação das rotinas básicas de um estrutura de dados do tipo FILA, com:
    - Função Enfileirar()
    - Função Desenfileirar()
    - Função Vazia()
    - Função Exibir()
*/
#include <iostream>
using namespace std;

// Estrutura para a fila dinâmica.
struct t_fila {
    int dado;
    struct t_fila *prox;
};

// Assinatura das funções.
void Enfileirar(struct t_fila *, int);
int Desenfileirar(struct t_fila *);
int Vazia(struct t_fila *);
void Exibir(struct t_fila *);

// Início do programa principal.
int main(void)
{
    char opcao, pausa;
    int valor;
    // Criação da fila (cabeça = minha_fila)
    struct t_fila minha_fila;
    minha_fila.prox = NULL;

    do
    {
        system("clear");
        cout << "=========================================" << endl;
        cout << "Prorama de implementação de Fila Dinâmica" << endl;
        cout << "-----------------------------------------" << endl;
        cout << " 1 - Enfileirar" << endl;
        cout << " 2 - Desenfileirar" << endl;
        cout << " 3 - Exiber" << endl;
        cout << " 0 - Sair" << endl;
        cout << "-----------------------------------------" << endl;
        cout << " Escolha uma opção: ";
        cin >> opcao;
        switch (opcao)
        {
        case '1':
            cout << "Digite o valor: ";
            cin >> valor;  //2 
            Enfileirar(&minha_fila, valor);
            break;
        case '2':
            if (Vazia(&minha_fila))
                cout << "Fila vazia!" << endl;
            else
            {
                valor = Desenfileirar(&minha_fila);
                cout << valor << endl;
                cout << "desenfileirado!" << endl;
            }
            break;
        case '3':
            if (Vazia(&minha_fila))
                cout << "Fila vazia!" << endl;
            else
                Exibir(&minha_fila);
            break;
        }
        cout << "Digite 1 e tecle <Enter>!";
        cin >> pausa;
    } while (opcao != '0');
    return 0;
}

void Enfileirar(struct t_fila *ptr_fila, int valor)
{
    struct t_fila *novo, *elemento;
    novo = new t_fila;
    //Verificar se fila está cheia.
    if (novo == NULL)
        cout << "Fila cheia!";
    else
    {
        if (ptr_fila->prox == NULL)
        {
            novo->dado = valor;
            novo->prox = NULL;
            ptr_fila->prox = novo;
        }
        else
        {
            novo->dado = valor;
            novo->prox = NULL;
            elemento = ptr_fila;
            while(elemento->prox != NULL)
                elemento = elemento->prox;
            elemento->prox = novo;
        }
        cout << "Enfileirado!" << endl;
    }
}

void Exibir(struct t_fila *ptr_fila)
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

int Desenfileirar(struct t_fila *ptr_fila)
{
    struct t_fila *elemento;
    int valor;
    elemento = ptr_fila->prox;
    valor = elemento->dado;
    ptr_fila->prox = elemento->prox;
    delete elemento;
    return valor;
}

int Vazia(struct t_fila *ptr_fila)
{
    if (ptr_fila->prox == NULL)
        return 1;
    else
        return 0;
}
