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

/** \brief Load employee data from data.csv file (text mode),
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Return the id of last Employee.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "r");
            if(pFile!=NULL)
            {
                r=parser_EmployeeFromText(pFile,pArrayListEmployee);
            }
        fclose(pFile);
    }

    return r;

}


/** \brief Load employee data from data.bin file (binary mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Return the id of last Employee.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "rb");
            if(pFile!=NULL)
            {
                r=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            }
        fclose(pFile);
    }

    return r;
}


/** \brief Employee registration.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int id)
{
    Employee* pEmployee=employee_new();
    int r=-1;
    char nombre[128];
    int horasTrabajadas=0;
    int sueldo=0;

    getStringOfLetters(nombre,"Ingrese su nombre: ","Error, ingrese un nombre valido: ");
    horasTrabajadas=getInt(horasTrabajadas,"Ingrese horas: ","Error, horas invalidas: ",0,3000);
    sueldo=getInt(sueldo,"Ingrese sueldo: ","Error, ingrese un sueldo valido: ",0,99999999);

    employee_setId(pEmployee,id);
    employee_setNombre(pEmployee,nombre);
    employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
    employee_setSueldo(pEmployee,sueldo);

    if(pEmployee!=NULL)
    {
        r=ll_add(pArrayListEmployee,pEmployee);
    }

    return r;
}


/** \brief List employees.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int i;

    printf("\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");
    len=ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        listEmployee(pArrayListEmployee,i);
    }

    printf("\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");

    return 0;
}


/** \brief Modify employee data.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;
    int option;

    system("cls");

    do
    {
    showMenuVerify();
    option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
        r=controller_ListEmployee(pArrayListEmployee);
        r=editEmployee(pArrayListEmployee);
            if(r==-1||r==0)
            {
            break;
            }
        }
     }while(option!=2);

     return r;
}


/** \brief Delete employee.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int option=0;
    int r=-1;

    system("cls");

    do
    {
    showMenuVerify();
    option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
            r=controller_ListEmployee(pArrayListEmployee);
            r=removeEmployee(pArrayListEmployee);
            break;
        }
     }while(option!=2);

     return r;
}


/** \brief Sort Employees.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int r=-1;

    LinkedList* cloneArrayListEmployee;

    cloneArrayListEmployee=ll_clone(pArrayListEmployee);

    r=sortEmployee(cloneArrayListEmployee);

    ll_deleteLinkedList(cloneArrayListEmployee);

    return r;
}


/** \brief Save employee data in data.csv file (text mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "w");
            if(pFile!=NULL)
            {
                r=parser_SaveEmployeeFromText(pFile,pArrayListEmployee);
            }
        fclose(pFile);
    }

    return r;
}


/** \brief Save employee data in data.bin file (binary mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "wb");
            if(pFile!=NULL)
            {
                r=parser_SaveEmployeeFromBinary(pFile,pArrayListEmployee);
            }
        fclose(pFile);
    }

    return r;
}


/** \brief Replace one employee with another.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_setEmployee(LinkedList* pArrayListEmployee)
{
    int r;
    Employee* pEmployee;
    int index;
    int indexId;

    indexId=getId("Ingrese la ID del empleado que desea mover: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    pEmployee=ll_pop(pArrayListEmployee,indexId);
    index=getId("Ingrese la ID del empleado que desea reemplazar: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    r=ll_set(pArrayListEmployee,index,pEmployee);

    return r;
}


/** \brief Remove all employees of a list.
 *
 * \param pArrayListEmployee LinkedList*
 * \param pSubListEmployee LinkedList*
 * \return int
 *
 */
int controller_clearListEmployee(LinkedList* pArrayListEmployee,LinkedList* pSubListEmployee)
{
    int r;

    r=ll_clear(pArrayListEmployee);

    return r;
}


/** \brief Create a sublist.
 *
 * \param pArrayListEmployee LinkedList*
 * \return LinkedList*
 *
 */
LinkedList* controller_createSubList(LinkedList* pArrayListEmployee)
{
    LinkedList* pSubListEmployee;
    int from;
    int to;

    controller_ListEmployee(pArrayListEmployee);
    from=getId("Ingrese la ID del empleado DESDE el cual quiere crear la sublista: ","Error, ingrese un inicio valido: ",pArrayListEmployee);
    to=getId("Ingrese la ID del empleado HASTA el cual quiere crear la sublista: ","Error, ingrese un final valido: ",pArrayListEmployee);
    pSubListEmployee=ll_subList(pArrayListEmployee,from,to);
    controller_ListEmployee(pSubListEmployee);

    return pSubListEmployee;
}


/** \brief Check if all employees from the sublist is in the list.
 *
 * \param pArrayListEmployee LinkedList*
 * \param pArrayListEmployee2 LinkedList*
 * \return int
 *
 */
int controller_compareList(LinkedList* pArrayListEmployee,LinkedList* pArrayListEmployee2)
{
    int r=-1;
    if(ll_isEmpty(pArrayListEmployee)!=-1 && ll_isEmpty(pArrayListEmployee2)!=-1)
    {
        printf("LENsub: %d LEN: %d\n",ll_len(pArrayListEmployee2),ll_len(pArrayListEmployee));
        r=ll_containsAll(pArrayListEmployee,pArrayListEmployee2);
        switch(r)
        {
            case -1:
                printf("Error\n");
            break;
            case 0:
                printf("Todos los empleados de la sublista NO estan contenidos en la lista.\n");
            break;
            case 1:
                printf("Todos los empleados de la sublista SI estan contenidos en la lista\n");
            break;
        }
    }
    return r;
}


/** \brief Employee changes places.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_pushEmployee(LinkedList* pArrayListEmployee)
{
    int r;
    int index;
    int indexId;
    Employee* pEmployee;

    controller_ListEmployee(pArrayListEmployee);
    indexId=getId("Ingrese la ID del empleado que desea mover: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    pEmployee=ll_pop(pArrayListEmployee,indexId);
    index=getId("Ingrese la ID del empleado donde desea reubicar: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    r=ll_push(pArrayListEmployee,index,pEmployee);

    return r;
}


/** \brief Check if an employee from the sublist is in the list.
 *
 * \param pArrayListEmployee LinkedList*
 * \param pSubListEmployee LinkedList*
 * \return int
 *
 */
int controller_containsEmployee(LinkedList* pArrayListEmployee,LinkedList* pSubListEmployee)
{
    int r;
    int index;
    Employee* pEmployee;

    controller_ListEmployee(pSubListEmployee);
    index=getId("Ingrese la ID del empleado que desea verificar: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    pEmployee=ll_get(pArrayListEmployee,index);
    r=ll_contains(pSubListEmployee,pEmployee);

    switch(r)
    {
        case -1:
            printf("Error\n");
        break;
        case 0:
            printf("El empleado de la sublista NO esta dentro de la lista.\n");
        break;
        case 1:
            printf("El empleado de la sublista SI esta dentro de la lista\n");
        break;
    }

    return r;
}
