# 💻 Computer From Scratch (C++ / Bake)

A bottom-up implementation of a 16-bit RISC computer architecture, heavily inspired by **ARM** and **MMIX** philosophy. We start at the level of electrical signals and build up to a programmable system that accounts for physical phenomena like power and heat.

## 🛠 Tech Stack
* **Language:** C++ (Systems-focused implementation)
* **Build System:** [Bake](https://github.com/SanderMertens/bake)
* **OS:** Arch Linux
* **Visualization:** Raylib / Dear ImGui
* **Target Architecture:** 16-bit RISC (8-16 General Purpose Registers)

---

## 🗺 The "Hardware-First" Roadmap

### Phase 0: Foundation Layer (Minimal Infrastructure)
Establish the bare minimum needed to build gates. This replaces the current boolean-based approach with a proper hardware simulation foundation.

- [ ] **Signal Class**: Create a `Signal` class that represents a wire's state. It needs to hold three possible values: `HIGH` ($1$), `LOW` ($0$), and `FLOATING` ($Z$ for high-impedance/tri-state). This replaces `bool` in the current `Gate::nand()` implementation. Start simple: an enum and basic getters/setters.

- [ ] **Component Base Class**: Create a `Component` base class that all gates will inherit from. It should define the "Hardware Interface Contract": an `update()` method that gates call to compute their outputs based on inputs. This is what Phase 1 gates will inherit from.

- [ ] **Basic Wiring**: Implement a simple way to connect component outputs to inputs. This can be as simple as storing a `Signal*` pointer - when a gate's output changes, connected inputs automatically see the new value. No fancy propagation needed yet, just the ability to link outputs to inputs.

### Phase 1: Combinational Logic (Gates)
Building the atoms using the "Hardware Interface Contract" from Phase 0.
- [ ] **NAND Primitive:** Refactor the current `Gate::nand()` to use `Signal` instead of `bool`. This is the only function allowed to use C++ operators (`!`, `&&`). All other gates must be built from NAND.
- [ ] **Standard Library:** Build `NOT`, `AND`, `OR`, `XOR`, `NOR` gates by composing NAND gates. Each should inherit from `Component` and implement `update()`.
- [ ] **Routing:** Implement Multiplexers (Mux) and Demultiplexers (Demux) using the standard gates.

### Phase 2: The ALU (Arithmetic Logic Unit)
Moving from logic to mathematics.
- [ ] **Binary Arithmetic:** Implement `HalfAdder` and `FullAdder`.
- [ ] **16-bit Adder:** A Ripple-Carry or Carry-Lookahead adder.
- [ ] **The ALU:** Performs operations based on control bits ($ADD$, $SUB$, $AND$, $OR$, $SLT$).
- [ ] **Condition Flags:** $Z$ (Zero), $N$ (Negative), $C$ (Carry), $V$ (Overflow).

### Phase 3: Sequential Logic (Memory)
Introducing the concept of "State."
- [ ] **D-Flip-Flop:** Memory that only changes on a clock edge.
- [ ] **Register File:** A bank of 8-16 general-purpose registers (RISC/MMIX style).
- [ ] **RAM:** A 16-bit addressable grid of memory (no `std::map` allowed).

### Phase 4: The CPU & ISA Design
Designing the brain and the Instruction Set Architecture.
- [ ] **ISA Specification:** Define the 16-bit RISC instruction format.
- [ ] **Instruction Decoder:** Turns machine code into control signals for the datapath.
- [ ] **Control Unit:** The Finite State Machine managing the Fetch-Decode-Execute cycle.

### Phase 5: Peripherals & I/O
How the CPU sees the world.
- [ ] **Memory Mapping:** High-memory addresses mapped to virtual hardware.
- [ ] **Video Buffer:** A pixel grid mapped directly to RAM for graphical output.
- [ ] **Integrated Visualizer:** Use Raylib to draw a real-time heat map and logic-state diagram.

### Phase 6: The Software Stack
- [ ] **Assembler:** Translate `.asm` code into machine-executable binary.
- [ ] **Monitor/BIOS:** A small program to initialize system state and handle basic I/O.
- [ ] **C-Compiler (Stretch Goal):** A basic compiler targeting our custom ISA.

---

## 📐 Key Design Decisions
1. **Word Size:** 16-bit.
2. **Logic Style:** Structural & Switch-Level hybrid.
3. **MMIX Influence:** Clean, orthogonal instruction set and register usage.
4. **Energy Realism:** Power and Thermals are first-class citizens in the simulation loop.

## ⚡ Internal Simulation Mechanics
* **The Hardware Contract:** All components must implement `update()` to compute outputs from inputs. Power tracking (`getPowerDraw()`) will be added in a later phase.
* **Event-Driven Execution:** Simulator uses an event queue; gates only re-evaluate when their inputs change. (Can start simple with immediate evaluation, optimize later.)
* **Concurrency:** The `sim_engine` runs logic on one thread, while `sim_ui` renders the state on another.