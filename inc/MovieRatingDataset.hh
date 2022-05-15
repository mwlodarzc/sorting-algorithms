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
        bool operator>(const MovieRating &compared);
        bool operator>=(const MovieRating &compared);
        bool operator<(const MovieRating &compared);
        bool operator<=(const MovieRating &compared);
        bool operator==(const MovieRating &compared);
        bool operator!=(const MovieRating &compared);
        double operator/(const MovieRating &compared);
        double operator*(const MovieRating &compared);
        double operator+=(double added);
        int operator+(int added);
        double operator+(double added);
        double operator*(double multiplied);
        int operator*(int multiplied);
        double operator/(double divided);
        double operator/(int divided);
    };

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
    bool data_completion();
    void filter();
    MovieRating *load_data();
    int size() { return data_size; }
};
std::ostream &operator<<(std::ostream &strm, const MovieRatingDataset::MovieRating &elem);
int operator*(double multiplied, MovieRatingDataset::MovieRating data);
int operator*(int multiplied, MovieRatingDataset::MovieRating data);
int operator/(double multiplied, MovieRatingDataset::MovieRating data);
int operator/(int multiplied, MovieRatingDataset::MovieRating data);

#endif