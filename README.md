# Minitalk

A communication program in C that allows message transmission between client and server processes using UNIX signals.

## 📋 Overview

Minitalk is a 42 School project that demonstrates inter-process communication (IPC) using only UNIX signals. The program consists of a server that receives messages and a client that sends messages, communicating exclusively through `SIGUSR1` and `SIGUSR2` signals.

### Key Features

- **Signal-based communication**: Uses only UNIX signals for data transmission
- **Bit-level transmission**: Messages are sent bit by bit for reliable communication
- **Unicode support**: Can transmit any character including special characters
- **Bonus acknowledgment**: Server can send confirmation back to client
- **Error handling**: Robust error checking for invalid inputs

## 🛠️ Technical Details

### How It Works

1. **Server**: Starts and displays its Process ID (PID)
2. **Client**: Takes the server PID and message as arguments
3. **Transmission**: Each character is broken down into 8 bits and sent using:
   - `SIGUSR1` represents bit `1`
   - `SIGUSR2` represents bit `0`
4. **Reception**: Server receives signals and reconstructs the original message
5. **Acknowledgment** (bonus): Server confirms message receipt to client

### Signal Handling

The communication protocol uses a clever bit manipulation technique:
- Characters are transmitted LSB (Least Significant Bit) first
- Each bit is sent as a separate signal with a small delay
- Server uses static variables to maintain state between signal handlers

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- UNIX-like system (Linux, macOS)
- Make utility

### Building

```bash
# Build basic version (server + client)
make

# Build bonus version (with acknowledgment)
make bonus

# Clean object files
make clean

# Clean all generated files
make fclean

# Rebuild everything
make re
```

### Usage

#### Basic Version

1. **Start the server:**
```bash
./server
```
The server will display its PID (e.g., `PID: 1234`)

2. **Send a message from client:**
```bash
./client <server_pid> "<message>"
```

**Example:**
```bash
./server
# Output: PID: 1234

# In another terminal:
./client 1234 "Hello, World!"
# Server output: Hello, World!
```

#### Bonus Version

The bonus version includes client acknowledgment:

```bash
# Start bonus server
./server_bonus
# Output: PID: 5678

# Send message with bonus client
./client_bonus 5678 "Bonus message!"
# Client output: Message received
# Server output: Bonus message!
```

## 📁 Project Structure

```
minitalk/
├── Makefile          # Build configuration
├── minitalk.h        # Header file with includes
├── server.c          # Basic server implementation
├── client.c          # Basic client implementation
├── server_bonus.c    # Server with acknowledgment
├── client_bonus.c    # Client with acknowledgment
└── ft_printf/        # Custom printf implementation
    ├── ft_printf.c
    ├── ft_printf.h
    ├── ft_string.c
    ├── ft_digit.c
    └── Makefile
```

## 🎯 Features Comparison

| Feature | Basic Version | Bonus Version |
|---------|---------------|---------------|
| Signal-based communication | ✅ | ✅ |
| Bit-level transmission | ✅ | ✅ |
| Unicode support | ✅ | ✅ |
| Error handling | ✅ | ✅ |
| Server acknowledgment | ❌ | ✅ |
| Message receipt confirmation | ❌ | ✅ |

## 🔧 Implementation Details

### Signal Handler Implementation

The core of the communication lies in the signal handlers:

- **Server**: Uses static variables to maintain character and bit count state
- **Client**: Sends each bit with appropriate signal and timing delay
- **Synchronization**: Uses `usleep()` to ensure signals are properly received

### Error Handling

- **PID validation**: Ensures the provided PID contains only digits
- **Argument checking**: Validates correct number of command-line arguments
- **Signal verification**: Handles signal transmission errors gracefully

## 🎓 Educational Value

This project demonstrates several important concepts:

- **UNIX Signals**: Understanding signal handling and inter-process communication
- **Bit Manipulation**: Working with binary representation of data
- **Process Management**: Understanding PIDs and process communication
- **System Programming**: Low-level programming concepts in C
- **Synchronization**: Managing timing in concurrent operations

## ⚠️ Limitations

- **Speed**: Signal-based communication is slower than other IPC methods
- **Signal limitations**: Only two signals available for data transmission
- **Platform dependency**: Requires UNIX-like operating systems
- **Process dependency**: Server must be running before client attempts connection

## 📝 Notes

- This project is part of the 42 School curriculum
- The implementation uses a custom `ft_printf` library instead of standard `printf`
- All code follows the 42 Norm coding standard
- Memory management and error handling are implemented according to 42 requirements

## 🤝 Contributing

This is an educational project. If you're a 42 student, make sure to follow your school's academic integrity policies.

## 📄 License

This project is part of the 42 School curriculum and follows their guidelines for educational use.