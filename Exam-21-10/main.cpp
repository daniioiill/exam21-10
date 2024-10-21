#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <cstdlib>
#include "FilmDB.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    FilmDB db;

    // Добавляем фильмы в базу данных
    db.addFilm("Inception", "Sci-Fi", 8, 148);
    db.addFilm("Titanic", "Romance", 7, 195);
    db.addFilm("The Godfather", "Crime", 9, 175);
    db.addFilm("The Dark Knight", "Action", 9, 152);
    db.addFilm("Pulp Fiction", "Crime", 8, 154);

    QString output;
    output += "Good Sci-Fi Films:\n";
    auto goodSciFiFilms = db.getGoodFilmsOfGenre(8, "Sci-Fi");
    for (const auto& film : goodSciFiFilms) {
        output += film + "\n";
    }

    output += "\nShort Romance Films:\n";
    auto shortRomanceFilms = db.getFilmsOfGenreLessThan(200, "Romance");
    for (const auto& film : shortRomanceFilms) {
        output += film + "\n";
    }

    // Записываем вывод в файл
    QFile file("output.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(output.toUtf8());
        file.close();
    }

    // Открываем консоль и выводим содержимое файла
    system("start cmd /k type output.txt");

    return a.exec();
}
