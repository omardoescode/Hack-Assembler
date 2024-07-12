# Nand2Tetris Course: Project 1

This course provided me with a profound understanding of how digital logic and simple components can be combined to build a complete computer system from scratch. Starting with the basic building blocks, such as the NAND gate, I learned how these fundamental components can be used to create more complex circuits and ultimately construct a fully functioning computer capable of running software.

This course had 6 projects, the last one was buildin an assembler that can convert Hack assembly langugage to Hack binary Code.

# Hack Assembler

## Instalation

1. Clone the repository: `git clone https://github.com/omardoescode/Hack-Assembler.git`
2. Build this project
   ```sh
   mkdir build
   cmake -S . -B ./build
   cmake --build ./build --target assembler
   ```
3. To use the assembler
   ```sh
   ./build/assembler <path/to/asm_file>
   # or
   ./build/assembler <path/to/asm_file> <path/to/output_file>
   ```

> Contact [Me](https://linkedin.com/in/omardoescode)
