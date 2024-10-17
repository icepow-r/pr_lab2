#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

const int N = 100;
int unsorted_array[N], sorted_array[N];
time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start_time, end_time;
nanoseconds result_time;

void bubble_sort(int *arr, int n);

void shaker_sort(int *arr, int n);

void comb_sort(int *arr, int n);

void insertion_sort(int *arr, int n);

void quicksort(int *arr, int end, int begin);

void print_array(int *arr, int n);

void copy_array(const int *src, int *dest, int n);

void task_1();

void task_2();

void task_3();

void task_4();

void task_5();

void task_6();

void task_7();

void task_8();


int main() {
    srand(time(nullptr));
    task_1();
    task_2();
    task_3();
    task_4();


}


void bubble_sort(int *arr, int n) {
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void shaker_sort(int *arr, int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

void comb_sort(int *arr, int n) {
    const double shrinkFactor = 1.247;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = gap / shrinkFactor;
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void insertion_sort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quicksort(int *arr, int end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l) {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l) {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copy_array(const int *src, int *dest, int n) {
    for (int i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
}

void task_1() {
    cout << "--- task #1 ----" << endl;
    for (int i = 0; i < N; ++i) {
        unsorted_array[i] = rand() % 199 - 99;
    }

    cout << "Unsorted array:" << endl;
    print_array(unsorted_array, N);
}

void task_2() {
    cout << "--- task #2 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    bubble_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Bubble sort, ns: " << result_time.count() << endl;
    //print_array(sorted_array, N);

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    shaker_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Shaker sort, ns: " << result_time.count() << endl;
    //print_array(sorted_array, N);

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    comb_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Comb sort, ns: " << result_time.count() << endl;
    //print_array(sorted_array, N);

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    insertion_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Insertion sort, ns: " << result_time.count() << endl;
    //print_array(sorted_array, N);

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    quicksort(sorted_array, N - 1, 0);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Quick sort, ns: " << result_time.count() << endl;
    //print_array(sorted_array, N);
}

void task_3() {
    cout << "--- task #3 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    quicksort(sorted_array, N - 1, 0);

    int min = 100, max = -100;

    start_time = steady_clock::now();
    for (int i = 0; i < N; ++i) {
        if (min > unsorted_array[i]) {
            min = unsorted_array[i];
        }
        if (max < unsorted_array[i]) {
            max = unsorted_array[i];
        }
    }
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Min: " << min << ", max: " << max << endl;
    cout << "Unsorted search min and max time, ns: " << result_time.count() << endl;

    start_time = steady_clock::now();
    min = sorted_array[0];
    max = sorted_array[N - 1];
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Min: " << min << ", max: " << max << endl;
    cout << "Sorted search min and max time, ns: " << result_time.count() << endl;
}

void task_4() {
    cout << "--- task #4 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    quicksort(sorted_array, N - 1, 0);
    int min = sorted_array[0], max = sorted_array[N - 1], count = 0;
    int average = (max + min) / 2;
    cout << "Average min and max value: " << average << endl;
    cout << "Indexes with same value, unsorted array: ";
    start_time = steady_clock::now();
    for (int i = 0; i < N; ++i) {
        if (unsorted_array[i] == average) {
            cout << i << " ";
            count++;
        }
    }
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << endl << "Indexes count: " << count << endl;
    cout << "Time spent in unsorted array, ns: " << result_time.count() << endl;

    count = 0;
    cout << "Indexes with same value, sorted array: ";
    start_time = steady_clock::now();
    for (int i = 0; sorted_array[i] <= average; ++i) {
        if (sorted_array[i] == average) {
            cout << i << " ";
            count++;
        }
    }
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << endl << "Indexes count: " << count << endl;
    cout << "Time spent in sorted array, ns: " << result_time.count() << endl;
}