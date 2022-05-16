#include "MovieRatingDataset.hh"

std::ostream &
operator<<(std::ostream &strm, MovieRating &elem)
{
    strm << elem.get_title() << " " << elem.get_rating();
    return strm;
}

MovieRating &MovieRatingDataset::operator[](int index)
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
    if (!file)
    {
        std::cerr << "Error: file cant be opened" << std::endl;
        exit(1);
    }
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
        if (data[i].get_rating() == 0)
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
        if (data[index].get_rating() == 0)
            empty_data++;
        data[index] = data[index + empty_data];
    }
}

MovieRating *MovieRatingDataset::load_data()
{
    std::ifstream file;
    std::string tmp, tmp2;
    MovieRating *data = new MovieRating[data_size];

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
            data[i].set_title(tmp + ',' + tmp2 + '"');
            std::getline(file, tmp, ',');
        }
        else
        {
            data[i].set_title(tmp);
        }
        std::getline(file, tmp, '\n');
        data[i].set_rating(atoi(tmp.c_str()));
    }
    file.close();
    return data;
}
// needs testing
MovieRating *MovieRatingDataset::n_random(int n)
{
    int random_index, tmp_size = data_size;
    MovieRating *tmp = new MovieRating[data_size];
    MovieRating *randomized = new MovieRating[n];
    for (int i = 0; i < data_size; i++)
    {
        tmp[i] = data[i];
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        random_index = rand() % tmp_size;
        randomized[i] = data[random_index];
        for (int i = random_index; i < tmp_size; i++)
        {
            tmp[i] = tmp[i + 1];
        }
        tmp_size--;

    }
    delete[] tmp;
    return randomized;
}
