#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void eleccionColor();
void imprimirCalendario(int dia,int mes,int anio);
void diasFestivos(int p);
int seleccionModuloMes(int mes, int febrero);
int diasFebrero(int anio);
int diasDelMes(int febrero,int mes);

int main(int argc, char *argv[]) {
	int num,dia,mes,anio,hr,min;
	int mesFestivo=0;
	char atomico[100];
	char reason[100];
	char emperor[100];
	char bear[100];
	FILE *f;
	int salir=0;
	
	time_t sisTime; 
	struct tm*tiempoLocal;
	time(&sisTime);
	tiempoLocal=localtime(&sisTime);
	
	
	
	
	while(salir==0)
	{
		dia=(tiempoLocal->tm_mday);
		mes=(tiempoLocal->tm_mon);
		anio=(tiempoLocal->tm_year)+1900;
		hr=(tiempoLocal->tm_hour);
		min=(tiempoLocal->tm_min);
		
		printf("\t=============================>CALENDARIO<=============================\n\n");//rotulo
		
		printf("Hoy es: %d/%d/%d \t\t El programa incio a las %.2d:%.2d\n\n\n",dia,mes+1,anio,hr=(tiempoLocal->tm_hour),min=(tiempoLocal->tm_min));
		printf("1.-Cambiar el color de la pantalla\n2.-Mostrar fecha actual\n3.-Buscar una fecha específica\n4.-Mostrar calendario completo\n5.-Días festivos\n6.-Agregar Datos\n7.-Ver Datos\n8.- Salir\n");
		printf("\n\nIngrese: ");
		scanf("%d",&num);
		switch(num)
		{
			
			case(1):
				system("cls");
			fflush(stdin);/*Sirve para borrar el valor anterior, osea 1*/
			eleccionColor();
			break;
			
			case(2):
				
				system("cls");
			printf("\t=============================>CALENDARIO<=============================\n\n");//rotulo
			printf("Hoy es: %d/%d/%d \n\n\n",dia,mes+1,anio);
			imprimirCalendario(dia,mes,anio);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
			break;
			
			case(3):
				
				system("cls");
			printf("Ingresa el mes que deseas ver:");
			scanf("%d",&mes);
			while (mes>12)
			{
				printf("Ingrese otro valor:");
				scanf("%d",&mes);
			}
			printf("Ingresa el año que deseas ver:");
			scanf("%d",&anio);
			imprimirCalendario(dia,mes-1,anio);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
			
			break;
			
			case(4):
				
				system("cls");
			printf("Ingrese el año que desea visualizar: ");
			scanf("%d",&anio);
			
			for(mes=0;mes<=11;mes++)
			{
				imprimirCalendario(dia,mes,anio);
				printf("\n\n\n");
			}
			getch();
			system("cls");
			break;
			
			case(5):
				
				system("cls");
			fflush(stdin);
			diasFestivos(mesFestivo);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
			/*Ingresar aquí switchsote de días festivos*/ 	
			
			break;
			case(6):
				f=fopen("amor1.txt","w");
			if(f == NULL)
			{
				printf("no lo puedes abrir >:v \n");
				exit(1);
			}
			printf("escribe cositas importantes para ti \n");
			fgets(atomico,100,stdin);
			fprintf(f,"%s",atomico);
			fgets(reason,100,stdin);
			fprintf(f,"%s",reason);
			fgets(emperor,100,stdin);
			fprintf(f,"%s",emperor);
			fclose(f);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
			break;
			case(7):
				f=fopen("amor1.txt","r");
			if(f == NULL)
			{
				printf("no se puede >;v \n");
				exit(1);
			}
			while(!feof(f))
			{
				fgets(bear,100,f);
				printf("%s", bear);
				
				
				
			}
			
			fclose(f);
			
			case(8):
				salir=1;
			break;
			
		default:
			printf("Operación no encontrada");
			printf("\n\nPresione cualquier tecla");
			getch();
			fflush(stdin);
			system("cls");
			break;
		}
		
	} 
	
	return 0;
}


void eleccionColor()
{
	char color;
	printf ("\t ***Color de fondo***\n\n\t A = Verde claro\n\t B = Aguamarina claro\n\t C = Rojo claro\n\t D = Púrpura claro\n\t E = Amarillo claro\n\t F = Blanco brillante\n");
	
	printf("\nEscriba color del fondo que desea usar:\n");
	scanf("%c", &color);
	
	switch(color)
	{
	case 'A'|'a':
		system("color A1");
		system("cls");
		break;
		
	case 'B'|'b':
		
		system("color B2");
		system("cls");
		break;
		
	case 'C'|'c':
		system("color C0");
		system("cls");
		break;
		
	case 'D'|'d':
		system("color D4");
		system("cls");
		break;
		
	case 'E'|'e':
		system("color E5");
		system("cls");
		break;
		
	case 'F'|'f':
		system("color F6");
		system("cls");
		break;
		
	default:
		
		system("cls");
		printf("No existe esa operación\n");
		printf("Presione cualquier tecla");
		getch();
		system("cls");
		break;
	}
	
}

void diasFestivos(int mesEscogido)
{
	printf("Días festivos del mes:\n\n1.-Enero\t2.-Febrero\t3.-Marzo\n4.-Abril\t5.-Mayo\t\t6.-Junio\n7.-Julio\t8.-Agosto\t9.-Septiembre\n10.-Octubre\t11.-Noviembre\t12.-Diciembre");
	printf("\n\nIngrese: ");
	scanf("%d", &mesEscogido);
	switch (mesEscogido)
	{
	case 1: 
		printf("         Escogiste: Enero      ");
		printf("\n") ;
		printf("ESTOS SON LOS DIAS IMPORTANTES DE ENERO ");
		printf("\n");
		printf(" 1 de Enero, Año Nuevo. ");
		printf("\n");
		printf(" 6 de Enero, Dia de los Reyes Magos. ");
		printf("\n");
		printf("        Para la UADY       ");
		printf("\n");
		printf(" 2-3 de Enero, Dia Inhabil UADY. ");
		break;
	case 2:
		printf("     Escogiste: Febrero     ");
		printf("\n");
		printf("ESTOS SON LOS DIAS IMPORTANTES DE FEBRERO ");
		printf("\n");
		printf(" 6 de Febrero, Dia de la Constitución Mexicana ");
		printf("\n");
		printf(" 14 de Febrero, Día de San Valentin ");
		printf("\n");
		printf(" 24 de Febrero, Día de la Bandera ");
		printf("\n");
		printf("     Para la UADY    ");
		printf("\n");
		printf(" 25 de Febrero, Día Inhábil UADY ");
		printf("\n");
		printf(" 27-28 de Febrero, Día inhábil UADY Carnaval ");
		break;
	case 3:
		printf("     Escogiste: Marzo    ");
		printf("\n");
		printf("ESTOS SON LOS DIAS IMPORTANTES DE MARZO ");
		printf("\n");
		printf(" 20 de Marzo, Natalício de Benito Juarez ");
		printf("\n");
		printf(" 3 de Marzo, Día Inhábil UADY ");
		break;
	case 4:
		printf("     Escogiste: Abril    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE ABRIL ");
		printf("\n");
		printf(" 13 de Abril, Jueves Santo ");
		printf("\n");
		printf(" 14 de Abril, Viernes Santo ");
		printf("\n");
		printf(" 16 de Abril, Domingo de Resurrección ");
		printf("\n");
		printf(" 30 de Abril, Día del Niño ");
		printf("\n");
		printf("     Para la UADY     ");
		printf("\n");
		printf(" 10-21 de Abril, Día Inhábil UADY (Vacaciones de Semana Santa) ");
		printf("\n");
		printf(" 25 de Abril, Día Inhábil UADY ");
		break;
	case 5:
		printf("     Escogiste: Mayo     ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE MAYO ");
		printf("\n");
		printf(" 1 de Mayo, Día del Trabajo ");
		printf("\n");
		printf(" 5 de Mayo, Batalla de Puebla ");
		printf("\n");
		printf(" 10 de Mayo, Día de Las Madres ");
		printf("\n");
		printf("     Para la UADY     ");
		printf("\n");
		printf(" 5 de Mayo, Día Inhábil UADY  ");
		printf("\n");
		printf(" 10 de Mayo, Día Inhábil UADY ");
		printf("\n");
		printf(" 15 de Mayo, Día Inhábil UADY ");
		break;
	case 6:
		printf("     Escogiste: Junio     ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE JUNIO ");
		printf("\n");
		printf(" 3er Domingo del Mes, Día del Padre ");
		break;
	case 7:
		printf("     Escogiste: Julio     ");
		printf("\n");
		printf(" parece que no hay nada D: ");
		break;
	case 8:
		printf("     Escogiste: Agosto    ");
		printf("\n");
		printf(" parece que no hay nada D: ");
		break;
	case 9:
		printf("     Escogiste: Septiembre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE SEPTIEMBRE ");
		printf("\n");
		printf(" 16 de Septiembre, Día de La Independencia ");
		break;
	case 10:
		printf("     Escogiste: Octubre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE OCTUBRE ");
		printf("\n");
		printf(" 2 de Octubre, Día de Los Muertos ");
		break;
	case 11:
		printf("     Escogiste: Noviembre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE NOVIEMBRE ");
		printf("\n");
		printf(" 20 de Noviembre, Revolución Mexicana ");
		break;
	case 12:
		printf("     Escogiste: Diciembre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE DICIEMBRE ");
		printf("\n");
		printf(" 12 de Diciembre, Día de La Virgen de Guadalupe ");
		printf("\n");
		printf(" 24 de Diciembre, Noche Buena ");
		printf("\n");
		printf(" 25 de Diciembre, Navidad ");
		break;
	}
}

void imprimirCalendario(int dia,int mes,int anio)
{
	
	int semana,moduloMes,febrero,total_mes;
	
	febrero=diasFebrero(anio);
	//Agrupacion de mes.
	//Los meses se caracterizan por tener 28,29,30,31 dias...entonces hacemos una agrupacion.
	total_mes=diasDelMes(febrero,mes);
	//Asignar nombre del mes, en esta parte se imprime la cabecera del calendario mes, y anio.
	
	switch (mes)
	{
	case 0:printf("\t\tENERO\t%d",anio);break;
	case 1:printf("\t\tFEBRERO\t%d",anio);break;
	case 2:printf("\t\tMARZO\t%d",anio);break;
	case 3:printf("\t\tABRIL\t%d",anio);break;
	case 4:printf("\t\tMAYO\t%d",anio);break;
	case 5:printf("\t\tJUNIO\t%d",anio);break;
	case 6:printf("\t\tJULIO\t%d",anio);break;
	case 7:printf("\t\tAGOSTO\t%d",anio);break;
	case 8:printf("\t\tSEPTIEMBRE\t%d",anio);break;
	case 9:printf("\t\tOCTUBRE\t%d",anio);break;
	case 10:printf("\t\tNOVIEMBRE\t%d",anio);break;
	case 11:printf("\t\tDICIEMBRE\t%d",anio);break;
	}
	
	//Modulo Mes...
	moduloMes = seleccionModuloMes(mes, febrero);
	//Calculo del primer dia de la semana.
	//En [http://es.wikipedia.org/wiki/Algoritmo_para_calcular_el_dia_de_la_semana este algoritmo]
	//Remplacen dia por 1,(el primer dia del mes).
	
	semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+moduloMes+1%7)%7;//Formula para calcular el primer día del mes
	//Impresion de dias
	printf("\nDo\tLu\tMar\tMier\tJue\tVier\tSab\n");
	
	int m,i;
	
	for(m=0;m<semana;m++)//dar espacios para que el primer dia calce.
		printf("\t");
	
	for(i=1;i<=total_mes;i++)//imprimir dias correspondientes al mes.
	{
		if(i==8-semana||i==15-semana||i==22-semana||i==29-semana || i== 36-semana)
		{
			printf("\n%d\t",i);
		}
		else	
		{
			printf("%d\t",i);
		}
	}
}

int seleccionModuloMes(int mes, int febrero)
{
	//En wikipedia ya hay una tabla, para evitar mas calculos la voy a usar.
	//Esto trata de sacarle el modulo 7 a los limites de cada mes, hasta llegar al mes que se cuenta.
	int moduloMes;
	
	if (febrero==29) //ya calcule el anio bisisesto, asi que no volvere a hacerlo.
	{
		switch (mes)
		{
		case 0:moduloMes=0;break;
		case 1:moduloMes=3;break;
		case 2:moduloMes=4;break;
		case 3:moduloMes=0;break;
		case 4:moduloMes=2;break;
		case 5:moduloMes=5;break;
		case 6:moduloMes=0;break;
		case 7:moduloMes=3;break;
		case 8:moduloMes=6;break;
		case 9:moduloMes=1;break;
		case 10:moduloMes=4;break;
		case 11:moduloMes=6;break;
		}
		
	}
	else
	{
		switch (mes)
		{
		case 0:moduloMes=0;break;
		case 1:moduloMes=3;break;
		case 2:moduloMes=3;break;
		case 3:moduloMes=6;break;
		case 4:moduloMes=1;break;
		case 5:moduloMes=4;break;
		case 6:moduloMes=6;break;
		case 7:moduloMes=2;break;
		case 8:moduloMes=5;break;
		case 9:moduloMes=0;break;
		case 10:moduloMes=3;break;
		case 11:moduloMes=5;break;
		}
	}
	
	return moduloMes;
}
int diasFebrero(int anio)
{
	int febrero;
	if (anio%4==0 && (anio%100!=0 || anio%400==0))
	{	
		febrero=29;
	}
	else
	{	
		febrero=28;
	}
	
	return febrero;
}

int diasDelMes( int febrero,int mes)
{
	int total_mes;
	
	switch (mes)
	{
	case 3: case 5: case 8: case 10: 
	{
		
		total_mes=30; 
		break;
	}
	case 1:
	{
		total_mes=febrero; 
		break;
		
	}
	case 0: case 2: case 4: case 6: case 7: case 9: case 11: 
	{
		total_mes=31; 
		break;
	}
	}
	
	return total_mes;
}
