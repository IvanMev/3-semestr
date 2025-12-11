#include "WashingService.h"

namespace CarService {

    WashingService::WashingService(const std::string& name, double price, bool isDryCleaning)
        : Service(name, price), dryCleaning(isDryCleaning) {
    }

    std::string WashingService::getDescription() const {
        std::string type = dryCleaning ? "Химчистка" : "Обычная мойка";
        return "Услуга мойки: " + name + " (Тип: " + type + ", Цена: " + std::to_string(price) + ")";
    }

    std::string WashingService::getServiceType() const {
        return "Мойка";
    }

    bool WashingService::isDryCleaningService() const {
        return dryCleaning;
    }

}

