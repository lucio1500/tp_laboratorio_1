/******************************************************************************


*Programa: Trabajo Practico N°2.
*
*
*Objetivo:

             Sistema para administrar una nómina de empleados de una empresa.

*
*Autor: Lucio Andres Gonzalez.
*Curso,Division: 1C
*


*******************************************************************************/


#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ArrayEmployees.h"
#include "ShowData.h"
#include "Inputs.h"
#include"Validations.h"


int main()
{
    int option;                                 //Value of the chosen menu option.
    int r;                                      //Saves the return values ​​of the functions.
    int index;                                  //Stores the index of the first empty position in an array.
    int id=1000;                                //It is the initialization of the id of the employees.
    int flagOption=0;                           //Determine what options the program passed through.
    int counterInc=0;                           //Count the number of employees loaded.
    float accumSalary=0;                        //Accumulate charged wages.
    int counterSalaryHigh=0;                    //Count the number of employees that exceed the average salary.
    float average=0;                              //It is the average of wages.
    Employee arrayEmployees[ELEMENTS];          //List of employees.

    initEmployees(arrayEmployees, ELEMENTS);

    do
    {
        showMenu();
        option=getInt(option,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",0,6);

        switch(option)
        {
            case 1:
            index=searchIsEmpty(arrayEmployees,ELEMENTS);
            if(index!=-1)
            {
                id=generateId(id);
                r=createAnEmployee(arrayEmployees,ELEMENTS,accumSalary,counterInc,index,id);
                    if(r==-1)
                    {
                    printf("Error en la carga.\n");
                    }
                    else if(r==0)
                    {
                    flagOption++;
                    counterInc++;
                    printf("Carga Completada.\n");
                    }
            }
            break;
            case 2:
                if(flagOption>0)
                {
                r=verifyModifyEmployees(arrayEmployees,ELEMENTS,id);
                    if(r==-1)
                    {
                    printf("Error en la modificacion.\n");
                    }
                    else if(r==0)
                    {
                    printf("Modificacion Completa.\n");
                    }
                }
                else
                {
                printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n ");
                }
            break;
            case 3:
                if(flagOption>0)
                {
                r=verifyRemoveEmployees(arrayEmployees,ELEMENTS,id);
                    if(r==-1)
                    {
                    printf("Error en la baja.\n");
                    }
                    else if(r==0)
                    {
                    printf("Eliminacion Completa.\n");
                    flagOption--;
                    counterInc--;
                    }
                }
                else
                {
                printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n ");
                }
            break;
            case 4:
                if(flagOption>0)
                {
                showEmployees(arrayEmployees,ELEMENTS,average,accumSalary,counterSalaryHigh,counterInc);
                }
                else
                {
                printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n ");
                }
            break;
        }

    system("pause");
    system("cls");

    }while(option!=5);

}
