#include <stdio.h>
#include <stdlib.h>
#include "lab52.h" // 请不要删除本行头文件，否则检查不通过

int main() {
    GoodsList goodlist;
    GoodsList* L = &goodlist;
    GoodsList** pL = &L;
    init_list(pL);

    int choice;

    while (scanf("%d", &choice)) {
        switch (choice) {
        case 1:
            output_all_items(L);
            break;
        case 2:

        }
    }
}