#include "utils.h"
#include "conSimple.h"

// innitial setup
void setup()
{
  initial();
  // Message below the window
  std::cout << "\n\n";
  std::cout << "Hi\n";
}

void Frame()
{
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
}

int main()
{
  setup();
  Run(Frame);

  return 0;
}
