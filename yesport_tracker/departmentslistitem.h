#ifndef DEPARTMENTSLISTITEM_H
#define DEPARTMENTSLISTITEM_H

#include <QListWidgetItem>

class DepartmentsListItem : public QListWidgetItem
{
protected:
    int id;

public:
    DepartmentsListItem(const QString &text, int id = 0, QListWidget *view = 0, int type = Type);

    void setId(int id);
    int getId();
};

#endif // DEPARTMENTSLISTITEM_H
