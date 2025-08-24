#include "misaligned.hpp"
#include <vector>
#include <tuple>
#include <string>

// ===================================================
// Internal data generator (BUGGY on purpose!)
// ===================================================
//
// Generates the color map as a vector of tuples:
//   (index, majorColor, minorColor)
//
// BUG: Instead of using minorColor[j], it mistakenly uses minorColor[i].
// This causes wrong output, but we are NOT fixing it here.
// The purpose of the assignment is to expose this bug via strong tests.
//
static std::vector<std::tuple<int, std::string, std::string>> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<std::tuple<int, std::string, std::string>> colorMap;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // BUG HERE: minorColor[i] instead of minorColor[j]
            colorMap.emplace_back(i * 5 + j + 1, majorColor[i], minorColor[i]);
        }
    }
    return colorMap;
}

// ===================================================
// Helper function: formats one line of output
// ===================================================
static std::string formatColorMapEntry(int index, const std::string& major, const std::string& minor) {
    return std::to_string(index) + " | " + major + " | " + minor;
}

// ===================================================
// Public API function
// ===================================================
//
// Loops through the generated map, formats each line,
// and passes it to the caller-provided output function.
// Returns the total number of entries.
//
int printColorMap(const std::function<void(const std::string&)>& outputFunc) {
    auto colorMap = generateColorMap();
    for (const auto& [index, major, minor] : colorMap) {
        outputFunc(formatColorMapEntry(index, major, minor));
    }
    return static_cast<int>(colorMap.size());
}
