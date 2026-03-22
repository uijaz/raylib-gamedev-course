# macOS Setup Guide

This guide helps you set up raylib on macOS for terminal-based development.

---

## 1. Install Apple Command Line Tools

Open Terminal and run:

```bash
xcode-select --install
```

**Why:** This installs the macOS compiler (`clang`) and system frameworks raylib depends on (Cocoa, IOKit, OpenGL, CoreVideo).

---

## 2. Install Homebrew

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

**Why:** Homebrew is the easiest way to install raylib on macOS.

---

## 3. Install Raylib

```bash
brew install raylib
```

**Why:** This installs raylib into predictable locations:

- `/opt/homebrew/opt/raylib/include`
- `/opt/homebrew/opt/raylib/lib`

---

## 4. Verify Installation

```bash
brew info raylib
ls /opt/homebrew/opt/raylib/include
ls /opt/homebrew/opt/raylib/lib
```

You should see raylib header files and library files listed.

---

## 5. Clone the Course Repository

```bash
git clone https://github.com/yourusername/raylib-gamedev-course.git
cd raylib-gamedev-course
```

---

## 6. Build and Run a Module

Navigate to a module folder:

```bash
cd modules/module-01-move-the-square
```

Build the project:

```bash
clang src/*.c -o build/main -I include -I /opt/homebrew/opt/raylib/include -L /opt/homebrew/opt/raylib/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

Run the game:

```bash
./build/main
```

---

## Troubleshooting

### `'raylib.h' file not found`

Make sure raylib is installed:

```bash
brew install raylib
```

Then verify the include path exists:

```bash
ls /opt/homebrew/opt/raylib/include
```

### Build fails with linker errors

Make sure all frameworks are included in the build command:

```bash
-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

### Command not found: clang

Install Apple Command Line Tools:

```bash
xcode-select --install
```

---

## Next Steps

Now you're ready to start with [Module 1](../modules/module-01-move-the-square/)!
