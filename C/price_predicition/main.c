#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define bool int
#define false 0
#define true 1
struct Data {
    double CRIM;//城镇人均犯罪率
    double ZN;//住宅用地所占比例
    double INDUS;//城镇非商业用地的比例
    double CHAS;//是否临近查尔斯河,边界是河流为1，否则0
    double NOX;//一氧化氮浓度
    double RM;//住宅平均房间数
    double AGE;//1940年之前建成的自用房屋比例
    double DIS;//到波士顿5个中心区域的加权距离
    double RAD;//距离高速公路的便利指数
    double tax;//每10000美元的全值财产税率
    double PTRATIO;//城镇师生比例
    double B;//1000（Bk-0.63）^ 2，其中 Bk 指代城镇中黑人的比例
    double LSTAT;//低收入人群的比例
    double MEDV;//自住房的平均房价
};
struct Data data[510];
int dataNum;
double w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13;
double a;
double sumXXY[506];
double sumX[507];
double sumY[507];
double sumR[14];
double RMSE;

bool Inputs() {
    char fname[256];
    printf("File name:");
    scanf("%s", fname);
//    printf("\nNum of examples:\n");
//    scanf("%d", &dataNum);
    printf("Data num set default as 506.");
    dataNum = 506;
    FILE *fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return false;
    }
    for (int i = 0; i < dataNum; i++) {
        fscanf(fp, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &data[i].CRIM, &data[i].ZN, &data[i].INDUS,
               &data[i].CHAS, &data[i].NOX, &data[i].RM, &data[i].AGE, &data[i].DIS, &data[i].RAD, &data[i].tax,
               &data[i].PTRATIO, &data[i].B, &data[i].LSTAT, &data[i].MEDV);
    }
    fclose(fp);
    return true;
}

double tezhengzhi[510][15];

void Init1() {
    a = 1e-7;
    w0 = w1 = w2 = w3 = w4 = w5 = w6 = w7 = w8 = w9 = w10 = w11 = w12 = w13 = 1;
    for (int i = 0; i < 510; i++) {
        tezhengzhi[i][0] = 1;
        tezhengzhi[i][1] = data[i].CRIM;
        tezhengzhi[i][2] = data[i].ZN;
        tezhengzhi[i][3] = data[i].INDUS;
        tezhengzhi[i][4] = data[i].CHAS;
        tezhengzhi[i][5] = data[i].NOX;
        tezhengzhi[i][6] = data[i].RM;
        tezhengzhi[i][7] = data[i].AGE;
        tezhengzhi[i][8] = data[i].DIS;
        tezhengzhi[i][9] = data[i].RAD;
        tezhengzhi[i][10] = data[i].tax;
        tezhengzhi[i][11] = data[i].PTRATIO;
        tezhengzhi[i][12] = data[i].B;
        tezhengzhi[i][13] = data[i].LSTAT;
        tezhengzhi[i][14] = data[i].MEDV;
    }
}

void Init2() {
    for (int i = 0; i < 450; i++) {
        sumXXY[i] =
                w0 + w1 * data[i].CRIM + w2 * data[i].ZN + w3 * data[i].INDUS + w4 * data[i].CHAS + w5 * data[i].NOX +
                w6 * data[i].RM + w7 * data[i].AGE + w8 * data[i].DIS + w9 * data[i].RAD + w10 * data[i].tax +
                w11 * data[i].PTRATIO + w12 * data[i].B + w13 * data[i].LSTAT;
    }
}

double LineReg(double w, int i) {
    double sum1 = 0;
    double temp1;
    for (int j = 0; j < 400; j++) {
        temp1 = (sumXXY[j] - tezhengzhi[j][14]) * tezhengzhi[j][i];
        sum1 += temp1;
    }
    w = w - a / 400 * sum1;
    return w;
}

void Init3() {
    for (int i = 450; i < 506; i++) {
        sumXXY[i] =
                w0 + w1 * data[i].CRIM + w2 * data[i].ZN + w3 * data[i].INDUS + w4 * data[i].CHAS + w5 * data[i].NOX +
                w6 * data[i].RM + w7 * data[i].AGE + w8 * data[i].DIS + w9 * data[i].RAD + w10 * data[i].tax +
                w11 * data[i].PTRATIO + w12 * data[i].B + w13 * data[i].LSTAT;
    }
}

void Init4(int m) {
    double ave = 0;
    for (int i = 0; i < 506; i++) {
        sumX[i] = tezhengzhi[i][m];
        ave += tezhengzhi[i][m];
    }
    ave /= 506;
    for (int j = 0; j < 506; j++) {
        sumX[j] = sumX[j] - ave;
    }
}

void Init5() {
    double ave = 0;
    for (int i = 0; i < 506; i++) {
        sumY[i] = tezhengzhi[i][14];
        ave += sumY[i];
    }
    ave /= 506;
    for (int j = 0; j < 506; j++) {
        sumY[j] = sumY[j] - ave;
    }
}

void Init6() {
    for (int i = 0; i < 400; i++) {
        sumXXY[i] = w1 * data[i].CRIM + w2 * data[i].ZN + w10 * data[i].tax + w11 * data[i].PTRATIO + w0;
    }
}

void Init7() {
    for (int i = 400; i < 506; i++) {
        sumXXY[i] = w1 * data[i].CRIM + w2 * data[i].ZN + w10 * data[i].tax + w11 * data[i].PTRATIO + w0;
    }
}

int main() {
    Inputs();
    Init1();
    Init2();
    for (int i = 1; i < 550000; i++) {
        w0 = LineReg(w0, 0);
        w1 = LineReg(w1, 1);
        w2 = LineReg(w2, 2);
        w3 = LineReg(w3, 3);
        w4 = LineReg(w4, 4);
        w5 = LineReg(w5, 5);
        w6 = LineReg(w6, 6);
        w7 = LineReg(w7, 7);
        w8 = LineReg(w8, 8);
        w9 = LineReg(w9, 9);
        w10 = LineReg(w10, 10);
        w11 = LineReg(w11, 11);
        w12 = LineReg(w12, 12);
        w13 = LineReg(w13, 13);
        Init2();
    }
    Init3();
    double sum2 = 0;
    double temp2;
    for (int i = 400; i < 506; i++) {
        temp2 = sumXXY[i] - tezhengzhi[i][14];
        temp2 = temp2 * temp2;
        sum2 += temp2;
    }
    sum2 = sum2 / 106;
    RMSE = sqrt(sum2);
    printf("Calculated W:\n");
    printf("w0=%lf\nw1=%lf\nw2=%lf\nw3=%lf\nw4=%lf\nw5=%lf\nw6=%lf\nw7=%lf\nw8=%lf\nw9=%lf\nw10=%lf\nw11=%lf\nw12=%lf\nw13=%lf\n",
           w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13);
    printf("Mean sqrt:%lf\n", RMSE);
    Init5();
    double sum3 = 0;
    double temp3;
    double sum4 = 0;
    double temp4 = 0, temp5 = 0;
    for (int i = 0; i < 14; i++) {
        Init4(i);
        for (int j = 0; j < 506; j++) {
            temp3 = sumX[j] * sumY[j];
            sum3 += temp3;
        }
        for (int k = 0; k < 506; k++) {
            temp4 += sumX[k] * sumX[k];
            temp5 += sumY[k] * sumY[k];
        }
        sum4 = temp4 * temp5;
        sum4 = sqrt(sum4);
        sumR[i] = sum3 / sum4;
    }
    printf("Calculated Pearson correlation coefficient of each variable:\n");
    for (int i = 0; i < 14; i++) {
        printf("w%d=%lf\n", i, sumR[i]);
    }
    Init6();
    for (int i = 0; i < 7000000; i++) {
        w1 = LineReg(w1, 1);
        w2 = LineReg(w2, 2);
        w10 = LineReg(w10, 10);
        w11 = LineReg(w11, 11);
        w0 = LineReg(w0, 0);
        Init6();
    }
    Init7();
    for (int i = 400; i < 506; i++) {
        temp2 = sumXXY[i] - tezhengzhi[i][14];
        temp2 = temp2 * temp2;
        sum2 += temp2;
    }
    sum2 = sum2 / 106;
    RMSE = sqrt(sum2);
    printf("Calculated W:\n");
    printf("w0=%lf\nw1=%lf\nw2=%lf\nw10=%lf\nw11=%lf\n", w0, w1, w2, w10, w11);
    printf("Mean sqrt:%lf\n", RMSE);
    return 0;
}
