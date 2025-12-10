#pragma once

#include <string>
#include <memory>

namespace CarService {

    class Service {
    public:
        Service(const std::string& name, double price);
        virtual ~Service() = default;

        virtual std::string getDescription() const = 0;

        virtual std::string getServiceType() const = 0;

        std::string getName() const;
        double getPrice() const;

        void setPrice(double price);

    protected:
        std::string name;
        double price;
    };

}

