#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bike.h"

#include "validations.h"
#include "menu.h"
#include "extras.h"

#define EMPTY 0
#define TAKEN 1

void bike_hardcode(eBike bike[], int bikeToHardcode)
{
    int ids[] = {1000,1001,1002,1003};
    char brands[][20] = {"Venzo", "Vairo", "Philco", "Olmo"};
    int idsType[] = {1000,1001,1002,1003};
    int idsColor[] = {5000,5001,5002,5003,5004};
    int rodados[] = {20,22,24,26,28};

    for(int i=0; i<bikeToHardcode; i++)
    {
        bike[i].id = ids[i];
        strcpy(bike[i].brand, brands[i]);
        bike[i].idType = idsType[i];
        bike[i].idColor = idsColor[i];
        bike[i].rodado =  rodados[i];
        bike[i].state = TAKEN;
    }
}

void bike_initializate(eBike bike[], int sizeBike)
{
    for(int i=0; i<sizeBike; i++)
    {
        bike[i].state = EMPTY;
    }
}
int bike_findFreeSpace(eBike bike[], int sizeBike)
{
    int ret = -1;

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].state == EMPTY)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int bike_findOne(int id, eBike bike[], int sizeBike)
{
    int ret = -1;

    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].id == id && bike[i].state == TAKEN)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int bike_load(int id, eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColor)
{
    eBike auxBici;
    int index = bike_findFreeSpace(bike, sizeBike);
    int ok = 0;

    system("cls");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {

        auxBici.id = id;

        validations_getText(auxBici.brand,"\n\tIngrese la marca: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 20, 4);

        type_show(types, sizeTypes);
        validations_getUnsignedInt(&auxBici.idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1000-1003\n",1,1003,1000,1003,4);

        validations_getUnsignedInt(&auxBici.rodado,"\n\tIngrese la rodado: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 20-28\n",1, 28,20,28,4);

        auxBici.state = TAKEN;

        bike[index] = auxBici;

        printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
        system("cls");
        ok = 1;

    }
    return ok;
}

void bike_delate(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int id;
    int index;

    system("cls");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    bike_show(bike, sizeBike, types, sizeTypes, colors, sizeColors);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = bike_findOne(id, bike, sizeBike);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una bici con el ID: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\t\tLa bici que se dara de baja es:");
        printf("\n\t\t _________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO          ");
        printf("\n\t\t _________________________________________________________________________________\n");
        bike_showOne(bike[index], types, sizeTypes, colors, sizeColors);
        printf("\n\t\t _________________________________________________________________________________\n\n");

        if(confirm(2))
        {
            bike[index].state = EMPTY;
        }
    }
}

void bike_modify(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int id;
    int index;
    int newRodado;
    int newIDColor;

    system("cls");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    bike_show(bike, sizeBike, types, sizeTypes, colors, sizeColors);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = bike_findOne(id, bike, sizeBike);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una bici con el ID: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\t\tLa bici que se modificara es:");
        printf("\n\t\t __________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO            ");
        printf("\n\t\t __________________________________________________________________________________\n");
        bike_showOne(bike[index], types, sizeTypes, colors, sizeColors);
        printf("\n\t\t __________________________________________________________________________________\n\n");

        switch(menu_bikeModify())
        {
        case 1:
            color_show(colors, sizeColors);
            validations_getUnsignedInt(&newIDColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,5000,100000,4);
            if(confirm(3))
            {
                bike[index].idColor = newIDColor;
            }
            break;
        case 2:
            validations_getUnsignedInt(&newRodado,"\n\tIngrese la rodado: ", "\n\t(!) Error. Ingrese un valor numerico entero desde 50 hasta 28.\n",1,28,20,28,4);
            if(confirm(3))
            {
                bike[index].rodado = newRodado;
            }
            break;
        }

        printf("\n");
        printf("\n\t\t __________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO          ");
        printf("\n\t\t __________________________________________________________________________________\n");
        bike_showOne(bike[index], types, sizeTypes, colors, sizeColors);
        printf("\n\t\t __________________________________________________________________________________\n\n");

        system("pause");
    }
}

void bike_show(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;

    printf("\n\t\t ______________________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        RODADO               ");
    printf("\n\t\t ______________________________________________________________________________________\n");
    bike_sort(bike, sizeBike, types, sizeTypes, colors, sizeColors);
    for(int i=0; i<sizeBike; i++)
    {
        if(bike[i].state == TAKEN)
        {
            bike_showOne(bike[i], types, sizeTypes, colors, sizeColors);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

void bike_showOne(eBike x, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    char typeDescription[20];
    char colorName[20];

    bike_loadTypeDescription(typeDescription, x.idType, types, sizeTypes);
    bike_loadColorName(colorName, x.idColor, colors, sizeColors);


    printf("\n\t\t    %5d  %15s   %15s  %10s         %2d         \n", x.id, x.brand, typeDescription, colorName, x.rodado);
}

void bike_sort(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    eBike auxBici;

    for(int i=0; i<sizeBike-1; i++)
    {
        for(int j=i+1; i<sizeBike; i++)
        {
            if(bike[i].idType > bike[j].idType)
            {
                auxBici = bike[i];
                bike[i] = bike[j];
                bike[j] = auxBici;
            }
            else if(bike[i].idType == bike[j].idType && bike[i].id > bike[j].id)
            {
                auxBici = bike[i];
                bike[i] = bike[j];
                bike[j] = auxBici;
            }
        }
    }
}

int bike_loadTypeDescription(char description[], int id, eType types[], int sizeTypes)
{
    int ok = 0;

    for(int i=0; i<sizeTypes; i++)
    {
        if(types[i].id == id)
        {
            strcpy(description, types[i].description);
            ok = 1;
        }
    }

    return ok;
}

int bike_loadColorName(char colorName[], int id, eColor colors[], int sizeColors)
{
    int ok = 0;

    for(int i=0; i<sizeColors; i++)
    {
        if(colors[i].id == id)
        {
            strcpy(colorName, colors[i].colorName);
            ok = 1;
        }
    }

    return ok;
}
