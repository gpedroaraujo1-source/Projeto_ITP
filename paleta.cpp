#include "paleta.h"
#include <fstream>
#include <iostream>
#include <string>

Paleta::Paleta() {
    n_cores = 0;
    cores = nullptr;
}

Paleta::Paleta(std::string nomeArquivo) {
    n_cores = 0;
    cores = nullptr;

    std::ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            Cor cor;
            cor.r = stoi(linha.substr(1, 2), nullptr, 16);
            cor.g = stoi(linha.substr(3, 2), nullptr, 16);
            cor.b = stoi(linha.substr(5, 2), nullptr, 16);

            adicionarCor(cor);
        }
        arquivo.close();
    } else {
        std::cout << "Erro: Arquivo não encontrado" << std::endl;
    }
}

void Paleta::adicionarCor(Cor c) {
    Cor *novoArray = new Cor[n_cores + 1]; //aloca um novo array
    
    for (int i = 0; i < n_cores; i++) { //copia as cores do array antigo para o novo
        novoArray[i] = cores[i];
    }

    novoArray[n_cores] = c;//adiciona a cor 'c' na última posição

    delete[] cores;//deleta o array antigo

    cores = novoArray;//aponta o ponteiro para 'novoArray'

    n_cores++;//incrementa n_cores
}

int Paleta::getNumeroCores() {
    return n_cores;
}

Cor Paleta::getCorIndice(int indice) {
    if (indice >= 0 && indice < n_cores) {
        return cores[indice];
    } else {
        return Cor {0, 0 ,0};
    }
}

Paleta::~Paleta() {
    delete[] cores;
}