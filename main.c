#include <stdio.h>

int main()
{
    int estados_ccdccddc[] = {1, 2, 3, 4, 5, 6};
    int estados_finais_ccddc[] = {1, 4, 6};
    int estados_dcdccc[] = {7, 8, 9, 10, 11};
    int estados_finais_dcdccc[] = {7, 9, 11};
    int estado_atual = 0;
    char cadeia_da_linguagem[] = "ccdccddcdcdccc";

    char entrada[50];

    printf("Digite a cadeia (alfabeto = {c, d}): ");
    scanf("%49s", &entrada);
    while( getchar() != '\n' );

    if(entrada[0] != 'c' && entrada[0] != 'd'){
        printf("nao\n");
    }

    int indice_cadeia = 0;
    int indice_entrada = 1;
    if(entrada[0] == 'c'){
        while(entrada[indice] != '\0'){
            if(entrada[indice_entrada] == cadeia_da_linguagem[indice_cadeia]){

            }
            indice_entrada++;
        }
    }

    if(entrada[0] == 'd'){

    }
    else {
        indice = 0;
        while(entrada[indice] != '\0'){
            printf("%c", entrada[indice]);
            indice++;
        }
    }

    return 0;
}
