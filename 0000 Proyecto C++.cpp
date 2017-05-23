#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#define arriba 72
#define abajo 80
#define enter 13

using namespace std;

     
 void ColorTexto(int num);
int eleccionColor();
void mostrarColor(char color);
void imprimirCalendario(int dia,int mes,int anio);
void diasFestivos(int p);
int seleccionModuloMes(int mes, int febrero);
int diasFebrero(int anio);
int diasDelMes(int febrero,int mes);
void EscribirRecordatorio();
void LeerRecordatorios();
void RecordatoriosProximos(int diaA, int mesA, int anioA);
void RecordatoriosActuales(int mesA, int anioA);
void Menu();

int main() {
    Menu();
	return 0;
}

	/*Funciones de Entrada*/
char color;
int eleccionColor ()
{
	printf ("\t ***Color de fondo***\n\n\t A = Verde claro\n\t B = Aguamarina claro\n\t C = Rojo claro\n\t D = P�rpura claro\n\t E = Amarillo claro\n\t F = Blanco brillante\n");
	printf("\nEscriba color del fondo que desea usar:\n");
	scanf("%c", &color);
	return color;
}
	
void EscribirRecordatorio(){
    int op=1;
    while(op!=0){
    ofstream file;
    string mensaje;
    int dia;
    int mes;
    int anio;
    file.open("recordatorios.txt",ios::app);
    if(file.is_open()){
        printf("que quieres recordar? ");
        getline(cin,mensaje);
        printf("que dia? ");
        scanf("%d",&dia);
        printf("que mes? ");
        scanf("%d",&mes);
        printf("que anio? ");
        scanf("%d",&anio);
        file<<endl<<dia<<" "<<mes<<" "<<anio<<" "<<mensaje;
        }
    else{
        printf("no se pudo abrir el archivo");
        }
    file.close();
    printf("quieres hacer otra operacion? si=1 no=0\n");
    scanf("%d",&op);
    fflush(stdin);
    }
    };

	/*Funciones de proceso*/
void Menu(){
    int num,dia,mes,anio,hr,min;
	int mesFestivo=0;
    bool salir=false;
    int elec=0;
    time_t sisTime; 
	struct tm*tiempoLocal;
	time(&sisTime);
	tiempoLocal=localtime(&sisTime);
	char tecla;
    while(!salir){
        system("cls");
        dia=(tiempoLocal->tm_mday);
		mes=(tiempoLocal->tm_mon);
		anio=(tiempoLocal->tm_year)+1900;
		hr=(tiempoLocal->tm_hour);
		min=(tiempoLocal->tm_min);
		ColorTexto(15);
        printf("\t=============================>CALENDARIO<=============================\n\n");//rotulo
		printf("Hoy es: %d/%d/%d \t\t El programa incio a las %.2d:%.2d\n\n\n",dia,mes+1,anio,hr=(tiempoLocal->tm_hour),min=(tiempoLocal->tm_min));
            if(tecla==arriba && elec>0){
                elec--;
                }
            if(tecla==abajo && elec<7){
                elec++;
                }
            if(tecla==enter){
                switch(elec){
                    case 0:
            system("cls");
			fflush(stdin);/*Sirve para borrar el valor anterior, osea 1*/
			mostrarColor(eleccionColor());
                        break;
                    case 1:
            system("cls");
			printf("\t=============================>CALENDARIO<=============================\n\n");//rotulo
			printf("Hoy es: %d/%d/%d \n\n\n",dia,mes+1,anio);
			imprimirCalendario(dia,mes,anio);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
                        break;
                    case 2:
           	system("cls");
			printf("Ingresa el mes que deseas ver:");
			scanf("%d",&mes);
			while (mes>12)
			{
				printf("Ingrese otro valor:");
				scanf("%d",&mes);
			}
			printf("Ingresa el a�o que deseas ver:");
			scanf("%d",&anio);
			imprimirCalendario(dia,mes-1,anio);
			printf("\n");
			RecordatoriosActuales(mes,anio);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
			
                        break;
                    case 3:
                        				
				system("cls");
			printf("Ingrese el a�o que desea visualizar: ");
			scanf("%d",&anio);
			
			for(mes=0;mes<=11;mes++)
			{
				imprimirCalendario(dia,mes,anio);
				printf("\n\n\n");
			}
			getch();
			system("cls");
                        break;
                    case 4:
                        				system("cls");
			fflush(stdin);
			diasFestivos(mesFestivo);
			printf("\n\nPresione cualquier tecla");
			getch();
			system("cls");
                        break;
                    case 5:
                EscribirRecordatorio();
                        break;
                    case 6:
                    LeerRecordatorios();
                        break;
                    case 7:
                        salir=true;
                        break;
                    default:
			printf("Operaci�n no encontrada");
			printf("\n\nPresione cualquier tecla");
			getch();
			fflush(stdin);
			system("cls");
			break;
                    }
                }
        char menu[8][40]={
        "-Cambiar el color de la pantalla",
        "-Mostrar fecha actual",
        "-Buscar una fecha espec�fica",
        "-Mostrar calendario completo",
        "-D�as festivos",
        "-Agregar Recordatorios",
        "-Ver Recordatorios",
        "-Salir",
        };
    for(int i=0;i<8;i++){
        if(elec==i){
            ColorTexto(24);
            }
        for(int j=0;j<40;j++){
            printf("%c",menu[i][j]);
            }
            printf("\n");
            ColorTexto(15);
        }
    RecordatoriosProximos(dia,mes,anio);
    tecla=getch();
    }
}   

 void ColorTexto(int num){
    HANDLE consola;
    consola=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (consola,num);
    }



	/*Funciones de salida*/
	
void RecordatoriosProximos(int diaA, int mesA, int anioA){
    ifstream file;
    
    file.open("recordatorios.txt",ios::in);
    
    if(file.is_open()){
        int dia;
        int mes;
        int anio;
        string texto;
        printf("eventos proximos:\n");
        while(!file.eof()){
            file>>dia>>mes>>anio;
            getline(file,texto);
            if(anio>=anioA && mes>=mesA){
                printf("%d/%d/%d",dia,mes,anio);
                cout<<texto<<endl;
                }
            }
        }
    else{
    printf("no se pudo abrir el archivo");
        }
        file.close();
    }
    
void RecordatoriosActuales(int mesA, int anioA){
    ifstream file;
    
    file.open("recordatorios.txt",ios::in);
    
    if(file.is_open()){
        int dia;
        int mes;
        int anio;
        string texto;
        printf("eventos de esta fecha:\n");
        while(!file.eof()){
            file>>dia>>mes>>anio;
            getline(file,texto);
            if(anio==anioA && mes==mesA ){
                printf("%d/%d/%d",dia,mes,anio);
                cout<<texto<<endl;
                }
            }
        }
    else{
    printf("no se pudo abrir el archivo");
        }
        file.close();
    }    

void LeerRecordatorios(){
    ifstream file;
    
    file.open("recordatorios.txt",ios::in);
    
    if(file.is_open()){
        int dia;
        int mes;
        int anio;
        string texto;
        while(!file.eof()){
            file>>dia>>mes>>anio;
            printf("recordatorio para el dia: %d/%d/%d\n",dia,mes,anio);
            getline(file,texto);
            cout<<texto<<endl;
            }
        }
    else{
    printf("no se pudo abrir el archivo");
        }
        file.close();
        getch();
    }

void mostrarColor(char color)
{
	
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
		printf("No existe esa operaci�n\n");
		printf("Presione cualquier tecla");
		getch();
		system("cls");
		break;
	}
	
}






void diasFestivos(int mesEscogido)
{
	printf("D�as festivos del mes:\n\n1.-Enero\t2.-Febrero\t3.-Marzo\n4.-Abril\t5.-Mayo\t\t6.-Junio\n7.-Julio\t8.-Agosto\t9.-Septiembre\n10.-Octubre\t11.-Noviembre\t12.-Diciembre");
	printf("\n\nIngrese: ");
	scanf("%d", &mesEscogido);
	switch (mesEscogido)
	{
	case 1: 
		printf("         Escogiste: Enero      ");
		printf("\n") ;
		printf("ESTOS SON LOS DIAS IMPORTANTES DE ENERO ");
		printf("\n");
		printf(" 1 de Enero, A�o Nuevo. ");
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
		printf(" 6 de Febrero, Dia de la Constituci�n Mexicana ");
		printf("\n");
		printf(" 14 de Febrero, D�a de San Valentin ");
		printf("\n");
		printf(" 24 de Febrero, D�a de la Bandera ");
		printf("\n");
		printf("     Para la UADY    ");
		printf("\n");
		printf(" 25 de Febrero, D�a Inh�bil UADY ");
		printf("\n");
		printf(" 27-28 de Febrero, D�a inh�bil UADY Carnaval ");
		break;
	case 3:
		printf("     Escogiste: Marzo    ");
		printf("\n");
		printf("ESTOS SON LOS DIAS IMPORTANTES DE MARZO ");
		printf("\n");
		printf(" 20 de Marzo, Natal�cio de Benito Juarez ");
		printf("\n");
		printf(" 3 de Marzo, D�a Inh�bil UADY ");
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
		printf(" 16 de Abril, Domingo de Resurrecci�n ");
		printf("\n");
		printf(" 30 de Abril, D�a del Ni�o ");
		printf("\n");
		printf("     Para la UADY     ");
		printf("\n");
		printf(" 10-21 de Abril, D�a Inh�bil UADY (Vacaciones de Semana Santa) ");
		printf("\n");
		printf(" 25 de Abril, D�a Inh�bil UADY ");
		break;
	case 5:
		printf("     Escogiste: Mayo     ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE MAYO ");
		printf("\n");
		printf(" 1 de Mayo, D�a del Trabajo ");
		printf("\n");
		printf(" 5 de Mayo, Batalla de Puebla ");
		printf("\n");
		printf(" 10 de Mayo, D�a de Las Madres ");
		printf("\n");
		printf("     Para la UADY     ");
		printf("\n");
		printf(" 5 de Mayo, D�a Inh�bil UADY  ");
		printf("\n");
		printf(" 10 de Mayo, D�a Inh�bil UADY ");
		printf("\n");
		printf(" 15 de Mayo, D�a Inh�bil UADY ");
		break;
	case 6:
		printf("     Escogiste: Junio     ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE JUNIO ");
		printf("\n");
		printf(" 3er Domingo del Mes, D�a del Padre ");
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
		printf(" 16 de Septiembre, D�a de La Independencia ");
		break;
	case 10:
		printf("     Escogiste: Octubre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE OCTUBRE ");
		printf("\n");
		printf(" 2 de Octubre, D�a de Los Muertos ");
		break;
	case 11:
		printf("     Escogiste: Noviembre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE NOVIEMBRE ");
		printf("\n");
		printf(" 20 de Noviembre, Revoluci�n Mexicana ");
		break;
	case 12:
		printf("     Escogiste: Diciembre    ");
		printf("\n");
		printf(" ESTOS SON LOS DIAS IMPORTANTES DE DICIEMBRE ");
		printf("\n");
		printf(" 12 de Diciembre, D�a de La Virgen de Guadalupe ");
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
	
	semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+moduloMes+1%7)%7;//Formula para calcular el primer d�a del mes
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
