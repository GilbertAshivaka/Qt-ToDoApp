#include "todolist.h"

ToDoList::ToDoList(QObject *parent)
    : QObject{parent}
{
    mItems.append(TodoItem{true, QStringLiteral("Wash the car")});
    mItems.append(TodoItem{false, QStringLiteral("Fix the sink")});
}

QVector<TodoItem> ToDoList::items() const
{
    return mItems;
}

bool ToDoList::setItemAt(int index, const TodoItem &item)
{
    if (index < 0 || index >= mItems.size()){
        return false;
    }

    const TodoItem oldItem = mItems.at(index);

    if (item.done == oldItem.done && item.description == oldItem.description){
        return false;
    }

    mItems[index] = item;

    return true;
}

void ToDoList::appendItem()
{
    emit preItemAppended();

    TodoItem item;
    item.done = false;
    mItems.append(item);

    emit postItemAppended();
}

void ToDoList::removeCompletedItems()
{
    for(int i = 0; i < mItems.size();){
        if (mItems.at(i).done){
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        }else{
            ++i;
        }
    }
}

















