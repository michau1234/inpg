#include "vehicles.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

   
double compute_min_travel_duration(double distance, const Vehicle& vehicle) {
    return distance / vehicle.get_max_speed();
}

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle) {
    std::ostringstream oss;
    oss << std::setprecision(3) << std::fixed
        << compute_min_travel_duration(distance, vehicle) << " h";
    return oss.str();
}

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool(const Vehicle&)> predicate) {

    std::vector<Vehicle*> vehicles_filtered;
    std::copy_if(vehicles_begin, vehicles_end, std::back_inserter(vehicles_filtered),
                 [&predicate](const Vehicle* vehicle_ptr) { return predicate(*vehicle_ptr); });
    return vehicles_filtered;
}
