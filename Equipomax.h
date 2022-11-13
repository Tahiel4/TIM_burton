#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

#include <time.h>
#include <string.h>

/*el mundial empieza el 20 de noviembre y termina el 18 de diciembre*/

typedef struct  {
    char apellido[20];
    int goles;
}Artillero;

typedef struct {
    int goles_favor;
    int goles_contra;
    int puntaje_parcial;
}Resultados;

typedef struct{
    int anio, mes, dia;
} Fecha;


typedef struct {
    char pais[100];
    char dt[50];
    char capitan[20];
    char grupo;
    int puntaje_actual;
    Artillero goleador;
    int fase;
    Resultados resultados_fase[5];
    Fecha /*control*/ fecha_actualizada;
    int partidos_jugados;
    int partidos_ganados;
    int partidos_empatados;
}Equipo;

void init_equipo(Equipo *equipo_intro){
	int i;
	Equipo undefined={"sin nombre", "sin nombre", 'Z', 0, 1, 0, 0, 0, 0, 0, 0};
	Artillero undef_goleador={"sin nombre", 0};

	Fecha undef_fecha={0,0,0};
	(*equipo_intro)=undefined;

	equipo_intro->goleador=undef_goleador;
	for(i=0; i<=5; ++i){
     	equipo_intro->resultados_fase[i].goles_favor=0;
     	equipo_intro->resultados_fase[i].goles_contra=0;
     	equipo_intro->resultados_fase[i].puntaje_parcial=0;
	}
	equipo_intro->fecha_actualizada=undef_fecha;

}

/*ESTAS SON LAS FUNCIONES DE CARGAR ---------------------------------------------------------*/

void cargar_pais(Equipo *equipo,char pais[]){
    strcpy((*equipo).pais,pais);
    //strcpy(equipo->pais, pais);
}

void cargar_dt(Equipo *equipo,char dt[]){
    strcpy((*equipo).dt,dt);
    //strcpy(equipo->pais, pais);
}

void cargar_capitan(Equipo *equipo,char capi[]){
    strcpy((*equipo).capitan,capi);
    //strcpy(equipo->pais, pais);
}

void cargar_grupo(Equipo *equipo,char grupo){
    (*equipo).grupo=grupo;
}

void cargar_puntaje_actual (Equipo *equi, int cargado) {
    (*equi).puntaje_actual=cargado;
}

void cargar_goleador (Equipo *equi, Artillero arti) {
    (*equi).goleador=arti;
}

void cargar_fase (Equipo *equi, int fase_actual) {
    (*equi).fase=fase_actual;
}

void cargar_resultados_fase (Equipo *equi, int fase, Resultados cantidades) {
    (*equi).resultados_fase[fase]=cantidades;
}

void cargar_partidos_jugados (Equipo *equi, int cant_jugados) {
    (*equi).partidos_jugados=cant_jugados;
}

void cargar_partidos_ganados (Equipo *equi, int cant_ganados) {
    (*equi).partidos_ganados=cant_ganados;
}

void cargar_partidos_empatados (Equipo *equi, int cant_empatados) {
    (*equi).partidos_empatados=cant_empatados;
}

/*ACÁ TERMINAN LAS FUNCIONES DEL CARGAR-------------------------------------------------------------------------------*/

/*ACÁ EMPIEZAN LAS FUNCIONES DE MODIFICAR CAMPOS------------------------------------------------------------------------*/

void modificar_puntaje_actual (Equipo *equi, int cargado) {
    (*equi).puntaje_actual=cargado;
}

void modificar_fase_goleador (Equipo *equi, Artillero arti) {
    (*equi).goleador=arti;
}

void modificar_fase (Equipo *equi, int fase_actual) {
    (*equi).fase=fase_actual;
}

void modificar_resultados_fase (Equipo *equi, int fase, Resultados cantidades) {
    (*equi).resultados_fase[fase]=cantidades;
}

void modificar_fecha (Equipo *equi, Fecha fecha) {
    (*equi).fecha_actualizada = fecha;
}

void modificar_partidos_jugados (Equipo *equi, int cant_jugados) {
    (*equi).partidos_jugados=cant_jugados;
}

void modificar_partidos_ganados (Equipo *equi, int cant_ganados) {
    (*equi).partidos_ganados=cant_ganados;
}

void modificar_partidos_empatados (Equipo *equi, int cant_empatados) {
    (*equi).partidos_empatados=cant_empatados;
}

/*ACÁ TERMINAN LOS MODIFICAR TINTY NASTY*/




/*ACÁ EMPIEZAN LOS MOSTRAR TINTY NASTY*/

char* mostrar_pais(Equipo pais){
	char* s1=(char*)malloc(sizeof(char)*strlen(pais.pais));
	strcpy (s1, pais.pais);
	return s1;
	free((void*)s1);
}
char* mostrar_dt(Equipo pais){
	char* s1=(char*)malloc(sizeof(char)*strlen(pais.dt));
	strcpy (s1, pais.dt);
	return s1;
	free((void*)s1);
}

char* mostrar_capitan(Equipo pais){
	char* s1=(char*)malloc(sizeof(char)*strlen(pais.capitan));
	strcpy (s1, pais.capitan);
	return s1;
	free((void*)s1);
}

char mostrar_grupo(Equipo pais){
	return pais.grupo;
}

int mostrar_puntaje(Equipo pais){
	return pais.puntaje_actual;
}

char mostrar_goleador_nombre(Equipo pais){
	char* s1=(char*)malloc(sizeof(char)*strlen(pais.goleador.apellido));
	strcpy (s1, pais.capitan);
	return s1;
	free((void*)s1);
}

char mostrar_goleador_goles(Equipo pais){
	return pais.goleador.goles;
}

int mostrar_fase(Equipo pais){
	return pais.fase;
}

int mostrar_goles_favor(Equipo pais){
    return pais.resultados_fase[pais.fase].goles_favor;
}

int mostrar_goles_contra(Equipo pais){
    return pais.resultados_fase[pais.fase].goles_contra;
}

int mostrar_puntaje_parcial(Equipo pais){
    return pais.resultados_fase[pais.fase].puntaje_parcial;
}

int mostrar_fecha_dia(Equipo pais){
	return pais.fecha_actualizada.dia;
}

int mostrar_fecha_mes(Equipo pais){
	return pais.fecha_actualizada.mes;
}

int mostrar_fecha_anio(Equipo pais){
	return pais.fecha_actualizada.anio;
}

int mostrar_partidos_jugados(Equipo pais){
	return pais.partidos_jugados;
}

int mostrar_partidos_ganados(Equipo pais){
	return pais.partidos_ganados;
}

int mostrar_partidos_empatados(Equipo pais){
	return pais.partidos_empatados;
}
