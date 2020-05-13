#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ArrayEmployees.h"
#include "ShowData.h"
#include "Inputs.h"
#include"Validations.h"


/** \brief Shows the program options menu.
 *
 * \param void
 * \return void
 *
 */
void showMenu(void)
{
    printf("\n1.Cargar un Empleado\n");
    printf("2.Modificar Empleado\n");
    printf("3.Eliminar Empleado\n");
    printf("4.Listar\n");
    printf("  A)Los empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("  B)Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    printf("5.Salir\n");
}


/** \brief It shows the available options when wanting to list the employees.
 *
 * \param void
 * \return void
 *
 */
void showMenuReportEmployees(void)
{
    printf("\n1.Los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    printf("3.Volver Atras.\n");
}


/** \brief Displays the fields that can be modified from the employee struct.
 *
 * \param void
 * \return void
 *
 */
void showMenuModifyEmployee(void)
{
    printf("\n1.Modificar Nombre.\n");
    printf("2.Modificar Apellido.\n");
    printf("3.Modificar Salario.\n");
    printf("4.Modificar Sector.\n");
    printf("5.Volver Atras.\n");
}


/** \brief Allows you to go back if you did not want to enter this function.
 *
 * \param void
 * \return void
 *
 */
void showMenuVerify(void)
{
    printf("\n1.Ver la lista de empleados.\n");
    printf("2.Volver Atras.\n");
}


/** \brief It asks the user if they want to cancel the function.
 *
 * \param void
 * \return void
 *
 */
void showMenuVerifyRemove(Employee list[], int i)
{
    system("cls");
    printf("\n\n ¿Esta seguro que desea eliminar este empleado?\n\n");
    printf("ID\t\t\t\t NOMBRE\t\t\t\t\tAPELLIDO\t\tSALARIO\t\t SECTOR\n");
    printEmployee(list[i]);
    printf("\n1.Aceptar\n");
    printf("2.Cancelar\n");
}
