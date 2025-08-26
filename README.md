# C Playground

A collection of C programming exercises, experiments, and projects designed to explore the language from fundamentals to advanced concepts. What might appear as "ostensibly random" files actually represents a structured journey through C programming - from basic syntax to complex algorithms and real-world applications.

## Purpose

This repository serves as a learning laboratory for C programming, featuring:

- **Foundational exercises** that build core programming skills
- **Algorithm implementations** to understand computational complexity
- **CS50 problem sets** demonstrating academic computer science concepts
- **Personal projects** that apply C to solve real-world problems
- **Experimental code** for testing language features and techniques

The apparent randomness reflects the organic nature of learning - tackling problems as they arise, experimenting with different approaches, and building upon previous knowledge.

## Repository Structure

### 📁 `basic-programs/`

Essential C programs covering fundamental concepts:

- Memory management and pointers (`memory.c`)
- Array manipulation (`array_counter.c`)
- Mathematical operations (`avg_calc.c`, `factorials.c`)

### 📁 `algorithms/`

Classic algorithm implementations:

- Sorting algorithms (bubble sort, selection sort)
- Performance analysis and optimisation techniques

### 📁 `cs50/`

Harvard CS50 course problem sets, including:

- **Tideman Election System** (`cs50_tideman.c`) - A sophisticated ranked-choice voting algorithm
- **Image Processing** (`cs50_filter_less/`, `cs50_filter_more/`) - Bitmap manipulation and filters
- **Cryptographic Ciphers** (`cs50_caesar.c`, `cs50_substitution.c`) - Classical encryption methods
- **Text Analysis** (`cs50_readability.c`) - Coleman-Liau readability index calculator

### 📁 `projects/`

Personal projects showcasing practical applications:

#### 🏎️ **Grand Prix Predictor** (`grand_prixdictor.c`)

A Formula 1 race prediction engine that demonstrates:

- Complex data structures for teams and drivers
- Multi-factor algorithmic decision making
- Command-line argument processing
- JSON configuration handling
- Statistical modeling and probability calculations

#### 📝 **Text Analyzer** (`anal_text.c`)

A comprehensive text analysis tool implementing the Coleman-Liau readability index:

- String processing and character classification
- Statistical analysis of text complexity
- Grade-level reading assessment
- Clean, user-friendly output formatting

#### 📖 **Speller** (`speller/`)

A high-performance spell-checking application featuring:

- Hash table implementation for dictionary storage
- Memory-efficient data structures
- Performance benchmarking and optimisation
- Large-scale text processing capabilities

## Highlighted Programs

### Tideman Voting System

The Tideman algorithm (`cs50/cs50_tideman.c`) implements a sophisticated ranked-choice voting system that prevents vote splitting and ensures the most representative winner. This program showcases advanced data structures, graph theory concepts, and complex algorithmic thinking.

### Formula 1 Predictor

The Grand Prix predictor (`projects/grand_prixdictor.c`) combines multiple data sources to predict race outcomes, demonstrating real-world application of C programming to sports analytics. It features configurable parameters, probability modeling, and elegant result presentation.

### High-Performance Speller

The speller project (`projects/speller/`) implements a production-quality spell-checker with emphasis on performance optimisation, memory management, and scalability - essential skills for systems programming.

## Building and Running

Most programs can be compiled with standard GCC:

```bash
gcc -o program_name source_file.c
```

For the Grand Prix predictor:

```bash
make grand_prixdictor
./grand_prixdictor [track] [condition]
```

For CS50 programs that use the CS50 library:

```bash
gcc -lcs50 -o program_name source_file.c
```

## Learning Journey

This repository represents an iterative learning process where each program builds upon previous knowledge:

1. **Fundamentals** → Basic syntax, variables, and control structures
2. **Memory Management** → Pointers, dynamic allocation, and data structures
3. **Algorithms** → Sorting, searching, and complexity analysis
4. **Real Applications** → Text processing, data analysis, and predictive modeling
5. **Systems Programming** → Performance optimisation and large-scale data handling

The "randomness" reflects the natural progression of a programmer exploring different domains and challenges, making this repository both a learning archive and a testament to the versatility of C programming.
