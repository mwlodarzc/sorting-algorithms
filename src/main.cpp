#include "MovieRatingDataset.hh"
#include "Sort.hh"
#include "LinkedList.hh"
#include <iostream>

template <typename T>
void slice(T *data, int data_size)
{
    for (int i = 0; i < data_size; i++)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;
    int pivot;
    pivot = data_size / 2;
    std::cout << data_size << " " << pivot << std::endl;
    std::cout << std::endl;
    if (data_size > 1)
    {
        slice(data, pivot);
        slice(data + pivot, data_size - (pivot));
    }
}

int main()
{

    std::string filename = "larger_test.csv";
    MovieRatingDataset data(filename);
    // int data[] = {12, 8, 10, 3, 3, 6, 9, 9, 5, 6, 3, 8, 10, 3, 3, 6, 9, 9, 5, 6};

    // for (int i = 0; i < data.size(); i++)
    // {
    //     std::cout << data[i] << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << *(data.get_data() + 2) << std::endl;
    // slice(data, 10);
    // Sort::intro_sort<int>(data, 20);

    Sort::intro_sort<MovieRatingDataset::MovieRating>(data.get_data(), data.size());
    // // std::cout << data [0..2:1] << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;

    // // // std::cout << std::endl;
    // std::cout << Sort::check_sorted<int>(data, 20) << std::endl;

    std::cout << Sort::check_sorted<MovieRatingDataset::MovieRating>(data.get_data(), data.size()) << std::endl;

    return EXIT_SUCCESS;
}