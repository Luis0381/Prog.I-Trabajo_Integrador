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

/* === Ifndef: para prevenir las inclusiones duplicadas ======================================================== */
#ifndef GESTIONARCHIVOS_H /* reemplazar por el nombre del archivo correspondiente */
#define GESTIONARCHIVOS_H /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */
#include "tdaTurnos.h"

/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */

/* Funcion: controlArchivo
Tarea: Controla la existencia de un archivo y en caso que este no exista lo crea.
Parametros que recibe: Nombre del archivo
Retorna: Ninguno*/
void controlArchivo(char nombre[]);
/* Funcion: cargarArchivo
Tarea: Se ejecuta al inicio del programa, controla la existencia de todos los archivos que
seran utilizados en la ejecucion y en caso que no existan, los crea. Presentando el paso a paso por pantalla.
Parametros que recibe: Ninguno
Retorna: Ninguno*/
void cargarArchivos();
/* Funcion: guardarTurno
Tarea: Se encarga de imprimir en un archivo binario con extension ".dat" los datos
ingresados para un turno
Parametros que recibe: Datos de un turno
Retorna: Ninguno*/
void guardarTurno(turno datosTurnos);
/* Funcion: mostrarAgenda
Tarea: Muestra por pantalla los turnos de un dia especifico ordenados de manera ascendente.
Parametros que recibe: Ninguno
Retorna: Ninguno*/
void mostrarAgenda();
/* Funcion: consultarUltimaFecha
Tarea: Muestra por pantalla la ultima fecha en la cual una mascota fue atendida por el centro de estetica.
Ademas muestra la ficha de aquel turno.
Parametros que recibe: Ninguno
Retorna: Ninguno*/
void consultarUltimaFecha();
/* Funcion: mostrarListado
Tarea: Muestra por pantalla todos los turnos que se hayan creado alguna vez.
Parametros que recibe: Ninguno
Retorna: Ninguno*/
void mostrarListado();

/* === Ciere de archivo ======================================================================== */
#endif