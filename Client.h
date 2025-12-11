#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Car.h"

namespace CarService {

    class Client {
    public:
        Client(const std::string& name, const std::string& phone, bool isRegular = false);
        
        std::string getName() const;
        std::string getPhone() const;
        bool isRegularClient() const;
        
        void addCar(std::shared_ptr<Car> car);
        std::vector<std::shared_ptr<Car>> getCars() const;
        
        double getDiscountPercent() const;
        void setRegularStatus(bool isRegular);

    private:
        std::string name;
        std::string phone;
        bool regular;
        std::vector<std::shared_ptr<Car>> cars;
        static const double REGULAR_CLIENT_DISCOUNT;
    };

}

