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
prod_tienda * lee_inventario (FILE *,prod_tienda *);
prod_tienda * hazProductos(prod_tienda *);
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
		if(n_intentos == 3)
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
	return 0;
}
prod_tienda * hazProductos(prod_tienda *producto){
	int i;
	producto=(prod_tienda *) calloc(20,sizeof(prod_tienda));
	strcpy(producto[0].producto, "Aceite");
	producto[0].costo = 18.50;
	strcpy(producto[1].producto, "Coca-cola");
	producto[1].costo = 23.00;
	strcpy(producto[2].producto, "Nito");
	producto[2].costo = 9.00;
	strcpy(producto[3].producto, "Chips");
	producto[3].costo = 10.00;
	strcpy(producto[4].producto, "Chetos");
	producto[4].costo = 8.00;
	strcpy(producto[5].producto, "Huevo");
	producto[5].costo = 25.50;
	strcpy(producto[6].producto, "Frijoles");
	producto[6].costo = 16.50;
	strcpy(producto[7].producto, "Queso");
	producto[7].costo = 65.00;
	strcpy(producto[8].producto, "Jamon");
	producto[8].costo = 40.00;
	strcpy(producto[9].producto, "Leche");
	producto[9].costo = 16.00;
	strcpy(producto[10].producto, "Yogur");
	producto[10].costo = 5.50;
	strcpy(producto[11].producto, "Mantequilla");
	producto[11].costo = 10.00;
	strcpy(producto[12].producto, "Dulces");
	producto[12].costo = 1.50;
	strcpy(producto[13].producto, "Salsa");
	producto[13].costo = 10.50;
	strcpy(producto[14].producto, "Chiles");
	producto[14].costo = 12.50;
	strcpy(producto[15].producto, "Chipotles");
	producto[15].costo = 11.00;
	strcpy(producto[16].producto, "Pan");
	producto[16].costo = 27.00;
	strcpy(producto[17].producto, "Mermelada");
	producto[17].costo = 18.00;
	strcpy(producto[18].producto, "Sal");
	producto[18].costo = 11.50;
	strcpy(producto[19].producto, "Azucar");
	producto[19].costo = 16.00;
	for (i = 0; i < 20; i++)
		producto[i].disponible = 10;
	return producto;
}
void insertarProd(FILE *inventario, prod_tienda *producto){
	int i;
	if((inventario =fopen("inventario.txt","r")) == NULL)
		if((inventario =fopen("inventario.txt","a+")) == NULL)
		{
			p("\n\tError, el inventario no existe o esta daniado");
			exit(0);
		}
		else{
			fprintf(inventario, "Productos 	Costo\tDisponible\n\n");
			for(i=0;i<20;i++)
			fprintf(inventario, "%16s%10.2f\t%d\n", producto[i].producto, producto[i].costo, producto[i].disponible);
			}
	fclose(inventario);
	return;
}
void muestraInv(FILE *inventario,prod_tienda *producto){
	if((inventario = fopen("inventario.txt", "a+")) ==NULL)
		p("\n\n\tError al imprimir, el inventario no existe o esta daniado");
	else{
		char cadena = fgetc(inventario);
		while(cadena != -1)
		{
			p("%c",cadena);
			cadena=fgetc(inventario);
		}
	}
		fclose(inventario);
		return;
}

int main(){
	p("hola");
}

