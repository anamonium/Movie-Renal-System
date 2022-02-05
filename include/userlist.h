#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include <QString>
#include <QStandardItemModel>
#include <QMessageBox>
#include <vector>
#include "person.h"
#include "user.h"
#include "administrator.h"

namespace Ui {
class UserList;
}

class UserList : public QDialog
{
    Q_OBJECT
    QStandardItemModel *tableViewUsers;

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

    void fillTable(QStandardItemModel *tableView); //funkcja wypelniajaca tebele uzytkowikami


private slots:


private:
    Ui::UserList *ui;
};

#endif // USERLIST_H
