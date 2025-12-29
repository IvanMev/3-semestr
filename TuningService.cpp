#include "TuningService.h"

namespace CarService {

    TuningService::TuningService(const std::string& name, double price, const std::string& tuningCategory)
        : Service(name, price), tuningCategory(tuningCategory) {
    }

    std::string TuningService::getDescription() const {
        return "Услуга тюнинга: " + name + " (Категория: " + tuningCategory + ", Цена: " + std::to_string(price) + ")";
    }

    std::string TuningService::getServiceType() const {
        return "Тюнинг";
    }

    std::string TuningService::getTuningCategory() const {
        return tuningCategory;
    }

}

