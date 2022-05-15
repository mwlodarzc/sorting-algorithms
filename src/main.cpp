#include "MovieRatingDataset.hh"
#include "Sort.hh"
#include "LinkedList.hh"
#include <iostream>

int median(int *data, int size)
{
    int first = 0, last = size - 1;
    int mid = (first + last) / 2;
    int tmp;
    if (data[mid] < data[first])
    {
        tmp = data[first];
        data[first] = data[mid];
        data[mid] = tmp;
    }
    if (data[last] < data[first])
    {
        tmp = data[last];
        data[last] = data[first];
        data[first] = tmp;
    }
    if (data[mid] < data[last])
    {
        tmp = data[last];
        data[last] = data[mid];
        data[mid] = tmp;
    }
    return data[last];
}

int main()
{

    std::string filename = "test.csv";
    MovieRatingDataset data(filename);
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
    // int data[] = {9, 56, 28, 47, 32, 29, 16, 45, 50, 25, 96, 88, 50, 11, 72, 22, 17, 10, 33, 40};

    Sort::quicksort<MovieRatingDataset::MovieRating>(data.get_data(), 0, data.size() - 1);
    std::cout << std::endl;
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;

    // std::cout << std::endl;
    std::cout << Sort::check_sorted<MovieRatingDataset::MovieRating>(data.get_data(), data.size()) << std::endl;

    // LinkedList<int> *buckets = new LinkedList<int>[2];
    // LinkedList<int> list;
    // list.addFront(1);
    // list.insertion_sort();
    // while (!list.empty())
    // {
    //     std::cout << list.front() << std::endl;
    //     list.removeFront();
    // }

    // int *arr = new int[21];
    // buckets[0].addFront(1);
    // buckets[0].addFront(2);
    // buckets[0].addFront(3);
    // buckets[0].addFront(4);
    // buckets[0].addFront(5);
    // buckets[0].addFront(6);
    // buckets[0].addFront(7);
    // buckets[0].addFront(8);
    // buckets[0].addFront(9);
    // buckets[0].addFront(10);

    // buckets[1].addFront(20);
    // buckets[1].addFront(19);
    // buckets[1].addFront(18);
    // buckets[1].addFront(19);
    // buckets[1].addFront(16);
    // buckets[1].addFront(15);
    // buckets[1].addFront(14);
    // buckets[1].addFront(13);
    // buckets[1].addFront(12);
    // buckets[1].addFront(11);
    // for (int i = 0, j = 0; i < 2; i++)
    // {
    //     buckets[i].insertion_sort();

    //     while (!buckets[i].empty())
    //     {
    //         std::cout << (arr[j] = buckets[i].front()) << std::endl;
    //         buckets[i].removeFront();
    //         j++;
    //     }
    // }
    // for (int i = 0; i < 20; i++)
    // {
    //     std::cout << data[i] << std::endl;
    // }

    return EXIT_SUCCESS;
}