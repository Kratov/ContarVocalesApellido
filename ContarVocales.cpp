#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>

using namespace std;

//Constantes de la aplicacion
constexpr int MAX_APELLIDO_1 = 100;
constexpr int MAX_APELLIDO_2 = 100;
constexpr int MAX_BUFFER = MAX_APELLIDO_1 + MAX_APELLIDO_2;

int contarVocales(const char * pBuffer, const int max);

int main() {

	// Defincion de arreglos dinamicos
	char * pBuffer = (char*) malloc(MAX_BUFFER * sizeof(char));
	char * pApellido1 = (char*) malloc(MAX_APELLIDO_1 * sizeof(char));
	char * pApellido2 = (char*) malloc(MAX_APELLIDO_2 * sizeof(char));
	//Ingresar apellidos
	printf("%s", "Ingrese apellido: ");
	if (fgets(pBuffer, MAX_BUFFER, stdin) != NULL) 
		sscanf(pBuffer, "%s %s", pApellido1, pApellido2);
	//Imprimir apellidos 
	printf("%s: %s \n%s: %s \n", "Primer apellido",pApellido1,"Segundo apellido",pApellido2);
	//Imprmir resultados numero de vocales
	printf("%s %d\n%s %d\n", "Numero de vocales primer apellido: ", contarVocales(pApellido1, MAX_APELLIDO_1), "Numero de vocales segundo apellido:", contarVocales(pApellido2, MAX_APELLIDO_2));
	//Liberar memoria dinamica
	delete[] pApellido1;
	delete[] pApellido2;
	delete[] pBuffer;
	system("PAUSE");
	return 0;
}

int contarVocales(const char * pBuffer, const int max) {
	int nVocals = 0;
	for (int i = 0; i < max; i++)
		if (*(pBuffer + i) == 'a' || *(pBuffer + i) == 'e' ||
			*(pBuffer + i) == 'i' || *(pBuffer + i) == 'o' || *(pBuffer + i) == 'u' ||
			*(pBuffer + i) == 'A' || *(pBuffer + i) == 'E' || *(pBuffer + i) == 'I' ||
			*(pBuffer + i) == 'O' || *(pBuffer + i) == 'U')
			nVocals++;
	return nVocals;
}