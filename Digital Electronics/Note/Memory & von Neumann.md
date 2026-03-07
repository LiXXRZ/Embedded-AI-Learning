### **Part 1: Fundamentals of Digital Memory**
### **第一部分：数字存储器基础**

#### **1. Basic Definitions**
#### **1. 基本定义**

*   **Memory**: The ability to store data in a digital form (ones and zeros) for a period of time.
    *   **存储器**：以数字形式（1和0）存储数据一段时间的能力。
*   **Bit**: The most basic unit of information, a single one or zero.
    *   **比特 (Bit)**：最基本的信息单位，一个单独的1或0。
*   **Nibble**: A unit of 4 bits.
    *   **半字节 (Nibble)**：一个4比特的单位。
*   **Byte**: A unit of 8 bits.
    *   **字节 (Byte)**：一个8比特的单位。
*   **Word**: A complete unit of information, generally consisting of one or more bytes.
    *   **字 (Word)**：一个完整的信息单位，通常由一个或多个字节组成。

#### **2. Memory Arrays and Capacity**
#### **2. 存储阵列与容量**

*   **Memory Array**: A grid of memory cells organized to store data. A 64-cell array could be configured as 8x8, 16x4, or 64x1.
    *   **存储阵列**：用于存储数据的存储单元网格。一个64单元的阵列可以配置为8x8、16x4或64x1。
*   **Storage Capacity**: The total amount of data that can be stored on the device.
    *   **存储容量**：设备上可以存储的数据总量。
*   In the context of memory, 'k' refers to 1024 (2<sup>10</sup>), not 1000.
    *   在存储器领域，'k' 指的是 1024 (2<sup>10</sup>)，而不是1000。
*   **Example**: A 16k x 8 memory can store 16,384 words, where each word is 8 bits (1 byte) long.
    *   **示例**：一个 16k x 8 的存储器可以存储 16,384 个字，每个字长为8比特（1字节）。
    *   Total capacity in bytes: `16 x 1024 = 16384 bytes` (since 16 = 2<sup>4</sup> and 1024 = 2<sup>10</sup>, this is 2<sup>4</sup> x 2<sup>10</sup> = 2<sup>14</sup> bytes).
    *   以字节为单位的总容量：`16 x 1024 = 16384 字节`（因为 16 = 2<sup>4</sup> 且 1024 = 2<sup>10</sup>，所以这是 2<sup>4</sup> x 2<sup>10</sup> = 2<sup>14</sup> 字节）。
    *   Total capacity in bits: `16384 x 8 = 131,072 bits`.
    *   以比特为单位的总容量：`16384 x 8 = 131,072 比特`。

#### **3. Memory Structure and Operations**
#### **3. 存储器结构与操作**

*   **Core Components**: A memory system consists of an address decoder, a memory array, an address bus, and a data bus.
    *   **核心组件**：一个存储系统由地址译码器、存储阵列、地址总线和数据总线组成。
*   **Address Bus**: Carries the binary address of the memory location to be accessed.
    *   **地址总线**：传送待访问的存储位置的二进制地址。
*   **Address Decoder**: Interprets the binary address and selects the specific memory location (word).
    *   **地址译码器**：解释二进制地址并选择特定的存储位置（字）。
*   **Data Bus**: A bidirectional path to transfer data to (write) or from (read) the memory array.
    *   **数据总线**：用于向存储阵列传输数据（写入）或从存储阵列传出数据（读取）的双向路径。

##### **Writing Operation**
##### **写操作**

1.  The address code (e.g., `101`) is placed on the address bus.
    *   地址码（例如 `101`）被放到地址总线上。
2.  The address decoder selects the corresponding memory location (e.g., address 5).
    *   地址译码器选择相应的存储位置（例如地址5）。
3.  The data byte (e.g., `10011111`) is placed on the data bus.
    *   数据字节（例如 `10011111`）被放到数据总线上。
4.  A write command is issued, causing the data on the data bus to be stored in the selected address, replacing any previous data.
    *   发出写命令，使数据总线上的数据存储到选定的地址中，替换掉之前的数据。

##### **Reading Operation**
##### **读操作**

1.  The address code (e.g., `011`) is placed on the address bus, and the decoder selects the location (e.g., address 3).
    *   地址码（例如 `011`）被放到地址总线上，译码器选择该位置（例如地址3）。
2.  A read command is applied.
    *   应用读命令。
3.  The contents of the selected address are placed onto the data bus to be read by another component (e.g., a CPU).
    *   所选地址的内容被放到数据总线上，以供其他组件（如CPU）读取。
4.  The reading operation is **non-destructive**; the data in the memory location is not erased.
    *   读操作是**非破坏性**的；存储位置中的数据不会被擦除。

---

### **Part 2: Memory Types and Technologies**
### **第二部分：存储器类型与技术**

#### **1. General Categories**
#### **1. 基本分类**

*   **RAM (Random-Access Memory)**: Any memory location can be accessed in an equal amount of time. Most RAM is **volatile**, meaning it loses its data when power is turned off.
    *   **RAM (随机存取存储器)**：任何存储位置都可以在相等的时间内被访问。大多数RAM是**易失性**的，意味着断电后数据会丢失。
*   **ROM (Read-Only Memory)**: Data is stored permanently or semi-permanently and can only be read, not written to (in normal operation). Most ROM is **non-volatile**.
    *   **ROM (只读存储器)**：数据被永久或半永久地存储，并且（在正常操作下）只能读取，不能写入。大多数ROM是**非易失性**的。

#### **2. Cache Memory**
#### **2. 高速缓存 (Cache)**

*   **Function**: A small, high-speed memory that stores a copy of a small section of main memory.
    *   **功能**：一种小容量、高速度的存储器，用于存储主存储器一小部分的副本。
*   **Purpose**: It is faster than main memory and is located next to the processor to reduce the time it takes to access frequently used data.
    *   **目的**：它比主存储器快，并位于处理器旁边，以减少访问常用数据所需的时间。
*   **Levels**: L1 cache is internal to the microprocessor; L2 cache is external but still very close.
    *   **级别**：L1缓存位于微处理器内部；L2缓存位于外部但仍然非常靠近。

#### **3. SRAM (Static RAM)**
#### **3. SRAM (静态RAM)**

*   **Memory Cell**: Built from single-bit latches (typically using 6 transistors). It holds its state as long as DC power is applied.
    *   **存储单元**：由单位比特的锁存器构成（通常使用6个晶体管）。只要施加直流电源，它就会保持其状态。
*   **Key Properties**:
    *   **关键特性**：
    *   **Faster** than DRAM.
        *   比 DRAM **速度更快**。
    *   More **expensive** and less **dense** (less bits per area) than DRAM.
        *   比 DRAM **更昂贵**且**密度更低**（单位面积比特数更少）。
    *   Does **not** require periodic refreshing.
        *   **不**需要周期性刷新。
    *   Used for applications where speed is critical, such as **cache memory** (e.g., L2 cache).
        *   用于速度至关重要的应用，例如**高速缓存**（如L2缓存）。

#### **4. DRAM (Dynamic RAM)**
#### **4. DRAM (动态RAM)**

*   **Memory Cell**: Stores each bit of data in a separate capacitor.
    *   **存储单元**：将每一比特的数据存储在一个独立的电容器中。
*   **Key Properties**:
    *   **关键特性**：
    *   Very **simple** cell structure (1 transistor, 1 capacitor), allowing for very **high density** and **low cost per bit**.
        *   单元结构非常**简单**（1个晶体管，1个电容器），因此**密度非常高**且**每比特成本低**。
    *   Capacitors leak charge, so the data fades over time.
        *   电容器会漏电，因此数据会随时间衰退。
    *   It **must be refreshed periodically** (e.g., every 64 ms), which requires additional circuitry.
        *   它**必须被周期性刷新**（例如，每64毫秒），这需要额外的电路。
    *   Used for the **main memory** in personal computers due to its high capacity and low cost.
        *   因其高容量和低成本而被用作个人计算机的**主存储器**。

#### **5. Flash Memory**
#### **5. 闪存**

*   **Function**: A high-density, read/write memory that is **non-volatile**, meaning it stores data indefinitely without power.
    *   **功能**：一种高密度的、可读写的**非易失性**存储器，意味着它可以在没有电源的情况下无限期地存储数据。
*   **Cell Operation**: Uses a single MOS transistor with a **control gate** and a **floating gate**.
    *   **单元操作**：使用一个带有**控制门**和**浮动门**的MOS晶体管。
*   **Data Storage**: Data is stored as an electric charge on the floating gate.
    *   **数据存储**：数据以电荷的形式存储在浮动门上。
    *   `0` = a lot of negative charge.
        *   `0` = 大量负电荷。
    *   `1` = less charge.
        *   `1` = 较少电荷。

#### **6. Comparison of Memory Types**
#### **6. 存储器类型比较**

| Memory Type | Non-volatile (非易失性) | High Density (高密度) | One Transistor Cell (单晶体管单元) | In-system Writability (可系统内写入) |
| :--- | :--- | :--- | :--- | :--- |
| **Flash (闪存)** | Yes | Yes | Yes | Yes |
| **SRAM (静态RAM)** | No | No | No | Yes |
| **DRAM (动态RAM)** | No | Yes | Yes | Yes |
| **ROM (只读存储器)** | Yes | Yes | Yes | No |

---

### **Part 3: Basic Processors & Von Neumann Architecture**
### **第三部分：基本处理器与冯·诺依曼架构**

#### **1. The von Neumann Architecture**
#### **1. 冯·诺依曼架构**

*   **Concept**: A computer design model that uses a single storage structure (memory) to hold both program instructions and data.
    *   **概念**：一种计算机设计模型，它使用单一的存储结构（内存）来同时存放程序指令和数据。
*   This ability to treat instructions as data is what makes compilers and assemblers possible.
    *   这种将指令视为数据的能力使得编译器和汇编器成为可能。
*   **Core Components**:
    *   **核心组件**：
    *   **Memory**: Stores instructions and data.
        *   **存储器**：存储指令和数据。
    *   **Control Unit (CU)**: Fetches instructions from memory and directs the operation of other components. It acts as a **Finite State Machine**.
        *   **控制单元 (CU)**：从存储器中获取指令，并指导其他组件的操作。它就像一个**有限状态机**。
    *   **Arithmetic Logic Unit (ALU)**: Performs arithmetic and logical operations.
        *   **算术逻辑单元 (ALU)**：执行算术和逻辑运算。
    *   **Input/Output (I/O)**: Handles communication with external devices.
        *   **输入/输出 (I/O)**：处理与外部设备的通信。

#### **2. Registers in a Basic Processor**
#### **2. 基本处理器中的寄存器**

*   **MA**: Memory Address Register - Holds the address of the memory location to be accessed.
    *   **MA**: 存储器地址寄存器 - 保存要访问的存储位置的地址。
*   **MD**: Memory Data Register - Holds the data being transferred to or from memory.
    *   **MD**: 存储器数据寄存器 - 保存正在传入或传出存储器的数据。
*   **IR**: Instruction Register - Holds the current instruction being executed.
    *   **IR**: 指令寄存器 - 保存当前正在执行的指令。
*   **PC**: Program Counter - Holds the address of the next instruction to be fetched.
    *   **PC**: 程序计数器 - 保存下一条要获取的指令的地址。
*   **AC**: Accumulator - A register used by the ALU to hold intermediate results.
    *   **AC**: 累加器 - ALU使用的一个寄存器，用于保存中间结果。
*   **SP**: Stack Pointer - Points to a location in memory called the stack.
    *   **SP**: 堆栈指针 - 指向内存中一个称为堆栈的位置。

#### **3. The Fetch-Execute Cycle**
#### **3. 取指-执行周期**

This is the fundamental process of a von Neumann computer.
这是冯·诺依曼计算机的基本过程。

1.  **Fetch**: The Control Unit fetches the next instruction from the memory location indicated by the Program Counter (PC).
    *   **取指**：控制单元从程序计数器（PC）指示的存储位置获取下一条指令。
2.  **Decode**: The instruction is decoded by the Control Unit to determine what action to perform.
    *   **译码**：指令被控制单元译码，以确定要执行什么操作。
3.  **Execute**: The Control Unit sends signals to other components (like the ALU and registers) to carry out the instruction.
    *   **执行**：控制单元向其他组件（如ALU和寄存器）发送信号以执行该指令。
4.  This cycle repeats for every instruction in a program.
    *   这个周期对程序中的每条指令重复进行。

#### **4. The Von Neumann Bottleneck**
#### **4. 冯·诺依曼瓶颈**

*   **Problem**: The shared bus between the CPU and memory can only transfer one thing at a time (either an instruction or a data value).
    *   **问题**：CPU和存储器之间的共享总线一次只能传输一样东西（要么是一条指令，要么是一个数据值）。
*   The data transfer rate (throughput) between the CPU and memory is much slower than the rate at which the CPU can process data.
    *   CPU和存储器之间的数据传输速率（吞吐量）远低于CPU处理数据的速率。
*   This forces the fast CPU to constantly wait for the slow memory to provide instructions or data, creating a performance **bottleneck**.
    *   这迫使高速的CPU不断等待慢速的存储器提供指令或数据，从而造成了性能**瓶颈**。
*   **Solution**: The bottleneck is reduced by using a **cache** between the CPU and main memory to store frequently accessed items.
    *   **解决方案**：通过在CPU和主存储器之间使用**高速缓存**来存储频繁访问的项目，可以缓解这一瓶颈。