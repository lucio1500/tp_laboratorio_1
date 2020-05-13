#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ArrayEmployees.h"
#include "ShowData.h"
#include "Inputs.h"
#include"Validations.h"


/** \brief Check if the entered string is an integer.
 *
 * \param numero[] char
 * \return int Returns 1 if the string is numeric or 0 (zero) if it is not.
 *
 */
int validateNumbersInt(char numero[])
{
    int i=0;
    if(numero[0]=='-')
    {
        i=1;
    }
    for(; i<strlen(numero); i++)
    {
        if(!(numero[i]>=48 && numero[i]<=57))
        {
            printf("SOLO INGRESA NUMEROS\n");
            return 0;
        }
    }
    return 1;
}


/** \brief Check if the entered string is a floating number.
 *
 * \param numero[] char
 * \return int Returns 1 if the string is numeric or 0 (zero) if it is not.
 *
 */
int validateNumbersFloat(char numero[])
{
    int i=0;
    if(numero[0]=='-')
    {
        i=1;
    }
    for(; i<strlen(numero); i++)
    {

            if(!(numero[i]>=48 && numero[i]<=57 ))
            {
                if(numero[i]!='.'|| numero[i-1]=='.')
                {
                printf("SOLO INGRESA NUMEROS\n");
                return 0;
                }

            }
    }
    return 1;
}


/** \brief Verify that the string contains only letter or spaces.
 *
 * \param array[] char
 * \return int Returns 1 if the string contains only letters or 0 (zero).
 *
 */
int validateStringOfLetters(char array[])
{
    int i;
    for(i=0 ; i<strlen(array); i++)
    {
        if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
        {
            if(array[i]!=' ' || array[i-1]==' ')
            {
            printf("SOLO INGRESA LETRAS O CON MAXIMO UN ESPACIO ENTRE ELLAS\n");
            return 0;
            }
        }
    }
    return 1;
}

