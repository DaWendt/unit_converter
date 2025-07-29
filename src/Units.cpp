//
// Created by Daniel Wendt on 26.07.25.
//

#include "Units.h"
#include <functional>
#include <optional>
#include <string>
#include <unordered_map>

const std::unordered_map<Unit, UnitInfo> unit_registry = {
    // Temperature (base: Celsius)
    {Unit::Celsius,
     {UnitType::Temperature, "°C", [](double x) { return x; }, [](double x) { return x; }}},
    {Unit::Fahrenheit,
     {UnitType::Temperature, "°F", [](double x) { return (x - 32) * 5.0 / 9.0; }, // F to C
      [](double x) { return x * 9.0 / 5.0 + 32; }}},                              // C to F
    {Unit::Kelvin,
     {UnitType::Temperature, "K", [](double x) { return x - 273.15; }, // K to C
      [](double x) { return x + 273.15; }}},                           // C to K

    // Length (base: Meter)
    {Unit::Meter, {UnitType::Length, "m", [](double x) { return x; }, [](double x) { return x; }}},
    {Unit::Kilometer,
     {UnitType::Length, "km", [](double x) { return x * 1000; }, // km to m
      [](double x) { return x / 1000; }}},                       // m to km

    // Mass (base: Kilogram)
    {Unit::Kilogram,
     {UnitType::Mass, "kg", [](double x) { return x; }, [](double x) { return x; }}},
    {Unit::Pound,
     {UnitType::Mass, "lb", [](double x) { return x / 2.2046; },
      [](double x) { return x * 2.2046; }}}};

std::optional<double> convert(double value, Unit from, Unit to) {
    auto from_info = unit_registry.find(from);
    auto to_info = unit_registry.find(to);

    if (from_info == unit_registry.end() || to_info == unit_registry.end()) {
        return std::nullopt; // Invalid units
    }

    if (from_info->second.type != to_info->second.type) {
        return std::nullopt; // Incompatible types
    }

    // Convert: from -> base -> to
    double base_value = from_info->second.to_base(value);
    return to_info->second.from_base(base_value);
};