#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream arquivo_saida;

    arquivo_saida.open("exemplo.txt",ios_base::out);

    //verificar se foi aberto com sucesso
    if (arquivo_saida.is_open()){
        arquivo_saida << "Escrevendo arquivo." << endl;
        arquivo_saida <<20+30<<endl;
        arquivo_saida.close();
    } else{
        cout<<"Erro ao abrir o arquivo"<<endl;
    }
    //abrindo arquivo para leitura
    ifstream arquivo_entrada;
    arquivo_entrada.open("exemplo.txt", ios_base::in);

    //verificar se o arquivo foi aberto
    if (arquivo_entrada.is_open()) {
        string linha;
        while (arquivo_entrada.eof() == false) { 
            getline(arquivo_entrada, linha);
            cout << linha << endl;
        }

        arquivo_entrada.close();  
          
    } else {
        cout << "Erro ao abrir o arquivo exemplo.txt" << endl;
        return 0; 
    }
}