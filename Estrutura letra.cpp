/*
    JOÃO PEDRO MOREIRA FARIAS
    MAT: 201902447158

    WANDER ALISSON RODRIGUES DE SOUZA
    MAT: 201801130469

*/

#include <iostream>
#include <cstring>
using namespace std;

struct t_fila {
    char dado;
    struct t_fila *prox;
};

void Chegada(struct t_fila *, char); 
int Atendido(struct t_fila *); 
int S_Paciente(struct t_fila *); 
void Mostrar(struct t_fila *); 


int main(void) {
    char pausa, Paciente;
    int opcao;
    
    struct t_fila minha_fila;
    minha_fila.prox = NULL;
    
    opcao = 0;
    
    while (opcao != 4) {
    	cout << "Controle de Atendimento \n 1 - Chegada\n 2 - Atendido\n 3 - Mostrar\n 4 - Sair\n Escolha a sua opcao: ";
	    cin >> opcao;
	        
	    switch (opcao) {
	        case 1:
	            cout << "Nome do Paciente: ";
	            cin >> Paciente;  
	            Chegada(&minha_fila, Paciente);
	            break;
	  
	            
	        case 2:
	            if (S_Paciente(&minha_fila))
	                cout << "Sem Pacientes p/ Consulta!" << endl;
	            else
	            {
	                Paciente = Atendido(&minha_fila);
	                cout << Paciente << endl;
	                cout << "Atendido!" << endl;
	            }
	            break;
	            
	        case 3:
	            if (S_Paciente(&minha_fila))
	                cout << "Sem Pacientes p/ Consulta!" << endl;
	            else
	                Mostrar(&minha_fila);
	            break;
	    }
	}


}

void Chegada(struct t_fila *ptr_fila, char Paciente) {
    struct t_fila *novo, *elemento;
    novo = new t_fila;
    
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

int Atendido(struct t_fila *ptr_fila)
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
