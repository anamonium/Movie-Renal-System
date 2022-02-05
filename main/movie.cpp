#include "movie.h"

/*funkcja ktora z pliku wczytuje dane filmow do kontenera*/
void readMovie(std::vector<movie> &mv){

    std::fstream inFile;
    movie film;
    std::vector<std::string> row;
    std::string line, word, temp;
    inFile.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/movieList.csv", std::ios::in);
    while(getline(inFile, line)){
        row.clear();
        std::stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }

        film.title = row[0];
        film.director = row[1];
        film.category = row[2];
        film.length = stoi(row[3]); //konwersja do int
        film.year = stoi(row[4]);
        film.price = stoi(row[5]);
        mv.push_back(film);
    }

    inFile.close();
}
