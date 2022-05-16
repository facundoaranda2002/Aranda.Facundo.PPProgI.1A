#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

int mostrarCaracteres(char vec[], int tam);
float aplicarAumento(float precio);
int reemplazarCaracteres(char cadena[], char a, char b);
int listarVac(eVacuna vec[], int tam);
int ordenarVacPorTipoYEfectividad(eVacuna vec[], int tam);

int main()
{
    float precio=10;
    float precioAument;
    char cadena[5]={'a','9','7','@','2'};
    int contCambios;
    eVacuna vac[5]=
    {
       {5000, "aaaa", 'a', 2},
       {5001, "baaaa", 'b', 3},
       {5002, "caaa", 'a', 4},
       {5003, "daaaa", 'b', 5},
       {5004, "eaaaaa", 'a', 6}
    };
    precioAument=aplicarAumento(precio);
    contCambios=reemplazarCaracteres(cadena, 'a', '7');
    printf("%.2f\n", precioAument);
    mostrarCaracteres(cadena, 5);
    printf("%d\n", contCambios);
    listarVac(vac, 5);
    ordenarVacPorTipoYEfectividad(vac, 5);
    listarVac(vac, 5);

    return 0;
}


float aplicarAumento(float precio)
{
    if(precio>0)
    {
        return precio*1.05;
    }
    else
    {
        printf("Error\n");
        return -1;
    }
}

int reemplazarCaracteres(char cadena[], char a, char b)
{
    int cont=0;
    if(cadena!=NULL)
    {
        for(int i=0; i<5 ; i++)
        {
            if(cadena[i]==a)
            {
                cadena[i]=b;
                cont++;
            }
        }
        return cont;
    }
    else
    {
        printf("Error\n");
        return -1;
    }
}

int mostrarCaracteres(char vec[], int tam)
{
    int todoOK=0;
    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("%c ", vec[i]);
        }
        printf("\n");
        todoOK=1;
    }

    return todoOK;
}

int ordenarVacPorTipoYEfectividad(eVacuna vec[], int tam)
{
    int todoOk = 0;
    eVacuna auxVacuna;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if(  ((vec[i].tipo == vec[j].tipo) && (vec[i].efectividad < vec[j].efectividad))
                   || (vec[i].tipo > vec[j].tipo)  )
                {
                    auxVacuna = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxVacuna;
                }

            }
        }
      todoOk = 1;
    }
    return todoOk;
}


int listarVac(eVacuna vec[], int tam)
{
    int todoOk=0;

    if(vec!=NULL && tam>0)
    {
        printf("    *** Lista de Vacunas ***\n");
        printf("   Id    Nombre        Tipo   Efectividad\n");
        printf("-------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
           printf("   %4d    %10s    %c    %.2f\n", vec[i].id, vec[i].nombre, vec[i].tipo, vec[i].efectividad);
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}
