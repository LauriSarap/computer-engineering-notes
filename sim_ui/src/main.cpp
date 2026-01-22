#include <iostream>
#include <sim_engine.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  constexpr bool a{true};
  constexpr bool b{true};

  const bool result = hardware::Gate::nand(a, b);

  std::cout << std::boolalpha;
  std::cout << "--- Digital Computer Simulation ---\n";
  std::cout << "Input A: " << a << "\n";
  std::cout << "Input B: " << b << "\n";
  std::cout << "NAND Result: " << result << " (Expected: false)\n";

  std::cout << (result ? "FAILURE: Logic error." :
                          "SUCCESS: Sim engine linked correctly!")
            << "\n";

  return 0;
}
