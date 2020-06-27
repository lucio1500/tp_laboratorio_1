/******************************************************************************


*Programa: Trabajo Practico N°4. Etapa 2.
*
*
*Objetivo:
                • Manejo de punteros.
                • Manejo de linkedList.
                • Manejo de estructuras.
                • Manejo de memoria dinámica.
*
*Autor: Lucio Andres Gonzalez.
*Curso,Division: 1C
*


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "ShowData.h"
#include "Functions.h"
#include "UtnGenericFunctions.h"

int main()
{

    int option;                                 //Value of the chosen menu option.
    int id=2000;                                //It is the initialization of the id of the employees.
    LinkedList* pArrayListEmployee=NULL;        //List of employees.
    LinkedList* pSubListEmployee=NULL;          //Sublist of employees.
    int r=0;                                    //Value of return.
    int flagOption=0;                           //Determine what options the program passed through.
    int flagOption2=0;                           //Determine what options the program passed through.
    int flagLoad=0;                             //Determine what files was load.

    pArrayListEmployee=ll_newLinkedList();
    pSubListEmployee=ll_newLinkedList();

    do
    {
        showMenu();
        option=getInt(option,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",0,16);
        flagOption=controller_option(pArrayListEmployee);
        flagOption2=controller_option(pSubListEmployee);
        switch(option)
        {
            case 1:
                if(flagLoad==0)
                {
                    id=controller_loadFromText("data.csv",pArrayListEmployee);
                    verifyReturn("Carga completada.\n","Error en la carga\n",r);
                    flagLoad=1;
                }
                else
                {
                    printf("Ya cargo un archivo.\n");
                }
            break;
            case 2:
                if(flagLoad==0)
                {
                    id=controller_loadFromBinary("data.bin",pArrayListEmployee);
                    verifyReturn("Carga completada.\n","Error en la carga\n",r);
                    flagLoad=1;
                }
                else
                {
                    printf("Ya cargo un archivo.\n");
                }
            break;
            case 3:
                if(flagOption==0)
                {
                    id=generateId(id);
                    r=controller_addEmployee(pArrayListEmployee,id);
                    verifyReturn("Carga completada.\n","Error en la carga\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar el archivo.\n");
                }
            break;
            case 4:
                if(flagOption==0)
                {
                    r=controller_editEmployee(pArrayListEmployee);
                    verifyReturn("Editado con exito.\n","Error en la edicion\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 5:
                if(flagOption==0)
                {
                    r=controller_removeEmployee(pArrayListEmployee);
                    verifyReturn("Eliminado con exito.\n","Error al eliminar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 6:
                if(flagOption==0)
                {
                    r=controller_ListEmployee(pArrayListEmployee);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 7:
                if(flagOption==0)
                {
                    r=controller_sortEmployee(pArrayListEmployee);
                    verifyReturn("Ordenado con exito.\n","Error al ordenar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 8:
                if(flagOption==0)
                {
                    r=controller_setEmployee(pArrayListEmployee);
                    verifyReturn("Guardado con exito.\n","Error al guardar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 9:
                if(flagOption==0)
                {
                    r=controller_clearListEmployee(pArrayListEmployee,pSubListEmployee);
                     printf("LENsub: %d LEN: %d",ll_len(pSubListEmployee),ll_len(pArrayListEmployee));
                    verifyReturn("Guardado con exito.\n","Error al guardar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 10:
                if(flagOption==0)
                {
                    pSubListEmployee=controller_createSubList(pArrayListEmployee);
                    verifyReturn("Creada con exito.\n","Error al crear\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 11:
                if(flagOption2==0)
                {
                    r=controller_compareList(pArrayListEmployee,pSubListEmployee);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado en la sublista.\n");
                }
            break;
            case 12:
                if(flagOption==0)
                {
                    r=controller_pushEmployee(pArrayListEmployee);
                    verifyReturn("Empleado reubicado con exito.\n","Error al reubicar el empleado\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 13:
                if(flagOption2==0)
                {
                    r=controller_containsEmployee(pArrayListEmployee,pSubListEmployee);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado en la sublista.\n");
                }
            break;
            case 14:
                if(flagOption==0)
                {
                    r=controller_saveAsText("data.csv",pArrayListEmployee);
                    verifyReturn("Guardado con exito.\n","Error al guardar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 15:
                if(flagOption==0)
                {
                    r=controller_saveAsBinary("data.bin",pArrayListEmployee);
                    verifyReturn("Guardado con exito.\n","Error al guardar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
        }

    system("pause");
    system("cls");

    }while(option!=16);

    ll_deleteLinkedList(pSubListEmployee);
    ll_deleteLinkedList(pArrayListEmployee);

    return 0;
}
