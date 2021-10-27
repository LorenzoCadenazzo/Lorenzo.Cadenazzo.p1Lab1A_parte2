#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "extras.h"
#include "validations.h"


int menu_main()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *                MENU                *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *    1.  ALTA DE BICI                *");
    printf("\n\t\t\t\t *    2.  BAJA DE BICI                *");
    printf("\n\t\t\t\t *    3.  MODIFICACION DE BICI        *");
    printf("\n\t\t\t\t *    4.  LISTAR BICIS                *");
    printf("\n\t\t\t\t *    5.  LISTAR TIPOS                *");
    printf("\n\t\t\t\t *    6.  LISTAR COLORES              *");
    printf("\n\t\t\t\t *    7.  LISTAR SERVICIOS            *");
    printf("\n\t\t\t\t *    8.  ALTA TRABAJO                *");
    printf("\n\t\t\t\t *    9.  LISTAR TRABAJOS             *");
    printf("\n\t\t\t\t *    10. INFORMES                    *");
    printf("\n\t\t\t\t *    11. SALIR                       *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *____________________________________*\n\n");
    option = getOption(11);

	return option;
}

int menu_bikeModify()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA MODIFICAR?         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. COLOR                           |");
    printf("\n\t\t\t\t |    2. CILINDRADA                      |");
    printf("\n\t\t\t\t |    3. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(3);

    return option;
}

int menu_inform()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________________________");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |                       INFORMES                     |");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |   1.   INFORME BICIS POR COLOR                     |");
    printf("\n\t\t\t\t |   2.   INFORME BICIS POR TIPO                      |");
    printf("\n\t\t\t\t |   3.   INFORME BICI CON MAYOR CILINDRADA           |");
    printf("\n\t\t\t\t |   4.   INFORME BICIS SEPARADAS POR TIPOS           |");
    printf("\n\t\t\t\t |   5.   INFORME BICIS CONTADAS POR COLOR Y TIPO     |");
    printf("\n\t\t\t\t |   6.   INFORME TODOS LOS TRABAJOS DE UNA BICI      |");
    printf("\n\t\t\t\t |   7.   INFORME SUMA DE IMPORTES DE LOS SERVICIOS   |");
    printf("\n\t\t\t\t |   8.   INFORME BICIS CON SERVICIOS REALIZADOS      |");
    printf("\n\t\t\t\t |   9.   INFORME SERVICIOS DE UNA FECHA              |");
    printf("\n\t\t\t\t |   10.  VOLVER                                      |");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |____________________________________________________|\n\n");
    option = getOption(10);

    return option;
}
