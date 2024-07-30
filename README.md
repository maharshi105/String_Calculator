# String Calculator

## Overview

This project provides a simple implementation of a string calculator in C++. The `StringCalculator` class can handle basic arithmetic operations with custom delimiters and throws exceptions for negative numbers.

## Features

- **Addition**: Computes the sum of numbers in a string.
- **Custom Delimiters**: Supports custom delimiters specified in the format `//<delimiter>\n`.
- **Error Handling**: Throws exceptions if negative numbers are present in the input.

## Installation

Ensure you have a C++ compiler installed (e.g., `g++`).

## Compilation

To compile the code, use the following command:

```sh
g++ -o calculator main.cpp
./a.out
```
## Test Cases
1. Empty String
```sh
cout << "Result of empty string: " << calculator.add("") << endl;
```
2.Single Number
```sh
cout << "Result of '1': " << calculator.add("1") << endl;
```
3. Commma separated number
```sh
cout << "Result of '1,2,3': " << calculator.add("1,2,3") << endl;
```
4.Mixed delimiters (newline and comma)
```sh
cout << "Result of '1\\n2,3': " << calculator.add("1\n2,3") << endl;
```
5.Custom delimiter
```sh
cout << "Result of '//;\\n1;2': " << calculator.add("//;\n1;2") << endl;
```
6.Negative numbers
```sh
cout << "Result of '-1,-2,3': " << calculator.add("-1,-2,3") << endl;
```
## Error Handling
If negative numbers are included in the input, the program will throw an exception with a message listing all negative numbers.

## Output
![image](https://github.com/user-attachments/assets/e9af7f64-2a23-4fca-9a04-c83568efc0a4)




