#ifndef FILMDB_H
#define FILMDB_H

#include <QString>
#include <QList>

class FilmDB {
public:
    FilmDB();
    void addFilm(const QString& title, const QString& genre, int rating, int duration);
    QStringList getGoodFilmsOfGenre(int rating, const QString& genre);
    QStringList getFilmsOfGenreLessThan(int time, const QString& genre);
    QStringList getFilmsLessThan(int time);
    int countGenre(const QString& genre);

private:
    struct Film {
        QString title;
        QString genre;
        int rating;
        int duration;
    };

    QList<Film> films;

    QStringList filterFilms(std::function<bool(const Film&)> predicate);
};

#endif // FILMDB_H
