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
        
        void addServiceToCollection(std::shared_ptr<Service> service);
        void addClientToCollection(std::shared_ptr<Client> client);
        void addEmployeeToCollection(std::shared_ptr<Employee> employee);
        
        std::vector<std::shared_ptr<Service>> getServicesCollection() const;
        std::vector<std::shared_ptr<Client>> getClientsCollection() const;
        std::vector<std::shared_ptr<Employee>> getEmployeesCollection() const;

    protected:
        std::string name;
        double price;
        std::vector<std::shared_ptr<Service>> services; 
        std::vector<std::shared_ptr<Client>> clients; 
        std::vector<std::shared_ptr<Employee>> employees; 
    };

}

