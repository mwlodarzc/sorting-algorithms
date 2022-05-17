#include "MovieRating.hh"
bool MovieRating::operator>(const MovieRating &compared) { return rating > compared.rating; }
bool MovieRating::operator>=(const MovieRating &compared) { return rating >= compared.rating; }
bool MovieRating::operator<(const MovieRating &compared) { return rating < compared.rating; }
bool MovieRating::operator<=(const MovieRating &compared) { return rating <= compared.rating; }
bool MovieRating::operator==(const MovieRating &compared) { return rating == compared.rating; }
bool MovieRating::operator!=(const MovieRating &compared) { return rating != compared.rating; }
bool MovieRating::operator==(int compared) { return rating == compared; }
bool MovieRating::operator!=(int compared) { return rating != compared; }
double MovieRating::operator/(const MovieRating &compared) { return rating / compared.rating; }
double MovieRating::operator*(const MovieRating &compared) { return rating * compared.rating; }
double MovieRating::operator*(double multiplied) { return rating * multiplied; }
int MovieRating::operator*(int multiplied) { return rating * multiplied; }
double MovieRating::operator/(double divided) { return rating / divided; }
double MovieRating::operator/(int divided) { return rating / divided; }
int MovieRating::operator+(int added) { return rating + added; }
double MovieRating::operator+(double added) { return rating + added; }
double MovieRating::operator-(double subtracted) { return rating - subtracted; }
int MovieRating::operator-(int subtracted) { return rating - subtracted; }
double MovieRating::operator+=(double added) { return rating = rating + added; }
double MovieRating::operator+(const MovieRating &added) { return rating + added.rating; }

double operator*(double multiplied, MovieRating data) { return multiplied * data.get_rating(); }
int operator*(int multiplied, MovieRating data) { return multiplied * data.get_rating(); }
double operator/(double multiplied, MovieRating data) { return multiplied / data.get_rating(); }
double operator/(int multiplied, MovieRating data) { return multiplied / data.get_rating(); }
