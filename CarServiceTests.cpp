#include "pch.h"
#include "CppUnitTest.h"
#include "Service.h"
#include "RepairService.h"
#include "PaintingService.h"
#include "WashingService.h"
#include "TuningService.h"
#include "Car.h"
#include "Client.h"
#include "Employee.h"
#include "CarServiceManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CarService;

namespace CarServiceTests
{
    TEST_CLASS(ServiceTests)
    {
    public:
        TEST_METHOD(TestRepairService)
        {
            auto service = std::make_shared<RepairService>("Engine Repair", 500.0, "Engine");
            Assert::AreEqual(std::string("Engine Repair"), service->getName());
            Assert::AreEqual(500.0, service->getPrice());
            Assert::AreEqual(std::string("Repair"), service->getServiceType());
            Assert::AreEqual(std::string("Engine"), service->getRepairType());
        }

        TEST_METHOD(TestPaintingService)
        {
            auto service = std::make_shared<PaintingService>("Full Paint", 800.0, "Red");
            Assert::AreEqual(std::string("Full Paint"), service->getName());
            Assert::AreEqual(800.0, service->getPrice());
            Assert::AreEqual(std::string("Painting"), service->getServiceType());
            Assert::AreEqual(std::string("Red"), service->getColor());
        }

        TEST_METHOD(TestWashingService)
        {
            auto service = std::make_shared<WashingService>("Dry Clean", 150.0, true);
            Assert::AreEqual(std::string("Dry Clean"), service->getName());
            Assert::AreEqual(150.0, service->getPrice());
            Assert::AreEqual(std::string("Washing"), service->getServiceType());
            Assert::IsTrue(service->isDryCleaningService());
        }

        TEST_METHOD(TestTuningService)
        {
            auto service = std::make_shared<TuningService>("Engine Tune", 600.0, "Performance");
            Assert::AreEqual(std::string("Engine Tune"), service->getName());
            Assert::AreEqual(600.0, service->getPrice());
            Assert::AreEqual(std::string("Tuning"), service->getServiceType());
            Assert::AreEqual(std::string("Performance"), service->getTuningCategory());
        }

        TEST_METHOD(TestServicePolymorphism)
        {
            std::vector<std::shared_ptr<Service>> services;
            services.push_back(std::make_shared<RepairService>("Repair", 100.0, "Engine"));
            services.push_back(std::make_shared<PaintingService>("Paint", 200.0, "Blue"));
            services.push_back(std::make_shared<WashingService>("Wash", 50.0, false));
            services.push_back(std::make_shared<TuningService>("Tune", 300.0, "Performance"));

            Assert::AreEqual(4, (int)services.size());
            for (const auto& service : services) {
                Assert::IsNotNull(service.get());
                Assert::IsFalse(service->getDescription().empty());
            }
        }
    };

    TEST_CLASS(CarTests)
    {
    public:
        TEST_METHOD(TestCarCreation)
        {
            auto car = std::make_shared<Car>("ABC123", "Toyota", "Camry", 2020);
            Assert::AreEqual(std::string("ABC123"), car->getLicensePlate());
            Assert::AreEqual(std::string("Toyota"), car->getMake());
            Assert::AreEqual(std::string("Camry"), car->getModel());
            Assert::AreEqual(2020, car->getYear());
        }

        TEST_METHOD(TestCarServices)
        {
            auto car = std::make_shared<Car>("ABC123", "Toyota", "Camry", 2020);
            auto service = std::make_shared<RepairService>("Repair", 100.0, "Engine");
            car->addService(service);
            
            auto services = car->getServices();
            Assert::AreEqual(1, (int)services.size());
        }
    };

    TEST_CLASS(ClientTests)
    {
    public:
        TEST_METHOD(TestClientCreation)
        {
            auto client = std::make_shared<Client>("John Doe", "555-0101", true);
            Assert::AreEqual(std::string("John Doe"), client->getName());
            Assert::AreEqual(std::string("555-0101"), client->getPhone());
            Assert::IsTrue(client->isRegularClient());
            Assert::AreEqual(10.0, client->getDiscountPercent());
        }

        TEST_METHOD(TestRegularClientDiscount)
        {
            auto regularClient = std::make_shared<Client>("John", "555-0101", true);
            auto regularClient2 = std::make_shared<Client>("Jane", "555-0102", false);
            
            Assert::AreEqual(10.0, regularClient->getDiscountPercent());
            Assert::AreEqual(0.0, regularClient2->getDiscountPercent());
        }
    };

    TEST_CLASS(CarServiceManagerTests)
    {
    public:
        TEST_METHOD(TestManagerServices)
        {
            CarServiceManager manager;
            auto service = std::make_shared<RepairService>("Repair", 100.0, "Engine");
            manager.addService(service);
            
            auto services = manager.getAllServices();
            Assert::AreEqual(1, (int)services.size());
        }

        TEST_METHOD(TestManagerCars)
        {
            CarServiceManager manager;
            auto car = std::make_shared<Car>("ABC123", "Toyota", "Camry", 2020);
            manager.addCar(car);
            
            auto cars = manager.getAllCars();
            Assert::AreEqual(1, (int)cars.size());
        }
    };
}

