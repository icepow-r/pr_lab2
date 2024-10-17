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

int binary_search(int *arr, int value, int start, int end);

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

    int choice;

    do {
        cout << "Choose a task to execute (1-8) or 0 to exit: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                task_1();
                break;
            case 2:
                task_2();
                break;
            case 3:
                task_3();
                break;
            case 4:
                task_4();
                break;
            case 5:
                task_5();
                break;
            case 6:
                task_6();
                break;
            case 7:
                task_7();
                break;
            case 8:
                task_8();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a number from 0 to 8." << endl;
                break;
        }

    } while (choice != 0);

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

int binary_search(int *arr, int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binary_search(arr, value, start, mid - 1);
        }

        return binary_search(arr, value, mid + 1, end);
    }

    return -1;
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

    cout << "Sorted array:" << endl;
    copy_array(unsorted_array, sorted_array, N);
    quicksort(sorted_array, N - 1, 0);
    print_array(sorted_array, N);
}

void task_2() {
    cout << "--- task #2 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    bubble_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Bubble sort, ns:\t" << result_time.count() << endl;

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    shaker_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Shaker sort, ns:\t" << result_time.count() << endl;

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    comb_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Comb sort, ns  :\t" << result_time.count() << endl;

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    insertion_sort(sorted_array, N);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Insertion sort, ns:\t" << result_time.count() << endl;

    copy_array(unsorted_array, sorted_array, N);
    start_time = steady_clock::now();
    quicksort(sorted_array, N - 1, 0);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Quick sort, ns: \t" << result_time.count() << endl;
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

void task_5() {
    cout << "--- task #5 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    quicksort(sorted_array, N - 1, 0);
    int a, counter = 0;
    print_array(sorted_array, N);
    cout << "Enter number to count less elements: ";
    cin >> a;
    while (sorted_array[counter++] < a);
    cout << "Result: " << --counter << endl;
}

void task_6() {
    cout << "--- task #6 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    quicksort(sorted_array, N - 1, 0);
    int b, counter = N - 1;
    print_array(sorted_array, N);
    cout << "Enter number to count greater elements: ";
    cin >> b;
    while (sorted_array[counter--] > b);
    cout << "Result: " << N - counter - 2 << endl;
}

void task_7() {
    cout << "--- task #7 ----" << endl;
    copy_array(unsorted_array, sorted_array, N);
    quicksort(sorted_array, N - 1, 0);
    int number, index = -1;
    print_array(sorted_array, N);
    cout << "Enter number to search in array: ";
    cin >> number;

    start_time = steady_clock::now();
    for (int i = 0; i < N; ++i) {
        if (sorted_array[i] == number) {
            index = i + 1;
            break;
        }
    }
    end_time = steady_clock::now();

    if (index == -1) {
        cout << "Not found" << endl;
    } else {
        cout << "Found at " << index << " position" << endl;
    }
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time spent, simple search, ns: " << result_time.count() << endl;

    start_time = steady_clock::now();
    index = binary_search(sorted_array, number, 0, N - 1);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time spent, binary search, ns: " << result_time.count() << endl;
}

void task_8() {
    cout << "--- task #8 ----" << endl;
    cout << "Array:" << endl;
    print_array(unsorted_array, N);
    cout << "Enter two indexes for swap: ";
    int i1, i2;
    cin >> i1 >> i2;
    start_time = steady_clock::now();
    swap(unsorted_array[i1], unsorted_array[i2]);
    end_time = steady_clock::now();
    result_time = duration_cast<nanoseconds>(end_time - start_time);
    cout << "Time spent for swap, ns: " << result_time.count() << endl;
    cout << "New array:" << endl;
    print_array(unsorted_array, N);
}