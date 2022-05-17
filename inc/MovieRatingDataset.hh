#ifndef MOVIE_RATING_DATASET
#define MOVIE_RATING_DATASET
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MovieRating.hh"
#include "Sort.hh"

class MovieRatingDataset
{
private:
    std::string file_name;
    int data_size;
    MovieRating *data;

public:
    MovieRatingDataset(std::string file_name_) : file_name(file_name_), data_size(file_length() - 2), data(load_data()) {}
    ~MovieRatingDataset() { delete[] data; }
    MovieRating &operator[](int index);
    MovieRating *get_data() { return data; }
    int file_length();
    MovieRating *load_data();
    int size() { return data_size; }
    void set_size(int size) { data_size = size; }
    MovieRating *n_random(int n);
};
std::ostream &operator<<(std::ostream &strm, MovieRating &elem);

#endif