#include "PaintingService.h"

namespace CarService {

    PaintingService::PaintingService(const std::string& name, double price, const std::string& color)
        : Service(name, price), color(color) {
    }

    std::string PaintingService::getDescription() const {
        return "Painting Service: " + name + " (Color: " + color + ", Price: " + std::to_string(price) + ")";
    }

    std::string PaintingService::getServiceType() const {
        return "Painting";
    }

    std::string PaintingService::getColor() const {
        return color;
    }

}

