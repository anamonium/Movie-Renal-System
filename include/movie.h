#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct movie{
    std::string title, director, category;
    int length, price, year;
};

void readMovie(std::vector<movie> &mv); //odczytuje filmy i zapisuje do kontenera

#endif // MOVIE_H
