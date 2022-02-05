#include "moviesearch.h"
#include "ui_moviesearch.h"


MovieSearch::MovieSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovieSearch)
{
    ui->setupUi(this);

    tableView = new QStandardItemModel(ui->tableSearch);
     ui->tableSearch->setModel(tableView);
     tableView->setColumnCount(6);
     tableView -> setHorizontalHeaderLabels({"Title", "Director", "Category" , "Length" , "Year" , "Price"});
     ui->tableSearch->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableSearch->setSelectionBehavior(QAbstractItemView::SelectRows);
}

MovieSearch::~MovieSearch()
{
    tableView->clear();
    delete tableView;
    tableView = nullptr;
    delete ui;
}

/*funkcja pobierająca dane z pola do którego użytkownik wpisuje dane
  następnie sprawdza ona czy taki tytuł istnieje już w bazie danych
  na ekranie wyświetlnony zostaje tytuł bądź odpowiednia informacja
  funkcja ignoruje przy sprawdzaniu wielkość liter*/
void MovieSearch::on_searchButton_clicked()
{
    bool flag = false;
    std::string title, word;
    title = (ui->searchTitle->text()).toLocal8Bit().constData();
    std::for_each(title.begin(), title.end(), [](char &c){
        c = ::tolower(c);
    });
    std::vector<movie> movList, titlesFound;
    std::vector<movie>::iterator x;
    readMovie(movList);

    for(x = movList.begin(); x!=movList.end(); ++x){
        word = (*x).title;
        std::for_each(word.begin(), word.end(), [](char &d){
            d = ::tolower(d);
        });

       if(word == title){
           titlesFound.push_back((*x));
           flag = true;
       }
    }

    if(!flag){
        QMessageBox::information(this, "Search", "No matching title found!");
    }
    else{
        fillTheTable(tableView, titlesFound);
    }

}

//patrz movielistcategoty
void MovieSearch::fillTheTable( QStandardItemModel *tableView, std::vector<movie> mCatList){
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


void MovieSearch::on_tableSearch_doubleClicked(const QModelIndex &index)
{
    QMessageBox::information(this, "Rent a movie", "Movie has been succesfully rented");
}
