#include <chrono>
#include <thread>
#include "utils.h"
#include "Timer.h"

struct Gwindow
{
  static constexpr int width{10};
  static constexpr int height{10};
  static constexpr int fps = 24;
  static constexpr std::chrono::milliseconds frameTime{1000 / fps};
  std::chrono::milliseconds DeltaT{frameTime};
};

// Global Window, 
Gwindow W{};

void Run()
{
  Timer clock{};
  auto targetFrameTime = std::chrono::steady_clock::now();

  int FrameCountr{0};
  int DispFps{0};
  auto SecondWatch = std::chrono::steady_clock::now();

  int countr{0};

  for (;;)
  {
    cte::cursor::ResetPosition();
    for (int y{0}; y < W.height; ++y)
    {
      for (int x{0}; x < W.width; ++x)
      {
        if (x + y * W.height < countr) { cte::colorText("X ", cte::Colors::Black, cte::BgColors::Green); }
        else if (x + y * W.height == countr){ cte::colorText("> "); }
        else { cte::colorText("O ", cte::Colors::Red, cte::BgColors::White); }
      }
      std::cout << '\n';
    }
    // reset colors (bg and normal)
    cte::Reset();

    countr < W.width *W.height ? ++countr : countr = 0;


    // StatisticsCalculations
    ++FrameCountr;
    if (std::chrono::steady_clock::now() - SecondWatch >= std::chrono::seconds(1))
    {
      DispFps = FrameCountr;
      FrameCountr = 0;
      SecondWatch = std::chrono::steady_clock::now();
    }


    // Print Statistics
    std::cout << '\n';
    cte::special::ClearLine();
    std::cout << "Point Counter: " << countr << " Fps: " << DispFps << '\\' << W.fps
              << " LastFrameExecutionTime: " << W.DeltaT;

    // set deltatime, may be needed for something
    W.DeltaT = clock.elapsed<std::chrono::milliseconds>();

    targetFrameTime += W.frameTime;
    if (std::chrono::steady_clock::now() < targetFrameTime) { std::this_thread::sleep_until(targetFrameTime); }
    clock.reset();
  }
}

void setup()
{
  cte::special::clearScreen();
  cte::cursor::Hide();
  for (int i{0}; i < W.height; ++i) { std::cout << '\n'; }
  std::cout << "\n\n\n";
  std::cout << "The Above is a potential rendering example.\n";
  std::cout << "As the cursor jumps to the beginning per RunScreen here could controls be displayed\n";
  std::cout << "or an inventory if RunScreen is updated\n";
}

int main()
{
  setup();
  Run();

  return 0;
}
