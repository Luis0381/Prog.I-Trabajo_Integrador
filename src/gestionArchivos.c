/* Copyright 2021, Cátedra de Informática y Programación I
 * Departamento de Electricidad, Electrónica y Computación
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 * Copyright 2021, Mariana Sánchez <msanchez@herrera.unt.edu.ar>, Enzo A. Sémola <esemola@herrera.unt.edu.ar>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* === Inclusiones de cabeceras ================================================================ */
/* En primer lugar incluir el archivo .h correspondiente a éste archivo .c si corresponde*/
/* #include "plantilla.h"*/

#include "gestionArchivos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliar.h"
#include "login.h"
#include "turnos.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */
void controlArchivo(char nombre[]) {
    FILE *punteroArchivo;
    punteroArchivo = fopen(nombre, "r");
    if (punteroArchivo == NULL) {
        printf("Error al abrir %s, se procedera a crearlo\n", nombre);
        punteroArchivo = fopen(nombre, "w");
        if (punteroArchivo == NULL) {
            printf("No se pudo crear el archivo\n");
            exit(0);
        }
    } else {
        printf("%s cargado correctamente.\n", nombre);
    }
    fclose(punteroArchivo);
    return;
}

void mostrarListado() {
    FILE *punteroArchivo;
    char turnosVete[] = "turnosVete.dat";
    int contador = 0;
    turno memoria;
    punteroArchivo = fopen(turnosVete, "rb");
    printf("=======================================\n");
    printf("    CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("=======================================\n");
    printf("\n     LISTADO DE TODOS LOS TURNOS\n");
    printf("_______________________________________\n\n");
    while (feof(punteroArchivo) == 0) {
        fread(&memoria, sizeof(memoria), 1, punteroArchivo);
        if (feof(punteroArchivo) == 0) {
            printf("\t -TURNO NUMERO %i-", memoria.codigo);
            printf("\n");
            mostrarTurno(&memoria);
            printf("\n");
            contador++;
        }
    }
    if (contador == 0) {
        printf("\t    NO HAY TURNOS\n\n");
    }
    fclose(punteroArchivo);
}

void mostrarAgenda() {
    FILE *punteroArchivo;
    char turnosVete[] = "turnosVete.dat";
    int contador = 0;
    fecha unaFecha;
    turno memoria;
    punteroArchivo = fopen(turnosVete, "rb");
    printf("=======================================\n");
    printf("    CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("=======================================\n\n");
    printf("A continuacion, ingrese una fecha por favor\n");
    unaFecha = leerFecha();
    limpiarPantalla();
    printf("=======================================\n");
    printf("    CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("=======================================\n");
    printf("\n      AGENDA DEL DIA %i/%i/%i\n", unaFecha.dia, unaFecha.mes, unaFecha.anio);
    printf("_______________________________________\n\n");

    for (int hora = 0; hora <= 23; hora++) {
        for (int minuto = 0; minuto <= 59; minuto++) {
            rewind(punteroArchivo);
            while (feof(punteroArchivo) == 0) {
                fread(&memoria, sizeof(memoria), 1, punteroArchivo);
                if (feof(punteroArchivo) == 0) {
                    if (unaFecha.dia == memoria.fechaTurno.dia && unaFecha.mes == memoria.fechaTurno.mes && unaFecha.anio == memoria.fechaTurno.anio) {
                        if (memoria.horaTurno.hora == hora && memoria.horaTurno.minuto == minuto) {
                            printf("\t -TURNO NUMERO %i-", contador);
                            printf("\n");
                            mostrarTurno(&memoria);
                            printf("\n");
                            contador++;
                        }
                    }
                }
            }
        }
    }
    if (contador == 0) {
        printf("\t    NO HAY TURNOS\n\n");
    }
    fclose(punteroArchivo);
}

void consultarUltimaFecha() {
    FILE *punteroArchivo;
    char turnosVete[] = "turnosVete.dat";
    char mascota[MAX];
    fecha fechaActual, ultimaFecha;
    turno memoria, ultimoTurno;
    int bandera = 0;
    punteroArchivo = fopen(turnosVete, "rb");
    printf("=======================================\n");
    printf("    CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("=======================================\n\n");
    printf("A continuacion, ingrese la fecha actual por favor\n");
    fechaActual = leerFecha();
    printf("\nIngrese el nombre de la mascota: ");
    fgets(mascota, MAX, stdin);
    mascota[strlen(mascota) - 1] = '\0';
    convertirPrimeraMayuscula(mascota);
    limpiarPantalla();
    while (feof(punteroArchivo) == 0) {
        fread(&memoria, sizeof(memoria), 1, punteroArchivo);
        if (strcmp(mascota, memoria.nombreMascota) == 0) {
            if (compararFechas(fechaActual, memoria.fechaTurno) == 1) {
                if (bandera == 0 && feof(punteroArchivo) == 0) {
                    ultimoTurno = memoria;
                    bandera++;
                } else {
                    if (compararFechas(memoria.fechaTurno, ultimoTurno.fechaTurno) == 1 && feof(punteroArchivo) == 0) {
                        ultimoTurno = memoria;
                    }
                    if (compararFechas(memoria.fechaTurno, ultimoTurno.fechaTurno) == 0 && feof(punteroArchivo) == 0) {
                        if (compararHoras(memoria.horaTurno, ultimoTurno.horaTurno) == 1 && feof(punteroArchivo) == 0) {
                            ultimoTurno = memoria;
                        }
                    }
                }
            }
        }
    }
    if (bandera == 0) {
        printf("=======================================\n");
        printf("    CENTRO DE ESTETICA DE MASCOTAS\n");
        printf("=======================================\n");
        printf("\n  No se atendio nunca a %s todavia\n\n", mascota);
    } else {
        printf("=======================================\n");
        printf("    CENTRO DE ESTETICA DE MASCOTAS\n");
        printf("=======================================\n");
        printf("\nLa ultima vez que se atendio a %s en el centro de estetica es el: %i/%i/%i\n", mascota, ultimoTurno.fechaTurno.dia, ultimoTurno.fechaTurno.mes, ultimoTurno.fechaTurno.anio);
        printf("\nLa ficha del turno de aquel dia es: \n");
        printf("\n\tFICHA DEL TURNO\n");
        printf("_______________________________________\n\n");
        mostrarTurno(&ultimoTurno);
        printf("\n\n");
    }
    fclose(punteroArchivo);
}

void cargarArchivos() {
    char turnosVete[] = "turnosVete.dat";
    char servicios[] = "servicios.txt";
    char usuarios[] = "usuarios.txt";
    printf("\n========================================================\n");
    printf("\t         CARGA DE ARCHIVOS\n");
    printf("\nCargando los archivos necesarios para la ejecucion...\n");
    controlArchivo(turnosVete);
    controlArchivo(servicios);
    controlArchivo(usuarios);
    printf("\n========================================================\n");
    printf("\n");
    printf("         ");
    presioneContinuar();
    limpiarPantalla();
    return;
}

void guardarTurno(turno datosTurno) {
    FILE *punteroArchivo;
    char turnosVete[] = "turnosVete.dat";
    punteroArchivo = fopen(turnosVete, "ab");
    fwrite(&datosTurno, sizeof(datosTurno), 1, punteroArchivo);
    fclose(punteroArchivo);
    printf("\n");
}

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */
