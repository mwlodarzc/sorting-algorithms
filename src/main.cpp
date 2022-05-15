#include "MovieRatingDataset.hh"
#include "Sort.hh"
#include "LinkedList.hh"
#include <iostream>

int main()
{

    std::string filename = "test.csv";
    MovieRatingDataset data(filename);
    // int data[] = {3, 8, 10, 3, 3, 6, 9, 9, 5, 6};

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;

    Sort::intro_sort<MovieRatingDataset::MovieRating>(data.get_data(), data.size());
    std::cout << std::endl;
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;

    // // std::cout << std::endl;
    // std::cout << Sort::check_sorted<MovieRatingDataset::MovieRating>(data.get_data(), data.size()) << std::endl;

    return EXIT_SUCCESS;
}