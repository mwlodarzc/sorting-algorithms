#include "MovieRatingDataset.hh"

std::ostream &operator<<(std::ostream &strm, const MovieRatingDataset::MovieRating &elem)
{
    strm << elem.title << " " << elem.rating;
    return strm;
}

MovieRatingDataset::MovieRating &MovieRatingDataset::operator[](int index)
{
    if (index < 0 || index >= size)
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
    for (int i = 0; i < size; i++)
    {
        if (data[i].rating == 0)
        {
            return false;
            filtered = false;
        }
    }
    filtered = true;
    return true;
}

void MovieRatingDataset::filter()
{
    for (int index = 0, empty_data = 0; index < size; index++)
    {
        if (data[index].rating == 0)
            empty_data++;
        data[index] = data[index + empty_data];
    }
    filtered = true;
}

MovieRatingDataset::MovieRating *MovieRatingDataset::load_data()
{
    MovieRating *data = new MovieRating[size];
    std::ifstream file;
    std::string tmp;

    file.open(file_name);
    if (!file)
    {
        std::cerr << "Error: file cant be opened" << std::endl;
        exit(1);
    }
    std::getline(file, tmp);
    for (int i = 0; i < size && !file.eof(); i++)
    {
        std::getline(file, tmp, ',');
        std::getline(file, tmp, ',');
        data[i].title = tmp;
        std::getline(file, tmp, '\n');
        data[i].rating = atoi(tmp.c_str());
    }
    file.close();
    return data;
}
