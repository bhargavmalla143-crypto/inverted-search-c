# Inverted Search in C

A console-based Inverted Search system developed using C programming language using Hash Tables and Linked Lists.

## Features

- Create inverted index database
- Search words across multiple files
- Display database contents
- Save database into backup file
- Update database dynamically
- File validation and duplicate checking
- Hash table based searching
- Command-line execution

## Technologies Used

- C Language
- Hash Tables
- Linked Lists
- File Handling
- Dynamic Memory Allocation
- Data Structures
- Modular Programming

## How to Run

### Compile

```bash
gcc main.c create.c display.c save.c search.c update.c inverted.c -o inverted
```

### Run

```bash
./inverted f1.txt f2.txt f3.txt f4.txt
```

## Project Structure

```text
.
├── main.c
├── create.c
├── display.c
├── save.c
├── search.c
├── update.c
├── inverted.c
├── inverted.h
├── f1.txt
├── f2.txt
├── f3.txt
└── backup.txt
```

## Concepts Used

- Inverted Indexing
- Hash Tables
- Linked Lists
- File Parsing
- Dynamic Memory Allocation
- Collision Handling
- Searching Algorithms

## Future Improvements

- GUI support
- Case-insensitive search
- Stop-word filtering
- Phrase searching
- Web-based search engine version

## Author

Surya Bhargav
