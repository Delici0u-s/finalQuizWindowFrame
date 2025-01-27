#include "incl/utils.h"
#include "incl/conSimple.h"
#include <vector>

// innitial setup
void setup()
{
  initial();
  // Draw Background
  cte::cursor::ResetPosition();
  for (int y{0}; y < W.height; ++y)
  {
    for (int x{0}; x < W.width; ++x)
    {
      // in here goes the printing logic
      cte::colorText("#");
    }

    std::cout << '\n';
  }

  // Message below the window
  std::cout << "\n\n";
  std::cout << "Hi\n";
}

struct Monster
{
  double x;
  double y;
};

void Frame()
{
  static std::vector<Monster> monsters{{1, 1}, {5, 3}};

  // still needs some way to efficiently reset
  cte::cursor::MvTo(monsters[1].x, monsters[1].y);
  cte::colorText("#");

  monsters[1].x += 0.2*W.getDelta();

  if (monsters[1].x > W.width) monsters[1].x = 0;

  for (auto &i : monsters)
  {
    // intentional inplicid type conversion, as grid is made of integers
    cte::cursor::MvTo(i.x, i.y);
    cte::colorText("M", cte::Colors::Red);
  }


  cte::cursor::MvTo(0, W.height+1);
  std::cout << W.getDelta();
}

int main()
{
  setup();
  Run(Frame);

  return 0;
}
