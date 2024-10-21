#include "FilmDB.h"

FilmDB::FilmDB() {}

void FilmDB::addFilm(const QString& title, const QString& genre, int rating, int duration) {
    films.append({title, genre, rating, duration});
}

QStringList FilmDB::getGoodFilmsOfGenre(int rating, const QString& genre) {
    return filterFilms([rating, genre](const Film& film) {
        return film.rating >= rating && film.genre == genre;
    });
}

QStringList FilmDB::getFilmsOfGenreLessThan(int time, const QString& genre) {
    return filterFilms([time, genre](const Film& film) {
        return film.duration <= time && film.genre == genre;
    });
}

QStringList FilmDB::getFilmsLessThan(int time) {
    return filterFilms([time](const Film& film) {
        return film.duration <= time;
    });
}

int FilmDB::countGenre(const QString& genre) {
    return std::count_if(films.begin(), films.end(), [&genre](const Film& film) {
        return film.genre == genre;
    });
}

QStringList FilmDB::filterFilms(std::function<bool(const Film&)> predicate) {
    QStringList result;
    for (const auto& film : films) {
        if (predicate(film)) {
            result.append(film.title);
        }
    }
    return result;
}
