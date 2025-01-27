#include <chrono>
#include <thread>
#include "utils.h"
#include "Timer.h"

// struct to handle window size etc
struct Gwindow
{
  static constexpr int width{20};
  static constexpr int height{10};
  static constexpr int fps = 24;
  static constexpr std::chrono::milliseconds frameTime{1000 / fps};
  std::chrono::milliseconds DeltaT{frameTime};
};

// Global Window, 
Gwindow W{};

// Function to print text everytime. By adding args you can like print special based on enemy pos
void Run()
{
  Timer clock{};
  auto targetFrameTime = std::chrono::steady_clock::now();

  for (;;)
  {
    // go to top left and print "screen" accordingly
    cte::cursor::ResetPosition();
    for (int y{0}; y < W.height; ++y)
    {
      for (int x{0}; x < W.width; ++x)
      {
        // in here goes the printing logic
        cte::colorText("# ");
      }

      std::cout << '\n';
    }

    // set deltatime, may be needed for something like movement
    W.DeltaT = clock.elapsed<std::chrono::milliseconds>();

    // calculate time to wait till next frame is "rendered"
    targetFrameTime += W.frameTime;
    if (std::chrono::steady_clock::now() < targetFrameTime) { std::this_thread::sleep_until(targetFrameTime); }
    clock.reset();
  }
}

// innitial setup
void setup()
{
  cte::special::clearScreen();
  cte::cursor::Hide();
  for (int i{0}; i < W.height; ++i) { std::cout << '\n'; }
  std::cout << "\n\n";
  std::cout << "Hi\n";
}

int main()
{
  setup();
  Run();

  return 0;
}

