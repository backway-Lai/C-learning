#include "lab52.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	GoodsList* list;
	init_list(&list);

	char id[MAX_ID_LEN] = { 0 };
	int x = 0;

	for (;;) {
        printf("1.显示所有商品的信息\n");
        printf("2.修改某个商品的信息\n");
        printf("3.插入某个商品的信息\n");
        printf("4.删除某个商品的信息\n");
        printf("5.查找某个商品的信息\n");
        printf("6.商品存盘并退出系统\n");
        printf("7.对商品价格进行排序\n");
        printf("8.(慎用)删除所有内容\n");
        printf("其他.不存盘并退出系统\n");

        int ope;
        scanf("%d", &ope);

        switch (ope) {
        case 1:
            output_all_items(list);
            break;

        case 2:
            printf("请输入要修改的商品id:\n");
            read_line(id, MAX_ID_LEN);
            printf("请输入商品新参数：\n");
            if (change_item(list, id, read_goods_info())) {
                printf("修改成功！\n");
            }
            else printf("修改失败!\n");
            memset(id, 0, sizeof(0));
            break;

        case 3:
            printf("0：插入到链表尾部\n");
            printf("1:插入到链表头部\n");
            printf("其他数字:插入到对应位置\n");
            scanf("%d", &x);
            printf("请输出商品参数：\n");

            if (insert_item(list, read_goods_info(), x)) printf("插入成功!\n");
            else printf("插入失败!\n");

            break;

        case 4:
            printf("请输出被删除商品id：\n");
            read_line(id, MAX_ID_LEN);
            if (delete_item(list, id)) printf("删除成功!\n");
            else printf("删除失败!\n");

            memset(id, 0, sizeof(0));
            break;

        case 5:
            printf("请输出被查找商品id:\n");
            read_line(id, MAX_ID_LEN);
            if (search_item(list, id) == NULL) printf("查找失败！\n");
            else {
                printf("查找成功！\n");
                output_one_item(search_item(list, id));
            }
            memset(id, 0, sizeof(0));
            break;

        case 6:
            save_to_file(list);
            return 0;

        case 7:
            bubble_sort(list);
            break;

        case 8:
            destory_list_and_file(&list);
            break;

        default:
            destory_list(&list);
            return 0;
        }
	}
}
