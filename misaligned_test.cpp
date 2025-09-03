#include "misaligned.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

// Stores captured lines from printColorMap()
static std::vector<std::string> capturedLines;

// Capture output instead of printing to console
void captureOutput(const std::string& line) {
    capturedLines.push_back(line);
}

// Expected correct output (ground truth)
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

// ---------- Tests ----------

// Test 1: Check total count
TEST(ColorMapTest, CountIsCorrect) {
    capturedLines.clear();
    int count = printColorMap(captureOutput);
    EXPECT_EQ(count, 25);
}

// Test 2: Compare full output (should fail due to bug)
TEST(ColorMapTest, LinesMatchExpected) {
    capturedLines.clear();
    printColorMap(captureOutput);
    auto expected = generateExpectedOutput();
    EXPECT_EQ(capturedLines, expected);
}

// Test 3: Spot-check first and last entry
TEST(ColorMapTest, FirstAndLastEntries) {
    capturedLines.clear();
    printColorMap(captureOutput);

    ASSERT_EQ(capturedLines.size(), 25);
    EXPECT_EQ(capturedLines.front(), "1 | White | Blue");      // should pass
    EXPECT_EQ(capturedLines.back(), "25 | Violet | Slate");    // will fail
}

// Run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
