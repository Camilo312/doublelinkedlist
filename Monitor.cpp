//
// Created by Camilo on 26/08/2021.
//

#include "Monitor.h"

Monitor::Monitor(const std::string &brand, const std::string &color, std::string id, int inches, double refreshRate)
        : brand(
        brand), color(color), id(id), inches(inches), refreshRate(refreshRate) {}

const std::string &Monitor::getBrand() const {
    return brand;
}

void Monitor::setBrand(const std::string &brand) {
    Monitor::brand = brand;
}

const std::string &Monitor::getColor() const {
    return color;
}

void Monitor::setColor(const std::string &color) {
    Monitor::color = color;
}

std::string Monitor::getId() const {
    return id;
}

void Monitor::setId(const std::string &id) {
    Monitor::id = id;
}

int Monitor::getInches() const {
    return inches;
}

void Monitor::setInches(int inches) {
    Monitor::inches = inches;
}

double Monitor::getRefreshRate() const {
    return refreshRate;
}

void Monitor::setRefreshRate(double refreshRate) {
    Monitor::refreshRate = refreshRate;
}

std::ostream &operator<<(std::ostream &os, const Monitor &monitor) {
    os << " Id: " << monitor.id << " Marca: " << monitor.brand << " Color: " << monitor.color << " Pulgadas: "
       << monitor.inches << " Tasa de refresco: " << monitor.refreshRate;
    return os;
}

std::string Monitor::toString() {
    return " Id: " + Monitor::id + " Marca: " + Monitor::brand + " Color: " + Monitor::color + " Pulgadas: " +
           std::to_string(Monitor::inches) + " Tasa de refresco: " + std::to_string(Monitor::refreshRate);
}

Monitor::Monitor() = default;

Monitor::~Monitor() = default;
