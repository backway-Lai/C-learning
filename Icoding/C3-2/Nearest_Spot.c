//结构：最近的点
//
//有三位直角坐标点的类型定义如下
//
//typedef struct {
//    double x, y, z;
//} point3D;
//要求补充完整求两点间距离平方函数和查询最近点函数。
//输入规则：输入在一行：第1个整数n是点的个数，接下来是n个三位坐标，最后一个查询点的坐标。
//输出形式：距离查询点最近的点的坐标。
//输入样例1：4 1 2 1 2 2 2 0 2 1 3 2 1 3 4 5    输出样例1：(2.0, 2.0, 2.0)
//输入样例2：4 1 2 1 2 2 2 0 2 1 3 2 1 1 0 0    输出样例2：(1.0, 2.0, 1.0)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} point3D;

double distance2(const point3D* a, const point3D* b);
int find_closest_point(const point3D* points, int n, const point3D* query);

#define MAXN 20       //保证测试用例输入0 <= n <= 20
point3D points[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf%lf", &points[i].x, &points[i].y, &points[i].z);

    point3D query;
    scanf("%lf%lf%lf", &query.x, &query.y, &query.z);
    int index = find_closest_point(points, n, &query);
    printf("(%.1lf,%.1lf,%.1lf)\n", points[index].x, points[index].y, points[index].z);
    return 0;
}

//请勿删除或修改此行以上的所有内容！！！
//你的代码写在TODO和END OF TODO之间

//计算点a和点b之间的距离的平方
double distance2(const point3D* a, const point3D* b) {
    // TODO
    double distance = (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z);
    return distance;
    // END OF TODO
}

//查询距离点query最近的点的下标。points数组中保存了n个点，query是查询的点。
int find_closest_point(const point3D* points, int n, const point3D* query) {
    // TODO 此函数中要调用distance2函数
    int index = 0;
    double distance = distance2(points, query);
    for (int i = 1;i < n;i++) {
        if (distance > distance2(&points[i], query)) {
            distance = distance2(&points[i], query);
            index = i;
        }
    }

    return index;
    // END OF TODO
}