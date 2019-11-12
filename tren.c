
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include "tren.h"
#define MAX 80 
#define PORT 8080
#define SA struct sockaddr 

void escribirMensaje(int sockTren,ST_TREN * tren) { 
    char mensaje[MAX]; 
    int i; 
    for (;;) { 
        bzero(mensaje, sizeof(mensaje)); 
        printf(" \n Ingrese el mensaje: \n"); 
        i = 0; 
        while ((mensaje[i++] = getchar()) != '\n'); 
        
            if ((strncmp(mensaje, "info", 4)) == 0) { 
                printf("Informacion del tren:\n"); 
                printf("Modelo:%s\n",tren->idTren);
                printf("Origen:%s\n",tren->estacionOrigen);
                printf("Destino:%s\n",tren->estacionDestino);
                printf("Cant de pasajeros:%d\n",tren->pasajeros);
                printf("Litros de combustible:%d\n",tren->combustible);
                printf("tiempo de viaje restante:%d\n",tren->tViaje);
                printf("Estado:%s\n",tren->estado); // en transito, en anden, en estacion
                printf("Motivo:%s\n",tren->motivo); // paso o anden
          } 
            if ((strncmp(mensaje, "exit", 4)) == 0) { 
            printf("te desconectaste.\n"); 
            break; 
        } else{
        
            send(sockTren, mensaje, sizeof(mensaje),0); 
            //bzero(mensaje, sizeof(mensaje)); 
            //recv(sockTren, mensaje, sizeof(mensaje),0); 
           // printf("Estacion envio: %s \n", mensaje); 
        } 
        bzero(mensaje, sizeof(mensaje)); 
    } 
} 
  
int main(int argc, char * argv[]) { 
    FILE * config=NULL;
    char * linea=(char*)malloc(sizeof(char)*MAX);
    memset(linea,'\0',MAX);
    config=fopen(argv[1],"r");

    if(config==NULL){
        printf("fallo la apertura");
        exit(EXIT_FAILURE);
    } else{
        printf("se abrio el archivo\n");
        }
        while(fgets(linea,37+1,config)!=NULL){
            
              
        }
    ST_TREN tren;
   // createTren(&tren);
    
    int sockTren; 
    struct sockaddr_in estacionAddr; 
  
    // se crea el socket
    sockTren = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockTren == -1) { 
        printf("la creacion del socket fallo...\n"); 
        exit(0); 
    } 
    else
        printf("Se creo el tren..\n"); 
    bzero(&estacionAddr, sizeof(estacionAddr)); 
  
    // se asigna la ip y el puerto a usar
    estacionAddr.sin_family = AF_INET; 
    estacionAddr.sin_addr.s_addr = INADDR_ANY; 
    estacionAddr.sin_port = htons(PORT); 
  
    // se conecta el tren con la estacion
    if (connect(sockTren, (SA*)&estacionAddr, sizeof(estacionAddr)) != 0) { 
        printf("La conexion con la estacion fallo...\n"); 
        exit(0); 
    } 
    else
        printf("Esta conectado con la estacion..\n"); 
  
    
    escribirMensaje(sockTren, &tren); 
  
    
    close(sockTren); 
} 
