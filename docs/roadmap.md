# 💻 Computer From Scratch (C++ / Bake)

A bottom-up implementation of a 16-bit computer architecture, starting from the logic gate level and moving up to a functional CPU, Assembler, and Virtual Visualizer.

## 🛠 Tech Stack
* **Language:** C++ (Systems-focused implementation)
* **Build System:** [Bake](https://github.com/SanderMertens/bake)
* **OS:** Arch Linux
* **Visualization:** Raylib / Dear ImGui (Planned)
* **Target Architecture:** 16-bit Custom ISA

---

## 🗺 The Roadmap

### Phase 1: The Logical Foundation (Combinational Logic)
The goal is to build every gate using only the `NAND` primitive.
- [ ] **Primitives:** Implement `NAND` as the atom of the system.
- [ ] **Basic Gates:** Build `NOT`, `AND`, `OR`, `XOR`.
- [ ] **Multi-Bit Gates:** Create 16-bit versions of basic gates.
- [ ] **Multiplexers:** Implement `Mux` and `Demux` (The traffic controllers of the CPU).
  - *Logic:* $out = (a \cdot \neg sel) + (b \cdot sel)$

### Phase 2: The Arithmetic Logic Unit (ALU)
Moving from logic to math.
- [ ] **Adders:** Implement `HalfAdder` and `FullAdder`.
- [ ] **Multi-bit Adder:** Build a 16-bit Adder to handle hexadecimal math.
- [ ] **The ALU:** A unified component that can perform `ADD`, `AND`, `OR`, and `NOT` based on control bits.
- [ ] **Status Flags:** Implement Zero ($Z$) and Negative ($N$) flags for conditional logic.

### Phase 3: Memory & Sequential Logic
Introducing time and state.
- [ ] **The Flip-Flop:** Implement the D-Flip-Flop (The smallest unit of memory).
- [ ] **Registers:** Build a 16-bit Register to store values.
- [ ] **RAM:** Create a memory grid by stacking registers.
- [ ] **Program Counter (PC):** A specialized register that tracks the address of the next instruction.

### Phase 4: The CPU & Instruction Set Architecture (ISA)
Designing the brain.
- [ ] **Instruction Decoder:** A module that takes a 16-bit "Hex instruction" and converts it into control signals.
- [ ] **The CPU:** Connecting the ALU, Registers, and PC onto a shared Data Bus.
- [ ] **Control Unit:** Managing the Fetch-Decode-Execute cycle.
- [ ] **The Bus:** Implementing the Address Bus and Data Bus logic.

### Phase 5: The Software Stack
Talking to the machine.
- [ ] **The Assembler:** A C++ tool that translates `.asm` files into binary/hex images.
- [ ] **The Simulator UI:** A Raylib-based dashboard to visualize registers, memory, and the clock in real-time.
- [ ] **Basic OS/Programs:** Writing a "Hello World" or a math program in your custom Assembly.

---

## 🚀 How to Build

### Prerequisites
Ensure `bake` is installed and in your `PATH`.

### Compile & Run
To build the engine and run the visualizer/test suite:
```bash
# Build everything recursively
bake --recursive

# Run the UI / Sanity Check
bake run sim_ui