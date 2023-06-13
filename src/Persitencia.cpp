#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h> 

#include "Persistencia.h"

using namespace std;

int* lerDados() {
    fstream arquivo;
    string linha, str;
    arquivo.open("./Dados.txt", ios::in);
    int num = 0, cont = 0;
    
    if (arquivo.is_open()) {
        cont = qtdObj();
        cout<<cont<<endl;
        vector <int>dados = new int[cont];
        
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            while (getline(ss, str, ';')) {
                dados[num] = stoi(str);
                num++;
            }for (size_t i = 0; i < cont; i++)
            {
                cout<<"dado:"<<dados[i]<<endl;
            }
            
        }
        
        arquivo.close();
        return dados;
    }
    
    arquivo.close();
    return dados; // Retorna um ponteiro nulo em caso de erro na leitura do arquivo
}

int qtdObj() {
    fstream arquivo;
    string linha, str;
    arquivo.open("./Dados.txt", ios::in);
    int cont = 0;
    
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            while (getline(ss, str, ';')){
                cont++;
            }
        }
        
        arquivo.close();
    }
    
    return cont;
}

