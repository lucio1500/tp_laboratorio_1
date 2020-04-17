#include <stdio.h>
#include <stdlib.h>
#include "IngresarValidar.h"
#include "MostrarDatos.h"
#include "FuncionesMatematicas.h"


/** \brief Esta funcion se encarga de realizar la suma entre los operandos.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \return float El resultado de la suma entre los operandos.
 *
 */
float funcionSumar(float numeroA,float numeroB)
{
    float resultadoSuma;

    resultadoSuma=numeroA+numeroB;

    return resultadoSuma;
}


/** \brief Esta funcion se encarga de realizar la resta entre los operandos (al primero le resta el segundo).
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \return float El resultado de la resta entre los operandos.
 *
 */
float funcionRestar(float numeroA,float numeroB)
{
    float resultadoResta;

    resultadoResta=numeroA-numeroB;

    return resultadoResta;
}

/** \brief Esta funcion se encarga de realizar la division entre los operandos (al primero lo divide por el segundo).
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \return float El resultado de la division entre los operandos.
 *
 */
float funcionDividir(float numeroA,float numeroB)
{
    float resultadoDivision;

    if(numeroA!=0&&numeroB!=0)
    {
        resultadoDivision=numeroA/numeroB;
    }
    else
    {
        resultadoDivision=0;
    }

    return resultadoDivision;
}


/** \brief Esta funcion se encarga de realizar la multiplicacion entre los operandos.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \return float El resultado del producto entre los operandos.
 *
 */
float funcionMultiplicar(float numeroA,float numeroB)
{
    float resultadoMultipliacion;

    resultadoMultipliacion=numeroA*numeroB;

    return resultadoMultipliacion;
}

/** \brief Esta funcion se encarga de realizar el factor de los operandos.
 *
 * \param numero float El operando a factorizar.
 * \return int El operando factorizado.
 *
 */
int funcionFactorear(float numero)
{
    int i;
    int numFactoriado=1;

    for (i=1;i<=numero;i++)
    {
        numFactoriado=numFactoriado*i;
    }

    return numFactoriado;
}

