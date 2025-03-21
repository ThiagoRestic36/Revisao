#include<string>
#include <iostream>

using namespace std;

//Exercício 1
//● Crie uma superclasse chamada Animal com atributos nome, idade e um método fazerSom().
//● Em seguida, crie uma subclasse chamada Cachorro que herda de Animal e substitua o método fazerSom() 
//para que ele imprima "Au Au!" quando chamado.
//● Crie objetos de ambas as classes e teste seus métodos (função main() )

class Animal{
    
    private:
    string nome;
    int idade;

    public:
    Animal(string nome, int idade){
        nome = nome;
        idade = idade;
    }


    void FazerSom(){
        cout<<"Animal fazendo som"<<endl;
    }
};

class Cachorro : public Animal{
    public:
    Cachorro(string nome, int idade) : Animal( nome, idade){}
    
    void FazerSom(){
        cout<<"AU AU !"<< endl;
    }

};

int main(){
    Animal animal("fido", 5);
    Cachorro cachorro("Rex", 3);

    cout<< "Animal: "; 
    animal.FazerSom();
    cout<<"Cachorro: ";
    cachorro.FazerSom(); 

    return 0;
}