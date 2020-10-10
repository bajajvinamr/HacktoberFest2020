#include <iostream>
using namespace std;

/**
 * Algorithm implementation
 * \param [in] array array to search in
 * \param [in] size length of array
 * \param [in] key key value to search for
 * \returns index where the key-value occurs in the array
 * \returns -1 if key-value not found
 */
int LinearSearch(int *array, int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == key)
        {
            return i;
        }
    }

    return -1;
}

/** main function */
int main()
{
    int size;
    cout << "\nEnter the size of the Array : ";
    cin >> size;

    int *array = new int[size];
    int key;

    // Input array
    cout << "\nEnter the Array of " << size << " numbers : ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "\nEnter the number to be searched : ";
    cin >> key;

    int index = LinearSearch(array, size, key);
    if (index != -1)
    {
        cout << "\nNumber found at index : " << index;
    }
    else
    {
        cout << "\nNot found";
    }

    delete[] array;
    return 0;
}