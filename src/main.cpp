#include "MovieRatingDataset.hh"
#include "Sort.hh"
#include "LinkedList.hh"
#include <iostream>
#include <fstream>
#include <chrono>
double median(MovieRating *data, int data_size)
{
    if ((data_size % 2) != 0)
        return data[(data_size - 1) / 2].get_rating();
    return ((double)data[(data_size / 2) - 1].get_rating() + (double)data[data_size / 2].get_rating()) / 2;
}

double mean(MovieRating *data, int data_size)
{
    double sum;
    for (int i = 0; i < data_size; i++)
    {
        sum += data[i].get_rating();
    }
    return sum / data_size;
}

template <typename T>
T *copy(const T *copied, int data_size)
{
    T *copy = new T[data_size];
    for (int i = 0; i < data_size; i++)
    {
        copy[i] = copied[i];
    }
    return copy;
}

void test_algorithms(MovieRatingDataset &data, int data_size, std::fstream &out_file)
{
    std::chrono::duration<double> elapsed;
    std::chrono::_V2::system_clock::time_point begin, end;
    MovieRating *tmp, *tested_data = data.n_random(data_size);

    tmp = copy<MovieRating>(tested_data, data_size);
    begin = std::chrono::high_resolution_clock::now();
    Sort::bucket_sort<MovieRating>(tmp, data_size, 10);
    end = std::chrono::high_resolution_clock::now();

    elapsed = begin - end;
    out_file << elapsed.count() << "," << Sort::check_sorted<MovieRating>(tmp, data_size) << ",";
    delete[] tmp;

    tmp = copy<MovieRating>(tested_data, data_size);
    begin = std::chrono::high_resolution_clock::now();
    Sort::quick_sort<MovieRating>(tmp, 0, data_size - 1);
    end = std::chrono::high_resolution_clock::now();

    elapsed = begin - end;
    out_file << elapsed.count() << "," << Sort::check_sorted<MovieRating>(tmp, data_size) << ",";
    delete[] tmp;

    tmp = copy<MovieRating>(tested_data, data_size);
    begin = std::chrono::high_resolution_clock::now();
    Sort::intro_sort<MovieRating>(tmp, data_size);
    end = std::chrono::high_resolution_clock::now();

    elapsed = begin - end;
    out_file << elapsed.count() << "," << Sort::check_sorted<MovieRating>(tmp, data_size) << ",";
    delete[] tmp;

    out_file << median(tested_data, data_size) << "," << mean(tested_data, data_size) << std::endl;
}

int main()
{

    std::string filename = "data/projekt2_dane.csv";
    MovieRatingDataset data(filename);
    int tested_size = 100;
    // MovieRating *tested_data = data.n_random(tested_size);
    // int test_size[] = {10000, 100000, 500000, 1000000};
    std::fstream output_file;
    // for (int i = 0; i < 4; i++)
    // {
    output_file.open("tests/test1", std::ios::app);
    if (!output_file)
    {
        std::cerr << "File doesnt exist!";
    }
    //     output_file << "bucket_sort, poprawny, quick_sort, poprawny, intro_sort-czas, poprawny, mediana_data, średnia_data" << std::endl;
    // }

    // for (int i = 0; i < tested_size; i++)
    // {
    //     std::cout << tested_data[i] << std::endl;
    // }
    // std::cout << std::endl;

    // std::cout << std::endl;
    // std::cout << *(data.get_data() + 2) << std::endl;
    // slice(data, 10);
    // Sort::intro_sort<int>(data, 20);

    // Sort::intro_sort<MovieRating>(tested_data, 100, 20);
    // std::cout << Sort::check_sorted<MovieRating>(tested_data, 100) << std::endl;

    // // std::cout << data [0..2:1] << std::endl;
    // std::cout << std::endl;
    test_algorithms(data, tested_size, output_file);

    // for (int i = 0; i < 100; i++)
    // {
    //     std::cout << tested_data[i] << std::endl;
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << tested_data[i] << std::endl;
    // }
    // std::cout << std::endl;

    // // // std::cout << std::endl;
    // int data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // std::cout << median(tested_data, tested_size) << " " << mean(tested_data, tested_size) << std::endl;
    // Sort::intro_sort<int>(data, 20);
    // std::cout << Sort::check_sorted<int>(data, 20) << std::endl;
    return EXIT_SUCCESS;
}

// template <typename T>
// void slice(T *data, int data_size)
// {
//     for (int i = 0; i < data_size; i++)
//     {
//         std::cout << data[i] << std::endl;
//     }
//     std::cout << std::endl;
//     int pivot;
//     pivot = data_size / 2;
//     std::cout << data_size << " " << pivot << std::endl;
//     std::cout << std::endl;
//     if (data_size > 1)
//     {
//         slice(data, pivot);
//         slice(data + pivot, data_size - (pivot));
//     }
// }