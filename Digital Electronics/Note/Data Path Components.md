### **Recap: Asynchronous vs. Synchronous Counters**
### **回顾：异步与同步计数器**

*   **Asynchronous (Ripple) Counters**: The flip-flops are not clocked by the same signal; the output of one flip-flop triggers the clock input of the next.
    *   **异步（行波）计数器**：触发器不由同一时钟信号驱动；一个触发器的输出会触发下一个触发器的时钟输入。
*   **Propagation Delay**: In asynchronous counters, the delay of each flip-flop accumulates. This "ripple" effect can cause temporary incorrect output states.
    *   **传播延迟**：在异步计数器中，每个触发器的延迟会累积。这种“行波”效应可能导致暂时的错误输出状态。
*   **Synchronous Counters**: All flip-flops share a common clock signal and change state simultaneously.
    *   **同步计数器**：所有触发器共享一个共同的时钟信号，并同时改变状态。
*   This eliminates the cumulative propagation delay issue found in asynchronous counters, making them faster and more reliable for high-frequency applications.
    *   这消除了异步计数器中的累积传播延迟问题，使它们在高速应用中更快、更可靠。

---

### **1. Datapath Components**
### **1. 数据路径组件**

*   **Concept**: While basic logic gates (AND, OR) and sequential elements (Flip-Flops) are primitive components, we need higher-level building blocks for data processing.
    *   **概念**：虽然基本的逻辑门（与门、或门）和时序元件（触发器）是原始组件，但我们需要更高级别的构建模块来进行数据处理。
*   Datapath components operate at the **Register-Transfer-Level (RTL)** of abstraction. They are designed to store or transform multi-bit data.
    *   数据路径组件在**寄存器传输级（RTL）**的抽象层次上运行。它们被设计用来存储或转换多位数据。
*   Combining these components (like registers, multiplexers, decoders) forms a **datapath**.
    *   将这些组件（如寄存器、多路复用器、译码器）组合起来就形成了一个**数据路径**。
*   **N-bit Bus**: To simplify circuit diagrams, N parallel wires carrying N bits of data are represented by a single bold line with a slash and the number 'N' to indicate the width.
    *   **N位总线**：为了简化电路图，承载N位数据的N条平行导线用一条粗线表示，并带有一个斜杠和数字“N”来表示其宽度。

---

### **2. Combinational Datapath Components**
### **2. 组合数据路径组件**

These components produce an output based only on the current input values.
这些组件的输出仅取决于当前的输入值。

#### **2.1. Encoders (编码器)**

*   **Function**: An encoder converts one of its 2<sup>n</sup> high (active) inputs into an n-bit binary output number.
    *   **功能**：编码器将其 2<sup>n</sup> 个高电平（有效）输入中的一个转换为一个n位的二进制输出数。
*   **Example (4-to-2 Encoder)**:
    *   **示例（4-2编码器）**：
    *   It has 4 input lines (d0, d1, d2, d3) and 2 output lines (i0, i1).
        *   它有4条输入线（d0, d1, d2, d3）和2条输出线（i0, i1）。
    *   If input `d2` is high (1) and all others are low (0), the binary output will be `10`, which is the number 2.
        *   如果输入 `d2` 为高电平（1）而所有其他输入为低电平（0），则二进制输出将是 `10`，即数字2。

#### **2.2. Decoders (译码器)**

*   **Function**: A decoder does the opposite of an encoder. It converts an n-bit input binary number to activate one of its 2<sup>n</sup> output lines.
    *   **功能**：译码器的功能与编码器相反。它将一个n位的二进制输入数转换为激活其 2<sup>n</sup> 个输出线中的一条。
*   **Example (2-to-4 Decoder)**:
    *   **示例（2-4译码器）**：
    *   It has 2 input lines (i1, i0) and 4 output lines (d0, d1, d2, d3).
        *   它有2条输入线（i1, i0）和4条输出线（d0, d1, d2, d3）。
    *   If the binary input is `11` (which is 3), the output line `d3` will go high (1), and all others will be low.
        *   如果二进制输入是 `11`（即3），则输出线 `d3` 将变为高电平（1），而所有其他输出线将保持低电平。
*   **Decoder with Enable (e)**: An additional input that can turn the decoder on or off.
    *   **带使能端(e)的译码器**：一个可以开启或关闭译码器的额外输入。
    *   If `e=0`, all outputs are forced to 0, regardless of the binary input.
        *   如果 `e=0`，无论二进制输入是什么，所有输出都被强制为0。
    *   If `e=1`, the decoder functions normally.
        *   如果 `e=1`，译码器正常工作。

##### **Quick Exercise: Decoder Size**
##### **小练习：译码器尺寸**

*   **Problem**: A microprocessor counts from 0 to 59 and needs to turn on a corresponding lamp for each number. What is the size of a suitable decoder?
    *   **问题**：一个微处理器从0计数到59，并需要为每个数字点亮一盏相应的灯。一个合适的译码器的尺寸是多少？
*   **Solution**:
    *   **解答**：
    1.  **Inputs**: We need to represent numbers up to 59.
        *   **输入**：我们需要表示最大为59的数字。
        *   2<sup>5</sup> = 32 (too small / 太小).
        *   2<sup>6</sup> = 64 (sufficient / 足够).
        *   Therefore, the microprocessor will provide a **6-bit** input to the decoder.
        *   因此，微处理器将向译码器提供一个 **6位** 的输入。
    2.  **Outputs**: We need to control 60 different lamps (one for each number from 0 to 59).
        *   **输出**：我们需要控制60盏不同的灯（从0到59每个数字一盏）。
        *   Therefore, the decoder needs **60** output lines.
        *   因此，译码器需要 **60条** 输出线。
    3.  **Conclusion**: The required decoder is a **6-to-64 decoder**, as this is a standard size that provides enough output lines (we would simply use the first 60 outputs).
        *   **结论**：所需的译码器是一个 **6-64译码器**，因为这是一个标准尺寸，提供了足够的输出线（我们只需使用前60个输出）。

#### **2.3. Multiplexer (Mux) / Data Selector (多路复用器 / 数据选择器)**

*   **Function**: A multiplexer routes one of its multiple data inputs to a single output line. The selection of which input to route is controlled by binary 'select' inputs.
    *   **功能**：多路复用器将其多个数据输入中的一个路由到一个单一的输出线上。通过二进制的“选择”输入来控制路由哪个输入。
*   A Mux with 'k' select lines can choose from 2<sup>k</sup> data inputs.
    *   一个有'k'条选择线的多路复用器可以从 2<sup>k</sup> 个数据输入中进行选择。
*   **Example (4x1 Mux)**: It has 4 data inputs, 2 select lines (s1, s0), and 1 output. If the select lines are `10` (2), the 3rd data input (i2) is passed to the output.
    *   **示例（4x1多路复用器）**：它有4个数据输入、2条选择线（s1, s0）和1个输出。如果选择线是 `10`（即2），第3个数据输入（i2）将被传递到输出端。

##### **Quick Exercise: Design a 4-bit 2x1 Mux**
##### **小练习：设计一个4位2x1多路复用器**

*   **Problem**: Design a 4-bit 2x1 multiplexer from four 1-bit 2x1 multiplexers. It should select between two 4-bit inputs, A (a3,a2,a1,a0) and B (b3,b2,b1,b0).
    *   **问题**：使用四个1位2x1多路复用器设计一个4位2x1多路复用器。它应在两个4位输入A (a3,a2,a1,a0) 和 B (b3,b2,b1,b0) 之间进行选择。
*   **Solution**:
    *   **解答**：
    1.  Use four 1-bit 2x1 Muxes, one for each bit position.
        *   使用四个1位2x1多路复用器，每个对应一个比特位。
    2.  Connect the single select line (`s0`) to the select input of all four multiplexers. This ensures they all switch together.
        *   将单条选择线 (`s0`) 连接到所有四个多路复用器的选择输入端。这确保了它们会同时切换。
    3.  For the first Mux, connect inputs `a0` and `b0`. Its output will be the first bit of the result.
        *   对于第一个多路复用器，连接输入 `a0` 和 `b0`。其输出将是结果的第一位。
    4.  Repeat for the other bits: `a1`/`b1` to the second Mux, `a2`/`b2` to the third, and `a3`/`b3` to the fourth.
        *   对其他比特位重复此操作：`a1`/`b1` 连接到第二个多路复用器，`a2`/`b2` 到第三个，`a3`/`b3` 到第四个。
    5.  The four outputs from the multiplexers form the final 4-bit output.
        *   这四个多路复用器的输出共同构成了最终的4位输出。

#### **2.4. Demultiplexer (DeMux) (解复用器)**

*   **Function**: A demultiplexer does the opposite of a Mux. It takes a single input and routes it to one of its multiple output lines, based on the value of the select inputs.
    *   **功能**：解复用器的功能与多路复用器相反。它接收一个单一输入，并根据选择输入的值将其路由到多个输出线中的一条。

---

### **3. Registers (寄存器)**

Registers are sequential datapath components used for storing data.
寄存器是用于存储数据的时序数据路径组件。

#### **3.1. N-bit Register**

*   **Function**: Stores N bits of data. It is constructed from multiple flip-flops (typically D-type) that share a common clock signal.
    *   **功能**：存储N位数据。它由多个共享一个共同时钟信号的触发器（通常是D型）构成。
*   **Loading**: The process of storing new data into the register.
    *   **加载**：将新数据存入寄存器的过程。
*   **Reading**: The process of accessing the data stored in the register (this does not change the contents).
    *   **读取**：访问寄存器中存储的数据的过程（这不会改变其内容）。

#### **3.2. Register with Parallel Load**

*   **Function**: A more advanced register that can either hold its current value or load a new value on the next clock edge.
    *   **功能**：一种更高级的寄存器，它可以在下一个时钟沿选择保持其当前值或加载一个新值。
*   **Implementation**: A 2x1 multiplexer is placed in front of each flip-flop.
    *   **实现**：在每个触发器的输入端前放置一个2x1多路复用器。
*   A `load` control signal is used:
    *   使用一个 `load` 控制信号：
    *   **`load = 0`**: The Mux selects the flip-flop's own output and feeds it back to the input. The register keeps its current value.
        *   **`load = 0`**：多路复用器选择触发器自身的输出并将其反馈回输入端。寄存器保持其当前值。
    *   **`load = 1`**: The Mux selects the new external data input. The register loads the new value on the next clock edge.
        *   **`load = 1`**：多路复用器选择新的外部数据输入。寄存器在下一个时钟沿加载新值。

#### **3.3. Shift Register**

*   **Function**: A register that can shift its stored bits one position to the left or right on each clock pulse.
    *   **功能**：一种可以在每个时钟脉冲下将其存储的比特向左或向右移动一个位置的寄存器。
*   **Implementation**: The output (Q) of each flip-flop is connected to the input (D) of the next flip-flop in the chain.
    *   **实现**：链中每个触发器的输出（Q）连接到下一个触发器的输入（D）。
*   **Shift Right Operation**:
    *   **右移操作**：
    *   Each bit moves one position to the right.
        *   每个比特向右移动一个位置。
    *   A new bit (usually 0) is shifted into the leftmost position.
        *   一个新的比特（通常是0）被移入最左边的位置。
    *   The rightmost bit is "dropped" (discarded).
        *   最右边的比特被“丢弃”。

##### **Quick Exercise: Shift Register Operation**
##### **小练习：移位寄存器操作**

*   **Problem**: A binary number `1000` is stored in a 4-bit shift register. Determine the output of the register after four right shifts (assuming 0 is shifted in).
    *   **问题**：一个二进制数 `1000` 存储在一个4位移位寄存器中。通过进行四次右移，确定每次移位后寄存器的输出（假设移入0）。
*   **Solution**:
    *   **解答**：

| Shift Number | Register Contents |
| :--- | :--- |
| **移位次数** | **寄存器内容** |
| Initial State | `1000` |
| 初始状态 | `1000` |
| After 1st shift | `0100` |
| 第一次移位后 | `0100` |
| After 2nd shift | `0010` |
| 第二次移位后 | `0010` |
| After 3rd shift | `0001` |
| 第三次移位后 | `0001` |
| After 4th shift | `0000` |
| 第四次移位后 | `0000` |