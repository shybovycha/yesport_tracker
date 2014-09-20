#ifndef DATABASEROWLISTITEM_H
#define DATABASEROWLISTITEM_H

#include <QListWidgetItem>

class DatabaseRowListItem : public QListWidgetItem
{
protected:
    int id;

public:
    DatabaseRowListItem(const QString &text, int id = 0, QListWidget *view = 0, int type = Type);

    void setId(int id);
    int getId();
};

#endif // DATABASEROWLISTITEM_H
