#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

#include <string>

// -----------------------------------------
// WeatherSensor interface-like structure
// -----------------------------------------
// Instead of hardware drivers, we use function pointers
// so we can easily provide test stubs in unit tests.
//
struct WeatherSensor {
    double (*TemperatureInC)(void);   // Returns temperature in °C
    int    (*Precipitation)(void);    // Returns precipitation %
    int    (*Humidity)(void);         // Returns humidity %
    int    (*WindSpeedKMPH)(void);    // Returns wind speed in km/h
};

// Function under test: Returns a weather report string
std::string Report(const WeatherSensor* sensor);

#endif // WEATHERREPORT_H
