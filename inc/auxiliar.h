/* Copyright 2021, CÃ¡tedra de InformÃ¡tica y ProgramaciÃ³n I
 * Departamento de Electricidad, ElectrÃ³nica y ComputaciÃ³n
 * Facultad de Ciencias Exactas y TecnologÃ­a 
 * Universidad Nacional de Tucuman
 * Copyright 2021, Mariana SÃ¡nchez <msanchez@herrera.unt.edu.ar>, Enzo A. SÃ©mola <esemola@herrera.unt.edu.ar>
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

/* === Ifndef: para prevenir las inclusiones duplicadas ======================================================== */
#ifndef AUXILIAR_H /* reemplazar por el nombre del archivo correspondiente */
#define AUXILIAR_H /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */
#include "tdaTurnos.h"

/* === Definicion y Macros ===================================================================== */

#ifdef _WIN32
#define limpiarPantalla() system("cls")
#else
#define limpiarPantalla() system("clear")
#endif

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */

/* Funcion: limpiarBuffer
Tarea: Limpia el buffer del teclado
Parámetros que recibe: Ninguno
Retorna: Ninguno*/
void limpiarBuffer();
/* Funcion: presioneContinuar
Tarea: Muestra un mensaje por pantalla solicitando que se presione enter para continuar con la 
ejecucion del programa
Parámetros que recibe: Ninguno
Retorna: Ninguno*/
void presioneContinuar();
/* Funcion: convertirPrimeraMayuscula
Tarea: Convierte la primera letra de cada palabra de una string a mayuscula
Parámetros que recibe: Cadena de caracteres
Retorna: Cadena de caracteres con la primera letra de cada palabra en mayuscula*/
void convertirPrimeraMayuscula(char cadena[MAX]);

/* === Ciere de archivo ======================================================================== */
#endif