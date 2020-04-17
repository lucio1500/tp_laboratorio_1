/******************************************************************************


*Programa: Trabajo Practico N°1.
*
*
*Objetivo:

            Hacer una calculadora, con un menu de opciones.

*
*Autor: Lucio Andres Gonzalez.
*Curso,Division: 1C
*


*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "FuncionesMatematicas.h"
#include "MostrarDatos.h"
#include "IngresarValidar.h"

int main()
{
    float fNumeroA;    //Valor del primer operando.
    float fNumeroB;    //Valor del segundo operando.
    float fSuma;       //Resultado de la suma.
    float fResta;      //Resultado de la resta.
    float fDivision;   //Resultado de la division.
    float fProducto;   //Resultado del producto.
    int iEntero;       //Determina si los operandos son enteros.
    int iEnteroA;      //Determina si el primer operando es entero.
    int iEnteroB;      //Determina si el segundo operando es entero.
    int iOpcion;       //Valor de la opcion del menu elegida.
    int iFlagOpcion=0; //Determina por que opciones paso el programa.
    int iFlagA=0;      //Determina si el programa paso por la opcion 1.
    int iFlagB=0;      //Determina si el programa paso por la opcion 2.

do
{

    mostrarMenu(iFlagOpcion,fNumeroA,fNumeroB);

    iOpcion=getOpcion(iOpcion,"Ingrese el numero de la opcion que desea: \n","Incorrecto, Ingrese el numero de la opcion que desea: \n",0,6);

    iFlagOpcion=opcionIngresada(iOpcion,iFlagA,iFlagB,iFlagOpcion);

    switch(iOpcion)
    {
        case 1:
            fNumeroA=getOperando(iOpcion);
            iFlagA=1;
        break;

        case 2:
            fNumeroB=getOperando(iOpcion);
            iFlagB=1;
        break;

        case 3:
            if(iFlagOpcion==3)
            {
                iEntero=getInt(fNumeroA,fNumeroB);
                iEnteroA=primerEntero(fNumeroA);
                iEnteroB=segundoEntero(fNumeroB);
                fSuma=funcionSumar(fNumeroA,fNumeroB);
                fResta=funcionRestar(fNumeroA,fNumeroB);
                fDivision=funcionDividir(fNumeroA,fNumeroB);
                fProducto=funcionMultiplicar(fNumeroA,fNumeroB);
            }
            else
            {
                printf("Debe ingresar el operando que le falta. ");
            }
        break;

        case 4:
            if(iFlagOpcion==4)
            {
                mostrarSuma(fNumeroA,fNumeroB,fSuma);
                mostrarResta(fNumeroA,fNumeroB,fResta);
                mostrarDivision(fNumeroA,fNumeroB,fDivision);
                mostrarProducto(fNumeroA,fNumeroB,fProducto);
                mostrarFactor(fNumeroA,fNumeroB,iEntero,iEnteroA,iEnteroB);
            }
            else
            {
                printf("Debe completar las 3 opciones anteriores antes de mostrar resultados. \n");
            }
        break;
    }

    system("pause");
    system("cls");

}while(iOpcion!=5);



    return 0;
}

