#include "Service.h"

namespace CarService {

    Service::Service(const std::string& name, double price)
        : name(name), price(price) {
        services.clear();
        clients.clear();
        employees.clear();
    }

    std::string Service::getName() const {
        return name;
    }

    double Service::getPrice() const {
        return price;
    }

    void Service::setPrice(double price) {
        this->price = price;
    }

}

