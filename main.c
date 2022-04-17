#include "product.h"
#include "manager.h"

int main(void){
#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif
    Product plist[100];
    int count = 0, index = 0, menu;
    count = loadData(plist);
    index = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1 || menu == 3 || menu == 4 || menu == 5)
            if (count == 0)
                continue;
        if (menu == 1)
            listProduct(plist, count);
        else if (menu == 2){
            count += addProduct(&plist[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(index);
            printf("수정할 제품의 번호를 선택하시오. (취소:0)\n>> ");
            scanf(" %d", &no);
            if (no > 0)
                updateProduct(&plist[no - 1]);
        }
        else if (menu == 4){
            int no = selectDataNo(index);
            if (no > 0){
                int deleteok;
                printf("정말로 삭제하시겠습니까?(삭제:1)");
                scanf("%d", &deleteok);
                if (deleteok == 1)
                {
                    deleteProduct(&plist[no - 1]);
                    count--;
                }
            }
        }
        else if (menu == 5){
            if (saveData(plist, index))
                printf("저장됨!\n");
           
        }
	else if (menu == 6){
            searchProduct(plist, index);
        }
        else if (menu == 7){
            searchPrice(plist, index);
        }
        else if (menu == 8){
            searchDeliver(plist, index);
        }
    }
    return 0;
}
