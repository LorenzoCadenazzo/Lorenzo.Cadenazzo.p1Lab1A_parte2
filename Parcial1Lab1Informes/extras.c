#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validations.h"

int getOption(int maxOption)
{
    int option;

    validations_getUnsignedInt(&option, "\n\tIntroduzca una opcion: ", "\n\t(!) Error. Opcion inexistente\n", 1, sizeof(int),0, maxOption,4);

    return option;
}


int confirm(int menuOption)
{
    char option;
    int confirmed = 0;


    switch(menuOption)
    {
        case 2:
                validations_getChar(&option,"\n\tConfirma la baja? (s/n): ", "\n\t(!) Error. Caracter invalido.\n\tConfirma la baja? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n\n\t\t>>>>> Registro dado de baja exitosamente <<<<<\n\n\n");
                    system("pause");
                }
                else
                {
                    printf("\n\n\t\t>>>>> El registro no fue dado de baja <<<<<\n\n\n");
                    system("pause");
                }
                break;

        case 3:
                validations_getChar(&option,"\n\tConfirma la modificacion? (s/n): ", "\n\t(!) Error. Caracter invalido.\n\tConfirma la modificacion? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n\n\t\t>>>>> Registro modificado exitosamente <<<<<\n\n\n");
                    system("pause");
                }
                else
                {
                    printf("\n\n\t\t>>>>> El registro no fue modificado <<<<<\n\n\n");
                    system("pause");
                }
                break;
        case 11:
                validations_getChar(&option,"\n\tEsta seguro que desea salir? (s/n): ", "\n\t (!) Error. Caracter invalido.\n\tEsta seguro que desea salir? (s/n): ",2);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                }
                break;
    }
    return confirmed;
}
