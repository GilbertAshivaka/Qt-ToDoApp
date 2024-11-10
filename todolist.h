#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>
#include <QVector>

struct TodoItem{
    bool done;
    QString description;
};

class ToDoList : public QObject
{
    Q_OBJECT
public:
    explicit ToDoList(QObject *parent = nullptr);

    QVector<TodoItem> items() const;

    bool setItemAt(int index, const TodoItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void removeCompletedItems();

private:
    QVector<TodoItem> mItems;

};

#endif // TODOLIST_H
