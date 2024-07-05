#include <stdio.h>
#include <string.h>
#include "funciones.h"

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void loadProducts() {
    FILE *file = fopen("productos.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de productos.\n");
        return;
    }
    while (fscanf(file, " %[^\n] %[^\n] %d %f", inventory[productCount].name, inventory[productCount].brand, &inventory[productCount].quantity, &inventory[productCount].price) != EOF) {
        productCount++;
    }
    fclose(file);
}

void saveProducts() {
    FILE *file = fopen("productos.txt", "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de productos.\n");
        return;
    }
    for (int i = 0; i < productCount; ++i) {
        fprintf(file, "%s\n%s\n%d\n%.2f\n", inventory[i].name, inventory[i].brand, inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventario lleno, no se pueden agregar más productos.\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", inventory[productCount].name);
    printf("Ingrese la marca del producto: ");
    scanf(" %[^\n]", inventory[productCount].brand);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &inventory[productCount].quantity);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &inventory[productCount].price);
    productCount++;
    printf("Producto agregado con éxito.\n");
    saveProducts();
}

void editProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos.\n");
            printf("Ingrese el nuevo nombre del producto: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Ingrese la nueva marca del producto: ");
            scanf(" %[^\n]", inventory[i].brand);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &inventory[i].quantity);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &inventory[i].price);
            printf("Producto editado con éxito.\n");
            saveProducts();
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void deleteProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Producto eliminado con éxito.\n");
            saveProducts();
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    printf("Listado de productos:\n");
    for (int i = 0; i < productCount; ++i) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", inventory[i].name);
        printf("Marca: %s\n", inventory[i].brand);
        printf("Cantidad: %d\n", inventory[i].quantity);
        printf("Precio: %.2f\n", inventory[i].price);
    }
}

void searchProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", inventory[i].name);
            printf("Marca: %s\n", inventory[i].brand);
            printf("Cantidad: %d\n", inventory[i].quantity);
            printf("Precio: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

