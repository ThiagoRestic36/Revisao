#include <iostream>
#include <string>

using namespace std;

class carro{
    public:
    string tipo, cor, placa;
    int numportas;


    void acelerar(float _velocidade){
    cout<<"Acelerando para "<< _velocidade << "Km" <<endl;
    }
    void freiar(){
    cout<<"Freando"<<endl;
    }
};

int main(){
    carro civic;
    civic.tipo = "sedan";
    cout<< civic.tipo <<endl;
    civic.cor = "vermelho";
    cout<< civic.cor << endl;
    civic.placa = "HKM-5846";
    cout << civic.placa <<endl;

    civic.acelerar(30);
    civic.freiar();

    return 0;
}

