#include "misaligned.hpp"
#include <vector>
#include <tuple>
#include <string>

// Generate color map (BUG: uses minorColor[i] instead of minorColor[j])
static std::vector<std::tuple<int, std::string, std::string>> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<std::tuple<int, std::string, std::string>> colorMap;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            colorMap.emplace_back(i * 5 + j + 1, majorColor[i], minorColor[i]); // BUG
        }
    }
    return colorMap;
}

// Format one entry into a string
static std::string formatColorMapEntry(int index, const std::string& major, const std::string& minor) {
    return std::to_string(index) + " | " + major + " | " + minor;
}

// Public API: format and send all entries to outputFunc
int printColorMap(const std::function<void(const std::string&)>& outputFunc) {
    auto colorMap = generateColorMap();
    for (const auto& [index, major, minor] : colorMap) {
        outputFunc(formatColorMapEntry(index, major, minor));
    }
    return static_cast<int>(colorMap.size());
}
