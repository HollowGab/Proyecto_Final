//Arellanes Aniceto Gabriel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUEB 100
#define BEBI 8

// bebidas
char *nombres[] = {"Natural", "Refresco", "Vino", "Cerveza", "Whisky", "Licores", "Energéticos", "Combinados"};

// Funciones
void IniMat(int A[PUEB][BEBI]); 
void LlenarMat(int A[PUEB][BEBI]); 
int MasBebida(int A[PUEB][BEBI], int total[BEBI]); 
int MasAlc(int A[PUEB][BEBI], int total2[BEBI]); 
int PueAlc(int A[PUEB][BEBI], int total3[PUEB]); 

// Declarar funciones
void IniMat(int A[PUEB][BEBI]) {
    int i, j;
    for (i = 0; i < PUEB; i++) {
        for (j = 0; j < BEBI; j++) {
            A[i][j] = 0;
        }
    }
    printf("Se inicializó la matriz de forma correcta.\n");
}

void LlenarMat(int A[PUEB][BEBI]) {
    int i, var1, var2;
    for (i = 0; i < PUEB; i++) {
        printf("Dame la bebida correspondiente del pueblo %d (0-7, -1 para terminar): ", i);
        scanf("%d", &var1);
        while (var1 != -1) {
            if (var1 >= 0 && var1 < BEBI) {
                printf("Dame la cantidad en litros: ");
                scanf("%d", &var2);
                A[i][var1] = var2;
            } else {
                printf("Código de bebida inválido. Intenta otra vez.\n");
            }
            printf("Dame otra bebida: ");
            scanf("%d", &var1);
        }
    }
}

int MasBebida(int A[PUEB][BEBI], int total[BEBI]) {
    int i, j, max = 0, beb = 0;
    for (j = 0; j < BEBI; j++) {
        for (i = 0; i < PUEB; i++) {
            total[j] += A[i][j];
        }
    }

    for (i = 0; i < BEBI; i++) {
        if (max < total[i]) {
            max = total[i];
            beb = i;
        }
    }

    printf("La bebida %s fue la más consumida con %d litros.\n", nombres[beb], max);
    return beb;
}

int MasAlc(int A[PUEB][BEBI], int total2[BEBI]) {
    int i, j, acum, max2 = 0, beb2 = 0;
    for (i = 0; i < BEBI; i++) {
        acum = 0;
        if (i != 1 && i != 6) { // no cuenta refresco ni energéticos
            for (j = 0; j < PUEB; j++) {
                acum += A[j][i];
            }
            total2[i] = acum;
        }
    }

    for (i = 0; i < BEBI; i++) {
        if (max2 < total2[i]) {
            max2 = total2[i];
            beb2 = i;
        }
    }

    printf("La bebida alcohólica más consumida fue la %s con %d litros.\n", nombres[beb2], max2);
    return beb2;
}

int PueAlc(int A[PUEB][BEBI], int total3[PUEB]) {
    int i, j, acum2, max3 = 0, pue = 0;
    for (i = 0; i < PUEB; i++) {
        acum2 = 0;
        for (j = 0; j < BEBI; j++) {
            if (j != 1 && j != 6) {
                acum2 += A[i][j];
            }
        }
        total3[i] = acum2;
        if (max3 < total3[i]) {
            max3 = total3[i];
            pue = i;
        }
    }

    printf("El pueblo %d consumió más alcohol con %d litros.\n", pue, max3);
    return pue;
}

// Funcion principal
void main() {
    int A[PUEB][BEBI];
    int total[BEBI] = {0};
    int total2[BEBI] = {0};
    int total3[PUEB] = {0};

    IniMat(A);
    LlenarMat(A);
    MasBebida(A, total);
    MasAlc(A, total2);
    PueAlc(A, total3);

}
