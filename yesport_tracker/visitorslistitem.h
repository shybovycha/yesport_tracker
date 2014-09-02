#ifndef VISITORSLISTITEM_H
#define VISITORSLISTITEM_H

#include <QListWidgetItem>

class VisitorsListItem : public QListWidgetItem
{
protected:
    int id;

public:
    VisitorsListItem(const QString &text, int id = 0, QListWidget *view = 0, int type = Type);

    int getId();
    void setId(int id);
};

#endif // VISITORSLISTITEM_H
