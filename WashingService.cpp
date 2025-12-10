#include "WashingService.h"

namespace CarService {

    WashingService::WashingService(const std::string& name, double price, bool isDryCleaning)
        : Service(name, price), dryCleaning(isDryCleaning) {
    }

    std::string WashingService::getDescription() const {
        std::string type = dryCleaning ? "Dry Cleaning" : "Regular Washing";
        return "Washing Service: " + name + " (Type: " + type + ", Price: " + std::to_string(price) + ")";
    }

    std::string WashingService::getServiceType() const {
        return "Washing";
    }

    bool WashingService::isDryCleaningService() const {
        return dryCleaning;
    }

}

