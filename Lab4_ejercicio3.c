#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *nombre;
	int ID;
	int tiempo;
}usuarios;

// funciones utilizadas//
void abrir_archivo();
void imprim_lista_user();
void imprim_lista_user_condicion();
void ultim_hora_acceso();
void actualizar_user();


// por defecto//
usuarios *user;
void vaciar(char temp[]);
void copiar(char temp[], int i);

// menu variable//
int op,cent;

int main(){
      cent=5;
      while(cent<=5){
            printf("Bienvenido al menu de usuarios, elige una opcion");
            printf("\n\n1.- Imprimir la lista de usuarios.");
            printf("\n\n2.- Imprimir la lista de usuarios y su condición");
            printf("\n\n3.- Ordenar los usuarios por ultima hora de acceso.");
            printf("\n\n4.- Actualizar los datos de un usuario.");
            printf("\n\n5.- Salir del menu");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  imprim_lista_user();
               break;
               case 2:
                  imprim_lista_user_condicion();
               break;
               case 3:
                  ultim_hora_acceso();
               break;
               case 4:
                  actualizar_user();
               break;
               case 5:
                  cent=6;
               break;
               default:
                  printf("\nError, opcion no valida");
                  printf("\n Introduce una opcion valida");
               break;
            }
        }
}

//Definicion de funciones//

//FUNCION PARA USAR EL ARCHIVO//

void abrir_archivo(){
    int i,j;
	char aux;
	char temp[50];
	int cont = 0;
	
	FILE *f; //se declara un fichero
	f = fopen("Bloque8.2.txt", "r"); //abrir el fichero, modo de apertura de lectura
	if (f==NULL){  //comprobar que se abrio correctamente el fichero
		printf("No se ha podido abrir el fichero.\n");
		exit(1);
	}
	
	while(!feof(f)){  //con este bucle se reccorre el archivo y se llega hasta el final 
		fgets(temp,50,f); //leer toda la linea y lo almacena en string
		cont++;
	}
	
	rewind(f); //para volver al inicio del fichero
	
	user = (usuarios*)malloc(cont*sizeof(usuarios)); //se le asigna un espacio de memoria a los usuarios
	if(user == NULL){  //en caso de que salga mal la reserva 
		printf("No se ha podido reservar la memoria.\n");
		exit(1);
	}
	
	for (i = 0; !feof(f); i++){  //para leer la informacion dentro del fichero
		vaciar(temp); //se vacia temp para llenarla con los caracteres del nombre 
		aux = '0';
		for(j = 0; aux != '-'; j++){ //se mete cada uno de los caracteres dentro de aux
			aux = fgetc(f);  //agarra uno a uno los elementos del fichero hasta guion
			if (aux != '-'){
				temp[j] = aux;  //despues del guion se metera en j
			}
		}
		copiar(temp,i); //funcion que recibe la cadena de caracteres 
		
		fgets(temp,9,f); //coge todo lo que esta en adelante del guion 
		fgets(temp,2,f); //coge todo lo que esta en adelante del guion
		user[i].ID = atoi(temp);
		user[i].tiempo = atoi(temp);  //pasa los caracteres a enteros
		sscanf("%s ",&user[i].nombre);
		printf("Nombre: %s ID: %i tiempo: %i \n", user[i].nombre, user[i].ID, user[i].tiempo );
	}
	
   }

//FUNCIONES EXTRAS//

void vaciar(char temp[]){ //funcion para vaciar temp
	int i;
	
	for(i = 0; i < 50; i++){
		temp[i] = '\0';
	}
}

void copiar(char temp[], int i){ //funcion que recibe la cadena de caracteres temp y contador i
	int N = strlen(temp) + 1;  //cuenta cuantos caracteres hay dentro de temp (no cuenta el final de linea)
	user[i].nombre = (char*)malloc(N*sizeof(char)); //se reserva espacio de memoria en el string nom
	if (user[i].nombre == NULL){  //se comprueba que se reservo correctamente 
		printf("No se ha podido reservar memoria.\n");
		exit(1);
	}
	strcpy(user[i].nombre, temp);  //con esta funcion se copian los strings
}

//FUNCION PARA IMPRIMIR LA LISTA DE USUARIOS//

void imprim_lista_user( ){
	abrir_archivo();
	
	
	
	

}

//FUNCION PARA IMPRIMIR LA LISTA DE USUARIOS Y SU CONDICION//

void imprim_lista_user_condicion(){
	
}

//FUNCION PARA ORDENAR LOS USUARIOS POR SU ULTIMA HORA DE CONEXION//

void ultim_hora_acceso(){
	
}

//FUNCION PARA ACTUALIZAR LOS DATOS DE UN USUARIO//

void actualizar_user(){
	
}
