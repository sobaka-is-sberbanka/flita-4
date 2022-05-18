#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

int main(void) {
    int count=0;
    scanf("%d", &count);
    char filename[32];
    sprintf(filename, "%d", count);
    FILE * fp = fopen(filename, "r");
    int ** data = malloc(count*sizeof(int *));
    for (int i=0; i<count; i++) data[i] = malloc(count*sizeof(int));
    for (int i=0; i<count; i++) {
        for (int k=0; k<=i; k++) {
            data[i][k] = fgetc(fp)-'0';
            data[k][i] = data[i][k];
            if (k==i) data[k][i] *= 2;
        }
    }
    //Считывание завершено.
    printf("Гони ребро в формате a=b, где а и b это вершины: ");
    int a, b;
    scanf("%d=%d", &a, &b);
    data[a][b] = 0;
    data[b][a] = 0;
    printf("\nНужное ребро удалено\n");
    printf("Крч работаем однако отсчёт первой части пошёл\n");
    int tmp[3]={0, 0, 0};
    time_t stop, start = clock();
    for (int i=0; i<count; i++) {
        for (int k=0; k<count; k++) {
            tmp[2]+=data[i][k];
        }
        if (tmp[2]>=tmp[1]) {
            tmp[1] = tmp[2];
            tmp[0] = i;
        }
        tmp[2]=0;
    }
    stop = clock();
    printf("Вершина с максимальной степенью - %d. Время выполнения - %lo", ++tmp[0], (stop-start)*1000/CLOCKS_PER_SEC);
    return 0;
}
