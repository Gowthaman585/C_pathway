# 📦 Shared Macro Definitions & Function Sharing in C
### A Beginner-Friendly Guide to Multi-File C Projects

---

## 🗂️ What Are We Building?

A small C project split across **4 files** that work together:

```
project/
├── config.h     ← Shared definitions (types, enums)
├── module.h     ← Function blueprint (prototype)
├── module.c     ← Function logic (implementation)
└── main.c       ← Entry point (runs the program)
```

> **Why split into multiple files?**
> Each file has one job. This keeps code clean, reusable, and easy to maintain.

---

## 📄 File-by-File Breakdown

### 1️⃣ `config.h` — Shared Definitions

This file defines types and values that **every other file needs**.

```c
#ifndef CONFIG_H
#define CONFIG_H

typedef int Status;  // "Status" is now an alias for int

typedef enum {
    success   = 0,
    failure   = 1,
    max_limit = 2
} StatusCode;

#endif
```

**What's happening here?**
- `typedef int Status` → Creates a custom name `Status` (same as `int` under the hood)
- The `enum` gives human-readable names to numbers (`success = 0`, etc.)
- `#ifndef CONFIG_H / #define CONFIG_H / #endif` → **Include Guard** (explained below ↓)

---

### 2️⃣ `module.h` — Function Blueprint

This file is a **promise** to the compiler: *"A function called `print_status` exists somewhere."*

```c
#ifndef MODULE_H
#define MODULE_H

#include "config.h"  // Needed because we use the 'Status' type

// Function Prototype — just the signature, no body
Status print_status(int st);

#endif
```

**What's a prototype?**
It tells the compiler:
- The function name: `print_status`
- What it takes: one `int`
- What it returns: a `Status`

The actual code (body) lives in `module.c`.

---

### 3️⃣ `module.c` — Function Logic

This is where the **real work** happens.

```c
#include <stdio.h>
#include "config.h"
#include "module.h"

Status print_status(int st) {
    if (st == success) {
        printf("status : %d\n", success);
    }
    else if (st == failure) {
        printf("status : %d\n", failure);
    }
    else if (st == max_limit) {
        printf("status : %d\n", max_limit);
    }
    else {
        printf("status : Invalid input\n");
    }
    return st;
}
```

**Why does `module.c` include `module.h`?**
So the compiler can check: *"Does my implementation match the blueprint I promised?"*
If they don't match → compiler error. This is a **safety check**.

---

### 4️⃣ `main.c` — Entry Point

The driver. It **uses** `print_status` but doesn't define it.

```c
#include <stdio.h>
#include "config.h"
#include "module.h"

int main() {
    int st = 10;
    Status result = print_status(st);
    return 0;
}
```

`main.c` is completely **blind** to what's inside `module.c`.
It only knows the function exists because of the prototype in `module.h`. ✅

---

## 🧠 Key Concepts Explained Simply

### 🔐 Include Guards — What is `#ifndef MODULE_H`?

```c
#ifndef MODULE_H   // "If MODULE_H is NOT defined yet..."
#define MODULE_H   // "...define it now"

// ... header content ...

#endif             // "End of the guarded block"
```

**The problem they solve:** If two files both include `module.h`, the compiler would see the same declarations twice → error.

Include guards say: *"Only read this file once, no matter how many times it's included."*

> ⚠️ `MODULE_H` (the macro name) and `module.h` (the filename) look similar **on purpose** — it's a naming convention, NOT a magic connection. The compiler doesn't link them automatically. You could name the macro `BANANA` and it would still work.

---

### 🏗️ Separate Compilation — How Each File Compiles Alone

In C, each `.c` file compiles **independently** (called a **Translation Unit**):

```
main.c    →  [compiler]  →  main.o
module.c  →  [compiler]  →  module.o
```

- When compiling `main.c`, the compiler **cannot see** `module.c`
- It trusts the prototype in `module.h` as a placeholder
- The `.o` files are combined later by the **linker**

```
main.o + module.o  →  [linker]  →  status_program  ✅
```

---

### 🔗 The Full Journey: Source → Binary

```
config.h ──┐
           ├──► module.c ──► module.o ──┐
module.h ──┘                            ├──► status_program
           ┌──► main.c   ──► main.o   ──┘
config.h ──┘
```

---

## 🚀 Build & Run Commands

### Step 1 — Compile each file into an object file

```bash
gcc -c main.c   -o main.o
gcc -c module.c -o module.o
```

> The `-c` flag means: *"Compile only, don't link yet."*

### Step 2 — (Optional) Inspect symbols

Check that `main.o` is waiting for `print_status` to be resolved:

```bash
nm main.o | grep print_status
# Output will show 'U print_status' → U means Undefined (waiting for linker)
```

### Step 3 — Link into final executable

```bash
gcc main.o module.o -o status_program
```

### Step 4 — Run it!

```bash
./status_program
```

---

## 🐛 Common Mistakes & What They Teach

| Mistake | What Happens | Lesson |
|---|---|---|
| Missing `;` in `typedef int Status` | Errors cascade into unrelated files | Headers are shared — one typo breaks everything |
| No prototype before calling a function | `implicit declaration` warning/error | Compiler is blind across files without `.h` |
| Using `%p` instead of `%d` for an `int` | Wrong output / undefined behavior | Format specifiers must match the actual data type |
| Forgetting include guards | `redefinition` errors | Always guard your headers |

---

## 💡 Quick Mental Model

Think of it like a restaurant:

| File | Role | Analogy |
|---|---|---|
| `config.h` | Shared types/values | The menu (what's available) |
| `module.h` | Function prototype | The order ticket (what you want) |
| `module.c` | Function body | The kitchen (makes the food) |
| `main.c` | Entry point | The customer (places the order) |

The customer doesn't go into the kitchen.
They just read the menu and place an order. The kitchen handles the rest. 🍽️

---

*Built while learning C compilation internals — separate translation units, header contracts, and the linker pipeline.*
