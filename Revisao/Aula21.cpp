#include <iostream>
#include <string>

using namespace std;


class MinhaClasse {
public:
    static int contador;
    static void MetodoEstatico() {
        cout << "Este e um matodo estatico" << endl;
    }
    
    void MetodoNaoEstatico() {
        cout << "Este e um metodo nao estatico" << endl;
    }
};
//variavel estatica da class
int MinhaClasse::contador = 0;

int main(){
    //chamando um metodo estatico
    MinhaClasse::MetodoEstatico();

    //criando instancia da class
    MinhaClasse objeto1;
    MinhaClasse objeto2;

    //chamando um metodo nao estatico em uma instancia
    objeto1.MetodoNaoEstatico();

    //acessando uma variavel estatica
    cout<<"Contador:"<< MinhaClasse::contador<<endl;
    
    return 0;
    
}