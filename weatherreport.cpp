#include "weatherreport.hpp"

// --------------------------------------------------
// Implementation of Report()
// --------------------------------------------------
// Rules:
// - Default is "Sunny Day"
// - If Temp > 25:
//     * Precipitation 20-59 -> "Partly Cloudy"
//     * Precipitation >= 60 -> "Rainy"
//     * WindSpeed > 50      -> "Alert, Stormy with heavy rain"
// --------------------------------------------------
std::string Report(const WeatherSensor* sensor)
{
    int precipitation = sensor->Precipitation();
    int wind = sensor->WindSpeedKMPH();
    double temp = sensor->TemperatureInC();

    std::string report = "Sunny Day";  // Default condition

    if (temp > 25.0) {
        if (precipitation >= 20 && precipitation < 60) {
            report = "Partly Cloudy";
        } else if (precipitation >= 60) {
            report = "Rainy";
        }

        if (wind > 50) {
            report = "Alert, Stormy with heavy rain";
        }
    }

    return report;
}
