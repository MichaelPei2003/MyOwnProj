#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define K 3        //共有三种鸢尾花,即三个簇群
#define MAX_ROUNDS 100    //最大聚类次数

//鸢尾花结构体
struct Iris {
    double sl;    //sepalLength
    double sw;  //sepalWidth
    double pl;    //petalLength
    double pw;    //petalWidth
    int sp;        //species
    int id;        //predictID
};

int n = 132;        //数据总量
int test = 100;  //测试集数量
struct Iris flw[400];
int ct[K + 1] = {-1, -1, -1, -1};        //初始质心位置
struct Iris PreCenter[K + 1];    //上一个质心位置
struct Iris Center[K + 1];        //计算得新质心位置
int f = 1;

bool ReadData() {
    char s[20];
    printf("Reading file from ../data.txt...");
    FILE *fp = fopen("../data.txt", "rb"); //requires to be customized path
    if (!fp) {
        printf("Failed to open file!\n");
        return false;
    }

    int i;
    for (i = 0; i < n; i++) {
        fscanf(fp, "%lf,%lf,%lf,%lf,%s", &flw[i].sl, &flw[i].sw, &flw[i].pl, &flw[i].pw, s);
        if (!strcmp(s, "Iris-setosa")) flw[i].sp = 1;
        else if (!strcmp(s, "Iris-versicolor")) flw[i].sp = 2;
        else if (!strcmp(s, "Iris-virginica")) flw[i].sp = 3;
    }
    fclose(fp);
    return true;
}

void Exchange(int a, int b) {
    double f1;
    int f2;
    f1 = flw[a].sl;
    flw[a].sl = flw[b].sl;
    flw[b].sl = f1;
    f1 = flw[a].sw;
    flw[a].sw = flw[b].sw;
    flw[b].sw = f1;
    f1 = flw[a].pl;
    flw[a].pl = flw[b].pl;
    flw[b].pl = f1;
    f1 = flw[a].pw;
    flw[a].pw = flw[b].pw;
    flw[b].pw = f1;
    f2 = flw[a].sp;
    flw[a].sp = flw[b].sp;
    flw[b].sp = f2;
}

void DataProcess() {
    int k;
    printf("Processing data...\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        Exchange(i, rand() % n);
    }
    //set init center
    int d = 0;
    for (int i = 0; d < 3; i++) {
        if (ct[flw[i].sp] == -1) {
            ct[flw[i].sp] = i;
            flw[i].id = flw[i].sp;
            k = flw[i].id;
            PreCenter[k].sl = flw[i].sl;
            PreCenter[k].sw = flw[i].sw;
            PreCenter[k].pl = flw[i].pl;
            PreCenter[k].pw = flw[i].pw;

            Center[k].sl = flw[i].sl;
            Center[k].sw = flw[i].sw;
            Center[k].pl = flw[i].pl;
            Center[k].pw = flw[i].pw;
            d++;
        }
    }
    printf("Data precessing finished.\nCenter is %d %d %d\n", ct[1], ct[2], ct[3]);
}

double Distance(int i, int t) {
    double k;
    k = sqrt(pow(flw[i].sl - Center[t].sl, 2) + pow(flw[i].sw - Center[t].sw, 2) + pow(flw[i].pl - Center[t].pl, 2) +
             pow(flw[i].pw - Center[t].pw, 2));
    return k;
}

int Rank(double a, double b, double c) {
    if (a <= b && a <= c) return 1;
    else if (b <= a && b <= c) return 2;
    else if (c <= a && c <= b) return 3;
    return 0;
}

void PartAllPoint() {
    double a, b, c;
    for (int i = 0; i < test; i++) {
        a = Distance(i, 1);
        b = Distance(i, 2);
        c = Distance(i, 3);
        flw[i].id = Rank(a, b, c);
    }
}

void CalNewCenter() {
    double sum[4][5] = {0};
    double d[4] = {0};
    int k;
    for (int i = 1; i <= 3; i++) {
        PreCenter[i].sl = Center[i].sl;
        PreCenter[i].sw = Center[i].sw;
        PreCenter[i].pl = Center[i].pl;
        PreCenter[i].pw = Center[i].pw;
    }
    for (int j = 0; j < test; j++) {
        k = flw[j].id;
        sum[k][1] = sum[k][1] + flw[j].sl;
        sum[k][2] = sum[k][2] + flw[j].sw;
        sum[k][3] = sum[k][3] + flw[j].pl;
        sum[k][4] = sum[k][4] + flw[j].pw;
        d[k]++;
    }
    //refresh center
    for (int i = 1; i <= 3; i++) {
        Center[i].sl = sum[i][1] / d[i];
        Center[i].sw = sum[i][2] / d[i];
        Center[i].pl = sum[i][3] / d[i];
        Center[i].pw = sum[i][4] / d[i];
    }
}

int CompareCenter() {
    int i;
    for (i = 1; i <= 3; i++) {
        if (PreCenter[i].sl != Center[i].sl || PreCenter[i].sw != Center[i].sw || PreCenter[i].pl != Center[i].pl ||
            PreCenter[i].pw != Center[i].pw)
            break;
    }
    if (i == 4) return 0;
    return 1;
}

void KMeans() {
    printf("Clustering...\n");
    int rounds;
    for (rounds = 0; rounds < MAX_ROUNDS; rounds++) {
        //printf("\nRounds: %d\n", rounds + 1);
        PartAllPoint();
        CalNewCenter();
        f = CompareCenter();
        if (f == 0) {
            printf("Cluster finished. Round = %d\n", rounds + 1);
            break;
        }
    }
    if (rounds == MAX_ROUNDS)printf("Cluster unfinished. Round reached max(%d). \n", MAX_ROUNDS);
}

void PredictSp() {
    printf("\nClustering remaining data...\n");
    int correct = 0, incorrect = 0;
    double a, b, c;
    for (int i = test; i < n; i++) {
        a = Distance(i, 1);
        b = Distance(i, 2);
        c = Distance(i, 3);
        flw[i].id = Rank(a, b, c);
        if (flw[i].id == flw[i].sp) correct++;
        else incorrect++;
    }
    printf("Cluster finished. Total:%d, %d are correctly sorted, %d haven't been correctly sorted.\n", n - test, correct, incorrect);
    printf("Cluster accuracy: %lf %%", (double)correct / ((double)correct + (double)incorrect) * 100);
}

int main() {
    if (!ReadData()) return 0;
    DataProcess();
    KMeans();
    PredictSp();
    return 0;
}
