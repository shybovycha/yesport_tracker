#include "departmentslistitem.h"

DepartmentsListItem::DepartmentsListItem(const QString &text, int id, QListWidget *view, int type) : QListWidgetItem(text, view, type), id(id)
{
}

void DepartmentsListItem::setId(int id)
{
    this->id = id;
}

int DepartmentsListItem::getId()
{
    return this->id;
}
