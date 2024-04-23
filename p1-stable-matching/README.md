# Gale-Shapley Algorithm for Stable Matching

## Overview

This project implements the Gale-Shapley algorithm for stable matching in C++. In this version, people will be adopting pets. Each person will adopt exactly one pet and each pet will be adopted by exactly one person. Both people and pets have preference lists.

## Input Format

The input data is read from a file named `program1data.txt`. The file is formatted as follows:

- Line 1: Number of people/pets (n)
- Lines 2 to n+1: Names of people
- Lines n+2 to 2n+1: Preference lists of people using indices, not names (n preferences per line)
- Lines 2n+2 to 3n+1: Names of pets
- Lines 3n+2 to 4n+1: Preference lists of pets using indices, not names (n preferences per line)


## Output

The program will output the stable matching between people and pets. Each line of the output will contain a pair consisting of a person's name and the name of the pet they adopt.

## How to Run

1. Compile the program using a C++ compiler (e.g., g++).
2. Run the program with `program1data.txt` in the same directory.

