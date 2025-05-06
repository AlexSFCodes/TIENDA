#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10

float valpp();
int valopc();
void menu();
int valP();

int main()
{
    int opc = 0, productos = 0, len, compara;
    float PrecioProducto[MAX_PRODUCTOS] = {0};
    float sumaT, promedio;
    char Nombres[MAX_PRODUCTOS][30],BNombres[30];

    do
    {
        menu();
        printf("Ingrese la opcion: ");
        opc = valopc();

        switch (opc)
        {
        case 1:
            printf("Cuantos productos desea ingresar (maximo %d): ", MAX_PRODUCTOS);
            productos = valP();
            while (getchar() != '\n');
            for (int i = 0; i < productos; i++)
            {
                printf("Ingrese el nombre del producto #%i: ", i + 1);
                fgets(Nombres[i], 30, stdin);
                len = strlen(Nombres[i]);
                if (Nombres[i][len - 1] == '\n')
                {
                    Nombres[i][len - 1] = '\0';
                }
                printf("Ingrese el precio del producto #%i: ", i + 1);
                PrecioProducto[i] = valpp();
            }
            break;

        case 2:
            if (productos == 0)
            {
                printf("Primero debe ingresar productos con la opcion 1.\n");
                break;
            }
            for (int i = 0; i < productos - 1; i++)
            {
                for (int j = 0; j < productos - i - 1; j++)
                {
                    if (PrecioProducto[j] < PrecioProducto[j + 1])
                    {
                        float temp = PrecioProducto[j];
                        PrecioProducto[j] = PrecioProducto[j + 1];
                        PrecioProducto[j + 1] = temp;

                        char tempNombre[30];
                        strcpy(tempNombre, Nombres[j]);
                        strcpy(Nombres[j], Nombres[j + 1]);
                        strcpy(Nombres[j + 1], tempNombre);
                    }
                }
            }
            printf("El producto que cuesta mas es '%s' con precio %.2f\n", Nombres[0], PrecioProducto[0]);
            printf("El producto que cuesta menos es '%s' con precio %.2f\n", Nombres[productos - 1], PrecioProducto[productos - 1]);
            break;

        case 3:
            if (productos == 0)
            {
                printf("Primero debe ingresar productos con la opcion 1.\n");
                break;
            }
            sumaT = 0;
            for (int i = 0; i < productos; i++)
            {
                sumaT += PrecioProducto[i];
            }
            promedio = sumaT / productos;
            printf("Suma total del inventario es %.2f\n", sumaT);
            printf("Promedio del inventario es %.2f\n", promedio);
            break;
        case 4:
            if (productos==0)
            {   
                printf("Primero debe ingresar productos con la opcion 1.\n");
                break;
            }
            printf("Ingrese el nombre del producto \n");
            fgets(BNombres,30,stdin);
            len = strlen(BNombres);
            if (BNombres[len - 1] == '\n')
            {
                BNombres[len - 1] = '\0';
            }
            for (int i = 0; i < productos; i++)
            {
                compara=strcmp(BNombres,Nombres[i]);
                if (compara==0)
                {
                    printf("El precio del producto  es %.2f",PrecioProducto[i]);
                }
            }
            break;
        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida.\n");
            break;
        }

    } while (opc != 5);

    return 0;
}
int valP(){
    int x, val;
    val=scanf("%i", &x);
    while (val!=1 ||x < 1 || x > 10)
    {
        while (getchar() != '\n');
        printf("INCORRECTO Ingrese entre 1 y 10: ");
        val=scanf("%i", &x);
    }
    return x;
}
void menu()
{
    printf("\n-- Que desea hacer --\n");
    printf("1. Crear productos\n");
    printf("2. Encontrar producto mas caro y mas barato\n");
    printf("3. Precio total del inventario y el promedio\n");
    printf("4. Encontrar un producto \n");
    printf("5. Salir\n");
}

int valopc()
{
    int x, val;
    val = scanf("%i", &x);
    while (val != 1 || x < 1 || x > 5)
    {
        while (getchar() != '\n');
        printf("Entrada invalida, solo numeros del 1 al 5\n>> ");
        val = scanf("%i", &x);
    }
    while (getchar() != '\n');
    return x;
}

float valpp()
{
    float x;
    int val = scanf("%f", &x);
    while (val != 1 || x <= 0)
    {
        while (getchar() != '\n');
        printf("Entrada invalida, ingrese un numero positivo\n>> ");
        val = scanf("%f", &x);
    }
    while (getchar() != '\n');
    return x;
}
