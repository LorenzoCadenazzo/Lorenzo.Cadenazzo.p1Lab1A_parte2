#include "type.h"
#include "color.h"

#ifndef BIKE_H_INCLUDED
#define BIKE_H_INCLUDED

typedef struct
{
    int id;
    char brand[20];
    int idType;
    int idColor;
    int rodado;
    int state;

} eBike;


/** \brief Hardcodea las bicis
 *
 * \param bike[] eBike El array de bicis
 * \param bikeToHardcode int La cantidad de bicis a harcodear
 * \return void
 *
 */
void bike_hardcode(eBike bike[], int bikeToHardcode);
/** \brief Inicializa el array de bicis en 0 o vacio
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array
 * \return void
 *
 */
void bike_initializate(eBike bike[], int sizeBike);
/** \brief Busca lugar libre en el array de bicis para guardar nuevos datos
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int bike_findFreeSpace(eBike bike[], int sizeBike);
/** \brief Verifica la existencia de otra bici con el mismo ID
 *
 * \param id int El ID a buscar
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int bike_findOne(int id, eBike bike[], int sizeBike);


/** \brief Da de alta una bici
 *
 * \param int id El id que se le asignara a la bici
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bici
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bici
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
int bike_load(int id, eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Da de baja una bici
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bike_delate(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Modifica una bici
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bike_modify(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra las bicis cargadas en una lista
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bike_show(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra solo una bici
 *
 * \param eBike La bici a mostrar
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bike_showOne(eBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Ordena las bicis
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bike_sort(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);

/** \brief Ordena las bicis por patente
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bike_sortPatent(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);

/** \brief Carga la descripcion de los tipos de bicis
 *
 * \param description[] char Donde se cargara la informacion
 * \param id int El id de la estructura Type
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int bike_loadTypeDescription(char description[], int id, eType types[], int sizeTypes);
/** \brief Carga el nombre de los colores de bicis
 *
 * \param colorName[] char Donde se cargara la informacion
 * \param id int El id de la estructura Color
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int bike_loadColorName(char colorName[], int id, eColor colors[], int sizeColors);

#endif // BIKE_H_INCLUDED
