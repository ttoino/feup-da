#ifndef TP05
#define TP05

#include <gtest/gtest.h>

#include <functional>
#include <sstream>
#include <string>

// A
void quantasDepois(std::istream &in, std::ostream &out);

// C
void sociologia(std::istream &in, std::ostream &out);

// D
void sobPressao(std::istream &in, std::ostream &out);

// E
void cronogramasLda(std::istream &in, std::ostream &out);

// Common
void test(const std::function<void(std::istream &, std::ostream &)> &f,
          const std::string &input, const std::string &output);

#endif
