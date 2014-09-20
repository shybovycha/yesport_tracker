#include "visitorslistitem.h"

VisitorsListItem::VisitorsListItem(const QString &text, int id, QListWidget *view, int type) : QListWidgetItem(text, view, type), id(id)
{
}

int VisitorsListItem::getId()
{
    return this->id;
}

void VisitorsListItem::setId(int id)
{
    this->id = id;
}
