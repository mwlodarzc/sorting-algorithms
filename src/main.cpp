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

    elapsed = end - begin;
    out_file << elapsed.count() << "," << Sort::check_sorted<MovieRating>(tmp, data_size) << ",";
    delete[] tmp;

    tmp = copy<MovieRating>(tested_data, data_size);
    begin = std::chrono::high_resolution_clock::now();
    Sort::quick_sort<MovieRating>(tmp, 0, data_size - 1);
    end = std::chrono::high_resolution_clock::now();

    elapsed = end - begin;
    out_file << elapsed.count() << "," << Sort::check_sorted<MovieRating>(tmp, data_size) << ",";
    delete[] tmp;

    tmp = copy<MovieRating>(tested_data, data_size);
    begin = std::chrono::high_resolution_clock::now();
    Sort::intro_sort<MovieRating>(tmp, data_size);
    end = std::chrono::high_resolution_clock::now();

    elapsed = end - begin;
    out_file << elapsed.count() << "," << Sort::check_sorted<MovieRating>(tmp, data_size) << ",";
    std::cout << median(tmp, data_size) << "," << mean(tmp, data_size) << std::endl;
    delete[] tmp;
    delete[] tested_data;
}

int main()
{
    std::chrono::duration<double> elapsed;
    std::chrono::_V2::system_clock::time_point begin, bf, end, ef;
    std::string outname = "tests_HP/test_size_", filename = "data/projekt2_dane.csv";
    MovieRatingDataset data(filename);
    MovieRating *test;
    int test_size[] = {10000, 100000, 500000, 1000000, data.size()};
    int filter_size;
    std::fstream output_file, program_runtime;
    int data_size_number = 5, test_tries_number = 30;

    program_runtime.open("tests_HP/program_runtime.txt", std::ios::app);
    if (!program_runtime)
        std::cerr << "File doesnt exist!";
    // ###################################################################################
    // ################## PKT.1 - FILTROWANIE DANYCH #####################################
    // ###################################################################################
    begin = std::chrono::high_resolution_clock::now();
    output_file.open("tests/filtrowanie.txt", std::ios::app);
    if (!output_file)
        std::cerr << "File doesnt exist!";
    for (int i = 0; i < data_size_number; i++)
    {
        filter_size = test_size[i];
        test = data.n_random(filter_size);
        bf = std::chrono::high_resolution_clock::now();
        filter_size = (Sort::filter(test, filter_size));
        ef = std::chrono::high_resolution_clock::now();
        output_file << "Done " << test_size[i] << " " << filter_size << ": " << Sort::complete(test, filter_size) << std::endl;
        elapsed = ef - bf;
        output_file << "Czas filtrowania: " << elapsed.count() << std::endl;
        delete[] test;
    }
    output_file.close();
    // ###################################################################################
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - begin;
    program_runtime << "Czas filtrowania danych: " << elapsed.count() << std::endl;
    // ###################################################################################
    // ################## PKT.2 - ANALIZA EFEKTYWNOŚCI SORTOWANIA ########################
    // ###################################################################################
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < data_size_number; i++)
    {
        output_file.open(outname + std::to_string(test_size[i]) + ".txt", std::ios::app);
        if (!output_file)
            std::cerr << "File doesnt exist!";
        output_file << "bucket_sort, poprawny, quick_sort, poprawny, intro_sort-czas, poprawny, mediana_data, średnia_data" << std::endl;
        for (int j = 0; j < test_tries_number; j++)
            test_algorithms(data, test_size[i], output_file);

        output_file.close();
    }
    end = std::chrono::high_resolution_clock::now();
    // ###################################################################################
    elapsed = end - begin;
    program_runtime << "Czas analizy efektywności: " << elapsed.count() << std::endl;
    program_runtime.close();
    return EXIT_SUCCESS;
}
