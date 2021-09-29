//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//
#include "main.h"

int main()
{
    auto *primeiraLista = new TipoLista;
    auto *segundaLista = new TipoLista;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    inicializaLista(primeiraLista);
    inicializaLista(segundaLista);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);

    cout << endl << "02. Inserir um novo item imediatamente após o i-ésimo item" << endl;
    insereValor("banana", 3, primeiraLista);
    insereValor("laranja", 5, primeiraLista);
    insereValor("manga", 4, primeiraLista);
    insereValor("morango", 2, primeiraLista);
    insereValor("uva", 1, primeiraLista);
    insereValor("batata", 4, segundaLista);
    insereValor("cebola", 5, segundaLista);
    insereValor("vagem", 6, segundaLista);
    insereValor("cenoura", 2, segundaLista);
    insereValor("beterraba", 1, segundaLista);
    insereValor("tomate",3, segundaLista);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);

    cout << endl <<  "03. Retirar o primeiro item" << endl;
    retiraPrimeiroItem(primeiraLista);
    retiraPrimeiroItem(segundaLista);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);

    cout << endl << "04. Retirar o i-ésimo item" << endl;
    retira(primeiraLista, 1);
    retira(segundaLista, 2);
    imprimeLista(primeiraLista);
    imprimeLista(segundaLista);

    cout << endl <<  "05. Localizar um item na Lista" << endl;
    buscarValor(*primeiraLista, "banana");
    buscarValor(*primeiraLista, "laranja");
    buscarValor(*segundaLista, "tomate");
    buscarValor(*segundaLista, "cenoura");

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    auto *novaLista = new TipoLista;
    inicializaLista(novaLista);
    concatenarLista(*segundaLista, *primeiraLista, novaLista);
    imprimeLista(novaLista);

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto *novaListaEsquerda = new TipoLista;
    auto *novaListaDireita = new TipoLista;
    inicializaLista(novaListaEsquerda);
    inicializaLista(novaListaDireita);
    dividirListas(*novaLista, novaListaEsquerda, novaListaDireita);
    imprimeLista(novaListaEsquerda);
    imprimeLista(novaListaDireita);

    cout << endl << "08. Fazer uma cópia" << endl;
    auto *listaCopiada = new TipoLista;
    inicializaLista(listaCopiada);
    copiarLista(*novaListaEsquerda, listaCopiada);
    imprimeLista(listaCopiada);

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaLista(novaLista);
    imprimeLista(novaLista);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    insereValor("laranja", 8, novaLista);
    imprimeLista(novaLista);
    buscarOcorrenciaDeValor(*novaLista, "laranja");
}
