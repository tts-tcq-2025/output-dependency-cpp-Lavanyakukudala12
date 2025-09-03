#ifndef MISALIGNED_HPP
#define MISALIGNED_HPP

#include <functional>
#include <string>

// Public API for printing the color map.
// - outputFunc: callback to handle each formatted line.
// - returns: total number of color pairs (25).
int printColorMap(const std::function<void(const std::string&)>& outputFunc);

#endif // MISALIGNED_HPP
