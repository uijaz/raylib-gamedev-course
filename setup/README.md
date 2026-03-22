# Setup Guides

Choose your operating system for raylib installation instructions:

- [macOS](macos.md)
- [Linux](linux.md) — coming soon
- [Windows](windows.md) — coming soon

---

## What You'll Need

- A C compiler (clang on macOS, gcc on Linux/Windows)
- raylib installed
- A text editor of your choice
- Terminal access

---

## After Installing

Once raylib is installed, you can build any module using these terminal commands from inside a module folder:

**macOS:**
```bash
clang src/*.c -o build/main -I include -I /opt/homebrew/opt/raylib/include -L /opt/homebrew/opt/raylib/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
```

**Linux:**
🔜 Coming soon

**Windows:**
🔜 Coming soon