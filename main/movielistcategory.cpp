#include "movielistcategory.h"
#include "ui_movielistcategory.h"

//zajrzyj do definicji konstruktora MovieList
MovieListCategory::MovieListCategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovieListCategory)
{
    ui->setupUi(this);
    tableView = new QStandardItemModel(ui->tableCategory);
     ui->tableCategory->setModel(tableView);
     tableView->setColumnCount(6);
     tableView -> setHorizontalHeaderLabels({"Title", "Director", "Category" , "Length" , "Year" , "Price"});
     ui->tableCategory->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableCategory->setSelectionBehavior(QAbstractItemView::SelectRows);

}

MovieListCategory::~MovieListCategory()
{
    tableView->clear();
    delete tableView;
    tableView = nullptr;
    delete ui;
}


/*funkcja z 'comboboxa' pobiera aktualna obiekt który się tam znajduje
  następnie na podstawie tej kategorii wyszukuje filmy które do niej należą
  i dodaje je do nowego kontenera
  jezeli w kontenerze nie znajdują się żadne filmy zostaje wyświetlona informacja*/
void MovieListCategory::on_searchButton_clicked()
{
    std::string category = (ui->comboBox->currentText()).toLocal8Bit().constData();
    std::vector<movie> mList;
    std::vector<movie> ::iterator x;
    readMovie(mList);
    tableView->setRowCount(0);
    mCatList.clear();

    if(category == "All"){
        fillTheTable(tableView);
    }
    else{
        for(x=mList.begin(); x!=mList.end(); ++x){
            if((*x).category == category){
                mCatList.push_back((*x));
            }
        }

        if(mCatList.size()==0){
            QMessageBox::information(this, "Search", "No movies in this category");
        }
        else{
            fillTheTable(tableView, mCatList);
        }
    }
}


/*funkcja wypełnia tabele, drugim jej argumentem jest lista filmow
  z konkretnej kategorii*/
void MovieListCategory::fillTheTable( QStandardItemModel *tableView, std::vector<movie> mCatList){
     std::vector<movie>::iterator x;
     QString title, director, category, year, length, price;
     int i=0;

     for(x=mCatList.begin(); x!=mCatList.end(); ++x){
         title = QString::fromUtf8((*x).title);
         director = QString::fromUtf8((*x).director);
         category = QString::fromUtf8((*x).category);
         year = QString::number((*x).year);
         length = QString::number((*x).length);
         price = QString::number((*x).price);
         QStandardItem *ttitle =  new QStandardItem(title);
         QStandardItem *ddirector =  new QStandardItem(director);
         QStandardItem *ccategory =  new QStandardItem(category);
         QStandardItem *yyear = new QStandardItem(year);
         QStandardItem *llength =  new QStandardItem(length);
         QStandardItem *pprice =  new QStandardItem(price);
         tableView->setItem(i, 0, ttitle);
         tableView->setItem(i, 1, ddirector);
         tableView->setItem(i, 2, ccategory);
         tableView->setItem(i, 3, llength);
         tableView->setItem(i,4,yyear);
         tableView->setItem(i, 5, pprice);
         i++;
     }
}

//funckja wypelnia tabele wszystkimi filmami znajdujacymi sie w bazie danych
void MovieListCategory::fillTheTable(QStandardItemModel *tableView){
    std::vector<movie> mList;
    std::vector<movie>::iterator x;
    readMovie(mList);

    QString title, director, category, year, length, price;
    int i=0;

    for(x=mList.begin(); x!=mList.end(); ++x){
        title = QString::fromUtf8((*x).title);
        director = QString::fromUtf8((*x).director);
        category = QString::fromUtf8((*x).category);
        year = QString::number((*x).year);
        length = QString::number((*x).length);
        price = QString::number((*x).price);
        QStandardItem *ttitle =  new QStandardItem(title);
        QStandardItem *ddirector =  new QStandardItem(director);
        QStandardItem *ccategory =  new QStandardItem(category);
        QStandardItem *yyear = new QStandardItem(year);
        QStandardItem *llength =  new QStandardItem(length);
        QStandardItem *pprice =  new QStandardItem(price);
        tableView->setItem(i, 0, ttitle);
        tableView->setItem(i, 1, ddirector);
        tableView->setItem(i, 2, ccategory);
        tableView->setItem(i, 3, llength);
        tableView->setItem(i,4,yyear);
        tableView->setItem(i, 5, pprice);
        i++;
    }
}


//funkcja obsluguje podwojne klikniecie w rzad znajdujacy sie tabeli
void MovieListCategory::on_tableCategory_doubleClicked(const QModelIndex &index)
{
    QMessageBox::information(this, "Rent a movie", "Movie has been succesfully rented");
}

