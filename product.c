#include "product.h"

int selectMenu(){
    int menu;
    printf("\n*** product.c ***\n");
    printf("1. 제품 조회\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 수정\n");
    printf("4. 제품 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 제품 이름 검색\n");
    printf("7. 제품 가격대 검색\n");
    printf("8. 제품 배송방법 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addProduct(Product *p){ // 제품을 추가하는 함수 2
    printf("제품의 이름은? ");
    scanf(" %s", p->name);
    printf("제품의 중량은? ");
    scanf(" %s", p->weight);
    printf("제품의 가격은? ");
    scanf(" %d", &p->price);
    printf("제품 상세설명");
    scanf(" %s", p->desc);
    printf("제품의 배송방법? ");
    scanf(" %d", &p->deliver);
    return 1;
}

void readProduct(Product p){ // 하나의 제품 출력 함수
    printf("%6s %6s %6d %20s %6d\n", p.name, p.weight, p.price, p.desc, p.deliver);
}



int selectDataNo(int count){
    int no;
    printf("번호는? (취소:0)? ");
    scanf("%d", &no);
    return no;
}

int updateProduct(Product *p){ //제품 수정 3
    printf("제품의 새 이름은? ");
    scanf("%s", p->name);
    printf("제품의 새 중량은? ");
    scanf("%s", p->weight);
    printf("제품의 새 가격은? ");
    scanf(" %d", &p->price);
    printf("제품 상세설명");
    scanf(" %s", p->desc);
    printf("제품의 배송방법? ");
    scanf(" %d", &p->deliver);
    return 1;
}


int deleteProduct(Product *p){ // 제품 삭제 
    p->price = -1;
    printf("=> 삭제됨!\n");
    return 1;
}

int loadData(Product *p){ // 파일에서 불러오기
    FILE *fp = fopen("product.txt", "r");
    int i=0;
    if (fp == NULL)
        return 0;
    else{
        for (; i < 100; i++){
            if (feof(fp))
                break;
            fscanf(fp, "%s %s %d %s %d", p[i].name, p[i].weight, &p[i].price,p[i].desc, &p[i].deliver);
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    }
    return i;
}

int saveData(Product *p, int count)
{ //파일에 저장5
    FILE *fp = fopen("product.txt", "w");
    for (int i = 0; i < count; i++)
    {
        if (p[i].price == -1)
            continue;
        fprintf(fp, "%s %s %d %s %d\n",p[i].name, p[i].weight, p[i].price, p[i].desc, p[i].deliver);
    }
    fclose(fp);
    return 1;
}

