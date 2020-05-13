#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ArrayEmployees.h"
#include "ShowData.h"
#include "Inputs.h"
#include"Validations.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list[] Employee Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */
int initEmployees(Employee list[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
       list[i].isEmpty=TRUE;
       list[i].salary=-1;
    }

    return 0;
}


/** \brief Allows data entry of the fields of the Employee struct.
 *
 * \param list[] Employee
 * \param len int
 * \param accumSalary float
 * \param counterInc int
 * \param index int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int createAnEmployee(Employee list[],int len,float accumSalary,int counterInc,int index,int id)
{
    char name[51];
    char lastName[51];
    float salary=-1;
    int sector=-1;
    int r=-1;


        getStringOfLetters(name,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
        getStringOfLetters(lastName,"Ingrese apellido: ","Error Reingrese un apellido valido: ");
        index=searchIsEmpty(list,len);
        salary=getFloat(salary,"Ingrese salario: ","Error, reingrese salario: ",0,10000);
        sector=getInt(sector,"Ingrese sector: ","Error, reingrese sector: ",-1,1000);
        r=addEmployee(list, len,id,name,lastName,salary,sector);

    return r;
}


/** \brief add in a existing list of employees the values received as parameters
*     in the first empty position
* \param list[] employee
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int index=searchIsEmpty(list,len);

    if(len==0||len>1000||index==-1)
    {
    return -1;
    }
    else
    {
    list[index].id = id;
    strcpy(list[index].name, name);
    strcpy(list[index].lastName, lastName);
    list[index].salary = salary;
    list[index].sector = sector;
    list[index].isEmpty=FALSE;
    return 0;
    }
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list[] Employee
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    int index = -1;


    for (i = 0; i < len; i++)
    {
        if(list[i].id==id)
        {
            index = list[i].id;
            break;
        }
    }



    return index;
}


/** \brief It allows you to go back in case you have chosen the wrong option.
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int verifyRemoveEmployees(Employee list[], int len, int id)
{
    int r;
    int option;

    system("cls");

    do
    {
    showMenuVerify();
    option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
        printf("ID\t\t\t\t NOMBRE\t\t\t\t\tAPELLIDO\t\tSALARIO\t\t SECTOR\n");
        r=printEmployees(list,len);
        id=getId(list,"\nIngrese el numero de id del empleado que desea eliminar: ", "Error id ingresada no valida, reingrese: ");
        r=removeEmployee(list,len,id);
            if(r==-1||r==0)
            {
            break;
            }
        }
     }while(option!=2);

     return r;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list[] Employee
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee list[], int len, int id)
{

    int i;
    int option=0;

    for(i=0; i<len;i++)
    {
        if(id == list[i].id)
        {
        showMenuVerifyRemove(list,i);
        option=getInt(option,"\nIngrese la opcion que desee: ","\nError,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
            list[i].isEmpty=TRUE;
            return 0;
            break;
        }
        else
        {
            return -1;
            break;
        }
        }
    }

    return -1;
}




/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list[] Employee
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee list[], int len, int order)
{
    int flag=-1;
    int i;
    int j;
    Employee auxEmployee;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(stricmp(list[i].lastName,list[j].lastName)>=0&&order==1&&list[i].sector>=list[j].sector)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
                flag=0;
            }
            else if(stricmp(list[i].lastName,list[j].lastName)<=0&&order==0&&list[i].sector<=list[j].sector)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
                flag=0;
            }
        }

    }

    return flag;
}


/** \brief print the content of employees array
*
* \param list[] Employee
* \param length int
* \return int
*
*/
int printEmployees(Employee list[], int length)
{
    int i;

   for(i=0; i<length; i++)
   {
       if(list[i].isEmpty==FALSE)
       {
           printEmployee(list[i]);
       }

   }


    return 0;
}


/** \brief Shows an employee
 *
 * \param list Employee
 * \return
 *
 */
void printEmployee (Employee list)
{
  printf ("%4d\t%30s\t%40s\t%15g\t%15d\n", list.id,list.name,list.lastName,list.salary,list.sector);
}


/** \brief Allows the entry and validation of an id.
 *
 * \param list[] Employee
 * \param message[] char
 * \param [] char messageError
 * \return int Returns a validated id.
 *
 */
int getId(Employee list[],char message[], char messageError [])
{
    int indexId;
    int valueId;
    printf("%s ",message);
    scanf("%d",&valueId);

    indexId=findEmployeeById(list,ELEMENTS,valueId);

     while(indexId == -1)
    {
        printf("%s", messageError);
        scanf("%d", &valueId);
        indexId=findEmployeeById(list,ELEMENTS,valueId);
    }

    return valueId;
}


/** \brief Receives an initialized ID and adds 1.
 *
 * \param id int
 * \return int Return a new id
 *
 */
int generateId(int id)
{
    id++;

    return id;
}


/** \brief look for an empty space in the array employee.
 *
 * \param list[] Employee
 * \param len int
 * \return int Returns the index of the first element of the array that is empty
 *
 */
int searchIsEmpty(Employee list[], int len)
{
     int i;
     int index = -1;


    for (i = 0; i < len; i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            index = i;
            break;
        }
    }

    return index;
}



/** \brief Lets you choose what you want to show.
 *
 * \param list[] Employee
 * \param len int
 * \param average float
 * \param accumSalary int
 * \param counterSalaryHigh int
 * \param counterInc int
 * \return
 *
 */
void showEmployees (Employee list[],int len,float average,float accumSalary,int counterSalaryHigh,int counterInc)
{
    int option;
    int order;

    accumSalary=addSalarys(list,ELEMENTS);
    average=salaryAverage(accumSalary,counterInc);
    counterSalaryHigh=numberOfEmployeesAboveAverage(average,list,ELEMENTS);

    do
    {
    showMenuReportEmployees();
    option=getInt(option,"Ingrese la opcion que desea: ","Error, Reingrese una opcion valida: ",1,3);
        switch(option)
        {
        case 1:
        order=getInt(order,"Ingrese 0 para ordenar los apellidos de forma DESCENDENTE (Z-A) o 1 para ordenar los apellidos de forma ASCENDENTE (A-Z): ","Error, reingrese un orden valido: ",0,2);
        printf("\nLISTADO:\n");
        printf("ID\t\t\t\t NOMBRE\t\t\t\t\tAPELLIDO\t\tSALARIO\t\t SECTOR\n");
        sortEmployees(list,len,order);
        printEmployees(list,len);
        break;
        case 2:
        printf("El total de los salarios es: %f\n",accumSalary);
        printf("El promedio de los salarios es: %f\n",average);
        printf("El numero de empleados que superan el salario promedio es: %d\n",counterSalaryHigh);
        break;
        }
    }while(option!=3);


}


/** \brief performs the sum of wages.
 *
 * \param list[] Employee
 * \param len int
 * \return float Returns the total sum of wages entered.
 *
 */
float addSalarys(Employee list[],int len)
{
    int i;
    float accumSalary=0;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==FALSE && list[i].salary>=0)
        {
            accumSalary=accumSalary+list[i].salary;
        }

    }

    return accumSalary;
}


/** \brief Calculate the average salary of employees.
 *
 * \param accumSalary float
 * \param counterInc int
 * \return float The average salary
 *
 */
float salaryAverage(float accumSalary, int counterInc)
{
    float average;

    average=accumSalary/counterInc;

    return average;

}


/** \brief Count employees who are above average salary.
 *
 * \param average float
 * \param list[] Employee
 * \param len int
 * \return int The number of employees who above the average salary.
 *
 */
int numberOfEmployeesAboveAverage (float average,Employee list[],int len)
{
    int i;
    int counterSalaryHigh=0;
    for(i=0;i<len;i++)
    {
        if (list[i].salary>average)
        {
        counterSalaryHigh++;
        }
    }
    return counterSalaryHigh;
}


/** \brief It allows you to go back in case you have chosen the wrong option.
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int verifyModifyEmployees(Employee list[], int len, int id)
{
    int r;
    int option;

    system("cls");

    do
    {
    showMenuVerify();
    option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,2);
        if(option==1)
        {
        printf("ID\t\t\t\t NOMBRE\t\t\t\t\tAPELLIDO\t\tSALARIO\t\t SECTOR\n");
        r=printEmployees(list,len);
        id=getId(list,"\nIngrese el numero de id del empleado que desea modificar: ", "Error id ingresada no valida, reingrese: ");
        r=modifyEmployees(list,len,id);
            if(r==-1||r==0)
            {
            break;
            }
        }
     }while(option!=2);

     return r;
}


/** \brief Through the identification number, it allows to modify: or Name or Lastname or Salary or Sector
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployees(Employee list[], int len, int id)
{
    int flag=-1;
    int option;
    int i;


    do
    {
        if(flag==0)
        {
        printf("Modificacion Completa.\n");
        printf("ID\t\t\t\t NOMBRE\t\t\t\t\tAPELLIDO\t\tSALARIO\t\t SECTOR\n");
        printEmployees(list,ELEMENTS);
        }

    showMenuModifyEmployee();
    option=getInt(option,"Ingrese la opcion que desee: ","Error,opcion invalida reingrese: ",1,5);
        switch(option)
        {
        case 1:
            for(i=0; i<len;i++)
            {
                if(id == list[i].id)
                {
                getStringOfLetters(list[i].name,"Ingrese nombre: ","Error Reingrese un nombre valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 2:
            for(i=0; i<len;i++)
            {
                if(id == list[i].id)
                {
                getStringOfLetters(list[i].lastName,"Ingrese apellido: ","Error Reingrese un apellido valido: ");
                flag=0;
                break;
                }
            }
        break;
        case 3:
            for(i=0; i<len;i++)
            {
                if(id == list[i].id)
                {
                list[i].salary=getFloat(list[i].salary,"Ingrese salario: ","Error, reingrese salario: ",0,10000);
                flag=0;
                break;
                }
            }
        break;
        case 4:
            for(i=0; i<len;i++)
            {
                if(id == list[i].id)
                {
                list[i].sector=getInt(list[i].sector,"Ingrese sector: ","Error, reingrese sector: ",-1,1000);
                flag=0;
                break;
                }
            }
        break;
    }

    system("cls");

    }while(option!=5);

    return flag;


}
