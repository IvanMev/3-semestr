#pragma once

#include <string>
#include <memory>
#include <vector>

namespace CarService {

    class Client;
    class Employee;

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
        std::vector<std::shared_ptr<Service>> services; 
        std::vector<std::shared_ptr<Client>> clients; 
        std::vector<std::shared_ptr<Employee>> employees; 
    };

}

