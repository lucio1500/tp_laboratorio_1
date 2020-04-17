#include <stdio.h>
#include <stdlib.h>
#include "IngresarValidar.h"
#include "MostrarDatos.h"
#include "FuncionesMatematicas.h"


/** \brief Esta funcion permite la validacion de la opcion ingresada.
 *
 * \param opcion int Opcion ingresada.
 * \param mensaje[] char Mensaje de ingreso.
 * \param error[] char Mensaje de error.
 * \param min int Minimo valor del rango para validar.
 * \param max int Maximo valor del rango para validar.
 * \return int Opcion validada.
 *
 */
int getOpcion(int opcion, char mensaje[], char error[], int min, int max)
{
    printf("%s",mensaje);
    scanf("%d",&opcion);

    while(!(opcion>min&&opcion<max))
    {
        printf("%s",error);
        scanf("%d",&opcion);
    }

    return opcion;
}


/** \brief Esta funcion permite tomar registro de la opcion que fue ingresada.
 *
 * \param opcion int Opcion ingresada.
 * \param flagA int Bandera de la opcion uno.
 * \param flagB int Bandera de la opcion dos.
 * \param flag int Bandera de la opcion ingresada.
 * \return int El valor de la opcion ingresada.
 *
 */
int opcionIngresada(int opcion,int flagA,int flagB,int flag)
{

    if (opcion==1)
    {
        flag=1;
    }
    else if(opcion==2)
    {
        flag=2;
    }
    else if(flagA==1&&flagB==1&&opcion==3)          //Solo si ingreso los operandos podra ingresar.
    {
        flag=3;
    }
    else if(flagA==1&&flagB==1&&flag==3&&opcion==4) //Solo si ingreso las primeras tres opciones podra ingresar.
    {
        flag=4;
    }

    return flag;
}


/** \brief Permite el ingreso del operando.
 *
 * \param opcion int Opcion ingresada.
 * \return float El valor del operando.
 *
 */
float getOperando(int opcion)
{
    float numero;

    if(opcion==1)
    {
        printf("1. Ingresar 1er operando (A=x): ");
        scanf("%f",&numero);
    }
    else
    {
        printf("2. Ingresar 2do operando (B=y): ");
        scanf("%f",&numero);
    }

    return numero;
}


/** \brief Esta funcion se encarga de establecer si los operandos ingresados son enteros o no.
 *
 * \param numeroA float Primer operando.
 * \param numeroB float Segundo operando.
 * \return int Valor de verdad.
 *
 */
int getInt(float numeroA, float numeroB)
{
    int siEs=0;
    int validarA;
    int validarB;

    validarA=numeroA;
    validarB=numeroB;

    if (validarA==numeroA && validarB==numeroB&&numeroA>0&&numeroB>0)
    {
        siEs=1;
    }

    return siEs;
}


/** \brief Esta funcion se encarga de establecer si el primer operando ingresado es entero o no.
 *
 * \param numeroA float Primer operando.
 * \return int Valor de verdad.
 *
 */
int primerEntero(float numeroA)
{
    int siEsA=0;
    int validarA;

    validarA=numeroA;

    if (validarA==numeroA&&numeroA>0)
    {
        siEsA=1;
    }

    return siEsA;
}


/** \brief Esta funcion se encarga de establecer si el segundo operando ingresado es entero o no.
 *
 * \param numeroB float Segundo operando.
 * \return int Valor de verdad.
 *
 */
int segundoEntero(float numeroB)
{
    int siEsB=0;
    int validarB;

    validarB=numeroB;

    if (validarB==numeroB&&numeroB>0)
    {
        siEsB=1;
    }

    return siEsB;
}
