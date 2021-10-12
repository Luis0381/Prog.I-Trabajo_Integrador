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

#include "turnos.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliar.h"
#include "controles.h"
#include "gestionArchivos.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */

tipoServicio leerServicios(char cadena[MAX]) {
    static int bandera = 0;
    char *punteroReferencia;

    tipoServicio servicios;

    char codigoServicio[MAX];
    char precioServicio[MAX];

    punteroReferencia = strtok(cadena, ";");
    strcpy(codigoServicio, punteroReferencia);
    punteroReferencia = strtok(NULL, ";");
    strcpy(servicios.nombreServicio, punteroReferencia);
    punteroReferencia = strtok(NULL, "\n");
    strcpy(precioServicio, punteroReferencia);

    convertirPrimeraMayuscula(servicios.nombreServicio);
    servicios.codigoServicio = atoi(codigoServicio);
    servicios.precioServicio = atoi(precioServicio);

    return servicios;
}

encabezadosServicios leerEncabezados(char cadena[MAX]) {
    static int bandera = 0;
    char *punteroReferencia;

    encabezadosServicios encabezados;

    punteroReferencia = strtok(cadena, ";");
    strcpy(encabezados.codigoServicio, punteroReferencia);
    punteroReferencia = strtok(NULL, ";");
    strcpy(encabezados.nombreServicio, punteroReferencia);
    punteroReferencia = strtok(NULL, "\n");
    strcpy(encabezados.precioServicio, punteroReferencia);

    convertirPrimeraMayuscula(encabezados.codigoServicio);
    convertirPrimeraMayuscula(encabezados.nombreServicio);
    convertirPrimeraMayuscula(encabezados.precioServicio);

    return encabezados;
}

int menuServicios() {
    char servicios[] = "servicios.txt";
    char cadena[MAX];
    tipoServicio servicio;
    encabezadosServicios encabezados;
    int opcion, bandera = 1, banderaServicio = 0;
    FILE *punteroArchivo;
    punteroArchivo = fopen(servicios, "r");
    do {
        if (bandera == 0) {
            printf("La opcion ingresada es incorrecta, por favor ingrese nuevamente\n");
        } else {
            printf("\n\t\tMENU DE SERVICIOS\n\n");
        }
        while (feof(punteroArchivo) == 0) {
            if (fgets(cadena, MAX, punteroArchivo) != NULL) {
                if (banderaServicio == 0) {
                    encabezados = leerEncabezados(cadena);
                    printf("  %s\t   %s\t        %s\n", encabezados.codigoServicio, encabezados.nombreServicio, encabezados.precioServicio);
                    banderaServicio++;
                } else {
                    servicio = leerServicios(cadena);
                    if (strlen(servicio.nombreServicio) > 10) {
                        printf("    %i\t     %s      %i\n", servicio.codigoServicio, servicio.nombreServicio, servicio.precioServicio);
                    } else {
                        printf("    %i\t\t     %s\t\t  %i\n", servicio.codigoServicio, servicio.nombreServicio, servicio.precioServicio);
                    }
                }
            }
        }
        printf("\n\tSeleccionar una opcion: ");
        scanf("%i", &opcion);
        setbuf(stdin, NULL);
        bandera = 0;
    } while (opcion < 1 || opcion > 3);
    fclose(punteroArchivo);
    return opcion;
}

turno leerTurno() {
    turno datosTurno;
    int banderaNombreDuenio = 0;
    int banderaNombreMascota = 0;
    char turnosVete[] = "turnosVete.dat";
    do {
        if (banderaNombreDuenio != 0) {
            printf("Se ingresaron caracteres invalidos, ingrese nuevamente\n");
        }
        printf("Ingrese el nombre del duenio de la mascota: ");
        fgets(datosTurno.nombreDueno, MAX, stdin);
        datosTurno.nombreDueno[strlen(datosTurno.nombreDueno) - 1] = '\0';
        banderaNombreDuenio++;
    } while (controlarCadenaCaracteres(datosTurno.nombreDueno) == 0);
    convertirPrimeraMayuscula(datosTurno.nombreDueno);
    do {
        if (banderaNombreMascota != 0) {
            printf("Se ingresaron caracteres invalidos, ingrese nuevamente\n");
        }
        printf("Ingrese el nombre de la mascota: ");
        fgets(datosTurno.nombreMascota, MAX, stdin);
        datosTurno.nombreMascota[strlen(datosTurno.nombreMascota) - 1] = '\0';
        banderaNombreMascota++;
    } while (controlarCadenaCaracteres(datosTurno.nombreMascota) == 0);
    convertirPrimeraMayuscula(datosTurno.nombreMascota);
    printf("\nA continuacion, Seleccione el tipo de servicio\n");
    datosTurno.servicio = menuServicios();
    printf("\nA continuacion, ingrese la fecha\n\n");
    datosTurno.fechaTurno = leerFecha();
    printf("\nA continuacion, ingrese la hora\n\n");
    datosTurno.horaTurno = leerHora();
    datosTurno.codigo = asignarNumeroTurno(turnosVete);
    return datosTurno;
}

int asignarNumeroTurno(char nombre[]) {
    int numero;
    FILE *punteroArchivo;
    turno memoria;
    punteroArchivo = fopen(nombre, "rb");
    memoria.codigo = 0;
    while (feof(punteroArchivo) == 0) {
        fread(&memoria, sizeof(memoria), 1, punteroArchivo); /*Lee del archivo una estructura*/
    }
    numero = memoria.codigo + 1;
    fclose(punteroArchivo);
    return numero;
}

void mostrarTurno(turno *unTurno) {
    printf("Nombre del duenio: %s\n", (*unTurno).nombreDueno);
    printf("Nombre de la mascota: %s\n", (*unTurno).nombreMascota);
    if ((*unTurno).servicio == 1) {
        printf("Servicio: Peinado\n");
    }
    if ((*unTurno).servicio == 2) {
        printf("Servicio: Banio\n");
    }
    if ((*unTurno).servicio == 3) {
        printf("Servicio: Corte de pelo higienico\n");
    }
    printf("Codigo del turno: %i\n", (*unTurno).codigo);
    printf("Fecha del turno: ");
    mostrarFecha(&(*unTurno).fechaTurno);
    printf("\n");
    printf("Hora del turno: ");
    mostrarHora(&(*unTurno).horaTurno);
    printf("\n");
}

fecha leerFecha() {
    fecha unaFecha;
    char dia[MAX], mes[MAX], anio[MAX];
    int bandera = 1;
    do {
        do {
            if (bandera == 0) {
                printf("Los caracteres ingresados son incorrectos, por favor, ingrese digitos\n");
            }
            printf("Dia: ");
            fgets(dia, MAX, stdin);
            dia[strlen(dia) - 1] = '\0';
            bandera = 0;
        } while (controlarCadenaDigitos(dia) == 0);
        unaFecha.dia = atoi(dia);
        bandera = 1;
        do {
            if (bandera == 0) {
                printf("Los caracteres ingresados son incorrectos, por favor, ingrese digitos\n");
            }
            printf("Mes: ");
            fgets(mes, MAX, stdin);
            mes[strlen(mes) - 1] = '\0';
            bandera = 0;
        } while (controlarCadenaDigitos(mes) == 0);
        unaFecha.mes = atoi(mes);
        bandera = 1;
        do {
            if (bandera == 0) {
                printf("Los caracteres ingresados son incorrectos, por favor, ingrese digitos\n");
            }
            printf("Anio: ");
            fgets(anio, MAX, stdin);
            anio[strlen(anio) - 1] = '\0';
            bandera = 0;
        } while (controlarCadenaDigitos(anio) == 0);
        unaFecha.anio = atoi(anio);
        bandera = 1;
        if (controlFecha(unaFecha) == 0) {
            printf("Los valores ingresados son incorrectos, por favor ingrese de nuevo\n");
        }
    } while ((controlFecha(unaFecha)) == 0);
    return unaFecha;
}

void mostrarFecha(fecha *unaFecha) {
    if ((*unaFecha).dia < 10) {
        printf("0%i", (*unaFecha).dia);
    } else {
        printf("%i", (*unaFecha).dia);
    }
    printf("/");
    if ((*unaFecha).mes < 10) {
        printf("0%i", (*unaFecha).mes);
    } else {
        printf("%i", (*unaFecha).mes);
    }
    printf("/");
    if ((*unaFecha).anio < 10) {
        printf("0%i", (*unaFecha).anio);
    } else {
        printf("%i", (*unaFecha).anio);
    }
}

hora leerHora() {
    hora unaHora;
    char hora[MAX], minuto[MAX];
    int bandera = 1;
    do {
        do {
            if (bandera == 0) {
                printf("Los caracteres ingresados son incorrectos, por favor, ingrese digitos\n");
            }
            printf("Hora: ");
            fgets(hora, MAX, stdin);
            hora[strlen(hora) - 1] = '\0';
            bandera = 0;
        } while (controlarCadenaDigitos(hora) == 0);
        unaHora.hora = atoi(hora);
        bandera = 1;
        do {
            if (bandera == 0) {
                printf("Los caracteres ingresados son incorrectos, por favor, ingrese digitos\n");
            }
            printf("Minuto: ");
            fgets(minuto, MAX, stdin);
            minuto[strlen(minuto) - 1] = '\0';
            bandera = 0;
        } while (controlarCadenaDigitos(minuto) == 0);
        unaHora.minuto = atoi(minuto);
        bandera = 1;
        if (controlHora(unaHora) == 0) {
            printf("Los valores ingresados son incorrectos, por favor, ingrese nuevamente\n");
        }
    } while (controlHora(unaHora) == 0);
    return unaHora;
}

void mostrarHora(hora *unaHora) {
    if ((*unaHora).hora < 10) {
        printf("0%i", (*unaHora).hora);
    } else {
        printf("%i", (*unaHora).hora);
    }
    printf(":");
    if ((*unaHora).minuto < 10) {
        printf("0%i", (*unaHora).minuto);
    } else {
        printf("%i", (*unaHora).minuto);
    }
}

int compararFechas(fecha fecha1, fecha fecha2) {
    if (fecha1.anio < fecha2.anio)
        return -1;

    else if (fecha1.anio > fecha2.anio)
        return 1;

    if (fecha1.anio == fecha2.anio) {
        if (fecha1.mes < fecha2.mes)
            return -1;
        else if (fecha1.mes > fecha2.mes)
            return 1;
        else if (fecha1.dia < fecha2.dia)
            return -1;
        else if (fecha1.dia > fecha2.dia)
            return 1;
        else
            return 0;
    }
}

int compararHoras(hora hora1, hora hora2) {
    if (hora1.hora < hora2.hora)
        return -1;

    else if (hora1.hora > hora2.hora)
        return 1;

    if (hora1.hora == hora2.hora) {
        if (hora1.minuto < hora2.minuto)
            return -1;
        else if (hora1.minuto > hora2.minuto)
            return 1;
    }
}

void generarTurno() {
    turno datosTurno;
    printf("===============================================================\n");
    printf("\t         CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("===============================================================\n\n");
    printf("\t            GENERACION DE TURNOS\n");
    printf("_______________________________________________________________\n\n");
    datosTurno = leerTurno();
    limpiarPantalla();
    printf("========================================\n");
    printf("     CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("========================================\n\n");
    printf("\t    TURNO GENERADO\n");
    printf("________________________________________\n\n");
    mostrarTurno(&datosTurno);
    guardarTurno(datosTurno);
}

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */