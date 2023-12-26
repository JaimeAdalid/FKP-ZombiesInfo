#include <iostream>
using namespace std;

long long vidaDosZumbis = 10;

void erroValorInvalido() {
    cout << "Parece que você inseriu um valor invalido, tente novamente ou feche o programa" << endl;
    cout << "" << endl;
}

/*void DesejaRetornarAoMenuPrincipal() {
    cout << "DIGITE 1: Se deseja Retornar ao Menu Principal" << endl;
    int input;
    cin >> input;
    if (input == 1) {
        MenuPrincipal();
    }
    else {
        erroValorInvalido();
    }
}*/


void CalculaQuantidadeZumbisVariosRounds(int roundLimite, int numeroDeJogadores) {
    float multiplicadorMultiplayer = 1;
    int quantidadeZumbis = 0;
    int quantidadeRoundAnterior = 5;
    float multiplicadorMinimoPorJogador = 0.33f;
    
    if (numeroDeJogadores > 1)
    {
        //cout << "Multiplicador de zumbis por possuir apenas 1 jogador e: 1 " << endl;
        multiplicadorMultiplayer = 1;
        for (int i = 2; i <= numeroDeJogadores; i++)
        {
            float adicionalDoJogador;
            adicionalDoJogador = 1.0f / i;
            adicionalDoJogador *= 1.7f;
            if (adicionalDoJogador < multiplicadorMinimoPorJogador)
            {
                adicionalDoJogador = multiplicadorMinimoPorJogador;
            }
            multiplicadorMultiplayer += adicionalDoJogador;
            //cout << "Multiplicador de zumbis por possuir mais de ";
            //cout << i;
            //cout << " jogadores e :";
            //cout << multiplicadorMultiplayer << endl;
        }
    }    

    for (int i = 1; i <= roundLimite; i++) {
        quantidadeZumbis = quantidadeRoundAnterior + (numeroDeJogadores + (i / 6) * multiplicadorMultiplayer);
        cout << "Quantidade de zumbis no round " << i << " e: ";
        cout << quantidadeZumbis << endl;
        quantidadeRoundAnterior = quantidadeZumbis;
    }
}

void CalculaVidaRoundEspecifico(int roundDesejado, int numeroDeJogadores) {
    float multiplicadorMultiplayer = 1;
    int quantidadeZumbis = 0;
    int quantidadeRoundAnterior = 5;
    float multiplicadorMinimoPorJogador = 0.33f;

    if (numeroDeJogadores > 1)
    {
        //cout << "Multiplicador de zumbis por possuir apenas 1 jogador e: 1 " << endl;
        multiplicadorMultiplayer = 1;
        for (int i = 2; i <= numeroDeJogadores; i++)
        {
            float adicionalDoJogador;
            adicionalDoJogador = 1.0f / i;
            adicionalDoJogador *= 1.7f;
            if (adicionalDoJogador < multiplicadorMinimoPorJogador)
            {
                adicionalDoJogador = multiplicadorMinimoPorJogador;
            }
            multiplicadorMultiplayer += adicionalDoJogador;
            //cout << "Multiplicador de zumbis por possuir mais de ";
            //cout << i;
            //cout << " jogadores e :";
            //cout << multiplicadorMultiplayer << endl;
        }
    }

    for (int i = 1; i <= roundDesejado; i++) {
        quantidadeZumbis = quantidadeRoundAnterior + (numeroDeJogadores + (i / 6) * multiplicadorMultiplayer);
        quantidadeRoundAnterior = quantidadeZumbis;
    }
    cout << "Quantidade de zumbis no round " << roundDesejado << " e: ";
    cout << quantidadeZumbis << endl;

}

void SelecionarCalculadoraDeQuantidadeDeZumbis() {
    cout << "Voce pode calcular a quantidade dos zumbis apenas de um round especifico ou de todos os rounds" << endl;
    cout << "DIGITE 1: Para saber a quantidade dos zumbis em um round especifico" << endl;
    cout << "DIGITE 2: Para saber a quantidade dos zumbis em todos os rounds" << endl;
    int input;
    cin >> input;
    int quantidadeJogadores;
    switch (input) {
    case 1:
        cout << "Qual o round voce gostaria de consultar?" << endl;
        int roundDesejado;
        cin >> roundDesejado;
        cout << "Quantos jogadores estariam jogadando?" << endl;
        cin >> quantidadeJogadores;
        CalculaVidaRoundEspecifico(roundDesejado, quantidadeJogadores);
        break;
    case 2:
        cout << "Ate que round voce gostaria de consultar?" << endl;
        int roundLimite;
        cin >> roundLimite;
        cout << "Quantos jogadores estariam jogadando?" << endl;
        cin >> quantidadeJogadores;
        CalculaQuantidadeZumbisVariosRounds(roundLimite, quantidadeJogadores);
        break;
    default:
        erroValorInvalido();
        SelecionarCalculadoraDeQuantidadeDeZumbis();
    }

}

void CalculaVidaVariosRounds(int roundLimite) {
    for (int i = 1; i <= roundLimite; i++) {
        cout << "Vida dos zumbis no round " << i << " e: ";
        cout << vidaDosZumbis << endl;
        if (i < 10)
        {
            vidaDosZumbis += 10;
        }
        else if (vidaDosZumbis < 9000000000000000)
        {
            vidaDosZumbis *= 1.1;
        }


    }
}

void CalculaVidaRoundEspecifico(int roundDesejado) {

    for (int i = 1; i <= roundDesejado; i++) {
        if (i == roundDesejado)
        {
            cout << "Vida dos zumbis no round " << i << " e: ";
            cout << vidaDosZumbis << endl;
        }
        if (i < 10)
        {
            vidaDosZumbis += 10;
        }
        else
        {
            vidaDosZumbis *= 1.1;
        }
    }

}

void SelecionarCalculadoraDeVida() {
    cout << "Voce pode calcular a vida dos zumbis apenas de um round especifico ou de todos os rounds" << endl;
    cout << "DIGITE 1: Para saber a quantidade de vida dos zumbis em um round especifico" << endl;
    cout << "DIGITE 2: Para saber a quantidade de vida dos zumbis em todos os rounds" << endl;
    int input;
    cin >> input;
    switch (input) {
    case 1:
        cout << "Qual o round voce gostaria de consultar?" << endl;
        int roundDesejado;
        cin >> roundDesejado;
        CalculaVidaRoundEspecifico(roundDesejado);
        break;
    case 2:
        cout << "Ate que round voce gostaria de consultar?" << endl;
        int roundLimite;
        cin >> roundLimite;
        CalculaVidaVariosRounds(roundLimite);
        break;
    default:
        erroValorInvalido();
        SelecionarCalculadoraDeVida();
    }

}

void SelecionarFunção() {

    cout << "DIGITE 1: Para saber sobre a vida dos zumbis em cada round" << endl;
    cout << "DIGITE 2: Para saber a quantidade de zumbis em cada round" << endl;
    cout << "DIGITE 3: Para saber o dano dos zumbis em cada round" << endl;
    cout << "DIGITE 4: Para saber a chance de zumbis estarem andando/correndo" << endl;
    cout << "DIGITE 5: Para saber todas as informações juntas" << endl;

    int input;
    cin >> input;

    switch (input) {
    case 1:
        SelecionarCalculadoraDeVida();
        break;
    case 2:
        SelecionarCalculadoraDeQuantidadeDeZumbis();
        break;
    default:
        erroValorInvalido();
        SelecionarFunção();

    }
    cout << "" << endl;
}

void MenuPrincipal() {
    cout << "********************************" << endl;
    cout << "*           Bem vindo!         *" << endl;
    cout << "*           essa e a:          *" << endl;
    cout << "*        Wikipedia Zumbi       *" << endl;
    cout << "********************************" << endl;
    cout << "" << endl;
    SelecionarFunção();
}

int main()
{
    MenuPrincipal();
}


