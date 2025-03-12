# HuggingFaceAPITest

A C++ application for testing different models using the HuggingFace API in QtCreator.

## Overview

This project demonstrates how to integrate and utilize the HuggingFace API within a Qt C++ application. It allows for testing and interacting with various machine learning models available through the HuggingFace platform.

## Features

- Connect to HuggingFace API using C++ and Qt
- Test different language and machine learning models
- Examples of API calls and response handling
- Simple Qt-based user interface for model testing

## Project Structure

- `huggingfaceapi.cpp/h` - Core implementation of the HuggingFace API interface
- `main.cpp` - Application entry point
- `Main.qml` - Main QML file for the UI
- `CMakeLists.txt` - CMake build configuration

## Prerequisites

- Qt 6 or higher
- CMake 3.15 or higher
- C++ compiler with C++17 support
- HuggingFace API key (sign up at [huggingface.co](https://huggingface.co/))

## Setup

1. Clone the repository:
   ```
   git clone https://github.com/GilbertAshivaka/HuggingFaceAPITest.git
   ```

2. Navigate to the project directory:
   ```
   cd HuggingFaceAPITest
   ```

3. Create a build directory:
   ```
   mkdir build && cd build
   ```

4. Configure with CMake:
   ```
   cmake ..
   ```

5. Build the project:
   ```
   cmake --build .
   ```

## Configuration

Before running the application, you need to set up your HuggingFace API key:

1. Create a file named `api_key.txt` in the application directory
2. Add your HuggingFace API key to this file
3. Alternatively, you can set the API key directly in the application settings

## Usage

1. Launch the application
2. Select a model from the available options on huggingface
3. Enter your input text or parameters
4. Submit the request to the HuggingFace API
5. View and analyze the results

## API Integration

The application demonstrates how to:
- Authenticate with the HuggingFace API
- Make requests to different model endpoints
- Parse and display JSON responses
- Handle errors and edge cases

## Models Tested

This application has been tested with various HuggingFace models, including:
- Text generation models
- Classification models
- Translation models
- And more!

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.


## Acknowledgements

- [HuggingFace](https://huggingface.co/) for their excellent API and models
- [Qt](https://www.qt.io/) for the application framework

## Contact

Gilbert Ashivaka - [GitHub Profile](https://github.com/GilbertAshivaka)

Project Link: [https://github.com/GilbertAshivaka/HuggingFaceAPITest](https://github.com/GilbertAshivaka/HuggingFaceAPITest)
