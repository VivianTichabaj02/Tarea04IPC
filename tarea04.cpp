#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long calcularFactorial (int num){
	if (num<=1){
		return 1;
	}
	return num * calcularFactorial(num-1);
}
    int main(){
    	FILE *archivo = fopen("salida.txt", "a+");
	system("cls");
	if (archivo == NULL ){
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	int opcion = 0;
	while (opcion !=3){
		system ("cls");
		printf("Menu:\n");
		printf("1. Ingresar datos\n");
		printf("2. Mostrar historial\n");
		printf("3. Salir\n");
		printf("Seleccione una opcion");
		scanf("%d", &opcion);
		switch (opcion){
		case 1:{
			char nombre[50];
			int numero;
			
			printf("Ingrese su nombre");
			scanf("%s", nombre);
			
			printf("Ingrese un numero entero:");
			scanf("%d", &numero);
			long long factorial = calcularFactorial(numero);
			fprintf(archivo, "Nombre: %s\n", nombre );
			fprintf(archivo, "Numero ingresado: %d\n", numero);
			fprintf(archivo, "Factorial: %lld\n\n", factorial);
			printf("Datos guardados en el archivo salida.txt.\n");
			
			sleep(5);
			break;
			 		
		}
		
		case 2:{
			char c;
			fseek(archivo, 0, SEEK_SET);
			while(( c = fgetc(archivo))!=EOF){
				printf("%c",c);
			}
			printf("\n\n");
			printf("Datos almacenados en el archivo salida.txt.\n");
			sleep(5);
			break;
		}
		case 3:
		    printf("Saliendo del programa.\n");
		    break;
		    default:
			printf("Opcion no valida . Por favor, seleccione una opcion valida.\n");
		    break;	
		}
	}
	
	fclose( archivo );
	return 0 ;
}