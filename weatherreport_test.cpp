#include "weatherreport.hpp"
#include <gtest/gtest.h>

// ---------------------------
// Test stub implementations
// ---------------------------
static double tempHigh() { return 30.0; }
static double tempLow()  { return 20.0; }

static int precipLow()   { return 10; }
static int precipMid()   { return 30; }
static int precipHigh()  { return 70; }

static int windLow()     { return 20; }
static int windHigh()    { return 60; }

static int dummyHumidity() { return 50; } // Not used in Report()

// ---------------------------
// Helper to build a WeatherSensor
// ---------------------------
WeatherSensor makeSensor(double (*temp)(), int (*precip)(), int (*hum)(), int (*wind)()) {
    WeatherSensor sensor { temp, precip, hum, wind };
    return sensor;
}

// ---------------------------
// Unit Tests
// ---------------------------

TEST(WeatherReportTest, DefaultSunnyDay) {
    auto sensor = makeSensor(tempLow, precipLow, dummyHumidity, windLow);
    EXPECT_EQ(Report(&sensor), "Sunny Day");
}

TEST(WeatherReportTest, PartlyCloudy) {
    auto sensor = makeSensor(tempHigh, precipMid, dummyHumidity, windLow);
    EXPECT_EQ(Report(&sensor), "Partly Cloudy");
}

TEST(WeatherReportTest, Rainy) {
    auto sensor = makeSensor(tempHigh, precipHigh, dummyHumidity, windLow);
    EXPECT_EQ(Report(&sensor), "Rainy");
}

TEST(WeatherReportTest, Stormy) {
    auto sensor = makeSensor(tempHigh, precipMid, dummyHumidity, windHigh);
    EXPECT_EQ(Report(&sensor), "Alert, Stormy with heavy rain");
}

