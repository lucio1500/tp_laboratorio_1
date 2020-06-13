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



