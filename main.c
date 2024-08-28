#include <stdio.h>
#define MAX_ENTRADA 50

int main()
{
    int estado_autm1 = 1;
    int estado_autm2 = 7;
    int estados_finais_autm1[] = {1, 4, 6};
    int estados_finais_autm2[] = {7, 9, 11};
    int indice_autm1 = 0;
    int indice_autm2 = 0;

    char parte_um[] = {'c','c', 'd', 'd', 'c', '\0'};
    char parte_dois[] = {'d', 'c', 'c', 'c', 'c', '\0'};
    int existe_parte_um = 0;
    int existe_parte_dois = 0;

    char entrada[MAX_ENTRADA];

    printf("Digite a cadeia (alfabeto = {c, d}): ");
    fgets(entrada, MAX_ENTRADA, stdin);

    if(entrada[0] == ' '){
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

    int indice = 1;
    while(entrada[indice] != '\0'){
        if(existe_parte_um == 1){
            if(parte_um[indice_autm1] == '\0'){
                indice_autm1 = 0;
            }
            if(entrada[indice] == parte_um[indice_autm1]){
                indice_autm1++;
                estado_autm1++;
                if(estado_autm1 > 6){
                    estado_autm1 = 1;
                }
            } else {
                existe_parte_um = 0;
            }
        }
        if(existe_parte_um == 0 || existe_parte_dois == 1){
            if(parte_dois[indice_autm2] == '\0'){
                indice_autm2 = 0;
            }
            if(entrada[indice] == parte_dois[indice_autm2]){
                indice_autm2++;
                estado_autm2++;
                if(estado_autm2 > 11){
                    estado_autm2 = 7;
                }
            } else {
                existe_parte_dois = 0;
            }
        }
        indice++;
    }

    int sim = 0;
    for(int i = 0; i < 3; i++){
        if(estado_autm1 == estados_finais_autm1[i]){
            sim+=1;
        }
        if(estado_autm2 == estados_finais_autm2[i]){
            sim+=1;
        }
    }

    if(sim == 2){
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}
