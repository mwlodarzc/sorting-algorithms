#include "MovieRatingDataset.hh"

bool MovieRatingDataset::MovieRating::operator>(const MovieRating &compared)
{
    if (rating > compared.rating)
        return true;
    return false;
}
bool MovieRatingDataset::MovieRating::operator>=(const MovieRating &compared)
{
    if (rating >= compared.rating)
        return true;
    return false;
}
bool MovieRatingDataset::MovieRating::operator<(const MovieRating &compared)
{
    if (rating < compared.rating)
        return true;
    return false;
}
bool MovieRatingDataset::MovieRating::operator<=(const MovieRating &compared)
{
    if (rating <= compared.rating)
        return true;
    return false;
}
bool MovieRatingDataset::MovieRating::operator==(const MovieRating &compared)
{
    if (rating == compared.rating)
        return true;
    return false;
}
bool MovieRatingDataset::MovieRating::operator!=(const MovieRating &compared)
{
    if (rating != compared.rating)
        return true;
    return false;
}

double MovieRatingDataset::MovieRating::operator/(const MovieRating &compared) { return rating / compared.rating; }
double MovieRatingDataset::MovieRating::operator*(const MovieRating &compared) { return rating * compared.rating; }
double MovieRatingDataset::MovieRating::operator*(double multiplied) { return rating * multiplied; }
int MovieRatingDataset::MovieRating::operator*(int multiplied) { return rating * multiplied; }
double MovieRatingDataset::MovieRating::operator/(double divided) { return rating / divided; }
double MovieRatingDataset::MovieRating::operator/(int divided) { return rating / divided; }
int MovieRatingDataset::MovieRating::operator+(int added) { return rating + added; }
double MovieRatingDataset::MovieRating::operator+(double added) { return rating + added; }
double MovieRatingDataset::MovieRating::operator+=(double added) { return rating = rating + added; }
int operator*(double multiplied, MovieRatingDataset::MovieRating data) { return multiplied * data.rating; }
int operator*(int multiplied, MovieRatingDataset::MovieRating data) { return multiplied * data.rating; }
int operator/(double multiplied, MovieRatingDataset::MovieRating data) { return multiplied / data.rating; }
int operator/(int multiplied, MovieRatingDataset::MovieRating data) { return multiplied / data.rating; }

std::ostream &
operator<<(std::ostream &strm, const MovieRatingDataset::MovieRating &elem)
{
    strm << elem.title << " " << elem.rating;
    return strm;
}

MovieRatingDataset::MovieRating &MovieRatingDataset::operator[](int index)
{
    if (index < 0 || index >= data_size)
    {
        std::cerr << "Error: Index out of bound!" << std::endl;
        exit(1);
    }
    return data[index];
}

int MovieRatingDataset::file_length()
{
    std::ifstream file;
    std::string unused_data;
    file.open(file_name);
    int num_lines = 0;
    while (!file.eof())
    {
        std::getline(file, unused_data, '\n');
        num_lines++;
    }
    return num_lines;
}

bool MovieRatingDataset::data_completion()
{
    for (int i = 0; i < data_size; i++)
    {
        if (data[i].rating == 0)
        {
            return false;
        }
    }
    return true;
}

void MovieRatingDataset::filter()
{
    for (int index = 0, empty_data = 0; index < data_size; index++)
    {
        if (data[index].rating == 0)
            empty_data++;
        data[index] = data[index + empty_data];
    }
}

MovieRatingDataset::MovieRating *MovieRatingDataset::load_data()
{
    MovieRating *data = new MovieRating[data_size];
    std::ifstream file;
    std::string tmp, tmp2;

    file.open(file_name);
    if (!file)
    {
        std::cerr << "Error: file cant be opened" << std::endl;
        exit(1);
    }
    std::getline(file, tmp);
    for (int i = 0; i < data_size && !file.eof(); i++)
    {
        std::getline(file, tmp, ',');
        std::getline(file, tmp, ',');
        if (tmp[0] == '"')
        {
            std::getline(file, tmp2, '"');
            data[i].title = tmp + ',' + tmp2 + '"';
            std::getline(file, tmp, ',');
        }
        else
        {
            data[i].title = tmp;
        }
        std::getline(file, tmp, '\n');
        data[i].rating = atoi(tmp.c_str());
    }
    file.close();
    return data;
}
