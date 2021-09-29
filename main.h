//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//

#ifndef PCO001_LISTA_ARRANJOS_MAIN_H
#define PCO001_LISTA_ARRANJOS_MAIN_H
#define INICIO_ARRANJO 1
#define TAMANHO_MAXIMO 100

#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    string chave;
} TipoItem;

typedef struct TipoLista
{
    TipoItem item[TAMANHO_MAXIMO];
    int primeiro{}, ultimo{};
} TipoLista;

bool isCheia(const TipoLista *lista) { return lista->ultimo == TAMANHO_MAXIMO; }

bool isVazia(const TipoLista *lista) { return lista->primeiro == lista->ultimo; }

void imprimeLista(TipoLista *lista)
{
    cout << "Lista -> ";
    for (int i = 0; i < lista->ultimo; i++)
    {
        cout << to_string(i+1) + ") " + lista->item[i].chave;
        if (i + 1 < lista->ultimo)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void inicializaLista(TipoLista* lista)
{
    lista->primeiro = INICIO_ARRANJO;
    lista->ultimo = lista->primeiro;
}

void insereValor(string item, int posicao, TipoLista* lista)
{
    if(isCheia(lista))
    {
        cout << "ERRO! Lista está cheia" << endl;
        return;
    }
    if(lista->ultimo < posicao)
    {
        lista->ultimo = posicao;
    }
    lista->item[posicao - 1].chave = std::move(item);
}

void retiraPrimeiroItem(TipoLista* lista)
{
    if (isVazia(lista))
    {
        cout << "ERRO! Lista está vazia" << endl;
        return;
    }
    for (int i = 0; i < lista->ultimo; i++)
    {
        lista->item[i] = lista->item[i+1];
    }
    lista->ultimo--;
}

void retira(TipoLista* lista, int posicao)
{
    if(isVazia(lista) || posicao - 1 > lista->ultimo)
    {
        cout << "ERRO! Lista está vazia ou índice fora do limite" << endl;
        return;
    }
    for(int i = posicao-1; i < lista->ultimo; i++)
    {
        lista->item[i] = lista->item[i+1];
    }
    lista->ultimo--;
}

void buscarValor(const TipoLista& lista, const string& valorBuscado)
{
    for (int i = lista.primeiro; i <= lista.ultimo; i++)
    {
        if(strcmp(lista.item[i - 1].chave.c_str(), valorBuscado.c_str()) == 0)
        {
            cout << "Valor " + valorBuscado + " encontrado na posição " + to_string(i) << endl;
            return;
        }
    }
    cout << "ERRO! Valor " + valorBuscado + " não encontrado" << endl;
}

void concatenarLista(const TipoLista& primeiraLista, const TipoLista& segundaLista, TipoLista* novaLista)
{
    int posicao = 1;
    if (primeiraLista.ultimo + segundaLista.ultimo > TAMANHO_MAXIMO)
    {
        cout << "ERRO! O tamanho das duas lista é maior do que a nova lista" << endl;
    }
    for (int i = primeiraLista.primeiro; i <= primeiraLista.ultimo; i++)
    {
        insereValor(primeiraLista.item[i-1].chave, posicao, novaLista);
        posicao++;
    }
    for (int j = segundaLista.primeiro; j <= segundaLista.ultimo; j ++)
    {
        insereValor(segundaLista.item[j-1].chave, posicao, novaLista);
        posicao++;
    }
}

void dividirListas(TipoLista& listaOriginal, TipoLista* novaListaEsquerda, TipoLista* novaListaDireita)
{
    int posicao = 1;
    int meio = listaOriginal.ultimo/2;
    for(int i = listaOriginal.primeiro - 1; i < listaOriginal.ultimo; i++)
    {
        if(i < meio)
        {
            insereValor(listaOriginal.item[i].chave, i+1, novaListaEsquerda);
        }
        else
        {
            insereValor(listaOriginal.item[i].chave, posicao, novaListaDireita);
            posicao++;
        }
    }
}

void copiarLista(TipoLista& listaOriginal, TipoLista* novaLista)
{
    for(int i = listaOriginal.primeiro; i <= listaOriginal.ultimo; i++)
    {
        insereValor(listaOriginal.item[i-1].chave ,i, novaLista);
    }
}
void ordenaLista(TipoLista* lista)
{
    string temp;
    for(int j = 0; j<lista->ultimo-1; j++)
    {
        for(int i = 0; i < lista->ultimo-1; i++)
        {
            if(lista->item[i].chave.compare(lista->item[i+1].chave) > 0)
            {
                temp = lista->item[i].chave;
                lista->item[i].chave = lista->item[i+1].chave;
                lista->item[i+1].chave = temp;
            }
        }
    }
}
void buscarOcorrenciaDeValor(TipoLista& lista, const string& valorBuscado)
{
    int ocorrencia = 0;
    bool isPresent = false;
    for (int i = lista.primeiro; i <= lista.ultimo; i++)
    {
        if(strcmp(lista.item[i - 1].chave.c_str(), valorBuscado.c_str()) == 0)
        {
            ocorrencia++;
            isPresent = true;
        }
    }
    if (isPresent)
    {
        cout << to_string(ocorrencia) + " ocorrências do valor " + valorBuscado + " encontradas" << endl;
        return;
    }
    cout << "ERRO! Valor " + valorBuscado + " não encontrado" << endl;
}

#endif //PCO001_LISTA_ARRANJOS_MAIN_H