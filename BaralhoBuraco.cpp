#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int baralho = 2;
const int carta = 52;

int main() {
    int matriz[baralho][carta];
    int contador = 1;
    int prefixo = 100;

    // Preenche a matriz
    for (int i = 0; i < baralho; ++i) {
        for (int j = 0; j < carta; ++j) {
            matriz[i][j] = prefixo + contador;
            contador++;
            if (contador == 14) {
                contador = 1;
                prefixo += 100;
            }
            //a linha 2 copia a linha 1 sempre
             if (i == 1) {
            for (int j = 0; j < carta; ++j) {
                matriz[i][j] = matriz[0][j];
                }
            }
        }
        // Aplica as operações baseado na linha
        for (int j = 0; j < carta; ++j) {
            if (i == 0) {
                matriz[i][j] = matriz[i][j] * 10 + 1; // Multiplica por 10 e adiciona 1 para a primeira linha
            } else {
                matriz[i][j] = matriz[i][j] + 1; // com a linha 1 copiada, some mais um para identificar que estamos na coluna 2
            }
        }
    }

    int array[104]; //esse vai receber as 104 cartas e futuramente verificar os valores nao repetidos e enviar para a mao dos jogadores
    int matriz2[4][11]; // define a mao dos jogadores
    bool numerosEscolhidos[104] = {false}; // Array para rastrear números já escolhidos

    srand(time(0)); //usa o horario para gerar a aleatoriedade
    for (int i = 0; i < 104; ++i) {
        int randomNumber;
        do {
            randomNumber = rand() % (baralho * carta); // Gerando um número aleatório dentro do intervalo possível
        } while (numerosEscolhidos[randomNumber]); // Verificando se o número já foi escolhido antes

        numerosEscolhidos[randomNumber] = true; // Marcando o número como escolhido
        int baralhoIndex = randomNumber / carta; // Calculando o índice do baralho
        int cartaIndex = randomNumber % carta; // Calculando o índice da carta
        array[i] = matriz[baralhoIndex][cartaIndex];
        
        // Preenchendo a matriz2 com os valores do array
        int linha = i / 11; 
        int coluna = i % 11; 
        matriz2[linha][coluna] = array[i];
    }
    
    
    
    
    
    
    
//interface simples com switch case(igual projeto cinema)
    int opcao;
    do {
        cout << "Escolha o que deseja:" << endl;
		cout << "0. Sair" << endl;
        cout << "1. Ver mão 1" << endl;
        cout << "2. Ver mão 2" << endl;
        cout << "3. Ver mão 3" << endl;
        cout << "4. Ver mão 4" << endl;
        cout << "5. Ver baralho" << endl;
		cout << "6. Ver cartas sorteadas" << endl;

        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Mão 1:" << endl;
                for (int j = 0; j < 11; ++j) {
                    cout << setw(4) << setfill('0') << matriz2[0][j] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Mão 2:" << endl;
                for (int j = 0; j < 11; ++j) {
                    cout << setw(4) << setfill('0') << matriz2[1][j] << " ";
                }
                cout << endl;
                break;
            case 3:
                cout << "Mão 3:" << endl;
                for (int j = 0; j < 11; ++j) {
                    cout << setw(4) << setfill('0') << matriz2[2][j] << " ";
                }
                cout << endl;
                break;
            case 4:
                cout << "Mão 4:" << endl;
                for (int j = 0; j < 11; ++j) {
                    cout << setw(4) << setfill('0') << matriz2[3][j] << " ";
                }
                cout << endl;
                break;
            case 5:
                cout << "Baralho:" << endl;
                for (int i = 0; i < baralho; ++i) {
                    for (int j = 0; j < carta; ++j) {
                        cout << setw(4) << setfill('0') << matriz[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
                    case 6:
            cout << "Cartas sorteadas:\n";
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 11; ++j) {
                    cout << setw(4) << setfill('0') << matriz2[i][j] << " ";
                }
                cout << endl;
            }
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, escolha novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
