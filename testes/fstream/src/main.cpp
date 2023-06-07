#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]){
    fstream arquivo;
    arquivo.open("./felipe.txt", ios::out | ios::app);
    string nome, linha;
    int idade;
    char opcao;
    cout<<"s/n";
    cin>>opcao;
    while ((opcao=='s')||(opcao=='S'))
    {
        
        cout<<"Nome:\n";
        cin>>nome;
        cout<<"Idade:\n";
        cin>>idade;
        arquivo<<nome<<";"<<idade<<endl;

        cout<<"s/n";
        cin>>opcao;
    }

    arquivo.close();

    arquivo.open("./felipe.txt", ios::in);
    if (arquivo.is_open()){
        while (getline(arquivo,linha))
        {
            cout<<linha<<endl;
        }
    }
    arquivo.close();
    



}