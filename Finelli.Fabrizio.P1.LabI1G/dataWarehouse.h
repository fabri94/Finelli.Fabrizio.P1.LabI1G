#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

//#include "ArrayEmployee.h" incluir auto.h o la biblioteca de la estructura principal que toque

/** \brief Array de empleados ya hardcodeados y predefinidos. Ayudan con la coreccion en la disposicion de las tablas y probar las fx
 * ya desarrolladas, sin tener que dar de alta un empleado necesariamente para hacerlo
 * \param lst[] Employee Array de los empleados que cargara
 * \param len int Tamaño del array de los empleados
 * \param cant int Cantidad de empleados que se quieren hardcodear en el array
 * \param pId int* ID que se le asigna a cada empleado hardcodeado
 * \return int Devuelve 1 si esta todoOk. 0 si hubo un error
 *
 */
int hardcodearEmpleados(Employee lst[], int len, int cant, int* pId);

#endif // DATAWAREHOUSE_H_INCLUDED
