#ifndef MISALIGNED_HPP
#define MISALIGNED_HPP

#include <functional>
#include <string>

// ==========================
// Public API (Header file)
// ==========================
//
// The assignment requires us to keep the buggy implementation as-is,
// but write stronger tests to expose the bug.
//
// Only this function is visible to the outside world.
// Internally, helper functions will do the work.
//
// Arguments:
//   - outputFunc: A callback function to handle each formatted line.
//                 This makes the function more testable, since in
//                 production you could pass `[](auto line){ std::cout << line << std::endl; }`,
//                 and in tests we can pass a "capture" function.
//
// Returns:
//   - Total number of color pairs (always 25, since 5 major × 5 minor).
//
int printColorMap(const std::function<void(const std::string&)>& outputFunc);

#endif // MISALIGNED_HPP
