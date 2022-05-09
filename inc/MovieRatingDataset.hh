#ifndef MOVIE_RATING_DATASET
#define MOVIE_RATING_DATASET
#include <iostream>
#include <fstream>
#include <string>

class MovieRatingDataset
{
public:
    struct MovieRating
    {
        std::string title;
        int rating;
    };

private:
    std::string file_name;
    int size;
    MovieRating *data;

    // flag
    bool filtered = false;

public:
    MovieRatingDataset(std::string file_name_) : file_name(file_name_), size(file_length() - 2), data(load_data()) {}
    ~MovieRatingDataset() {}
    MovieRating &operator[](int index);
    int file_length();
    bool data_completion();
    void filter();
    MovieRating *load_data();
    int get_size() { return size; }
};

std::ostream &operator<<(std::ostream &strm, const MovieRatingDataset::MovieRating &elem);
#endif