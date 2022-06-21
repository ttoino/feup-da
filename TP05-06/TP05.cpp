#include "TP05.h"

#include <gtest/gtest.h>

void test(const std::function<void(std::istream &, std::ostream &)> &f,
          const std::string &input, const std::string &output) {
    std::istringstream in{input};
    std::ostringstream out;
    f(in, out);

    EXPECT_EQ(output, out.str());
}
