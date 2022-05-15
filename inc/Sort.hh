#ifndef SORT_HH
#define SORT_HH
#include "LinkedList.hh"
#include <vector>
#include <cmath>

namespace Sort
{
    template <typename T>
    void swap(T &first, T &second)
    {
        T tmp = second;
        second = first;
        first = tmp;
    }

    template <typename T>
    void insertion_sort(T *data, int data_size)
    {
        for (int i = 1; i < data_size; i++)
        {
            for (int j = i; j > 0 && data[j] < data[j - 1]; j--)
            {
                swap(data[j - 1], data[j]);
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

    template <typename T>
    T median_of_three(T *data, int begin_index, int end_index)
    {
        int mid;
        // begin {pivot search - Median-of-three}
        mid = (begin_index + end_index) / 2;
        if (data[mid] < data[begin_index])
            swap(data[begin_index], data[mid]);
        if (data[end_index] < data[begin_index])
            swap(data[end_index], data[begin_index]);
        if (data[mid] < data[end_index])
            swap(data[end_index], data[mid]);
        return data[end_index];
        // end {pivot search - Median-of-three}
    }
    template <typename T>
    int partition(T *data, int begin_index, int end_index)
    {
        int left_index, right_index;
        T pivot;
        pivot = median_of_three(data, begin_index, end_index);

        // begin {partition array into two}
        left_index = begin_index - 1;
        right_index = end_index + 1;
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
                return right_index;
            swap(data[left_index], data[right_index]);
        }
        // end {partition array into two}
    }

    // run tests check if it works correctly try some shit
    template <typename T>
    void quick_sort(T *data, int begin_index, int end_index)
    {
        int pivot_index;
        if (begin_index >= 0 && end_index >= 0 && begin_index < end_index)
        {
            pivot_index = partition(data, begin_index, end_index);
            quick_sort(data, begin_index, pivot_index);
            quick_sort(data, pivot_index + 1, end_index);
        }
    }

    template <typename T>
    void sift_down(T *data, int begin_index, int end_index)
    {
        int swap_index, child_index, root_index;
        root_index = begin_index;
        while ((2 * root_index + 1) <= end_index)
        {
            child_index = (2 * root_index + 1);
            swap_index = root_index;
            if (data[swap_index] < data[child_index])
                swap_index = child_index;
            if (child_index + 1 <= end_index && data[swap_index] < data[child_index + 1])
                swap_index = child_index + 1;
            if (swap_index == root_index)
                return;
            else
            {
                swap(data[root_index], data[swap_index]);
                root_index = swap_index;
            }
        }
    }
    template <typename T>
    void heapify(T *data, int data_size)
    {
        int begin_index, end_index;
        end_index = data_size - 1;
        begin_index = (int)std::floor((end_index - 1) / 2);
        while (begin_index >= 0)
        {
            sift_down(data, begin_index, end_index);
            begin_index -= 1;
        }
    }

    template <typename T>
    void heap_sort(T *data, int data_size)
    {
        int end_index;
        heapify(data, data_size);
        end_index = data_size - 1;
        while (end_index > 0)

        {
            swap(data[end_index], data[0]);
            end_index -= 1;
            sift_down(data, 0, end_index);
        }
    }

    template <typename T>
    void intro_sort(T *data, int data_size, int begin_index = 0, int maximum_depth = 0)
    {
        int pivot_index;
        if (begin_index >= 0 && data_size > 0 && begin_index < data_size - 1)
        {
            if (maximum_depth == 0)
                maximum_depth = std::floor(std::log2(data_size)) * 2;
            if (data_size < 16)
                insertion_sort(data, data_size);
            else if (maximum_depth == 0)
                heap_sort(data, data_size);
            else
            {
                pivot_index = partition(data, 0, data_size - 1);
                intro_sort(data, pivot_index + 1, 0, maximum_depth - 1);
                intro_sort(data, data_size - (pivot_index + 1) + 1, pivot_index, maximum_depth - 1);
            }
        }
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