#ifndef MOVIESEARCH_H
#define MOVIESEARCH_H

#include <QDialog>
#include "movie.h"
#include <QStandardItemModel>
#include <QMessageBox>


namespace Ui {
class MovieSearch;
}

class MovieSearch : public QDialog
{
    Q_OBJECT
    QStandardItemModel *tableView;

public:
    explicit MovieSearch(QWidget *parent = nullptr);
    ~MovieSearch();

     void fillTheTable( QStandardItemModel *tableView, std::vector<movie> mCatList); //funkcja wypelniajaca tebele odpowiednia kategoria

private slots:
    void on_searchButton_clicked(); //obsluga przycisku search

    void on_tableSearch_doubleClicked(const QModelIndex &index); //obsluga podwojnego klikniecia w tabele

private:
    Ui::MovieSearch *ui;
};

#endif // MOVIESEARCH_H
