#ifndef MOVIELISTCATEGORY_H
#define MOVIELISTCATEGORY_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>
#include "movie.h"
#include <QMessageBox>


namespace Ui {
class MovieListCategory;
}

class MovieListCategory : public QDialog
{
    Q_OBJECT
     QStandardItemModel *tableView;

public:
    explicit MovieListCategory(QWidget *parent = nullptr);
    ~MovieListCategory();
    MovieListCategory(const std::string category);

    void fillTheTable( QStandardItemModel *tableView, std::vector<movie> mCatList); //wypelnia tabele odpowiednia kategoria
    void fillTheTable( QStandardItemModel *tableView); //wypelnia tabele wszystkimi filmami


private slots:
    void on_searchButton_clicked(); //obsluga przycisku search

    void on_tableCategory_doubleClicked(const QModelIndex &index); //obsluga podwojnego klikniecia w obiekt tabeli

private:
    Ui::MovieListCategory *ui;
    std::vector<movie> mCatList;

};

#endif // MOVIELISTCATEGORY_H
