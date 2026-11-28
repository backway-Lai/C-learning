#include "lab52.h"
#include <stdio.h>
#include <stdlib.h>

extern int CurrentCnt;

void init_list(GoodsList** pL) {
    FILE* fp;
    GoodsInfo goodsinfo;
    GoodsList* p, * r;

    (*pL) = (GoodsList*)malloc(sizeof(GoodsList));
    r = (*pL);
    if ((fp = fopen(GOODS_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)
            printf("Cant read the file.\n");
    }
    else {
        while (!feof(fp)) {
            fscanf(fp, "%s", goodsinfo.goods_id);
            fscanf(fp, "\t%s", goodsinfo.goods_name);
            fscanf(fp, "\t%d", &goodsinfo.goods_price);
            fscanf(fp, "\t%s", goodsinfo.goods_discount);
            fscanf(fp, "\t%d", &goodsinfo.goods_amount);
            fscanf(fp, "\t%d\n", &goodsinfo.goods_remain);

            p = (GoodsList*)malloc(sizeof(GoodsList));
            p->data = goodsinfo;
            r->next = p;
            r = p;
            CurrentCnt++;

        }
    }
    fclose(fp);
    r->next = NULL;
    printf("商品列表已建立，有%d个商品\n", CurrentCnt);
}

bool insert_item(GoodsList* L, GoodsInfo item, int choice) {
    GoodsList* x = (GoodsList*)malloc(sizeof(GoodsList));
    GoodsList* p = L;
    x->data = item;

    if (choice == 0) {                                //尾插法
        for (;p->next != NULL;p = p->next)
            ;
        p->next = x;
        x->next = NULL;
        CurrentCnt++;
        return true;
    }

    /*if (choice == 1) {
        x->next = L->next->next;
        L->next = x;
        CurrentCnt++;
        return true;
    }*/ 

    if (choice < 0 || choice > CurrentCnt + 1) return false;

    if (choice > 0 && choice <= CurrentCnt + 1) { //正常插入(必要注释：choice == CurrentCnt时相当于尾插)
        for (int i = 1;i < choice;i++) {
            p = p->next;
        }

        x->next = p->next;
        p->next = x;
        CurrentCnt++;
        return true;
    }
}

bool delete_item(GoodsList* L, char* goods_id) {
    GoodsList* p = L;
    while (p->next != NULL) {
        GoodsList* n = p->next;
        if (!strcmp(n->data.goods_id, goods_id)) {
            p->next = n->next;
            free(n);
            CurrentCnt--;
            return true;
        }
        p = p->next;
    }
    return false;
}

GoodsList* search_item(GoodsList* L, char* goods_id) {
    GoodsList* p = L;
    while (p != NULL && strcmp(p->data.goods_id, goods_id)) {
        p = p->next;
    }
    return p;
}

bool change_item(GoodsList* L, char* goods_id, GoodsInfo new_info) {
    GoodsList* p = L;
    while (p != NULL && strcmp(p->data.goods_id, goods_id)) {       //可以调用search_item
        p = p->next;
    }
    if (p == NULL) return false;
    else p->data = new_info;
    return true;
}

void output_one_item(GoodsList* p) {
    printf("%s\t%s\t%d\t%s\t%d\t%d", p->data.goods_id, p->data.goods_name, p->data.goods_price, p->data.goods_discount, p->data.goods_amount, p->data.goods_remain);
}

void output_all_items(GoodsList* L) {
    GoodsList* p = L->next;
    while (p != NULL) {
        output_one_item(p);
        p = p->next;
    }
}

void destory_list(GoodsList** L) {
    GoodsList* p = (*L)->next;
    GoodsList* q = *L;

    for (;p != NULL;q = p, p = p->next) {
        free(q);
    }
    free(q);
    *L = NULL;

    CurrentCnt = 0;
}

void destory_list_and_file(GoodsList** L) {
    destory_list(L);

    remove("goodinfo.txt");
}

int save_to_file(GoodsList* L) {
    int number = 0;
    FILE* fp;

    if (L == NULL) return 0;

    GoodsList* p = L->next;
    if ((fp = fopen("goodsinfo.txt", "w")) == NULL) return 0;

    while (p != NULL) {
        fprintf(fp, "%s\t", p->data.goods_id);
        fprintf(fp, "%s\t", p->data.goods_name);
        fprintf(fp, "%d\t", p->data.goods_price);
        fprintf(fp, "%s\t", p->data.goods_discount);
        fprintf(fp, "%d\t", p->data.goods_amount);
        fprintf(fp, "%d\t", p->data.goods_remain);
        
        p = p->next;
        number++;
    }

    L = NULL;
    return number;
}

void bubble_sort(GoodsList* L) {
    if (CurrentCnt <= 1) return;

    for (int i = 1;i < CurrentCnt;i++) {
        for (GoodsList* j = L;j->next->next != NULL;j = j->next) {
            GoodsList* a = j->next;
            GoodsList* b = a->next;
            if (a->data.goods_price > b->data.goods_price) {
                GoodsList* temp = b->next;
                j->next = b;
                b->next = a;
                a->next = temp;
            }
        }
    }
}
