
#ifndef INFORMS_H_INCLUDED
#define INFORMS_H_INCLUDED


#endif // INFORMS_H_INCLUDED

/** \brief Muestra el menu de informes y hace lo indicado en la opcion
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \return void
 *
 */
void inform(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices, eWork works[], int sizeWorks);


/** \brief Muestra las bicis del color seleccionado por el usuario
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_bikeXcolor(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra las bicis del tipo seleccionado por el usuario
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_bikeXtype(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Informa la o las bicis de mayor rodado
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_bikeWithHigherRodado(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra un listado de las bicis separadas por tipo
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_bikeXAllTypes(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Informa la cantidad de bicis que hay de un tipo y color ingresado por el usuario
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_bikeCountByColorAndType(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors);

/** \brief Muestra todos los trabajos realizados en una bici ingresada por el usuario
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */

void inform_bikeAndWorks(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeService);
/** \brief Informa la suma de los importes de los servicios que se le hicieron a una bici y la fecha
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_sumOfAmountsOfWorks(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices);
/** \brief Muestra las bicis a las que se le realizo un servicio ingresado por el usuario
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colore
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_serviceAndBike(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices);
/** \brief Muestra todos los servicios realizados en una fecha ingresada por el usuario
 *
 * \param bike[] eBike El array de bicis
 * \param sizeBike int El tamaño del array de bicis
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_serviceXdate(eBike bike[], int sizeBike, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices);

