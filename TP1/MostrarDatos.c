#include <stdio.h>
#include <stdlib.h>
#include "MostrarDatos.h"
#include "IngresarValidar.h"
#include "FuncionesMatematicas.h"


/** \brief Esta funcion se encarga de mostrar el menu de opciones del programa. Los elementos del menu varian segun las opciones que ya fueron ingresadas.
 *
 * \param flagOpcion int Opcion ingresada.
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \return void
 *
 */
void mostrarMenu(int flagOpcion,float numeroA,float numeroB)
{
    if(flagOpcion==0 || flagOpcion==4)
    {
        printf(" 1. Ingresar 1er operando (A=x)\n");
        printf(" 2. Ingresar 2do operando (B=y)\n");
        printf(" 3. Calcular todas las operaciones\n");
        printf("  a) Calcular la suma (A+B)\n");
        printf("  b) Calcular la resta (A-B)\n");
        printf("  c) Calcular la division (A/B)\n");
        printf("  d) Calcular la multiplicacion (A*B)\n");
        printf("  e) Calcular el factorial (A!)\n");
        printf(" 4. Informar resultados\n");
        printf(" 5. Salir\n");
    }
    else if(flagOpcion==1)
    {
        printf(" 1. Ingresar 1er operando (A=%g)\n",numeroA);
        printf(" 2. Ingresar 2do operando (B=y)\n");
        printf(" 3. Calcular todas las operaciones\n");
        printf("  a) Calcular la suma (%g + B)\n",numeroA);
        printf("  b) Calcular la resta (%g - B)\n",numeroA);
        printf("  c) Calcular la division (%g / B)\n",numeroA);
        printf("  d) Calcular la multiplicacion (%g * B)\n",numeroA);
        printf("  e) Calcular el factorial (%g!)(B!)\n",numeroA);
        printf(" 4. Informar resultados\n");
        printf(" 5. Salir\n");
    }
    else if(flagOpcion==2)
    {
        printf(" 1. Ingresar 1er operando (A=x)\n");
        printf(" 2. Ingresar 2do operando (B=%g)\n",numeroB);
        printf(" 3. Calcular todas las operaciones\n");
        printf("  a) Calcular la suma (A + %g)\n",numeroB);
        printf("  b) Calcular la resta (A - %g)\n",numeroB);
        printf("  c) Calcular la division (A / %g)\n",numeroB);
        printf("  d) Calcular la multiplicacion (A * %g)\n",numeroB);
        printf("  e) Calcular el factorial (A!)(%g!)\n",numeroB);
        printf(" 4. Informar resultados\n");
        printf(" 5. Salir\n");
    }
    else if(flagOpcion==3)
    {
        printf(" 1. Ingresar 1er operando (A=%g)\n",numeroA);
        printf(" 2. Ingresar 2do operando (B=%g)\n",numeroB);
        printf(" 3. Calcular todas las operaciones\n");
        printf("  a) Calcular la suma (%g + %g)\n",numeroA,numeroB);
        printf("  b) Calcular la resta (%g - %g)\n",numeroA,numeroB);
        printf("  c) Calcular la division (%g / %g)\n",numeroA,numeroB);
        printf("  d) Calcular la multiplicacion (%g * %g)\n",numeroA,numeroB);
        printf("  e) Calcular el factorial (%g!) (%g!)\n",numeroA,numeroB);
        printf(" 4. Informar resultados\n");
        printf(" 5. Salir\n");
    }

}


/** \brief Esta funcion se encarga de mostrar el resultado de la suma entre los operandos.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \param suma float Resultado de la suma.
 * \return void
 *
 */
void mostrarSuma(float numeroA,float numeroB,float suma)
{
    printf(" A) El resultado de %g + %g es: %g \n",numeroA,numeroB,suma);
}


/** \brief Esta funcion se encarga de mostrar el resultado de la resta entre los operandos.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \param resta float Resultado de la resta.
 * \return void
 *
 */
void mostrarResta(float numeroA,float numeroB,float resta)
{
    printf(" B) El resultado de %g - %g es: %g\n",numeroA,numeroB,resta);
}


/** \brief Esta funcion se encarga de mostrar el resultado de la division entre los operandos.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \param division float Resultado de la division.
 * \return void
 *
 */
void mostrarDivision(float numeroA,float numeroB,float division)
{
    if(division==0)
    {
        printf(" C) No es posible dividir por cero\n");
    }
    else
    {
        printf(" C) El resultado de %g / %g es: %g\n",numeroA,numeroB,division);
    }

}


/** \brief Esta funcion se encarga de mostrar el resultado de la multiplicacion entre los operandos.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \param producto float Resultado de la multiplicacion.
 * \return void
 *
 */
void mostrarProducto(float numeroA,float numeroB,float producto)
{
    printf(" D) El resultado de %g * %g es: %g \n",numeroA,numeroB,producto);
}


/** \brief Muestra el factor dependiendo de si es entero o no.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \param siEs int Si los dos operandos son enteros.
 * \param siEsA int Si el primer operando es entero.
 * \param siEsB int Si el segundo operando es entero.
 * \return void
 *
 */
void mostrarFactor(float numeroA,float numeroB,int siEs, int siEsA,int siEsB)
{
    int factorA=0;
    int factorB=0;

    if(siEs==1)        //Si los dos operandos son enteros.
    {
        factorA=funcionFactorear(numeroA);
        factorB=funcionFactorear(numeroB);
        printf(" E) El factorial de %g es: %d y El factorial de %g es: %d\n",numeroA,factorA,numeroB,factorB);
    }
    else if(siEsA==1)  //Si solo el primer operando es entero,
    {
        factorA=funcionFactorear(numeroA);
        printf(" E) El factorial de %g es: %d y El factorial de %g no es posible\n",numeroA,factorA,numeroB);
    }
    else if(siEsB==1)  //Si solo el segundo operando es entero
    {
        factorB=funcionFactorear(numeroB);
        printf(" E) El factorial de %g no es posible y El factorial de %g es: %d\n ",numeroA,numeroB,factorB);
    }
    else
    {
        printf(" E) Solo se pueden factorear numeros naturales. \n ");
    }


}
