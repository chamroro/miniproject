#include "manager.h"

int listProduct(Product *p, int count){ //전체 등록된 제품 리스트 출력1
    int i = 0;
    printf("NO 제품명 중량 가격 제품설명 배송\n ");
    for (i = 0; i < count; i++){
        if (p[i].price == -1)
            continue;
        printf("%d ", i + 1);
        readProduct(p[i]); 
    }
    return 1;

}

void searchProduct(Product *p, int count){ //제품이름 검색6
    char sname[20];
    printf("검색할 이름은? ");
    scanf(" %s", sname);
    printf("제품명 중량 가격 제품설명 배송\n ");
    for (int i = 0; i < count; i++){
        if (p[i].price == -1)
            continue;
        if (strstr(p[i].name, sname) != NULL){
            readProduct(p[i]);
        }
    }
    return;
}

void searchPrice(Product *p, int count){ //가격대 검색7
    int w1, w2;
    printf("검색할 가격대는?(00원 이상 00원 이하)");
    scanf(" %d %d", &w1, &w2);
    printf("제품명 중량 가격 제품설명 배송\n ");
    for (int i = 0; i < count; i++){
        if (p[i].price == -1)
            continue;
        if (w1 <= p[i].price && p[i].price <= w2){
            readProduct(p[i]);
        }
    }
    return;
}

void searchDeliver(Product *p, int count){ //별점기준 검색8
    int s1;
    printf("검색할 배송목록은? (1:새벽배송 /2:택배배송) ");
    scanf("%d", &s1);
    printf("제품명 중량 가격 제품설명 배송\n ");
    for (int i = 0; i < count; i++){
        if (p[i].price == -1)
            continue;
        else if (s1 == p[i].deliver){
            readProduct(p[i]);
        }
    }
    return;
}
