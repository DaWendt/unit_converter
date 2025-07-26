//
// Created by Daniel Wendt on 26.07.25.
//

#ifndef UNIT_CONVERTER_UNITS_H
#define UNIT_CONVERTER_UNITS_H

#include <functional>
#include <string>

enum class UnitType { Temperature, Length, Mass };
enum class Unit { Celsius, Fahrenheit, Kelvin, Meter, Kilometer, Kilogram, Pound };

struct UnitInfo {
    UnitType type;
    std::string name;
    std::function<double(double)> to_base;   // convert to base
    std::function<double(double)> from_base; // convert from base
};

std::optional<double> convert(double value, Unit from, Unit to);

#endif
