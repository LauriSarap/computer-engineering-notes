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

### Phase 0: The Physics Layer (Signals & Timing)
Before logic gates, we define how data moves through simulated wires.
- [ ] **Signal Class:** Tracks voltage state ($1$, $0$, $Z$), **Strength** (Supply, Strong, Weak), and **Last State** (for transition detection).
- [ ] **The Wire/Bus Object:** Not just a primitive, but an object with **Capacitance** ($C$) and **Resistance** ($R$).
- [ ] **Master Clock:** A high-precision oscillator that synchronizes the system.
- [ ] **Bus Contention:** Resolution logic to handle "Short Circuits" when two strong signals clash.

### Phase 0.5: Power & Thermals (The "Energy" Layer)
Integrating physical phenomena into the simulation engine.
- [ ] **Energy Tracking:** Calculate $P_{dynamic} = \alpha \cdot C \cdot V^2 \cdot f$ on every state transition.
- [ ] **Thermal Dissipation:** Implement a `temperature` value for components that increases with $P$ and decays via Newton's Law of Cooling:
  $$\frac{dT}{dt} = -k(T - T_{env})$$
- [ ] **Power Rail:** A global object that tracks total current draw.

### Phase 1: Combinational Logic (Gates)
Building the atoms using the "Hardware Interface Contract."
- [ ] **Base Component Class:** Every gate must report its internal capacitance and power leakage.
- [ ] **NAND Primitive:** The only function allowed to use C++ operators.
- [ ] **Standard Library:** Build `NOT`, `AND`, `OR`, `XOR`, `NOR`.
- [ ] **Routing:** Implement Multiplexers (Mux) and Demultiplexers (Demux).

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
* **The Hardware Contract:** All components must implement `update()` and `getPowerDraw()`.
* **Event-Driven Execution:** Simulator uses an event queue; gates only re-evaluate when their inputs change.
* **Concurrency:** The `sim_engine` runs logic on one thread, while `sim_ui` renders the state on another.