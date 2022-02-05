#include "userlist.h"
#include "ui_userlist.h"

//patrz MovieList
UserList::UserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);
    tableViewUsers = new QStandardItemModel(ui->UserListTable);
    ui->UserListTable ->setModel(tableViewUsers);
    tableViewUsers->setColumnCount(3);
    tableViewUsers -> setHorizontalHeaderLabels({"Username" , "Name" , "Surname"});
    ui->UserListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->UserListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    fillTable(tableViewUsers);

}

UserList::~UserList()
{
    tableViewUsers->clear();
    delete tableViewUsers;
    tableViewUsers = nullptr;
    delete ui;
}


//patrz MovieList
void UserList::fillTable(QStandardItemModel *tableView){
    User users;  
    std::vector <person> userList = users.getList();
    std::vector<person>::iterator x;

    QString name, surname, username;
    int i=0;

    for(x = userList.begin(); x!=userList.end(); ++x){
        name = QString::fromUtf8((*x).nm);
        surname = QString::fromUtf8((*x).sNm);
        username = QString::fromUtf8((*x).usNm);
        QStandardItem *uName =  new QStandardItem(username);
        QStandardItem *nam =  new QStandardItem(name);
        QStandardItem *surnam =  new QStandardItem(surname);

        tableView->setItem(i, 0, uName);
        tableView->setItem(i, 1, nam);
        tableView->setItem(i, 2, surnam);
        i++;
    }

}
