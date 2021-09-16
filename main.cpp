#include <iostream>
using namespace std;

class MergeSort{

public:


void merge (int array[], int front, int mid, int rear);
void mergeSort(int array[], int front2, int rear2);
void print (int array[], int size);

};

void MergeSort::merge(int array[], int front, int mid, int rear)
{
    int n1 = mid - front + 1;
    int n2 = rear - mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[front + i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = array[mid+1+j];
    }

    //Maintain current indes of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = front;

    //until we reach either end of either L or M, pick larger among
    //elements L and M and place them in the correct position at A[front...rear]

    while(i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    //when we run out of elements in either L or M,
    //pick up the remaining elements and put in A[front..rear]

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = M[j];
        j++;
        k++;
    }

}

//divide the array ito two sub arrays, sort them and merge them
void MergeSort::mergeSort(int array[], int front, int rear)
{
    if (front < rear)
    {
        //m is the middle point where the array is divided into two subarrays

        int mid = front + (rear - front)/2;

        mergeSort(array,front,mid);
        mergeSort(array,mid + 1, rear);

        //merge the sorted subarrays

        merge(array, front, mid, rear);
    }
}

//print the array
void MergeSort::print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
int array[] = {5,1,4,2,3}, size = sizeof(array)/sizeof(array[0]);

//0 = front of array, size - 1 = rear of array

MergeSort m;

m.mergeSort(array, 0, size - 1); //sort the array within int main.
m.print(array, size); //display sorted array


    return 0;
}
