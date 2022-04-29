#include <stdio.h>
#include <time.h>
#include <stdlib.h>
enum Colors {
    MAGENTA, //0
    CIAN, //1
    AMARILLO, //2 
    MORADO, //3
    BLANCO, //4
    ROJO, //5
    CELESTE, //6
    NARANJA//7
    };
const int TAM = 4; // TAM refiere al tamaño del codigo 4
const int Numcolors = 8; // Ncolors refiere al numero de colores disponibles +1*/
const char NL = '\n'; // salto de linea
const int LimT = 12;// LimT refiere al numero de intentos para decodificar el codigo

int main (){
    int Code [TAM], CB[TAM];
    int State[TAM]; 
    int turn = 0, op =0, coin=0, acert=0, rojito=0;
    char Mark [3];
    char colorCito[][10] = {"Magenta", "Cian","Amarillo","Morado","Blanco","Rojo","Celeste","Naranja"}; // esto es un arreglo de strings [Indica la cantidad de strings contenidas en la matriz][indica el tamaño MAX de los caracteres contenidos]
    int i, j;
    srand (time(NULL)); // se declara la semilla del randomizador
	system("clear");
   // genera un numero aleatorio  [0, Numcolors) *NOTA* el algoritmo sería ineficiente con rangos altos
    Code[0] = rand() %8;
    for (i =1; i < TAM; i++){
            Code[i] = rand() %Numcolors; 
            for (j =0; j < i; j++){
                if (Code[i]==Code[j]){
                    i--;
                }
            }
        }
    // muestra el codigo (debug)
    for (i =0; i < TAM; i++){
        printf("%d %c",Code[i], NL);
    }


    printf("*** MASTERMIND *** %c", NL);
    //printf("REGLAS");
    do {
        printf("%cTURNO # %d%c",NL,turn+1,NL);
        printf("*** Seleccion de colores ***%c", NL);


        // este hpta lo que hace es pintar los colores en pantalla [*cambiarlo por una funcion print*]

        printf("0.Magenta\t4.Blanco\n1.Cian  \t5.Rojo\n2.Amarillo\t6.Celeste\n3.Morado\t7.Naranja%c", NL);
	printf("****************************\n");
        // SELECCIOn de colores
        for (i =0; i < TAM; i++){

                printf("[%d] ",i);
                scanf("%d", &CB[i]);
           // validacion de datos
          if ((CB[i] <0) || (CB[i] >Numcolors)){
               printf("No te pases de gracioso perro hpta, si solo hay 8 COLORES%c", NL);
               i--;
           }

        }

        // pistas


printf("Rojitos: %d %ccoin: %d", acert, NL, coin);

        // mostrar los colores seleccionados:

        for (i =0; i < TAM ; i++){

            printf("%c[%d]-%s", NL,i, colorCito[CB[i]]);

        }

    turn++;
    }while (turn < LimT);




    return 0;
}
