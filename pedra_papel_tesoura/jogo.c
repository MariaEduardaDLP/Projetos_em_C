#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pontuacao(int jogador, int comp, int *ponto_jog, int *ponto_comp);
void imagens(int escolha);

int main(void)
{
    int jogada, computador, ponto_jog = 0, ponto_comp = 0;
    char resp = 'S';
    while(resp == 'S')
    {
        srand(time(NULL));
        computador = rand() % 3;
        printf("Pedra, papel ou tesoura\n[0]Pedra\n[1]Papel\n[2]Tesoura\n");
        do /* Para evitar que o jogador coloque um valor inválido */
        {    
            scanf("%d", &jogada);
        } while(!(jogada >= 0 && jogada < 3));
        printf("Computador:\n");
        imagens(computador);
        printf("Jogador:\n");
        imagens(jogada);
        pontuacao(jogada, computador, &ponto_jog, &ponto_comp);
        printf("=======PLACAR=======\n");
        printf("Computador | Jogador\n");
        printf("    %d      |    %d  \n", ponto_comp, ponto_jog);
        printf("====================\n");
        printf("Quer continuar [S/N]? ");
        scanf(" %c", &resp);
    }
    return 0;
}

void pontuacao(int jogador, int comp, int *ponto_jog, int *ponto_comp)
{
    if((comp == 0 && jogador == 2) || (comp == 1 && jogador == 0) || (comp == 2 && jogador == 1)) /* Condições para o computador ganhar */
    {
        *ponto_comp += 1;
    }
    else if((jogador == 0 && comp == 2) || (jogador == 1 && comp == 0) || (jogador == 2 && comp == 1)) /* Condições para o jogador gahar */
    {
        *ponto_jog  += 1;
    }
}

void imagens(int escolha)
{
    if(escolha == 0)
    {
        printf(" ####\n######\n######\n######\n######\n ####\n ####\n\n");
        /* Desenho da pedra */
    }
    else if(escolha == 1)
    {
        printf("  #\n ### #\n######\n######\n######\n ####\n ####\n\n"); 
        /* Desenho da mão aberta */
    }
    else
    {
        printf(" ##   ##\n  ## ##\n##### \n######\n######\n######\n ####\n ####\n\n"); 
        /* Desenho da tesoura */
    }
}