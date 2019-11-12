
#ifndef TREN_H 
#define TREN_H
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
	
    char idTren[8];
    char estacionOrigen[5];
    char estacionDestino[5];
    int pasajeros;
    int combustible;
    int tViaje;
    char estado[10];
    char motivo[10];
     
} ST_TREN ;

void createTren(ST_TREN * tren);

void registrarTren(ST_TREN * tren);

void cargartren(char *tren);

void pasardatosabuffer(char*linea, ST_TREN tren);

void bufferatren(const char*linea, ST_TREN*tren);

#ifdef __cplusplus
}

#endif
#endif /* TREN_H */
