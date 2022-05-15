#ifndef SORT_HH
#define SORT_HH
#include "LinkedList.hh"
#include <vector>
#include <cmath>

namespace Sort
{
    template <typename T>
    void insertion_sort(T *data, int data_size)
    {
        T tmp;
        for (int i = 1; i < data_size; i++)
        {
            for (int j = i; j > 0 && data[j] < data[j - 1]; j--)
            {
                tmp = data[j - 1];
                data[j - 1] = data[j];
                data[j] = tmp;
            }
        }
    }

    // working
    // there is one unresolved thing i add plus 1 to maximum to make the maximum value less than the bucket_number;
    // std::cout << data[i] << " " << (int)std::floor(bucket_number * data[i] / max_key) << std::endl;
    // std::cout << buckets[i].front() << std::endl;
    // std::cout << std::endl;

    template <typename T>
    void bucket_sort(T *data, int size, int bucket_number)
    {
        LinkedList<T> *buckets = new LinkedList<T>[bucket_number];
        T max_key = data[0];
        for (int i = 1; i < size; i++)
        {
            if (max_key < data[i])
                max_key = data[i];
        }
        max_key += 1;
        for (int i = 0; i < size; i++)
        {
            buckets[(int)std::floor(bucket_number * data[i] / max_key)].addFront(data[i]);
        }
        for (int i = 0, j = 0; i < bucket_number; i++)
        {
            if (!buckets[i].empty())
                buckets[i].insertion_sort();
            while (!buckets[i].empty())
            {
                data[j] = buckets[i].front();
                buckets[i].removeFront();
                j++;
            }
        }
        delete[] buckets;
    }

    // run tests check if it works correctly try some shit
    template <typename T>
    void quick_sort(T *data, int low_index, int high_index)
    {
        int pivot_index, mid, left_index, right_index;
        T pivot, tmp;
        if (low_index >= 0 && high_index >= 0 && low_index < high_index)
        {
            // begin {partition}
            // begin {pivot search - Median-of-three}
            mid = (low_index + high_index) / 2;
            if (data[mid] < data[low_index])
            {
                tmp = data[low_index];
                data[low_index] = data[mid];
                data[mid] = tmp;
            }
            if (data[high_index] < data[low_index])
            {
                tmp = data[high_index];
                data[high_index] = data[low_index];
                data[low_index] = tmp;
            }
            if (data[mid] < data[high_index])
            {
                tmp = data[high_index];
                data[high_index] = data[mid];
                data[mid] = tmp;
            }
            pivot = data[high_index];
            // end {pivot search - Median-of-three}

            // begin {partition array into two}
            left_index = low_index - 1;
            right_index = high_index + 1;
            while (1)
            {
                do
                {
                    left_index += 1;
                } while (data[left_index] < pivot);
                do
                {
                    right_index -= 1;
                } while (data[right_index] > pivot);
                if (left_index >= right_index)
                {
                    pivot_index = right_index;
                    break;
                }
                tmp = data[left_index];
                data[left_index] = data[right_index];
                data[right_index] = tmp;
            }
            // end {partition array into two}
            // end {partition}

            // begin {sort partitions}
            quick_sort(data, low_index, pivot_index);
            quick_sort(data, pivot_index + 1, high_index);
            // end {sort partitions}
        }
    }

    template <typename T>
    void intro_sort(T *data, int low_index, int high_index)
    {
    }

    template <typename T>
    bool check_sorted(T *data, int data_size)
    {
        for (int i = 0; i < data_size - 1; i++)
        {
            if (data[i + 1] < data[i])
            {
                return false;
            }
        }
        return true;
    }
}

#endif