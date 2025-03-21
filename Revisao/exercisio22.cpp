#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


//Implemente uma solução em C++ para que os professores da Residencia
//gerenciem suas turmas.
//Seu programa deve ser capaz de inserir o nome, email e duas notas (0 a 100)
//para cada discente.
//Seu programa deve permitir inserir, alterar ou excluir os dados.
//Seu programa deve salvar e carregar os dados em arquivo(s).
//Seu programa deve implementar as classes: Aluno e BancoDeDados.

class Aluno {
private:
    string nome;
    string email;
    double nota1;
    double nota2;

public:
    Aluno(string nome, string email, double nota1, double nota2)
        : nome(nome), email(email), nota1(nota1), nota2(nota2) {
    }

    string getNome() {
        return nome;
    }

    string getEmail()  {
        return email;
    }

    double getNota1() {
        return nota1;
    }

    double getNota2()  {
        return nota2;
    }
};

class BancoDeDados {
public:
    static void salvarDados(vector<Aluno>& alunos, string arquivo);
    static vector<Aluno> carregarDados(string arquivo);
};

void BancoDeDados::salvarDados(vector<Aluno>& alunos, string arquivo) {
    ofstream arquivo_saida(arquivo);

    if (arquivo_saida.is_open()) {
        for (Aluno& aluno : alunos) {
            arquivo_saida << aluno.getNome() << ',' << aluno.getEmail() << ','
                          << aluno.getNota1() << ',' << aluno.getNota2() << endl;
        }
        arquivo_saida.close();
    } else {
        cout << "Erro ao abrir o arquivo para escrita" << endl;
    }
}

vector<Aluno> BancoDeDados::carregarDados(string arquivo) {
    vector<Aluno> alunos;
    ifstream arquivo_entrada(arquivo);

    if (arquivo_entrada.is_open()) {
        string linha;
        while (getline(arquivo_entrada, linha)) {
            size_t pos = 0;
            string token;
            vector<string> tokens;
            while ((pos = linha.find(',')) != string::npos) {
                token = linha.substr(0, pos);
                tokens.push_back(token);
                linha.erase(0, pos + 1);
            }
            if (tokens.size() == 4) {
                alunos.push_back(Aluno(tokens[0], tokens[1], stod(tokens[2]), stod(tokens[3])));
            }
        }
        arquivo_entrada.close();
    } else {
        cout << "Erro ao abrir o arquivo para leitura" << endl;
    }

    return alunos;
}

int main() {
    vector<Aluno> alunos;

    // Carregando dados do arquivo (se existir)
    alunos = BancoDeDados::carregarDados("turma.txt");

    int opcao;
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Inserir aluno" << endl;
        cout << "2. Alterar aluno" << endl;
        cout << "3. Excluir aluno" << endl;
        cout << "4. Listar alunos" << endl;
        cout << "5. Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome, email;
                double nota1, nota2;
                cin.ignore(); // Consuma a nova linha pendente
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Email: ";
                getline(cin, email);
                cout << "Nota 1: ";
                cin >> nota1;
                cout << "Nota 2: ";
                cin >> nota2;
                alunos.push_back(Aluno(nome, email, nota1, nota2));
                BancoDeDados::salvarDados(alunos, "turma.txt");
                break;
            }
            case 2: {
                // Implemente a alteração de dados de um aluno aqui
                break;
            }
            case 3: {
                // Implemente a exclusão de um aluno aqui
                break;
            }
            case 4: {
                cout << "Lista de Alunos:" << endl;
                for (Aluno& aluno : alunos) {
                    cout << "Nome: " << aluno.getNome() << ", Email: " << aluno.getEmail()
                         << ", Nota 1: " << aluno.getNota1() << ", Nota 2: " << aluno.getNota2() << endl;
                }
                break;
            }
            case 5:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 5);

    return 0;
}