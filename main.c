#include <stdio.h>
#define MAX_ENTRADA 50
#define TAMANHO_ESTADOS 3

int verificar_final(int estado, int estados_finais[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (estado == estados_finais[i]) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int estado_autm1 = 1;
    int estado_autm2 = 7;
    int estados_finais_autm1[TAMANHO_ESTADOS] = {1, 4, 6};
    int estados_finais_autm2[TAMANHO_ESTADOS] = {7, 9, 11};
    int indice_autm1 = 0;
    int indice_autm2 = 0;

    char parte_um[] = {'c','c', 'd', 'd', 'c', '\0'};
    char parte_dois[] = {'d', 'c', 'c', 'c', '\0'};
    int existe_parte_um = 0;
    int existe_parte_dois = 1;

    char entrada[MAX_ENTRADA];

    printf("Digite a cadeia (alfabeto = {c, d}): ");
    fgets(entrada, MAX_ENTRADA, stdin);

    if(entrada[0] == ' ' || entrada[0] == '\n'){
        printf("sim\n");
        return 0;
    }

    if(entrada[0] == 'c'){
        existe_parte_um = 1;
        indice_autm1 = 1;
        estado_autm1 = 2;
    } else {
        existe_parte_dois = 1;
        indice_autm2 = 1;
        estado_autm2 = 8;
    }

    int indice;

    for(indice = 1; entrada[indice] != '\0'; indice++){
        if(existe_parte_um){
            if(parte_um[indice_autm1] == '\0'){
                indice_autm1 = 0;
                estado_autm1 = 1;
            }
            if(entrada[indice] == parte_um[indice_autm1]){
                indice_autm1++;
                estado_autm1++;
            } else {
                if(entrada[indice-1] == 'd' && entrada[indice] == 'c'){
                    indice_autm1 = 1;
                    estado_autm1 = 2;
                } else {
                    existe_parte_um = 0;
                }
            }
        }
        if(!existe_parte_um && existe_parte_dois){
            if(parte_dois[indice_autm2] == '\0'){
                indice_autm2 = 0;
                estado_autm2 = 7;
            }
            if(entrada[indice] == parte_dois[indice_autm2]){
                indice_autm2++;
                estado_autm2++;
            } else {
                existe_parte_dois = 0;
                if(entrada[indice+1] == 'd'){
                    indice_autm2 = 0;
                    estado_autm2 = 7;
                    existe_parte_dois = 1;
                }
            }
        }
    }

    int sim = verificar_final(estado_autm1, estados_finais_autm1, TAMANHO_ESTADOS) +
              verificar_final(estado_autm2, estados_finais_autm2, TAMANHO_ESTADOS);

    if(sim == 2){
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}
