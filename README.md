# Minishell

Minishell is a simple shell implementation written in C. It provides a minimalistic command-line interface with basic shell functionalities.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

Minishell is a lightweight shell designed to demonstrate basic shell operations and provide a learning resource for understanding shell programming. It includes features commonly found in Unix-like shells, allowing users to interact with the system through a command-line interface.

## Features

- Command execution
- Simple built-in commands (e.g., `cd`, `echo`, `pwd`, `export`, `unset`)
- Input/output/appaned/herdoc redirection
- Pipeline support
- error handling
- ctrl-C, ctrl-D and ctrl-\ handling

## Installation

To use Minishell, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/minishell.git
    cd minishell
    ```

2. Build the project:

    ```bash
    make
    ```

3. Run Minishell:

    ```bash
    ./minishell
    ```

## Usage

Minishell supports standard shell commands and features. Here are some examples:

- Run a command:

    ```bash
    ls -l
    ```

- Change directory:

    ```bash
    cd /path/to/directory
    ```

- Input/output redirection:

    ```bash
    ls > output.txt
    ```

- Pipeline:

    ```bash
    ls | grep keyword
    ```

For more information, refer to the man page or help command within Minishell.

## Contributing

Contributions are welcome! If you'd like to contribute to Minishell, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and submit a pull request.
