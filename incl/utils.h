#pragma once
#include "conSimple.h"
#include <chrono>
#include <functional>
#include <thread>
#include "Timer.h"

// struct to handle window size etc
struct Gwindow
{
  static constexpr int width{40};
  static constexpr int height{10};
  static constexpr int fps = 25;
  static constexpr std::chrono::milliseconds frameTime{1000 / fps};
  std::chrono::milliseconds DeltaT{1000/fps};
  constexpr double getDelta() {return DeltaT.count() / 100.0;}
};

// Global Window, default statistics
static Gwindow W{};

// Function to print text everytime. By adding args you can like print special based on enemy pos
constexpr void Run(const auto F)
{
  Timer clock{};
  auto targetFrameTime = std::chrono::steady_clock::now();

  for (;;)
  {
    // go to top left and print "screen" accordingly
    F();
    std::cout << std::flush;

    // calculate time to wait till next frame is "rendered"
    targetFrameTime += W.frameTime;
    if (std::chrono::steady_clock::now() < targetFrameTime) { std::this_thread::sleep_until(targetFrameTime); }

    // set deltatime, may be needed for something like movement
    W.DeltaT = clock.elapsed<std::chrono::milliseconds>();
    clock.reset();
  }
}

constexpr void initial()
{
  cte::special::clearScreen();
  cte::cursor::Hide();
  for (int i{0}; i < W.height; ++i) { std::cout << '\n'; }
}
