#include "Service.h"
#include "Client.h"
#include "Employee.h"

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

    void Service::addServiceToCollection(std::shared_ptr<Service> service) {
        services.push_back(service);
    }

    void Service::addClientToCollection(std::shared_ptr<Client> client) {
        clients.push_back(client);
    }

    void Service::addEmployeeToCollection(std::shared_ptr<Employee> employee) {
        employees.push_back(employee);
    }

    std::vector<std::shared_ptr<Service>> Service::getServicesCollection() const {
        return services;
    }

    std::vector<std::shared_ptr<Client>> Service::getClientsCollection() const {
        return clients;
    }

    std::vector<std::shared_ptr<Employee>> Service::getEmployeesCollection() const {
        return employees;
    }

}

