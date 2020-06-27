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


/** \brief Read the employee data from the data.csv file (text mode).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Return the id of last Employee.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int auxId;
    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    Employee* pEmployee;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        pEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee,pEmployee);
        employee_getId(pEmployee,&auxId);
    }

    return auxId;
}


/** \brief Read the employee data from the data.bin file (binary mode).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Return the id of last Employee.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int i=0;
    int auxId;

    while(!feof(pFile))
    {
        pEmployee=employee_new();

            if(fread(pEmployee,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,pEmployee);
            }

        pEmployee=ll_get(pArrayListEmployee,i);
        employee_getId(pEmployee,&auxId);
        i++;
    }

    return auxId;
}


/** \brief Write the employee data in the data.csv file (text mode).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int parser_SaveEmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r=1;
    int i;
    int len;
    Employee* pEmployee;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    len=ll_len(pArrayListEmployee);

    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

    for(i=0;i<len;i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        employee_getId(pEmployee,&id);
        employee_getNombre(pEmployee,nombre);
        employee_getHorasTrabajadas(pEmployee,&horasTrabajadas);
        employee_getSueldo(pEmployee,&sueldo);
        fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        r=0;
    }

    return r;
}


/** \brief Write the employee data in the data.bin file (binary mode).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int parser_SaveEmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r=1;
    int i;
    int len;
    Employee* pEmployee;

    len=ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        fwrite(pEmployee, sizeof(Employee),1,pFile);
        r=0;
    }

    return r;
}
