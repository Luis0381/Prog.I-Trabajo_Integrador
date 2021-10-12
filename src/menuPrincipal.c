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

#include "menuPrincipal.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "auxiliar.h"
#include "gestionArchivos.h"
#include "turnos.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */
void menuPrincipal() {
    char opcion;
    turno datosTurno;
    do {
        opcion = opcionesMenu();
        opcion = tolower(opcion);
        limpiarBuffer();
        switch (opcion) {
            case 'a':
                limpiarPantalla();
                generarTurno();
                retornarMenu();
                limpiarPantalla();
                break;
            case 'b':
                limpiarPantalla();
                mostrarAgenda();
                retornarMenu();
                limpiarPantalla();
                break;
            case 'c':
                limpiarPantalla();
                consultarUltimaFecha();
                retornarMenu();
                limpiarPantalla();
                break;
            case 'd':
                limpiarPantalla();
                mostrarListado();
                retornarMenu();
                limpiarPantalla();
                break;
            case 'e':
                limpiarPantalla();
                printf("Saliendo del programa...\n");
                break;
            default:
                limpiarPantalla();
                printf("\n\t\t     CENTRO DE ESTETICA DE MASCOTAS\n");
                printf("===========================================================================\n\n");
                printf("    El caracter ingresado no es valido, por favor ingrese de nuevo.\n\n");
                printf("               ");
                retornarMenu();
                limpiarPantalla();
                break;
        }
    } while (opcion != 'e');
}

char opcionesMenu() {
    char opcion;
    printf("\n\t\t     CENTRO DE ESTETICA DE MASCOTAS\n");
    printf("===========================================================================\n\n");
    printf("\t\t\t  Menu Principal\n\n");
    printf("a. Dar de Alta una solicitud de un turno.\n");
    printf("b. Mostrar al usuario la agenda de mascotas a ser atendidas en el dia.\n");
    printf("c. Mostrar la ultima fecha en la que fue atendida una determinada mascota.\n");
    printf("d. Mostrar todos los turnos\n");
    printf("e. Salir del programa\n\n");
    printf("Ingrese una opcion: ");
    opcion = fgetc(stdin);
    limpiarBuffer();
    return opcion;
}

void retornarMenu() {
    printf("Presionar ENTER para regresar al Menu... ");
    fgetc(stdin);
    limpiarBuffer();
}

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */