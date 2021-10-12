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

#include "login.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliar.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ============================================ ========= */

/* === Función principal ===================================================== */

/* === Definiciones de funciones internas ====================================================== */

int controlContrasena(char contrasena[MAX]) {
    int banderaControl = 1;

    if (strlen(contrasena) < 8 || strlen(contrasena) > 15) {
        banderaControl = 0;
    }

    for (int i = 0; i < strlen(contrasena); i++) {
        if (isalnum(contrasena[i]) == 0) {
            banderaControl = 0;
        }
    }
    return banderaControl;
}

void ingresoDatos(datosCuenta *cuenta) {
    int banderaContrasena = 1;
    printf("\tIngrese su usuario: ");
    scanf("%s", (*cuenta).usuario);
    setbuf(stdin, NULL);
    do {
        if (banderaContrasena == 0) {
            printf("\n--> La contrasena no cumple con los requisitos (8-15 caracteres, solo letras y numeros) <--\n\n");
        }
        printf("\tIngrese su contrasena: ");
        scanf("%s", (*cuenta).contrasena);
        setbuf(stdin, NULL);
        if (controlContrasena((*cuenta).contrasena) == 0) {
            banderaContrasena = 0;
        }
    } while (controlContrasena((*cuenta).contrasena) == 0);
}

void desencriptar(char frase[MAX]) {
    int i = 0, numero = 5;
    while (frase[i] != '\0') {
        if (frase[i] == '$')
            frase[i] = 'a';
        else if (frase[i] == '-')
            frase[i] = 'e';
        else if (frase[i] == '&')
            frase[i] = 'i';
        else if (frase[i] == '#')
            frase[i] = 'o';
        else if (frase[i] == '!')
            frase[i] = 'u';
        else
            frase[i] = frase[i] - numero;
        i++;
    }
}

datosCuenta procesarCadena(char cadena[MAX]) {
    datosCuenta comparacion;

    char *punteroReferencia;

    punteroReferencia = strtok(cadena, ":");
    strcpy(comparacion.usuario, punteroReferencia);
    punteroReferencia = strtok(NULL, "\n");
    strcpy(comparacion.contrasena, punteroReferencia);
    desencriptar(comparacion.contrasena);
    return comparacion;
}

int verificarDatos(datosCuenta cuenta) {
    char nombreArchivo[] = "usuarios.txt";
    int banderaSesion = 0;
    char cadena[MAX];
    datosCuenta comparacion;

    FILE *puntArchivo;
    puntArchivo = fopen(nombreArchivo, "r");

    while (feof(puntArchivo) == 0) {
        if (fgets(cadena, MAX, puntArchivo) != NULL) {
            comparacion = procesarCadena(cadena);
            if (strcmp(cuenta.usuario, comparacion.usuario) == 0) {
                if (strcmp(cuenta.contrasena, comparacion.contrasena) == 0) {
                    banderaSesion = 1;
                }
            }
        }
    }

    if (banderaSesion == 1) {
        printf("\n\t     --> ACCESO CONCEDIDO <--\n\n");
    } else {
        printf("\n\t      --> ACCESO DENEGADO <--\n");
        printf("\n\t      Se cerrara el programa...\n\n");
        printf("         ");
        presioneContinuar();
        exit(0);
    }
}

void iniciarSesion() {
    datosCuenta cuenta;
    printf("========================================================\n");
    printf("\t\tINICIO DE SESION\n");
    printf("========================================================\n\n");
    ingresoDatos(&cuenta);
    verificarDatos(cuenta);
    printf("         ");
    presioneContinuar();
    limpiarPantalla();
}

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */
