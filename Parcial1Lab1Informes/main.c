/*
Autor: Lorenzo Cadenazzo, División 1A. Profesor Baus/Scudero.
Primer parcial Laboratorio de computación 1, segunda parte.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bike.h"
#include "type.h"
#include "color.h"
#include "service.h"
#include "work.h"
#include "extras.h"
#include "menu.h"

#define SIZE_BIKE 10
#define SIZE_TYPE 4
#define SIZE_COLOR 5
#define SIZE_SERVICE 4
#define SIZE_WORK 10
#define HARDCODESIZE 4
#define HARDCODESIZE_WORK 4


int main()
{
    eBike bike[SIZE_BIKE];
    eType types[SIZE_TYPE] = {{1000,"Rutera"}, {1001,"Carrera"}, {1002, "Mountain"}, {1003, "BMX"}};
    eColor colors[SIZE_COLOR] = {{5000,"Gris"}, {5001,"Blanco"}, {5002, "Azul"}, {5003, "Negro"}, {5004, "Rojo"}};
    eService services[SIZE_SERVICE] = {{20000, "Limpieza", 30}, {20001, "Parche", 400}, {20002, "Centrado", 500}, {20003, "Cadena", 450}};
    eWork works[SIZE_WORK];

    char cont = 's';
    int nextIDBike = 1000;
    int nextIDWork = 0;
    int flag = 0;


    bike_initializate(bike, SIZE_BIKE);
    work_initializate(works, SIZE_WORK);

    bike_hardcode(bike, HARDCODESIZE);
    nextIDBike += HARDCODESIZE;

    work_hardcode(works, HARDCODESIZE_WORK);
    nextIDWork += HARDCODESIZE_WORK;


    do
    {
        switch(menu_main())
        {
        case 1:
            if(bike_load(nextIDBike,bike, SIZE_BIKE, types, SIZE_TYPE, colors, SIZE_COLOR)== 1)
            {
                nextIDBike++;
            }
            flag = 1;
            break;
        case 2:

            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {

                bike_delate(bike, SIZE_BIKE, types, SIZE_TYPE, colors, SIZE_COLOR);
            }

            break;
        case 3:
            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {

                bike_modify(bike, SIZE_BIKE, types, SIZE_TYPE, colors, SIZE_COLOR);
            }

            break;
        case 4:

            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {
                bike_show(bike,SIZE_BIKE, types, SIZE_TYPE, colors, SIZE_COLOR);
                system("pause");

            }

            break;
        case 5:
            type_show(types, SIZE_TYPE);
            break;
        case 6:
            color_show(colors, SIZE_COLOR);
            break;
        case 7:
            service_show(services, SIZE_SERVICE);
            break;
        case 8:
            if(work_load(nextIDWork, works, SIZE_WORK, bike, SIZE_BIKE, types, SIZE_TYPE, colors, SIZE_COLOR, services, SIZE_SERVICE) == 1)
            {
                nextIDWork++;
            }
            break;
        case 9:
            work_show(works, SIZE_WORK, bike, SIZE_BIKE, services, SIZE_SERVICE);
            break;
        case 10:
            inform(bike, SIZE_BIKE, types, SIZE_TYPE, colors, SIZE_COLOR, services, SIZE_SERVICE, works, SIZE_WORK);
            break;
        case 11:
            if(confirm(11) == 1)
            {
                cont = 'n';
            }
            break;
        }
    }
    while(cont == 's');

    return 0;
}
