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
#ifndef TURNOS_H /* reemplazar por el nombre del archivo correspondiente */
#define TURNOS_H /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */
#include "tdaTurnos.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */
/* Funcion: menuServicios
Tarea: Muestra un menu para elegir el servicio a realizar en un turno
Parametros que recibe: Ninguno
Retorna: Un valor numerico para el servicio elegido*/
int menuServicios();
/* Funcion: leerServicios
Tarea: Se encarga de desmenuzar una cadena extraida del archivo de
servicios y devuelve los valores en forma de variable.
Retorna: Esctructura con los datos de los servicios*/
tipoServicio leerServicios(char cadena[MAX]);
/* Funcion: leerEncabezados
Tarea: Se encarga de desmenuzar la cadena que contiene la primera linea
del archivo de servicios, la cual posee los encabezados
y los devuelve en forma de cadena de caracteres.
Parámetros que recibe: Cadena que contiene la primera linea del archivo servicios.txt
Retorna: Cadenas de caracteres con los encabezados*/
encabezadosServicios leerEncabezados(char cadena[MAX]);
/* Funcion: leerTurno
Tarea: Solicita el ingreso de los datos de un turno
Parámetros que recibe: Ninguno
Retorna: Datos de un turno*/
turno leerTurno();
/* Funcion: mostrarTurno
Tarea: Muestra por pantalla los datos de un turno
Parametros que recibe: Datos de un turno
Retorna:*/
void mostrarTurno(turno *unTurno);
/* Funcion: leerFecha
Tarea: Solicita el ingreso de una fecha
Parametros que recibe: Ninguno
Retorna: Una fecha*/
fecha leerFecha();
/* Funcion: mostrarFecha
Tarea: Muestra por pantalla una fecha
Parametros que recibe: Una fecha
Retorna: */
void mostrarFecha(fecha *unaFecha);
/* Funcion: leerHora
Tarea: Solicita el ingreso de una hora
Parametros que recibe: Ninguno
Retorna: Una hora*/
hora leerHora();
/* Funcion: mostrarHora
Tarea: Muestra por pantalla una hora
Parametros que recibe: Una hora
Retorna: Ninguno*/
void mostrarHora(hora *unaHora);
/* Funcion: compararFechas
Tarea: Compara dos fechas y devuelve un valor indicando si una es anterior, posterior o igual a otra
Parámetros que recibe: Dos fechas
Retorna: 1, si la fecha1 es posterior a la 2
-1, si la fecha1 es anterior a la 2
0 si la fecha1 es igual a la 2*/
int compararFechas(fecha fecha1, fecha fecha2);
/* Funcion: compararHoras
Tarea: Compara dos horas y devuelve un valor indicando si una es anterior, posterior o igual a otra
Parámetros que recibe: Dos horas
Retorna: 1, si la hora1 es posterior a la 2
-1, si la hora1 es anterior a la 2
0 si la hora1 es igual a la 2*/
int compararHoras(hora hora1, hora hora2);
/* Funcion: asignarNumeroTurno
Tarea: Lee el archivo de turnos, busca el ultimo turno generado y genera un codigo
para un nuevo turno, sumandole uno al ultimo.
Parametros que recibe: Nombre del archivo
Retorna: Codigo para un turno*/
int asignarNumeroTurno(char nombre[]);
/* Funcion: generarTurno
Tarea: Gestiona la generacion de turnos, primero pide el ingreso de un turno, lo almacena en 
un archivo binario y luego lo presenta por pantalla
Retorna: Codigo para un turno*/
void generarTurno();

/* === Ciere de archivo ======================================================================== */
#endif