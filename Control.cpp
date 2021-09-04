//
// Created by Camilo on 2/09/2021.
//

#include <sstream>
#include "Control.h"

Control::Control(LinkedList<Monitor> *list) {
    Control::list = list;
}

bool Control::isEmpty() {
    return Control::list->isEmpty();
}

void Control::addNodeFirst(Monitor mon) {
    list->addNodeFirst(mon);
}

void Control::addNodeLast(Monitor mon) {
    list->addNodeFirst(mon);
}

bool Control::addNodeSorted(Monitor mon) {
    if (list->nodeExist(mon.getId())) {
        return false;
    }
    list->addNodeSorted(mon);
    return true;
}

bool Control::addNodeAfter(std::string after, Monitor info) {
    if (list->nodeExist(after)) {
        list->addNodeAfterTo(list->findNode(after), info);
        return true;
    }
    return false;
}

bool Control::addNodeBefore(std::string before, Monitor info) {
    if (list->nodeExist(before)) {
        list->addNodeBeforeTo(list->findNode(before), info);
        return true;
    }
    return false;
}

std::string Control::findNode(std::string id) {
    if (list->nodeExist(id)) {
        return "Se ha encontrado el nodo: " + findInfo(id);
    }
    return "Nodo no encontrado";
}

std::string Control::findInfo(std::string id) {
    return (list->findInfo(id)->getId().compare("")) == 0 ? "Informacion no encontrada" : convertToString(
            *list->findInfo(id));
}

std::string Control::deleteNode(std::string id) {
    std::string retu = "Nodo no encontrado";
    Monitor ret;
    if (list->nodeExist(id)) {
        ret = list->deleteNode(list->findNode(id));
        retu = "Se ha eliminado: " + convertToString(ret);
    }
    return retu;
}

std::string Control::getList(bool dir) {
    std::string ret;
    if (list->isEmpty()) {
        return "La lista esta vacia";
    } else {
        for (const auto &item : list->getList(dir)) {
            ret += convertToString(item) + "\n";
        }
    }
    return ret;
}

int Control::getSize() {
    return list->getSize();
}

Monitor *Control::getObject(int index) {
    return list->getObject(index);
}

std::string Control::getFirst() {
    return convertToString(list->getFirst());
}

std::string Control::getLast() {
    return convertToString(list->getLast());
}

std::string Control::convertToString(Monitor mon) {
    std::ostringstream ret;
    ret << mon;
    return ret.str();
}








