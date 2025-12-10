#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Service.h"
#include "Car.h"
#include "Client.h"
#include "Employee.h"

namespace CarService {

    class CarServiceManager {
    public:
        CarServiceManager();
        
        void addService(std::shared_ptr<Service> service);
        std::vector<std::shared_ptr<Service>> getAllServices() const;
        std::string getServicesList() const;
        
        void addCar(std::shared_ptr<Car> car);
        std::vector<std::shared_ptr<Car>> getAllCars() const;
        std::string getCarsList() const;
        
        void addClient(std::shared_ptr<Client> client);
        std::vector<std::shared_ptr<Client>> getAllClients() const;
        
        void addEmployee(std::shared_ptr<Employee> employee);
        std::vector<std::shared_ptr<Employee>> getAllEmployees() const;
        
        std::string getCarInfo(const std::string& licensePlate) const;
        std::string getEmployeeWorkReport(const std::string& employeeName, std::time_t startDate, std::time_t endDate) const;
        double calculateClientCost(const std::string& clientName) const;
        
    private:
        std::vector<std::shared_ptr<Service>> services;
        std::vector<std::shared_ptr<Car>> cars;
        std::vector<std::shared_ptr<Client>> clients;
        std::vector<std::shared_ptr<Employee>> employees;
    };

}

