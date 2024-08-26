#include <stdio.h>

int main(){

printf("A expressao regular eh (ccd U ccddc)* (dc U dccc)* do Alfabeto c,d \n");
printf("Digite a entrada: \n");

scanf("%s",str);


char str[50];

char Lc[4] = {c,c,d,d,c};
char Ld[4]= {d,c,c,c};
int existe_parte_um = 0;
int existe_parte_dois = 0;
int parte_um_acabou = 0;
int parte_dois_acabou = 0;

char Lc_aceitos[]

int i = 0;
while(str[i] != '\0'){
	
	if((v[i] = 'c') && (i ==0)){
		existe_parte_um = 1;
	}
	
	if(existe_parte_um == 1){
		if(v[i] != Lc[i]){
			parte_um_acabou = 1;
		}
	}
	
	if((parte_um_acabou == 1) || (existe_parte_um == 0)){
		if(v[i] != Lc[i]){
			printf("NAO");
		}
	}
	

	
	i++;
}













    return 0;
}

