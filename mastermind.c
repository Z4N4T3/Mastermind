#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int TAM = 4; // TAM refiere al tamaño del codigo 4
const int Numcolors = 8; // Ncolors refiere al numero de colores disponibles +1*/
const char NL = '\n'; // salto de linea
const int LimT = 2;// LimT refiere al numero de intentos para decodificar el codigo

int main (){

    int win =0;
    int Code [TAM], CB[TAM];
    int att = 0;

    char colorCito[][10] = {"Magenta", "Cian","Amarillo","Morado","Blanco","Rojo","Celeste","Naranja"}; // esto es un arreglo de strings [Indica la cantidad de strings contenidas en la matriz][indica el tamaño MAX de los caracteres contenidos]
    int i=0, j=0;

    int blanco =0, rojo =0;

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


    //printf("REGLAS");
    do {
	if (att<LimT && rojo ==4){
		win =1;
		break;
	}
        printf("\n******** MASTERMIND ********%c", NL);
        printf("\t  TURNO #%d%c",att+1,NL);
        printf("*** Seleccion de colores ***%c", NL);


        // este hpta lo que hace es pintar los colores en pantalla [*cambiarlo por una funcion print*]

        printf("0.Magenta\t4.Blanco\n1.Cian  \t5.Rojo\n2.Amarillo\t6.Celeste\n3.Morado\t7.Naranja%c", NL);
	printf("****************************\n");


     // SELECCIOn de colores
        for (i =0; i < TAM; i++){
                printf("[%d] ",i);
                scanf("%d", &CB[i]);
           // validacion de datos
          if ((CB[i] <0) || (CB[i] >=Numcolors)){
               printf("No te pases de gracioso perro hpta, si solo hay 8 COLORES%c", NL);
               i--;
           }

        }
	system("clear");
        // pistas
	rojo =0;
	for (i =0; i<TAM;i++){
		blanco =0;
		if (Code[i]==CB[i]){
			printf("(%d) rojo\n",i); rojo++;
		}else{
			for (j=0;j<TAM;j++){
				if(CB[i]==Code[j]){
				printf("(%d) blanco\n",i);
				blanco =1;
				break;
				}
			}
		if (!blanco && j==TAM)
			printf("(%d) NULL\n",i);
		}
	}

        // mostrar los colores seleccionados:

        for (i =0; i < TAM ; i++){

            printf("%c[%d]-%s", NL,i, colorCito[CB[i]]);

        }


    att++;
    }while (!win && att<LimT);

    if (win){
    printf("\nHAS DECIFRADO EL CODIGO!!!\nEn %d turnos\n",att);
    for (i =0; i<TAM; i++)
	printf("%s  ",colorCito[Code[i]]);
    }else{
    printf("\nTe has quedado sin intentos\ny no has podido decifrar el codigo\n");
    for (i=0; i<TAM;i++)
	printf("%s - ",colorCito[Code[i]]);
    }
    printf("\n");
    return 0;
}
