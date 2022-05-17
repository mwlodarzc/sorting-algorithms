#ifndef MOVIE_RATING_HH
#define MOVIE_RATING_HH
#include <string>

class MovieRating
{
private:
    std::string title;
    int rating;

public:
    MovieRating() = default;
    MovieRating(std::string title_, int rating_) : title(title_), rating(rating_) {}
    int get_rating() { return rating; }
    void set_rating(int rating_) { rating = rating_; }
    const std::string &get_title() { return title; }
    void set_title(std::string title_) { title = title_; }
    bool operator>(const MovieRating &compared);
    bool operator>=(const MovieRating &compared);
    bool operator<(const MovieRating &compared);
    bool operator<=(const MovieRating &compared);
    bool operator==(const MovieRating &compared);
    bool operator==(int compared);
    bool operator!=(const MovieRating &compared);
    bool operator!=(int compared);
    double operator/(const MovieRating &compared);
    double operator*(const MovieRating &compared);
    double operator+(const MovieRating &added);
    double operator+=(double added);
    double operator+(double added);
    int operator+(int added);
    double operator-(double subtracted);
    int operator-(int subtracted);
    double operator*(double multiplied);
    int operator*(int multiplied);
    double operator/(double divided);
    double operator/(int divided);
};
double operator*(double multiplied, MovieRating data);
int operator*(int multiplied, MovieRating data);
double operator/(double multiplied, MovieRating data);
double operator/(int multiplied, MovieRating data);
#endif