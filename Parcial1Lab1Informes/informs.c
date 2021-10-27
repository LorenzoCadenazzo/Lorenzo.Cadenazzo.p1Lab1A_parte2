#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bike.h"
#include "type.h"
#include "color.h"
#include "service.h"
#include "work.h"
#include "informs.h"


#include "menu.h"
#include "extras.h"
#include "validations.h"

void inform(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices, eWork works[], int sizeWorks)
{
    char cont = 's';

    system("cls");
    printf("\n *** INFORMES ***************************************************************************");

    do
    {

        switch(menu_inform())
        {
        case 1:
            inform_bikeXcolor(bike, sizeBike, types, sizeTypes, colors, sizeColors);
            break;
        case 2:
            inform_bikeXtype(bike, sizeBike, types, sizeTypes, colors, sizeColors);
            break;
        case 3:
            inform_bikeWithHigherRodado(bike, sizeBike, types, sizeTypes, colors, sizeColors);
            break;
        case 4:
            inform_bikeXAllTypes(bike, sizeBike, types, sizeTypes, colors, sizeColors);
            break;
        case 5:
            inform_bikeCountByColorAndType(bike, sizeBike, types, sizeTypes, colors, sizeColors);
            break;
        case 6:
            inform_bikeAndWorks(bike, sizeBike, types, sizeTypes, colors, sizeColors, works, sizeWorks, services, sizeServices);
            break;
        case 7:
            inform_sumOfAmountsOfWorks(bike, sizeBike, types, sizeTypes, colors, sizeColors, works, sizeWorks, services, sizeServices);
            break;
        case 8:
            inform_serviceAndBike(bike, sizeBike, types, sizeTypes, colors, sizeColors, works, sizeWorks, services, sizeServices);
            break;
        case 9:
            inform_serviceXdate(bike, sizeBike, types, sizeTypes, colors, sizeColors, works, sizeWorks, services, sizeServices);
            break;
        case 10:
            cont = 'n';
            break;
        }

    }
    while(cont == 'y');
}

void inform_bikeXcolor(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;
    int idColor;

    system("cls");
    printf("\n *** BICIS POR COLOR *****************************************************************************\n\n");

    color_show(colors, sizeColors);
    validations_getUnsignedInt(&idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].state == 1 && bike[i].idColor == idColor)
        {
            printf("\n\t\t _____________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO    ");
            printf("\n\t\t _____________________________________________________________________________\n");

            bike_showOne(bike[i], types, sizeTypes, colors, sizeColors);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay bicis de ese color <<<\n");
    }
}
void inform_bikeXtype(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;
    int idType;

    system("cls");
    printf("\n *** BICIS POR TIPO *****************************************************************************\n\n");

    type_show(types, sizeTypes);
    validations_getUnsignedInt(&idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].state == 1 && bike[i].idType == idType)
        {
            printf("\n\t\t _____________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO    ");
            printf("\n\t\t _____________________________________________________________________________\n");

            bike_showOne(bike[i], types, sizeTypes, colors, sizeColors);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay bicis de ese tipo <<<\n");
    }
}
void inform_bikeWithHigherRodado(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int higherRodado = 0;

    system("cls");
    printf("\n *** MAYOR RODADO *********************************************\n\n");

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].state == 1)
        {
            if(bike[i].rodado > higherRodado)
            {
                higherRodado = bike[i].rodado;
            }
        }
    }
    printf("\nEl mayor rodado es %d y la/s bicis son: ", higherRodado);

    printf("\n\t\t _____________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO    ");
    printf("\n\t\t _____________________________________________________________________________\n");

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].rodado == higherRodado)
        {
            bike_showOne(bike[i], types, sizeTypes, colors, sizeColors);
        }
    }
}
void inform_bikeXAllTypes(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{

    system("cls");
    printf("\n *** BICIS DE TODOS LOS TIPOS *********************************************\n\n");

    for(int i=0; i<sizeTypes; i++)
    {

        printf("\n\n\n\n\nTipo: %s", types[i].description);

        for(int j=0; j<sizeBike; j++)
        {
            if(bike[j].state == 1 && bike[j].idType == types[i].id)
            {
                printf("\n\t\t _____________________________________________________________________________\n");
                printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO    ");
                printf("\n\t\t _____________________________________________________________________________\n");
                bike_showOne(bike[j], types, sizeTypes, colors, sizeColors);

            }
        }

    }
}
void inform_bikeCountByColorAndType(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;
    int idColor;
    int idType;
    int indexColor;
    int indexType;
    int counter = 0;

    system("cls");
    printf("\n *** CONTADOR DE BICIS POR COLOR Y TIPO *****************************************************************************\n\n");

    color_show(colors, sizeColors);
    validations_getUnsignedInt(&idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);

    type_show(types, sizeTypes);
    validations_getUnsignedInt(&idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,10000,1000,10000,4);

    indexColor = color_findOne(idColor, colors, sizeColors);
    indexType = type_findOne(idType, types, sizeTypes);

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].state == 1 && bike[i].idColor == idColor && bike[i].idType == idType)
        {
            counter++;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\n\t\t>>> No hay bicis de ese color y tipo <<<\n");
    }
    else
    {
        printf("\n\n\t\t>>> Hay %d bicis del color %s y del tipo %s <<<\n", counter, colors[indexColor].colorName, types[indexType].description);
        system("pause");
    }
}

void inform_bikeAndWorks(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeService)
{
    int flag = 0;
    int idBike;

    system("cls");
    printf("\n *** TODOS LOS TRABAJOS DE UNA BICI *****************************************************************************\n\n");

    bike_show(bike, sizeBike, types, sizeTypes, colors, sizeColors);
    validations_getUnsignedInt(&idBike,"\n\tIngrese ID de la bici: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idBike == idBike)
        {
            printf("\n\t\t ________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA           SERVICIO            FECHA          ");
            printf("\n\t\t ________________________________________________________________________\n");
            work_showOne(works[i],bike,sizeBike,services,sizeService);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay trabajos realizados en esta bici <<<\n");
    }
}
void inform_sumOfAmountsOfWorks(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices)
{
    int flag = 0;
    int idBike;
    float sum;

    system("cls");
    printf("\n *** SUMA DE IMPORTES DE LOS SERVICIOS *****************************************************************************\n\n");

    bike_show(bike, sizeBike, types, sizeTypes, colors, sizeColors);
    validations_getUnsignedInt(&idBike,"\n\tIngrese ID de la bici: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idBike == idBike)
        {
            sum += services[works[i].idService-20000].price;
            flag = 1;
        }
    }

    printf("\n\t\tLa suma de los importes de la bici seleccionada es: %.2f", sum);

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay servicios realizados en esta bici <<<\n");
    }
}
void inform_serviceAndBike(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors,eWork works[], int sizeWorks, eService services[], int sizeServices)
{
    int flag = 0;
    int idService;

    system("cls");
    printf("\n *** BICIS CON SERVICIOS REALIZADOS *****************************************************************************\n\n");

    service_show(services,sizeServices);
    validations_getUnsignedInt(&idService,"\n\tIngrese ID del servicio: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 20000\n",1,30000,20000,30000,4);

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idService == idService)
        {
            work_showOne(works[i],bike,sizeBike,services,sizeServices);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay bicis a las que se les haya realizado ese servicio <<<\n");
    }
}
void inform_serviceXdate(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices)
{
    int flag = 0;
    eWork auxWork;

    system("cls");
    printf("\n *** SERVICIOS POR FECHA *****************************************************************************\n\n");

    validations_getUnsignedInt(&auxWork.date.day,"\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
    validations_getUnsignedInt(&auxWork.date.month,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
    validations_getUnsignedInt(&auxWork.date.year,"\n\tIngrese anio: ", "\n\t(!) Error. Ingrese un valor numerico entero. El anio debe ser entre 1990 y 2020.\n",1,2020,1,2020,4);

    while(validations_getDate(auxWork.date.day, auxWork.date.month, auxWork.date.year, 1990, 2020)==0)
    {
        printf("\n\t(!) Error. Fecha no valida. \n");
        validations_getUnsignedInt(&auxWork.date.day,"\n\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,31,1,31,4);
        validations_getUnsignedInt(&auxWork.date.month,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,12,1,12,4);
        validations_getUnsignedInt(&auxWork.date.year,"\n\tIngrese anio: ", "\n\t(!) Error. Ingrese un valor numerico entero entre 1990 y 2020.\n",1,2020,1,2020,4);
    }

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && (works[i].date.day == auxWork.date.day) && (works[i].date.month == auxWork.date.month) && (works[i].date.year == auxWork.date.year))
        {
            work_showOne(works[i], bike, sizeBike, services, sizeServices);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No se realizaron servicios en esa fecha <<<\n");
    }
}
