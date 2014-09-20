#include "databaserowlistitem.h"

DatabaseRowListItem::DatabaseRowListItem(const QString &text, int id, QListWidget *view, int type) : QListWidgetItem(text, view, type), id(id)
{
}

void DatabaseRowListItem::setId(int id)
{
    this->id = id;
}

int DatabaseRowListItem::getId()
{
    return this->id;
}
