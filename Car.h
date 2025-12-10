#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Service.h"

namespace CarService {

    class Problem;

    class Car {
    public:
        Car(const std::string& licensePlate, const std::string& make, const std::string& model, int year);
        
        std::string getLicensePlate() const;
        std::string getMake() const;
        std::string getModel() const;
        int getYear() const;
        
        void addService(std::shared_ptr<Service> service);
        std::vector<std::shared_ptr<Service>> getServices() const;
        
        void addProblem(const std::string& problemDescription);
        std::vector<std::string> getProblems() const;
        
        std::string getInfo() const;

    private:
        std::string licensePlate;
        std::string make;
        std::string model;
        int year;
        std::vector<std::shared_ptr<Service>> services;
        std::vector<std::string> problems;
    };

}

