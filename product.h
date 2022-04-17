#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
typedef struct
{
    char name[20]; 
    char desc[100]; //제품이름 변수
    char weight[10];     //제품의 무게 변수
    int price;      //제품의 가격 변수
    int deliver;
} Product;
int selectMenu();
int addProduct(Product *p);   
void readProduct(Product p); 
int updateProduct(Product *p);
int deleteProduct(Product *p);
int saveData(Product *p, int count);
int loadData(Product *p);
int selectDataNo(int count);


