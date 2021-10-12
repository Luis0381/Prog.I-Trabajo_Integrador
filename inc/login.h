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
#ifndef LOGIN_H /* reemplazar por el nombre del archivo correspondiente */
#define LOGIN_H /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */
#include "tdaTurnos.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */
/* Funcion: ingresoDatos
Tarea: Solicita el ingreso de las credenciales de una cuenta
Parámetros que recibe: Ninguno
Retorna: Credenciales de una cuenta*/
void ingresoDatos(datosCuenta *cuenta);
/* Funcion: controlContrasena
Tarea: Controla que la contraseña ingresada cumpla con los requisitos
(Minimo 8 caracteres, solo letras y numeros)
Parámetros que recibe: Ninguno
Retorna: 1, si la contraseña es valida
0, si la contraseña no cumple con los requisitos */
int controlContrasena(char contrasena[MAX]);
/* Funcion: procesarCadena
Tarea: Se encarga de desmenuzar una cadena extraida de un archivo de texto
y devolver las variables.
Parámetros que recibe: Una cadena extraida de un archivo de texto
Retorna: Las credenciales de una cuenta*/
datosCuenta procesarCadena(char cadena[MAX]);
/* Funcion: desencriptar
Tarea: Se encarga de desencriptar la contraseña almacenada en un archivo de texto
Parámetros que recibe: Contraseña encriptada
Retorna: Contraseña desencriptada*/
void desencriptar(char frase[MAX]);
/* Funcion: verificarDatos
Tarea: Compara las credenciales ingresadas por el usuario con las presentes 
en el archivo
Parámetros que recibe: Credenciales ingresadas por el usuario
Retorna: 1, si las credenciales ingresadas coinciden con alguna del archivo
0, si las credenciales ingresadas NO coinciden con alguna del archivo*/
int verificarDatos(datosCuenta cuenta);
/* Funcion: iniciarSesion
Tarea: Gestiona el inicio de sesion, pide las credenciales, las controla, y
en caso de ser validas se continua con la ejecucion del programa. En caso
de que sean incorrectas, cerrara el programa.
Parámetros que recibe: Ninguno
Retorna: Ninguno*/
void iniciarSesion();

/* === Ciere de archivo ======================================================================== */
#endif