#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define n 10000

int Create();

void BubbleSort();

void Check();

void SelectionSort();

void MergeSort();

void MergeSortFunc();

void QuickSort();

void QuickSortFunc(int *arr, int low, int high);

static int a[n], z[n];
static int i, j, tmp;

int Create() {
    static unsigned int seed = 0;
    for (i = 0; i < n; i++) {
        seed++;
        srand((unsigned) time(NULL) + seed * seed);
        z[i] = rand();
    }
}

void BubbleSort() {
//    Create();
    for (i = 0; i < n; i++) {
        a[i] = z[i];
    }
    LARGE_INTEGER num;
    long long start, end, freq;
    QueryPerformanceFrequency(&num);
    freq = num.QuadPart;
    QueryPerformanceCounter(&num);
    start = num.QuadPart;
//    function here
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    Check();
//    end of function
    QueryPerformanceCounter(&num);
    end = num.QuadPart;
    printf("time.bubble=%d\n", (end - start) * 1000000 / freq);
}

void SelectionSort() {
//    Create();
    for (i = 0; i < n; i++) {
        a[i] = z[i];
    }
    LARGE_INTEGER num;
    long long start, end, freq;
    QueryPerformanceFrequency(&num);
    freq = num.QuadPart;
    QueryPerformanceCounter(&num);
    start = num.QuadPart;
//    function here
    for (i = 0; i < n - 1; i++) {
        int min = i;
        //search for minimum value
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        //swap to front
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
    Check();
//    end of function
    QueryPerformanceCounter(&num);
    end = num.QuadPart;
    printf("time.selection=%d\n", (end - start) * 1000000 / freq);//this value = second/1000000
}

void InsertionSort() {
//    Create();
    for (i = 0; i < n; i++) {
        a[i] = z[i];
    }
    LARGE_INTEGER num;
    long long start, end, freq;
    QueryPerformanceFrequency(&num);
    freq = num.QuadPart;
    QueryPerformanceCounter(&num);
    start = num.QuadPart;
//  function here
    for (i = 0; i < n; i++) {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp)) {
            a[j + 1] = a[j];
            j--;
        }
    }
    Check();
//  end of function
    QueryPerformanceCounter(&num);
    end = num.QuadPart;
    printf("time.insertion=%d\n", (end - start) * 1000000 / freq);
}

void MergeSort() {
//    Create();
    for (i = 0; i < n; i++) {
        a[i] = z[i];
    }
    LARGE_INTEGER num;
    long long start, end, freq;
    QueryPerformanceFrequency(&num);
    freq = num.QuadPart;
    QueryPerformanceCounter(&num);
    start = num.QuadPart;
//  function here
    MergeSortFunc();
    Check();
//  end of function
    QueryPerformanceCounter(&num);
    end = num.QuadPart;
    printf("time.merge=%d\n", (end - start) * 1000000 / freq);
}

int miner(int x, int y) {
    return x < y ? x : y;
}

void MergeSortFunc() {
    int *arr = a;
    int *b = (int *) malloc(n * sizeof(int));
    for (i = 1; i < n; i += i) {
        for (j = 0; j < n; j += i * 2) {
            int low = j, mid = miner(j + i, n), high = miner(j + i * 2, n);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
            while (start1 < end1)
                b[k++] = arr[start1++];
            while (start2 < end2)
                b[k++] = arr[start2++];
        }
        int *temp = arr;
        arr = b;
        b = temp;
    }
    if (arr != a) {
        for (i = 0; i < n; i++) b[i] = arr[i];
        b = arr;
    }
    free(b);
}

void QuickSort() {
//    Create();
    for (i = 0; i < n; i++) {
        a[i] = z[i];
    }
    LARGE_INTEGER num;
    long long start, end, freq;
    QueryPerformanceFrequency(&num);
    freq = num.QuadPart;
    QueryPerformanceCounter(&num);
    start = num.QuadPart;
//  function here
    QuickSortFunc(a, 0, n - 1);
    Check();
//  end of function
    QueryPerformanceCounter(&num);
    end = num.QuadPart;
    printf("time.quick=%d\n", (end - start) * 1000000 / freq);
}

void QuickSortFunc(int *arr, int low, int high) {
    if (low < high) {
        i = low;
        j = high;
        int k = arr[low];
        while (i < j) {
            while (i < j && arr[j] >= k) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            while (i < j && arr[i] < k) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
        }
        arr[i] = k;
        QuickSortFunc(arr, low, i - 1);
        QuickSortFunc(arr, i + 1, high);
    }
}

void Check() {
    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            printf("Incorrectly sorted.Exiting program.");
            exit(0);
        }
    }
}

int main() {
    Create();
    printf("n = %d\n", n);
//    BubbleSort();
    SelectionSort();
    InsertionSort();
    MergeSort();
//    QuickSort();
    a[10] = 10;
    a[9] = 11;
    for (i = 0; i < n; i++) {
        z[n-i-1] = a[i];
    }
    printf("\nSort a almost sorted list:\n");
    BubbleSort();
    SelectionSort();
    InsertionSort();
    MergeSort();
    QuickSort();
    printf("Unit 1/1000000sec");
}

//     Get time & check
/*
    LARGE_INTEGER  num;
    long long start,end,freq;
    QueryPerformanceFrequency(&num);
    freq=num.QuadPart;
    QueryPerformanceCounter(&num);
    start= num.QuadPart;
    //function here

    Check();
    //end of function
    QueryPerformanceCounter(&num);
    end= num.QuadPart;
    printf("time=%d\n",(end-start)*1000000/freq);//too little num if don’t *
*/
