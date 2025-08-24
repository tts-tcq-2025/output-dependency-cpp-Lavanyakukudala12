#include "misaligned.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

// ===================================================
// Test setup
// ===================================================

// Global container to capture output
static std::vector<std::string> capturedLines;

// Capture function to be passed to printColorMap()
// Instead of printing to console, we store each line in capturedLines.
void captureOutput(const std::string& line) {
    capturedLines.push_back(line);
}

// Helper: generate the CORRECT expected output (ground truth)
std::vector<std::string> generateExpectedOutput() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> expected;
    int index = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expected.push_back(
                std::to_string(index++) + " | " + majorColor[i] + " | " + minorColor[j]
            );
        }
    }
    return expected;
}

// ===================================================
// Unit tests (GoogleTest)
// ===================================================

// Test 1: Verify that the count is correct (should be 25)
TEST(ColorMapTest, CountIsCorrect) {
    capturedLines.clear();
    int count = printColorMap(captureOutput);
    EXPECT_EQ(count, 25);
}

// Test 2: Verify that every generated line matches the expected output
// This will FAIL because of the bug (minorColor[i] vs minorColor[j]).
TEST(ColorMapTest, LinesMatchExpected) {
    capturedLines.clear();
    printColorMap(captureOutput);
    auto expected = generateExpectedOutput();
    EXPECT_EQ(capturedLines, expected);
}

// Test 3: Spot-check specific entries
// The first entry will pass, but the last entry will FAIL.
TEST(ColorMapTest, FirstAndLastEntries) {
    capturedLines.clear();
    printColorMap(captureOutput);

    ASSERT_EQ(capturedLines.size(), 25);

    // First entry should be correct
    EXPECT_EQ(capturedLines.front(), "1 | White | Blue");

    // Last entry should be correct (but will fail due to bug)
    EXPECT_EQ(capturedLines.back(), "25 | Violet | Slate");
}

// ===================================================
// Test runner
// ===================================================
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
