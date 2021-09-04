//
// Created by Camilo on 2/09/2021.
//

#ifndef DOUBLELINKEDLIST_CONTROL_H
#define DOUBLELINKEDLIST_CONTROL_H

#include "Node.h"
#include "LinkedList.cpp"
#include "Monitor.h"

class Control{
public:
    Control(LinkedList<Monitor>*);

    bool isEmpty();

    void addNodeFirst(Monitor);

    void addNodeLast(Monitor);

    bool addNodeSorted(Monitor);

    bool addNodeAfter(std::string id, Monitor);

    bool addNodeBefore(std::string id, Monitor);

    std::string findNode(std::string);

    std::string findInfo(std::string);

    std::string deleteNode(std::string);

    std::string getList(bool);

    int getSize();

    Monitor* getObject(int);

    std::string getFirst();

    std::string getLast();

    std::string convertToString(Monitor);

private:
    LinkedList<Monitor>* list;
};




#endif //DOUBLELINKEDLIST_CONTROL_H
