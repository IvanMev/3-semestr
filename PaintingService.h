#pragma once

#include "Service.h"
#include <string>

namespace CarService {

    class PaintingService : public Service {
    public:
        PaintingService(const std::string& name, double price, const std::string& color);
        virtual ~PaintingService() = default;

        std::string getDescription() const override;
        std::string getServiceType() const override;

        std::string getColor() const;

    private:
        std::string color;
    };

}

