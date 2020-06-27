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

/** \brief Shows the program options menu.
 *
 * \param void
 * \return void
 *
 */
void showMenu(void)
{
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Reemplazar un empleado por otro.\n");
    printf("9. Eliminar todos los empleados de la lista.\n");
    printf("10. Crear una sublista.\n");
    printf("11. Comparar la sublista con la lista.\n");
    printf("12. Mover un empleado.\n");
    printf("13. Verifica si un empleado de la sublista esta en la lista.\n");
    printf("14. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("15. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("16. Salir.\n");
}


/** \brief It shows the available options when wanting to list the employees.
 *
 * \param void
 * \return void
 *
 */
void showMenuReportEmployees(void)
{
    printf("\n1. Ordenar los empleados por ID.\n");
    printf("2. Ordenar los empleados por nombre\n");
    printf("3. Ordenar los empleados por horas trabajadas\n");
    printf("4. Ordenar los empleados por sueldo\n");
    printf("5. Volver Atras.\n");
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
    printf("2.Modificar Horas Trabajadas.\n");
    printf("3.Modificar Sueldo.\n");
    printf("4.Volver Atras.\n");
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
void showMenuVerifyRemove(void)
{
    printf("\nEsta seguro que desea eliminar este empleado?\n");
    printf("1.Aceptar\n");
    printf("2.Cancelar\n");
}



