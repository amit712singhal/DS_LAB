// To implement Sorting  techniques using array.
//(Insertion sort, Merge sort, Quick sort, Bubble sort, Bucket sort, Radix sort, Shell sort, Selection sort, Heap sort and Exchange sort).

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void bucketSort(float arr[], int n)
{
    vector<float> buckets[n];

    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        buckets[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp)
{
    const int BASE = 10;
    int output[n];
    int count[BASE] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % BASE]++;

    for (int i = 1; i < BASE; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\n------------ Original array ------------" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, n);
    cout << "Insertion Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);
    cout << "Merge Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);
    cout << "Quick Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bubbleSort(arr, n);
    cout << "Bubble Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);
    cout << "Radix Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    shellSort(arr, n);
    cout << "Shell Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    selectionSort(arr, n);
    cout << "Selection Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);
    cout << "Heap Sort => ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    float floatArr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int floatArrSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "---------- Original float array ---------" << endl;
    for (int i = 0; i < floatArrSize; i++)
        cout << floatArr[i] << " ";
    cout << endl;

    bucketSort(floatArr, floatArrSize);
    cout << "Bucket Sort (on float array) => ";
    for (int i = 0; i < floatArrSize; i++)
        cout << floatArr[i] << " ";
    cout << endl;

    return 0;
}