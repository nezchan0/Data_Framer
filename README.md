# 🌐 DataFramer — Data Framing Visualizer & CLI Toolkit

An interactive **educational project** that demonstrates how data is structured and transmitted at the **Data Link Layer** using various **framing techniques** — through both **Graphical Visualization (Web App)** and **Command-Line Implementations (C Programs)**.

Built with **HTML, CSS, JavaScript**, and **C**, this project bridges theory and practice by showing how framing works internally and visually.

---

## 🧠 Overview

This project has **two main parts**:

### 🖥️ 1. Web Visualization (HTML + CSS + JS)
An interactive interface to visualize and understand how different data framing techniques work in real time.

### 💻 2. CLI Implementations (C Programs)
Simple and modular C programs that implement each framing method step by step — suitable for labs, assignments, and command-line demonstrations.

---

## 🚀 Features

### 🎞️ Framing Techniques Included
- **Fixed-Size Framing**  
  Data is divided into fixed-length frames; the last frame is padded if necessary.

- **Byte Stuffing**  
  Uses FLAG and ESC characters to mark frame boundaries and escapes internal occurrences.

- **Bit Stuffing**  
  Inserts a `0` after every five consecutive `1`s to avoid confusion with frame delimiters.

---

## 🖥️ Web Visualizer Highlights

- Beautiful and responsive interface  
- **Real-time frame animation** with color-coded bits and markers  
- **Dark Mode toggle** 🌙  
- Built-in **Info Page** explaining concepts  
- **Comparison table** between methods  
- Fully responsive for mobile and desktop  
- No dependencies — just open `index.html` or [Live Link](https://nezchan0.github.io/Framing_Methods/)

---

## 💻 CLI Program Highlights

Each framing method also has a **C implementation** located in the `cli/` folder.  
These programs read input data from the user and output the framed data on the terminal.


### ⚙️ How to Compile and Run

#### Fixed-Size Framing
```bash
gcc fixed_size_framing.c -o fixed
./fixed
```

#### Byte Stuffing
```bash
gcc byte_stuffing.c -o byte
./byte
```

#### Bit Stuffing
```bash
gcc bit_stuffing.c -o bit
./bit
```

Each program:
- Accepts user input (data and framing parameters)
- Displays the framed output  
- Optionally shows internal processing (if enabled in code)

---

## 🧩 Tech Stack

| Technology | Purpose |
|-------------|----------|
| **HTML5** | Web structure |
| **CSS3** | Styling, layout, animations |
| **JavaScript (Vanilla)** | Visualization logic |
| **C** | CLI-based framing implementations |

---

## 🎓 Educational Use

This dual-format project is ideal for:
- Computer Networks courses  
- Data Link Layer lab demonstrations  
- Comparing **implementation vs. visualization** of framing  
- Interactive learning for students and instructors  

---

## 🧠 Example Outputs

**Fixed-Size Framing (C):**
```
Enter data: HELLOWORLD
Enter frame size: 3
→ Frames: [HEL] [LOW] [ORL] [D__]
```

**Byte Stuffing (C):**
```
Enter data: AFEBFCD
FLAG: F
ESC: E
→ Stuffed: F | A | EF | EE | B | EF | C | D | F
```

**Bit Stuffing (C):**
```
Enter bit sequence: 011111011111110
→ Stuffed: 011111001111110010
```


---

## 💡 Future Enhancements
- Add **CRC/Error detection** to C and Web versions  
- Include **real-time transmission simulation**  
- Integrate **WebAssembly (WASM)** to run C logic in-browser  
- Extend to **Frame Check Sequences (FCS)** visualization  

---

## 🧑‍💻 Author

Alok Kumar Maurya – Developer | Email: [alok05.maurya@gmail.com](alok05.maurya@gmail.com)
---
