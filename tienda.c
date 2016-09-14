#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p printf
#define s scanf
typedef struct elementos_tienda
{
	char producto[15];
	float costo;
	int disponible;
}prod_tienda;

int login ();
prod_tienda * lee_archivo (FILE *,prod_tienda *);
prod_tienda * meteProductos(prod_tienda *);
prod_tienda * cambiarCant(FILE *, prod_tienda *);
prod_tienda * cambiarCost(FILE *, prod_tienda *);
void muestraInv(FILE *,prod_tienda *);
void insertarProd(FILE *, prod_tienda *);

int login(){
	int entrada=1, n_intentos=0;
	char usuario[16], contrasenia[16];
	while(1){
		system("clear");
		p("\n\t Abarrotes ****Los prebes****\n\t\n\tInicia sesion para continuar: ");
		p("\n\n\tUsuario: ");
		s("%[^\n]", usuario);
		p("\n\n\tContrasenia: ");
		s("%[^\n]", contrasenia);
	if (strcmp(usuario, "Donaldo") == 0 && strcmp(contrasenia, "1994") == 0)
		return entrada;
	else if(strcmp(usuario, "Admin") == 0 && strcmp(contrasenia, "toor") == 0)
		return entrada;
	else
		n_intentos ++;
		if(intento == 3)
		{
			p("\n\tError, has alcanzado el limite de intentos.");
			exit(0);
		}
		else{
			p("\n\tError intentelo de nuevo.");
			getchar();
			getchar();
		}
	}
}

