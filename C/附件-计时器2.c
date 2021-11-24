#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10000000
#define N 10

short a[M][N];
void assign_array_rows()
{
    int i, j;
        for (i = 0; i<M; i++)
            for (j = 0; j<N; j++)
                a[i][j] = 0;
}
void assign_array_cols()
{
    int i, j;

        for (j = 0; j<N; j++)
            for (i = 0; i<M; i++)
                a[i][j] = 0;
}

int main()
{
    clock_t start, finish;
    double  duration;

    start = clock();
    assign_array_rows();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("��������ʱ�� %f seconds\n", duration);

    start = clock();
    assign_array_cols();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("��������ʱ�� %f seconds\n", duration);

    system("pause");
    return 0;
}

