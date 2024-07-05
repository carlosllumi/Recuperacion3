#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    int option;
    do {
        printf("\nSistema de Inventarios\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Buscar producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                listProducts();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Saliendo del sistema de inventarios.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (option != 6);

    return 0;
}
