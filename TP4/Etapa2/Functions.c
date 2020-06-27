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


/** \brief find an Employee by Id en returns the index position in array.
*
* \param
* \param id int
* \param pArrayListEmployee LinkedList*
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(int id,LinkedList* pArrayListEmployee)
{
    int i;
    int auxId = -1;
    int len;
    Employee* auxEmployee;

    len=ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        auxEmployee=ll_get(pArrayListEmployee,i);
        employee_getId(auxEmployee,&auxId);

            if(auxId==id)
            {
                auxId=id;
                break;
            }
    }

    return i;
}


/** \brief Allows the entry and validation of an id.
 *
 * \param
 * \param message[] char
 * \param [] char messageError
 * \param pArrayListEmployee LinkedList*
 * \return int Returns the index of a validated id.
 *
 */
int getId(char message[], char messageError [],LinkedList* pArrayListEmployee)
{
    int indexId;
    int id;
    printf("%s ",message);
    scanf("%d",&id);

    indexId=findEmployeeById(id,pArrayListEmployee);

     while(indexId == -1)
    {
        printf("%s", messageError);
        scanf("%d", &id);
        indexId=findEmployeeById(id,pArrayListEmployee);
    }

    return indexId;
}


/** \brief List an employee.
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int Return (0) if Ok.
 *
 */
int listEmployee(LinkedList* pArrayListEmployee,int index)
{
    Employee* auxEmployee;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    auxEmployee=ll_get(pArrayListEmployee,index);
    employee_getId(auxEmployee,&id);
    employee_getNombre(auxEmployee,nombre);
    employee_getHorasTrabajadas(auxEmployee,&horasTrabajadas);
    employee_getSueldo(auxEmployee,&sueldo);

    printf("%d\t%15s\t\t\t%d\t\t%d\n",id,nombre,horasTrabajadas,sueldo);

    return 0;
}


/** \brief Through the ID, it allows to modify: or name or hours worked or salary.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int editEmployee(LinkedList* pArrayListEmployee)
{
    int flag=-1;
    int option;
    Employee* pEmployee;
    int indexId;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    indexId=getId("Ingrese la ID del empleado que desea editar: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    if(indexId==-1)
    {
        printf("Error.\n");
    }
    else
    {
        do
        {
        system("cls");

            if(flag==0)
            {
                printf("\nModificacion Completa.\n");
                printf("\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");
                listEmployee(pArrayListEmployee,indexId);
            }

        showMenuModifyEmployee();
        option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,4);
        pEmployee=ll_get(pArrayListEmployee,indexId);

            switch(option)
            {
            case 1:
                getStringOfLetters(nombre,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
                employee_setNombre(pEmployee,nombre);
                flag=0;
            break;
            case 2:
                horasTrabajadas=getInt(horasTrabajadas,"Ingrese las Horas Trabajadas: ","Error, reingrese las Horas Trabajadas: ",0,10000);
                employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
                flag=0;
            break;
            case 3:
                sueldo=getInt(sueldo,"Ingrese el sueldo: ","Error, reingrese sueldo: ",0,10000000);
                employee_setSueldo(pEmployee,sueldo);
                flag=0;
            break;
            }

        }while(option!=4);
    }

    return flag;
}


/** \brief Remove a Employee by Id.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int option;
    int r=-1;
    int indexId;

    indexId=getId("Ingrese la ID del empleado que desea eliminar: ","Error, ID invalida reingrese: ",pArrayListEmployee);
    do
    {
    system("cls");
    printf("\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");
    r=listEmployee(pArrayListEmployee,indexId);
    showMenuVerifyRemove();
    option=getInt(option,"\nIngrese la opcion que desee: ","\nError,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
            pEmployee=ll_get(pArrayListEmployee,indexId);
            employee_delete(pEmployee);
            r=ll_remove(pArrayListEmployee,indexId);

            break;
        }
     }while(option!=2);


    return r;
}


/** \brief Sort Employees.
 *
 * \param cloneArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int sortEmployee(LinkedList* cloneArrayListEmployee)
{
    int r=-1;
    int option;
    int order;

    system("cls");

    do
    {
    showMenuReportEmployees();
    option=getInt(option,"Ingrese la opcion que desea: ","Error, Reingrese una opcion valida: ",1,5);
        switch(option)
        {
        case 1:
            order=getInt(order,"Ingrese 0 para ordenar las IDs de forma DESCENDENTE o 1 para ordenar las IDs de forma ASCENDENTE: ","Error, reingrese un orden valido: ",0,1);
            printf("Ordenando espere un momento...\n");
            r=ll_sort(cloneArrayListEmployee,employee_CompareById,order);
            controller_ListEmployee(cloneArrayListEmployee);
        break;
        case 2:
            order=getInt(order,"Ingrese 0 para ordenar los nombres de forma DESCENDENTE (Z-A) o 1 para ordenar los nombres de forma ASCENDENTE (A-Z): ","Error, reingrese un orden valido: ",0,1);
            printf("Ordenando espere un momento...\n");
            r=ll_sort(cloneArrayListEmployee,employee_CompareByName,order);
            controller_ListEmployee(cloneArrayListEmployee);
        break;
        case 3:
            order=getInt(order,"Ingrese 0 para ordenar las horas trabajadas de forma DESCENDENTE o 1 para ordenar las horas trabajadas de forma ASCENDENTE: ","Error, reingrese un orden valido: ",0,1);
            printf("Ordenando espere un momento...\n");
            r=ll_sort(cloneArrayListEmployee,employee_CompareByHorasTrabajadas,order);
            controller_ListEmployee(cloneArrayListEmployee);
        break;
        case 4:
            order=getInt(order,"Ingrese 0 para ordenar los sueldos de forma DESCENDENTE o 1 para ordenar los sueldos de forma ASCENDENTE: ","Error, reingrese un orden valido: ",0,1);
            printf("Ordenando espere un momento...\n");
            r=ll_sort(cloneArrayListEmployee,employee_CompareBySalary,order);
            controller_ListEmployee(cloneArrayListEmployee);
        break;
        }
    system("pause");
    system("cls");
    }while(option!=5);

    return r;
}


/** \brief Check if there are any employees loaded.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_option(LinkedList* pArrayListEmployee)
{
    int r=1;
    int len;
    len=ll_len(pArrayListEmployee);
    if(len>0)
    {
        r=0;
    }
    return r;
}
