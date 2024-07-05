#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    char brand[50];
    int quantity;
    float price;
} Product;

extern Product inventory[MAX_PRODUCTS];
extern int productCount;

void addProduct();
void editProduct();
void deleteProduct();
void listProducts();
void searchProduct();
void loadProducts();
void saveProducts();

#endif

