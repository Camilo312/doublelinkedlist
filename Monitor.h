//
// Created by Camilo on 26/08/2021.
//

#ifndef DOUBLELINKEDLIST_MONITOR_H
#define DOUBLELINKEDLIST_MONITOR_H

#include <string>
#include <ostream>

class Monitor {
private:
    std::string brand;
    std::string color;
    std::string id;
    int inches;
    double refreshRate;
public:
    Monitor();

    Monitor(const std::string &brand, const std::string &color, std::string id, int inches, double refreshRate);

    const std::string &getBrand() const;

    void setBrand(const std::string &brand);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    std::string getId() const;

    void setId(const std::string &id);

    int getInches() const;

    void setInches(int inches);

    double getRefreshRate() const;

    void setRefreshRate(double refreshRate);

    std::string toString();

    friend std::ostream &operator<<(std::ostream &os, const Monitor &monitor);

    virtual ~Monitor();

};


#endif //DOUBLELINKEDLIST_MONITOR_H
