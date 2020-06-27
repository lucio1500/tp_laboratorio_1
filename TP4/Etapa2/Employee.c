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


/** \brief Employee Builder.
 *
 * \return Employee* Employee created.
 *
 */
Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*) calloc(sizeof(Employee),1);

    return pEmployee;
}


/** \brief Employee Builder with parameters
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* Employee created.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee = employee_new();

    if(pEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        employee_setId(pEmployee,atoi(idStr));
        employee_setNombre(pEmployee,nombreStr);
        employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        employee_setSueldo(pEmployee,atoi(sueldoStr));
    }

    return pEmployee;

}


/** \brief Delete an employee in memory.
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}


/** \brief Set a name in an Employee.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int Return (1) if Ok.
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int r=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        r=1;
    }

    return r;
}


/** \brief Get a name from an employee.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int Return (1) if Ok.
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int r;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        r=1;
    }

    return r;
}


/** \brief Set a salary in an Employee.
 *
 * \param this Employee*
 * \param sueldo int
 * \return int Return (1) if Ok.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int r;

    if(this!=NULL)
    {
        this->sueldo=sueldo;
        r=1;
    }

    return r;
}


/** \brief Get a salary from an employee
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int Return (1) if Ok.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int r;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        r=1;
    }

    return r;
}


/** \brief Set a ID in an Employee.
 *
 * \param this Employee*
 * \param id int
 * \return int Return (0) if Ok.
 *
 */
int employee_setId(Employee* this,int id)
{
    int r;

    if(this!=NULL)
    {
        this->id=id;
        r=1;
    }

    return r;
}


/** \brief Get a ID from an employee.
 *
 * \param this Employee*
 * \param id int*
 * \return int Return (0) if Ok.
 *
 */
int employee_getId(Employee* this,int* id)
{
    int r;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        r=1;
    }

    return r;
}


/** \brief Set a hours worked in an Employee.
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int Return (1) if Ok.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r;

    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        r=1;
    }

    return r;
}


/** \brief Get a hours worked from an employee.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int Return (1) if Ok.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        r=1;
    }

    return r;
}


/** \brief Compare the names of two employees.
 *
 * \param e1 void*
 * \param e2 void*
 * \return int Return the value of function strcmp between name 1 and name 2.
 *
 */
int employee_CompareByName(void* e1, void* e2)
{
    int r;
    Employee* pEmployee1=(Employee*) e1;
    Employee* pEmployee2=(Employee*) e2;
    char nombre1[128];
    char nombre2[128];

    if(pEmployee1!=NULL && pEmployee2!=NULL)
    {
        employee_getNombre(pEmployee1,nombre1);
        employee_getNombre(pEmployee2,nombre2);
        r=strcmp(nombre1, nombre2);
    }

    return r;
}


/** \brief Compare the IDs of two employees.
 *
 * \param e1 void*
 * \param e2 void*
 * \return int Return (1) if ID 1 is greater than ID 2 else return (-1).
 *
 */
int employee_CompareById(void* e1, void* e2)
{
    int r=0;
    int id1;
    int id2;
    Employee* pEmployee1=(Employee*) e1;
    Employee* pEmployee2=(Employee*) e2;

    if(pEmployee1!=NULL && pEmployee2!=NULL)
    {
    employee_getId(pEmployee1,&id1);
    employee_getId(pEmployee2,&id2);
        if(id1 > id2)
        {
            r=1;
        }
        else if(id1 < id2)
        {
            r=-1;
        }
    }

    return r;
}


/** \brief Compare the hours worked of two employees.
 *
 * \param e1 void*
 * \param e2 void*
 * \return int Return (1) if hours worked 1 is greater or equal than hours worked 2 else return (-1).
 *
 */
int employee_CompareByHorasTrabajadas(void* e1, void* e2)
{
    int r=0;
    int horas1;
    int horas2;
    Employee* pEmployee1=(Employee*) e1;
    Employee* pEmployee2=(Employee*) e2;

    if(pEmployee1!=NULL && pEmployee2!=NULL)
    {
    employee_getHorasTrabajadas(pEmployee1,&horas1);
    employee_getHorasTrabajadas(pEmployee2,&horas2);
        if(horas1 > horas2)
        {
            r=1;
        }
        else if(horas1 < horas2)
        {
            r=-1;
        }
    }

    return r;
}


/** \brief Compare the salaries of two employees.
 *
 * \param e1 void*
 * \param e2 void*
 * \return int Return (1) if salary 1 is greater or equal than salary 2 else return (-1).
 *
 */
int employee_CompareBySalary(void* e1, void* e2)
{
    int r=0;
    int sueldo1;
    int sueldo2;
    Employee* pEmployee1=(Employee*) e1;
    Employee* pEmployee2=(Employee*) e2;

    if(pEmployee1!=NULL && pEmployee2!=NULL)
    {
    employee_getSueldo(pEmployee1,&sueldo1);
    employee_getSueldo(pEmployee2,&sueldo2);
        if(sueldo1 > sueldo2)
        {
            r=1;
        }
        else if(sueldo1 < sueldo2)
        {
            r=-1;
        }
    }

    return r;
}
