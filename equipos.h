#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

#include <time.h>
#include <string.h>

typedef struct  {
    char apellido[20];
    int goles;
}Artillero;

typedef struct {
    int goles_favor;
    int goles_contra;
    int puntaje_parcial; /*Si la fase> f.grupos, entonces 1=gano, 0=perdio, 2=pendiente*/
}Resultados;

typedef struct{
    int anio, mes, dia;
} Fecha;

typedef struct {
    char pais[100];
    int continente; /*1=ASIA 2=AMERICA 3=AFRICA 4=EUROPA 5=OCEANIA*/
    char dt[50];
    char capitan[20];
    char grupo;
    int puntaje_actual;
    Artillero goleador;
    int fase; /*0=fase grup, 1=8avos, 2=4tos, 3=semi, 4=final*/
    Resultados resultados_fase[5];
    Fecha fecha_actualizada; /*control*/ 
    int partidos_jugados;
    int partidos_ganados;
    int partidos_empatados;
}Equipo;

/*ESTAS SON LAS FUNCIONES DE CARGAR ---------------------------------------------------------*/

void cargar_pais(Equipo *equipo, char pais[]){
    strcpy((*equipo).pais, pais);
}

void cargar_continente(Equipo *equipo, int continente_ing){
    equipo->continente = continente_ing;
}

void cargar_dt(Equipo *equipo,char dt[]){
    strcpy((*equipo).dt, dt);
}

void cargar_capitan(Equipo *equipo,char capi[]){
    strcpy((*equipo).capitan,capi);
}

void cargar_grupo(Equipo *equipo,char grupo){
    (*equipo).grupo=grupo;
}

void cargar_puntaje_actual (Equipo *equipo, int cargado) {
    equipo->puntaje_actual=cargado;
    equipo->resultados_fase[0].puntaje_parcial=cargado;
}

void cargar_goleador_struct (Equipo *equi, Artillero arti) {
    (*equi).goleador=arti;
}
void cargar_goleador_apellido (Equipo *equipo, char apellido_ing[]) {
    strcpy(equipo->goleador.apellido, apellido_ing);
}
void cargar_goleador_goles (Equipo *equipo, int goles_ing) {
    equipo->goleador.goles = goles_ing;
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

void cargar_fecha (Equipo *equi,int dia,int mes,int anio){
    (*equi).fecha_actualizada.dia=dia;
    (*equi).fecha_actualizada.mes=mes;
    (*equi).fecha_actualizada.anio=anio;
}

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
         equipo_intro->resultados_fase[i].puntaje_parcial=2;
    }
    equipo_intro->fecha_actualizada=undef_fecha;
    
}  

/*AC� EMPIEZAN LAS FUNCIONES DE MODIFICAR CAMPOS------------------------------------------------------------------------*/

void modificar_continente(Equipo *equipo, int continente_ing){
    equipo->continente = continente_ing;
}

void modificar_puntaje_actual (Equipo *equipo, int cargado) {
    equipo->puntaje_actual=cargado;
    equipo->resultados_fase[0].puntaje_parcial=cargado;
}

void modificar_fase_goleador (Equipo *equi, Artillero arti) {
    (*equi).goleador=arti;
}

void modificar_goleador_nombre (Equipo *equi, char arti[]) {
    strcpy((*equi).goleador.apellido,arti);
}

void modificar_goleador_goles(Equipo *equi, int gol){
    (*equi).goleador.goles = gol;
}

void modificar_fase (Equipo *equi, int fase_actual) {
    (*equi).fase=fase_actual;
}

void modificar_resultados_fase (Equipo *equi, int fase, Resultados cantidades) {
    (*equi).resultados_fase[fase]=cantidades;
}
void modificar_resultados_fase_GF(Equipo *equi, int fase, int goles_a_favor_intro) {
    equi->resultados_fase[fase].goles_favor = goles_a_favor_intro;
}
void modificar_resultados_fase_GC(Equipo *equi, int fase, int goles_en_contra_intro) {
    equi->resultados_fase[fase].goles_contra = goles_en_contra_intro;
}
void modificar_resultados_fase_ptj(Equipo *equi, int fase, int ptj_intro) {
    equi->resultados_fase[fase].puntaje_parcial = ptj_intro;
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

/*AC� EMPIEZAN LOS MOSTRAR TINTY NASTY*/

char* mostrar_pais(Equipo pais){
	char* s1=(char*)malloc(sizeof(char)*strlen(pais.pais));
	strcpy (s1, pais.pais);
	return s1;
	free((void*)s1);
}

int mostrar_continente(Equipo *equipo){
    return equipo->continente;
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

int mostrar_puntaje_actual(Equipo pais){
    return pais.puntaje_actual;
}

Artillero mostrar_goleador_struct(Equipo pais){
	return pais.goleador;
}

char* mostrar_goleador_apellido(Equipo pais){
    char* s1=(char*)malloc(sizeof(char)*strlen(pais.goleador.apellido));
	strcpy (s1, pais.goleador.apellido);
	return s1;
	free((void*)s1);
}

int mostrar_goleador_goles(Equipo pais){
	return pais.goleador.goles;
}

int mostrar_fase(Equipo pais){
	return pais.fase;
}

Resultados mostrar_resultados_fase(Equipo pais, int opcion){
	return pais.resultados_fase[opcion];
}

int mostrar_resultados_fase_gfav(Equipo pais, int opcion){
    return pais.resultados_fase[opcion].goles_favor;
}

int mostrar_resultados_fase_gcon(Equipo pais, int opcion){
    return pais.resultados_fase[opcion].goles_contra;
}

int mostrar_resultados_fase_punt_parcial(Equipo pais, int opcion){
    return pais.resultados_fase[opcion].puntaje_parcial;
}

Fecha mostrar_fecha_actualizada(Equipo pais){
	return pais.fecha_actualizada;
}

int mostrar_fecha_actualizada_dia(Equipo pais){
	return pais.fecha_actualizada.dia;
}

int mostrar_fecha_actualizada_mes(Equipo pais){
	return pais.fecha_actualizada.mes;
}

int mostrar_fecha_actualizada_anio(Equipo pais){
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

#endif // EQUIPOS_H_INCLUDED



