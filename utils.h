#ifndef UTILS_H
#define UTILS_H

#include <iostream>
namespace cte // console text extras
{
enum class Colors
{
  Black = 30,
  Red,
  Green,
  Yellow,
  Blue,
  Magenta,
  Cyan,
  White,
  BrightBlack = 90,
  BrightRed,
  BrightGreen,
  BrightYellow,
  BrightBlue,
  BrightMagenta,
  BrightCyan,
  BrightWhite,
};

enum class BgColors
{
  Black = 40,
  Red,
  Green,
  Yellow,
  Blue,
  Magenta,
  Cyan,
  White,
  BrightBlack = 100,
  BrightRed,
  BrightGreen,
  BrightYellow,
  BrightBlue,
  BrightMagenta,
  BrightCyan,
  BrightWhite,
};

// Hidden namespace
namespace
{
// Reset Colors
constexpr char Res[]{"\033[0m"};
// Clear the entire screen
constexpr char Clear[]{"\033[2J"};
// Reset cursor position to the top-left corner of the screen
constexpr char ResetPos[]{"\033[H"};
// Clear Current Line
constexpr char ClearL[]{"\033[2K"};
} // namespace

constexpr void colorText(const auto &Text, const Colors C = Colors::White, const BgColors Bg = BgColors::Black)
{
  std::cout << "\033[" << static_cast<int>(C) << 'm' << "\033[" << static_cast<int>(Bg) << 'm' << Text << Res;
}
constexpr void Reset()
{
  std::cout << Res;
}

namespace special
{
// clear current line of cursor
constexpr void ClearLine()
{
  std::cout << ClearL;
};
constexpr void clearScreen()
{
  std::cout << Clear << ResetPos;
}
constexpr void alert()
{
  std::cout << "\007";
}
} // namespace special

namespace cursor
{
constexpr void ResetPosition()
{
  std::cout << ResetPos;
}
constexpr void Hide()
{
  std::cout << "\033[?25l";
}
constexpr void Show()
{
  std::cout << "\033[?25h";
}
} // namespace cursor
} // namespace cte

#endif // UTILS_H
