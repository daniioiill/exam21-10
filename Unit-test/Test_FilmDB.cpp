#include <QtTest/QtTest>
#include <QFile>
#include <cstdlib>
#include "FilmDB.h"

class TestFilmDB : public QObject {
    Q_OBJECT

private slots:
    void init() {
        db.addFilm("Film1", "Genre1", 5, 120);
        db.addFilm("Film2", "Genre1", 7, 90);
        db.addFilm("Film3", "Genre2", 8, 150);
        db.addFilm("Film4", "Genre1", 9, 110);
        db.addFilm("Film5", "Genre2", 6, 130);
    }

    void testCountGenre() {
        QString output;
        output += "Testing countGenre:\n";
        output += QString("Count of Genre1: %1\n").arg(db.countGenre("Genre1"));
        output += QString("Count of Genre2: %1\n").arg(db.countGenre("Genre2"));
        output += QString("Count of Genre3: %1\n").arg(db.countGenre("Genre3"));

        // Записываем вывод в файл
        QFile file("test_output.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.write(output.toUtf8());
            file.close();
        }

        // Открываем консоль и выводим содержимое файла
        system("start cmd /k type test_output.txt");
    }

private:
    FilmDB db;
};

QTEST_MAIN(TestFilmDB)
#include "Test_FilmDB.moc"
