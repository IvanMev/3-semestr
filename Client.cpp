#include "Client.h"

namespace CarService {

    const double Client::REGULAR_CLIENT_DISCOUNT = 10.0;

    Client::Client(const std::string& name, const std::string& phone, bool isRegular)
        : name(name), phone(phone), regular(isRegular) {
    }

    std::string Client::getName() const {
        return name;
    }

    std::string Client::getPhone() const {
        return phone;
    }

    bool Client::isRegularClient() const {
        return regular;
    }

    void Client::addCar(std::shared_ptr<Car> car) {
        cars.push_back(car);
    }

    std::vector<std::shared_ptr<Car>> Client::getCars() const {
        return cars;
    }

    double Client::getDiscountPercent() const {
        return regular ? REGULAR_CLIENT_DISCOUNT : 0.0;
    }

    void Client::setRegularStatus(bool isRegular) {
        regular = isRegular;
    }

}

