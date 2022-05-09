#include "MovieRatingDataset.hh"

int main()
{
    std::string filename = "projekt2_dane.csv";
    MovieRatingDataset data(filename);
    std::cout << data[0] << std::endl;
    data[0].rating = 10;
    std::cout << data[0] << std::endl;

    return EXIT_SUCCESS;
}