#include<stdio.h> //Funciones básicas
#include<stdlib.h> //system, srand
#include<windows.h> //PlaySound
#include<time.h> //time, NULL
#include<string> //Cadenas de Caracteres
#define maletin 27 //Define la cantidad de maletines

typedef struct jugador 
{
	int premio;				//Estructura para contener las variables premio y el arreglo usuario
	char usuario[11];
	
}jugador;

bool Validar_Datos();//Funcion de validacion de Datos (Validar datos el login)
void stats_registro(jugador player); //Registrar estadísticas en los archivos .txt
void stats_generales(); //Muestra las Estadísticas Globales
void stats_personales(); //Muestra las Estadísticas Personales
void gotoxy(float x, float y); //Void encargado de las coordenadas para centrar texto
void AltEnter(); //Void encargado de colocar la consola en pantalla completa
void creditos(); //Void encargado de mostrar los creditos en pantalla
void registro();//Funcion registro
void login();//Funcion Login
void menu1(); //Menu donde decide si registrar, iniciar sesión, ver estadísticas o salir
void menu(); //Menu de inicio de sesión para decidir si va a jugar o va a ver sus estadísticas
void showCases(long int maletines[26], int isOpen[26]); //Muestra los maletines
int juego(); //Función del juego

	FILE *archivo;
	FILE *conti;
	char * usur = (char*)malloc(11*sizeof(char));
	char * pass = (char*)malloc(11*sizeof(char));
	char * compara = (char*)malloc(11*sizeof(char));


main() //Función principal		
{
	AltEnter(); //Llamamos a la función AltEnter para pantalla completa
	
	creditos(); //Llamamos a la funcion de creditos
	
	
	
	//Deal or no Deal ASCII
	gotoxy(65,5);
	printf(" /$$$$$$$                      /$$");
	gotoxy(65,6);
	printf("| $$__  $$                    | $$");
	gotoxy(65,7);
	printf("| $$  %c $$  /$$$$$$   /$$$$$$ | $$",92);
	gotoxy(65,8);
	printf("| $$  | $$ /$$__  $$ |____  $$| $$");
	gotoxy(65,9);
	printf("| $$  | $$| $$$$$$$$  /$$$$$$$| $$");
	gotoxy(65,10);
	printf("| $$  | $$| $$_____/ /$$__  $$| $$");
	gotoxy(65,11);
	printf("| $$$$$$$/|  $$$$$$$|  $$$$$$$| $$");
	gotoxy(65,12);
	printf("|_______/  %c_______/ %c_______/|__/",92,92);
	
	
	gotoxy(65,16);
	printf("        /$$$$$$   /$$$$$$       ");
	gotoxy(65,17);
	printf("       /$$__  $$ /$$__  $$      ");
	gotoxy(65,18);
	printf("      | $$  %c $$| $$  %c__/    ",92,92);
	gotoxy(65,19);
	printf("      | $$  | $$| $$            ");
	gotoxy(65,20);
	printf("      |  $$$$$$/| $$            ");
	gotoxy(65,21);
	printf("       %c______/ |__/           ",92);
	
	
	gotoxy(53,25);
	printf("                           /$$$$$$$                      /$$");
	gotoxy(53,26);
	printf("                          | $$__  $$                    | $$");
	gotoxy(53,27);
	printf(" /$$$$$$$   /$$$$$$       | $$  %c $$  /$$$$$$   /$$$$$$ | $$",92);
	gotoxy(53,28);
	printf("| $$__  $$ /$$__  $$      | $$  | $$ /$$__  $$ |____  $$| $$");
	gotoxy(53,29);
	printf("| $$  %c $$| $$  %c $$      | $$  | $$| $$$$$$$$  /$$$$$$$| $$",92,92);
	gotoxy(53,30);
	printf("| $$  | $$| $$  | $$      | $$  | $$| $$_____/ /$$__  $$| $$");
	gotoxy(53,31);
	printf("| $$  | $$|  $$$$$$/      | $$$$$$$/|  $$$$$$$|  $$$$$$$| $$");
	gotoxy(53,32);
	printf("|__/  |__/ %c______/       |_______/  %c_______/ %c_______/|__/\n\n\n\n\n\n\n",92,92,92);
	gotoxy(65,40);
	Sleep(3000);
	system("pause");
		system("cls");
	
	menu1(); // Llamada al menu principal
}

void gotoxy(float x, float y) //Funcion encargada de las coordenadas para acomodar el texto
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void AltEnter() //Funcion encargada de colocar la consola en pantalla completa
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}



void creditos() //Funcion encaragda de mostrar los creditos
{
	fflush(stdin); //Limpiado del bufer por errores de impresion
	//Aperture Solutions (Nombre de mi "empresa")
	gotoxy(40,10);
	printf("    ___                    __                     _____       __      __  _                 ");
	gotoxy(40,11);
	printf("   /   |  ____  ___  _____/ /___  __________     / ___/____  / /_  __/ /_(_)___  ____  _____");
	gotoxy(40,12);
	printf("  / /| | / __ %c/ _ %c/ ___/ __/ / / / ___/ _ %c    %c__ %c/ __ %c/ / / / / __/ / __ %c/ __ %c/ ___/",92,92,92,92,92,92,92,92);
	gotoxy(40,13);
	printf(" / ___ |/ /_/ /  __/ /  / /_/ /_/ / /  /  __/   ___/ / /_/ / / /_/ / /_/ / /_/ / / / (__  ) ");
	gotoxy(40,14);
	printf("/_/  |_/ .___/%c___/_/   %c__/%c__,_/_/   %c___/   /____/%c____/_/%c__,_/%c__/_/%c____/_/ /_/____/  ",92,92,92,92,92,92,92,92);
	gotoxy(40,15);
	printf("      /_/                                                                                   ");
	
	gotoxy(55,20);
	printf("Elaborado por:");
	gotoxy(55,23);
	printf("MART%cNEZ MIRANDA JUAN CARLOS 'CharlyAvocado'",161);
	
	Sleep(6500); //Pequeña pausa para mostrar el texto
	system("cls"); //limpiado de pantalla
}



void menu1() //Funcion encargada de mostrar el menu
{
	int op;
	gotoxy(70,10);
	printf("Hola, qu%c quieres hacer?\n\n",130);
	gotoxy(0,15);
	printf("\t\t\t\t1. Registrarte\t\t 2. Iniciar sesi%cn\t\t 3. Estad%csticas globales\t\t4.Salir\n\n\t",162,161); //Menu de opciones para el usuario
	printf("Ingresa el n%cmero de la opci%cn que escojas: ",163,162);
	gotoxy(0,30);
	scanf("%d",&op); //Lectura de la opcion
	system("cls");
	
	switch(op)
	{
		case 1: registro();break; 
		case 2: login();break;			//LLamado a las opciones dependiendo del caso seleccionado por el usuario
		case 3: stats_generales();break;
		case 4: 
		gotoxy(70,20);
		printf("Gracias por jugar, hasta luego!"); //Mensaje de despedida
		
	}
	
}

void registro(void) //Construccion de la funcion registro
{
		archivo=fopen("usu.txt","r"); //Comando para abrir el archivo de uasuarios en modo lectura
		regis:					//Marcador para usar Go To
			system("cls");
			gotoxy(60,15);
			printf("REGISTRO");
			gotoxy(60,18);
			printf("Ingresa tu nombre de usuario");
			gotoxy(60,19);
			printf("M%cximo 10 caracteres sin espacios",160);
			gotoxy(60,20);
			scanf("%s",usur);	//Llenado del nombre de usuario
			if(strlen(usur)>10) //Mide la logitud de la cadena para que sea menor de 10 caracteres
			{
				gotoxy(60,23);
				printf("N%cmero de caracteres excedido",163); //si la cadena es mayor a 10 caracteres se le informa al usuario
				gotoxy(60,24);
				system("pause");  //Se pausa el programa para que el usuario este consciente
				goto regis;       //Se le regresa al usuario al llenado del nombre
			}
			mientras:  			//Marcador Go To
				while(feof(archivo)==0) //While que lee el contenido del documento hasta llegar al final del archivo
				{
					fscanf(archivo,"%s",compara); //Comando para buscar la variable del nombre en el documento para que no se repita el usuario
					if(strcmp(compara,usur)==0)
					{
						system("cls");
						gotoxy(60,15);
						printf("USUARIO EXISTENTE"); //Si el usuario ingresado se encuentra en el documento, se le indica al usuario
						rewind(archivo); //El índice de escritura vuelve al inicio del archivo
						gotoxy(60,16);
						system("pause"); //Pausa para que el usuario esté consciente
						goto regis; //Se regresa al usuario al llenado del nombre
					}
					else
					{
						goto mientras; //Se regresa al inicio del marcador para la siguiente ejecucion
					}
				}
				fclose(archivo); //Se cierra el archivo 
		
				archivo=fopen("usu.txt","a"); //Se abre el archivo de usuarios en modo de creación y edición 
				fprintf(archivo,"%s\n",usur); //Se escribe el nombre del usuario en el documento
				fclose(archivo); //Se cierra el archivo
		
				conti=fopen("cont.txt","a"); //Se abre el archivo de contraseñas en modo creación y edición
				regis_cont: 				//Marcador Go To
					gotoxy(60,25);
					printf("Ingresa tu contrase%ca",164); 
					gotoxy(60,26);
					printf("M%cximo 10 caracteres sin espacios",160);
					gotoxy(60,27);
					scanf("%s",pass); 		//Llenado de la variable contraseña
					if(strlen(pass)>10)		//Se mide la longitud de la cadena para que no exceda los 10 caracteres
					{
						gotoxy(60,30);
						printf("N%cmero de caracteres excedido",163);// Si excede los 10 caracteres se le noifica al usuario
						gotoxy(60,31);
						system("pause"); 	//Se pausa el programa para que el usuario este consciente
						goto regis_cont;	//Se regresa al usuario al llenado de la contraseña
					}
				fprintf(conti,"%s\n",pass); //Se imprime la contraseña en el archivo de contraseñas
				fclose(conti); //Se cierra el documento de contraseñas
			system("cls"); 
			gotoxy(60,20);
			printf("Usuario registrado satisfactoriamente"); //Se le notifica al usuario que se registro con exito
			gotoxy(60,21);
			system("pause"); //Se pausa para que el usuario este consciente
			system("cls");
			menu1(); //Se lleva al menu principal
}

void login(void)//Construccion de la funcion LogIn
{
	int tr=0;
	log:				//Marcador GoTo
		system("cls");
		gotoxy(60,15);
		printf("Inicio de Sesi%cn",162);	
		gotoxy(60,18);
		printf("Ingresa tu nombre de usuario");
		gotoxy(60,19);
		scanf("%s",usur);	//Llenado del nombre de usuario
		gotoxy(60,24);
		printf("Ingresa tu contrase%ca",164);
		gotoxy(60,25);
		scanf("%s",pass);	//Llenado de la contraseña del usuario
		system("cls");
		if(Validar_Datos()==true){	//Se hace el llamado a la funcion 'Validar_Datos' si el valor retornado es verdad se manda al usuario al menu de usuario
			gotoxy(70,5);
			printf("Bienvenido %s! ",usur); //Bienvenida al jugador al menu de usuario
			
			menu(); 		//Llamada del menu de usuario
			free(pass);		//Se libera la variable que contiene a la contraseña
			free(compara);	//Se libera la variable que contiene el nombre de usuario
		}
			else //Si el valor retornado por 'Validar_Datos' es falso, se indica el error
			{
			tr++; //Se incrementa la variable contadora de intentos de inicio de sesión
			if(tr<5)//Si los intentos son menores a 5
			{	
			gotoxy(40,20); //Se le notifica al usuario que no se encontró su usuario o contraseña y s ele muestran sus intentos de inicio de sesion
			printf("Usuario y/o Contrase%ca no encontrado, intentalo de nuevo\t Intento n%cmero %i de 5",164,163,tr+1); 
			gotoxy(60,23);
			system("pause");
			goto log;//Se le regresa al Log In
				}
				else //Si se superan los 5 intentos
				{
					gotoxy(60,20);
					printf("N%cmero de intentos superado, regrese m%cs tarde",163,160); //Se le hace saber al usuario
					gotoxy(60,23);
					system("pause"); //Se pausa para que el usuario reanude manualmente
					menu1(); //Se le regresa al menú principal
				}
			}
}


void menu() //Construccion de la funcion del menu del jugador
{
	menu: //Marcador Go To
		int gano,opc; //Variables utilizadas por las funciones 'menu' y 'juego'
		gotoxy(70,10);
		printf("Hola, qu%c quieres hacer?\n",130);
		gotoxy(0,15);
		printf("\t\t\t\t\t\t1. Ver estad%cticas personales\t\t 2. Jugar\t\t 3. Salir\n\n\t",161);
			gotoxy(0,30);
			printf("Ingresa el n%cmero de la opci%cn que escojas: ",163,162);
			scanf("%d",&opc);
			switch(opc)
			{
				case 1: 
					stats_personales(); //Llamado a la funcion que muestra las estadisticas del jugador
					gotoxy(70,20);
					system("pause");  //Se pausa para que el usuario reaunde manualmente
					system("cls");
					goto menu; //Se le regresa al menu de jugador
					break;

				case 2: 	
					gano=juego();//Llamada a la función del juego y se le da el valor regresado por el juego a la variable 'gano'
					jugador ejemplo;
					for(int i =0;i<11;i++)
					{
						ejemplo.usuario[i]=usur[i];
					}
					ejemplo.premio=gano; //Se guarda el valor en la estructura jugador
					stats_registro(ejemplo); //Se le da ese valor a la funcion encargada de registrar las estadisticas
					break;
				
				case 3: 
					system("cls");
					menu1(); //Se le manda al menú principal
					break;
				
				
			}
	
}

void stats_registro(jugador player) //Construcción de la funcion encargada de registrar las estadisticas del usuario
{
		FILE *estadisticas; //Creacion del apuntador para los archivos de estadisticas
		FILE *auxiliar;     
		char compara[11];
		char c_total[15],c_juegos[3];
		int total,juegos;
		bool hup=false; //Verdadero o falso para controlar la escritura
		estadisticas=fopen("stats.txt","r"); // Se abre el documento de estadisticas en modo lectura
			mientras: 		//Marcador Go To
				while(feof(estadisticas)==0)//Se escanea el contenido del documento hasta llegar al final
				{
					fscanf(estadisticas,"%s",compara);	
					fscanf(estadisticas,"%s",c_total);		//Se buscan los datos de estadísticas del usuario en el documento
					fscanf(estadisticas,"%s",c_juegos);					

					if(strcmp(compara,player.usuario)==0) //Compara las cadenas de texto 
					{
						total=atoi(c_total)+player.premio; //atoi convierte de caracter a entero
						itoa(total,c_total,10); //itoa convierte de entero a caracter
						//printf("%s\n",c_total); //Banderas utilizadas para seguimiento del proceso en modo desarrollador
						juegos=atoi(c_juegos)+1; //Se le aumenta 1+ a la cantidad de juegos jugados
						itoa(juegos,c_juegos,10); //Se convierte entero a caracter
						//printf("%s\n",c_juegos); //Banderas utilizadas para seguimiento del proceso en modo desarrollador
						goto tarea_finalizada; //Se manda al marcador Siguiente
					}
					else
					{
						goto mientras; //Se regresa al marcador anterior para repetir el proceso

					}
				}
				fclose(estadisticas); //Se cierra el archivo de estadisticas
				estadisticas=fopen("stats.txt","a"); //Se abre el archivo de estadisticas en modo creacion y edicion
				
				fprintf(estadisticas,"\n%s\n",player.usuario); //Se imprime el usuario en la linea actual
				itoa(player.premio,c_total,10); 
				fprintf(estadisticas,"%s\n",c_total); //Se imprime el total de dinero ganado del jugador 
				itoa(1,c_juegos,10);
				fprintf(estadisticas,"%s\n\n",c_juegos); //Se imprime la cantidad de juegos jugados por el jugador
				goto final; //Se manda al marcador siguiente
		tarea_finalizada: //Marcador Go To
		fclose(estadisticas); //Se cierra el documento de estadisticas
		hup=true; //Se le da el valor verdadero a la variable booleana
		auxiliar=fopen("auxi.txt","a"); //Se abre un archivo auxiliar en modo creacion y edicion
		
		fprintf(auxiliar,"%s\n",player.usuario); 
		fprintf(auxiliar,"%s\n",c_total);		//Se imprimen las variables de las estadísticas en el documento auxiliar
		fprintf(auxiliar,"%s\n\n",c_juegos);
		
		estadisticas=fopen("stats.txt","r"); //Se abre el documento de estadisticas en modo lectura
		mientras_1:	//Marcador Go To
		while(feof(estadisticas)==0) //Se escanea el documento hasta el final
		{
			fscanf(estadisticas,"%s",compara);
			fscanf(estadisticas,"%s",c_total);	//Se buscan las variables de estadisticas
			fscanf(estadisticas,"%s",c_juegos);
				
			if(strcmp(compara,player.usuario)==0) //Se comparan las variables encontradas con las almacenadas
			{
				goto mientras_1; //Se manda al marcador anterior
			}
			else
			{	
				fprintf(auxiliar,"%s\n",compara);
				fprintf(auxiliar,"%s\n",c_total);		//Se imprimen las variables en el auxiliar
				fprintf(auxiliar,"%s\n\n",c_juegos);				
			}
		}
		fclose(auxiliar); //Se cierra el documento auxiliar
		final: //Marcador Go To
		fclose(estadisticas); //Se cierra el documento de estadisticas
		if (hup==true)//Si la variable booleana es verdadera
		{
			remove("stats.txt"); //Se elimina el archivo original de estadisticas
			rename("auxi.txt","stats.txt"); //Se renombra al archivo auxiliar que contiene los datos actualizados para ser el archivo principal de estadisticas
		}
}

void stats_generales() //Construccion de la funcion que imprime las estadisticas de todos los jugadores registrados
{
	FILE *estadisticas; //apuntador al archivo
	char compara[11],compara2[11];
	char c_total[15],c_juegos[3];
	estadisticas=fopen("stats.txt","r"); //Se abre el documento en modo lectura
			
				while(feof(estadisticas)==0) //Se escanea el documento hasta el final
				{
					fscanf(estadisticas,"%s",compara);
					fscanf(estadisticas,"%s",c_total);
					fscanf(estadisticas,"%s",c_juegos);
				//	printf("%s\n",compara); //Banderas para verificar la funcionalidad del proceso
				//	printf("%s\n",compara2);
					if(strcmp(compara,compara2)==0) //Se comparan las variables
					{
						//	printf("Los valores son iguales\n\n"); //Banderas para verificar la funcionalidad del proceso
						for(int i =0; i<11;i++)
						{
							compara2[i]=compara[i];
						}
						//	printf("Ahora compara2 tiene el siguiente valor %s\n",compara2); //Banderas para verificar la funcionalidad del proceso
					}
					else
					{
						//	printf("Los valores son diferentes\n\n");  //Banderas para verificar la funcionalidad del proceso
						
						printf("\t\t\t\t\t\t\t\t\tEl jugador %s obtuvo: \n",compara);
					
						printf("\t\t\t\t\t\t\t\t\t%s dinero ganado\n",c_total);	 	//Impresion de estadisticas en consola
						
						printf("\t\t\t\t\t\t\t\t\tEn %s juegos jugados\n\n\n",c_juegos);
							for(int i =0; i<11;i++)
							{
								compara2[i]=compara[i];
							}
						//	printf("Ahora comparados tiene el siguiente valor %s\n",compara2); //Banderas para verificar la funcionalidad del proceso
				}
				}
				fclose(estadisticas); // Se cierra el archivo
		
		printf("\t\t\t\t\t\t\t\t\t");
		system("pause"); //Pausa para reanudar manualmente
		system("cls");
		menu1(); //Se le manda al menu principal
	
}

void stats_personales() //Construccion de la funcion de estadisticas individuales
{
		system("cls"); 
		FILE *estadisticas; //Apuntador al archivo
		char compara[11];
		char c_total[15],c_juegos[3];
		
		estadisticas=fopen("stats.txt","r"); //Se abre el documento en modo lectura
			mientras:
				while(feof(estadisticas)==0) //Recorre el archivo hasta el final
				{
					fscanf(estadisticas,"%s",compara);
					fscanf(estadisticas,"%s",c_total); //Busca las estadisticas
					fscanf(estadisticas,"%s",c_juegos);
						
				if(strcmp(compara,usur)==0) //Si los resultados coinciden, se imprimen las estadisticas del usuario con sesion iniciada
					{
						gotoxy(60,15);					//En esta función se puede hacer uso de Go To XY porque se trata únicamente de un usuario
						printf("El jugador %s obtuvo:",compara);
						gotoxy(60,16);
						printf("%s dinero ganado",c_total);
						gotoxy(60,17);
						printf("En %s juegos jugados",c_juegos);
						goto cumplido; //Manda al marcador siguiente
					}
					else
					{
						goto mientras; // Manda al marcador anterior

					}
				}
				cumplido://Marcador Go To
				fclose(estadisticas);//Se cierra el documento de estadisticas
}

bool Validar_Datos(){ //Construccion de la funcion encargada de validar los datos ingresados con los que existen en los archivos de usuario y contraseñas
	 	int cont =0;
	 	char compass[11];
		archivo=fopen("usu.txt","r"); //Se abre el archivo de usuarion en modo lectura
		mientras: //Marcador Go To
		while(feof(archivo)==0) //Se recorre el archivo hasta el final
		{
			fscanf(archivo,"%s",compara); //Se escanean las cadenas para buscar coincidencias
			if(strcmp(compara,usur)==0) //Se comparan las cadenas
			{	
				fclose(archivo); //Se cierra el archivp de usuarios
				conti=fopen("cont.txt","r"); //Se abre el archivo de contraseñas en modo lectura
					for(int i=0; i< cont+1; i++ ) //Se recorren las cadenas 
					{
						fscanf(conti,"%s",compass);	 // Se busca por coincidencias
					}
					if(strcmp(compass,pass)==0) //Se realiza la comparación
					{
						return true; //Si se cumple retorna verdadero
					}
					else
					{
						return false; //Si no, retorna falso
					}
				fclose(conti); //Se cierra el archivo de contraseñas
			}
			else
			{
				cont++; //Se aumenta el contador
				goto mientras; //Se regresa al marcador inicial
			}
		}
				
		return false; 
}

int juego()
{
		long int maletines[maletin]={1,5,10,15,25,50,75,100,200,300,400,500,750,1000,2500,5000,10000,25000,50000,75000,
	100000,200000,300000,400000,500000,750000,1000000}; //Cantidades a asignar a los maletines
	long int oferta; //Variable que almacena la oferta
	float proba=0.15,divisor,ofprub,sumar;//Variables encargadas de calcular la oferta
	int isOpen[27]; 
	int remainingCase,eleccion,principal,toChoose;
	char aceptas;
	
	int i,j,deal,ronda,sum,temp,youWon;
	
	for(int i=0;i<maletin;i++) //For que recorre el arreglo de maletines abiertos y se le asigna el valor 0
	{
    	isOpen[i]=0;
	}
    
	srand(time(NULL));
	for(int i=26;i>0;--i) //Aleatoriza y asigna el valor de los maletines para que con cada ejecucion tengan cantidades distintas 
	{
		j = rand() % (maletin-1)+1;
    	temp = maletines[j];
    	maletines[j] = maletines[i];
    	maletines[i] = temp; 
   	} 
   
   
   	maletin_principal: //Marcador  Go To
   	system("cls");
	printf("\t\t\t\t\t\t\t\tQu%c malet%cn deseas guardar? ",130,161);
	showCases(maletines,isOpen);
	scanf("%d",&principal); //Se guarda el maletin inicial seleccionado por el jugador
	if(principal>maletin-1||principal<1){
	    printf("\t\t\t\t\t\tMalet%cn inv%clido, por favor selecciona uno distinto\n",161,160);//Se advierte cuando selecciona un maletin ya abierto o que no existe
	    goto maletin_principal; //Manda al marcador inicial
	}
	else
	isOpen[principal]=1; //Se marca que un maletin ha sido abierto
	printf("\t\t\t\t\t\t\t\tHas elegido tu malet%cn.\n\n",161); //Se le avisa al usuario que escogio su maletin
	system("pause"); //Pausa para reanudar manualmente
	system("cls");
	
	oferta=0;
	ronda=0;
	deal=0;
	toChoose=6;
	remainingCase=maletin-2;
	youWon=0;
	while (remainingCase != 1 && deal == 0) //Se hace el conteo de maletines restantes para avanzar con el juego
	{
    	printf("\t\t\t\t\t\t\tBienvenido a la ronda %d de Deal or No Deal\n",++ronda); //Se informa de la ronda actual
    	showCases(maletines,isOpen); //Llamado a la funcion que muestralos maletines en consola
		for(int i=0;i<toChoose;i++)
		{	
			select_maletin:
	        	printf("\n\t\t\t\t\t\t\tElige tu pr%cximo malet%cn. Tienes %d maletines disponibles para abrir:\t",162,161,toChoose-i);
	        	scanf("%d",&eleccion); //Se le indica cuantos maletines puede abrir en esta ronda
	        	
	        	if(isOpen[eleccion]==1||eleccion>maletin-1||eleccion<1){
	        		printf("\t\t\t\t\t\t\t\tMalet%cn inv%clido, por favor selecciona uno distinto\n",161,160); //Se advierte cuando selecciona un maletin ya abierto o que no existe
	        		goto select_maletin; //Manda al marcador anterior
				}
				else
				system("cls");
	        	printf("\n\t\t\t\t\t\t\t\tN%cmero de malet%cn abierto %d: $%ld pesos\n",163,161,eleccion,maletines[eleccion]); //Le indica al jugador el maletin que se abrio y la cantidad contenida
	        	isOpen[eleccion]=1; //0=cerrado, 1=abierto     
	        	showCases(maletines,isOpen); //Se llama a la funcion que muestra los maletines
    	}
    	
    	remainingCase-=toChoose;
    	//printf("%d\n",remainingCase); //Banderas para verificar los procesos
    	//printf("%d\n",toChoose);
    	if(toChoose>1){
    	--toChoose;
    	}
    	else{
    		toChoose=1;
		}
    	
    	printf("\t\t\t\t\t\t\t\tAhora veremos qu%c ofrecer%c el BANCO.",130,160);
		printf("\n\n\t\t\t\t\t\t\t\tAqu%c est%c la llamada telef%cnica\n",161,160,162);
    	sum=0;
    	
    	for(i=1,j=0;i<maletin;i++)
		{
        	if(isOpen[i]==0){
        	sum+=maletines[i];//Lee los maletines restantes
        	j++;
        }
    	}
    sum+=maletines[principal];//Se toma en cuenta al maletin del jugador
    	if(ronda<5){//Con base en la ronda genera la oferta
    	ofprub=((sum/j)*proba);//Se genera la oferta del banco para el jugador 
    	oferta = ofprub;//Se asigna el valor de la oferta
    	//printf("La oferta buena es %f\n",ofprub); //Bandera para verificar los procesos
      	printf("\n\t\t\t\t\t\t\t\tEl BANCO te ofrece: $%ld pesos\n",oferta); //Se le muestra la oferta al jugador
      	proba+=0.05;//se aumenta la probabilidad para realizar la oferta
      	}
      else{
      	if (ronda<9){//Lo mismo que arriba
	      	ofprub=((sum/j)*proba);
	    	oferta = ofprub;
	    	//printf("La oferta buena es %f\n",ofprub); //Bandera para verificar el funcionamiento
	      	printf("\n\t\t\t\t\t\t\t\tEl BANCO te ofrece: $%ld pesos\n",oferta); 
	      	proba+=0.10;//El aumento de la probabilidad es mas grande
	      }
	    else{
	    	printf("\t\t\t\tHas llegado a la ronda final, debes elegir si te quedas con tu maletín o lo cambias por este\n");
	    	for(i=1,j=0;i<maletin;i++)
			{
	        	if(isOpen[i]==0){
	        	 oferta=maletines[i];//Se asigna el valor del maletin a la oferta por cuestiones de practicidad
	        	}
    		}
    		
		}
	  }
       
    	printf("\t\t\t\t\t\t\t\t\La pregunta es: Aceptas? [s/n]: ");
    	scanf("\t\t\t\t\t\t\t\t %c",&aceptas);
    	getchar();
    	
    	if(aceptas=='s'){
        	deal=1;
        	youWon=oferta;//se asigna el valor de la oferta a la variable mensajera
    	}
    	
		system("cls");
	}
 
	gotoxy(70,10);
			printf("Gracias por jugar DEAL OR NO DEAL");

	if(deal==1)
	{
		gotoxy(70,20);
    	printf("Ganaste: $%ld",youWon);		
	}
	else
	{
    	youWon=maletines[principal];
    	gotoxy(60,30);
    	printf("Felicidades, tu maletin contenia: $%ld",youWon);
    	
	}
	
	gotoxy(70,35);
	system("pause");
	system("cls");
	menu();
	return youWon;
	

}

void showCases(long int maletines[maletin], int isOpen[maletin])
{
	int i;
	printf("\n\n\n\n\n");
	for(i=1;i<maletin;i++)
	{
    	if(isOpen[i]==0)
		{
        	printf("\t\t\t\t\t\t[ %d ]\t\t ",i);//Muestra el numero de maletin antes de ser abierto
        
    	}
    	else
		{	
        	printf("\t\t\t\t\t\t[    ]\t\t ");//Muestra el espacio vacio de un maletin ya abierto
    	}
    	if(i%2==0)
    	{
        	printf("\n");
        }
    
	}
}
