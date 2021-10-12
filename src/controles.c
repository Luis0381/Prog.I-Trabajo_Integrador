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

#include "controles.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */

int controlFecha(fecha unaFecha) {
    int bandera = 1;
    if (unaFecha.dia <= 0 || unaFecha.dia > 31) {
        bandera = 0;
    }
    if (unaFecha.mes <= 0 || unaFecha.mes > 12) {
        bandera = 0;
    }
    if (unaFecha.anio < 2021) {
        bandera = 0;
    }
    return bandera;
}

int controlHora(hora unaHora) {
    int bandera = 1;
    if (unaHora.hora < 0 || unaHora.hora > 23) {
        bandera = 0;
    }
    if (unaHora.minuto < 0 || unaHora.minuto > 59) {
        bandera = 0;
    }
    return bandera;
}

int controlarCadenaDigitos(char cadena[MAX]) {
    int bandera = 1;
    for (int i = 0; i < strlen(cadena); i++) {
        if (isdigit(cadena[i]) == 0) {
            bandera = 0;
        }
    }
    return bandera;
}

int controlarCadenaCaracteres(char cadena[MAX]) {
    int bandera = 1;
    for (int i = 0; i < strlen(cadena); i++) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || cadena[i] == ' ' || cadena[i] == '\n') {
            continue;
        } else {
            bandera = 0;
        }
    }
    return bandera;
}

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */