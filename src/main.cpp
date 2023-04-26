#include <iostream>
using namespace std;

#include "Janela.h"

int main(int argc, char const *argv[])
{
    char *title = "TESTE";
    
    Janela *janela = new Janela(title, 800, 600);
    janela->loop();

}
