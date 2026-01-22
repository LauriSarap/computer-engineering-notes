#ifndef SIM_ENGINE_H
#define SIM_ENGINE_H

namespace hardware {
class Gate {
public:
  static bool nand(bool a, bool b) { return !(a && b); }
};
} // namespace hardware
#endif
