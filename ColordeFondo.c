#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
/*este cronometro es la cuenta de un dia*/
int main(int argc, char *argv[]) {
	
	
	char color;
	printf ("\t ***Color de fuente***\n\n\t A = Verde claro\n\t B = Aguamarina claro\n\t C = Rojo claro\n\t D = Púrpura claro\n\t E = Amarillo claro\n\t F = Blanco brillante\n");
	
	printf("\nEscriba color del fondo que desea usar:\n");
	scanf("%c", &color);
	
	switch(color)
	{
	case 'A'|'a':
		system("color A1");
		break;
		
	case 'B'|'b':
		
		system("color B2");
		break;
		
	case 'C'|'c':
		system("color C0");
		break;
	case 'D'|'d':
		system("color D4");
		break;
	case 'E'|'e':
		system("color E5");
		break;
		
	case 'F'|'f':
		system("color F6");
		break;
		
	default:
		
		printf("No existe esa operación");
	}
	
	return 0;
}


