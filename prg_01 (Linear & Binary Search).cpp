#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void print_Array(int arr[], int n);
void lsearch(int arr[], int n, int Key);
void bsearch(int arr[], int n, int Key);

int main()
{
    int size, key, choice;
    printf("\nEnter the size of the array -> ");
    cin >> size;

    int arr[size];
    printf("Enter %d elements of the array -> \n", size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    print_Array(arr, size);

    cout << "Enter the Element to search -> ";
    cin >> key;

    printf("------Press 1 for Linear_Search-------\n------Press 2 for Binary_Search------\n");

    cout << "Enter your choice :: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        lsearch(arr, size, key);
        break;
    case 2:
        bsearch(arr, size, key);
        break;
    }

    return 0;
}

void print_Array(int arr[], int n)
{
    printf("The Array is -> {");
    for (int i = 0; i < n; i++)
    {
        if (i == (n - 1))
            cout << arr[i] << "}" << endl;

        else
            cout << arr[i] << ",";
    }
}

void lsearch(int arr[], int n, int Key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == Key)
        {

            cout << "The Element " << Key << " is found at INDEX ->" << i << endl;
            return;
        }
    }
    cout << Key << " is not present in the Array\n";
}

void bsearch(int arr[], int n, int Key)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == Key)
        {
            cout << "The Element " << Key << " is found at INDEX -> " << mid << endl;

            return;
        }

        if (arr[mid] > Key)
            end - mid - 1;

        else
            start = mid + 1;
    }

    cout << Key << " is not present in the Array\n";
}