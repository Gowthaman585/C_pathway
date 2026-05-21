# 🔍 Finding the Base Address of a Double Pointer Array

> A simple walkthrough of the code — line by line, no jargon.

---

## 🧠 What Does This Code Do?

It creates an **array of pointer slots** using `calloc`, then proves that **no matter which slot you're standing at, you can always walk back to the very first slot (the base address).**

---

## 🧱 The Setup

```c
int** deref_pointer;
int arr_rows = 3;

deref_pointer = calloc(arr_rows, sizeof(int*));
```

### What is happening here?

| Line | Plain English |
|---|---|
| `int** deref_pointer` | A double pointer — will hold the address of a row of pointer slots |
| `arr_rows = 3` | We want 3 slots |
| `calloc(3, sizeof(int*))` | Reserve 3 empty slots in memory, each big enough to hold one pointer |

`calloc` hands back **one base address** — the address of the very first slot.

```
Memory looks like this after calloc:

Slot [0] → [ empty ]   ← deref_pointer points HERE (base address)
Slot [1] → [ empty ]
Slot [2] → [ empty ]
```

---

## 🔁 The Loop — The Core Idea

```c
for(int i = 0; i < arr_rows; i++) {

    int** current_slot_address = deref_pointer + i;

    int** calculated_base = current_slot_address - i;

    printf(...);
}
```

### Step by step for each loop turn:

#### 🔵 When `i = 0` (first slot)
```
current_slot_address = deref_pointer + 0  → same as base
calculated_base      = current_slot_address - 0  → still base ✅
```

#### 🔵 When `i = 1` (second slot)
```
current_slot_address = deref_pointer + 1  → moved 1 step forward
calculated_base      = current_slot_address - 1  → stepped back 1 → back to base ✅
```

#### 🔵 When `i = 2` (third slot)
```
current_slot_address = deref_pointer + 2  → moved 2 steps forward
calculated_base      = current_slot_address - 2  → stepped back 2 → back to base ✅
```

### 🎯 The Point
No matter how far forward you walk in the array,  
**subtracting the same number of steps always brings you back to the base address.**

---

## 📟 What the Output Looks Like

```
Actual Base Address issued by calloc: 0x55ac8b13f010

At Slot [0] Address: 0x55ac8b13f010 | Stepping back 0 slots -> Master Base: 0x55ac8b13f010
At Slot [1] Address: 0x55ac8b13f018 | Stepping back 1 slots -> Master Base: 0x55ac8b13f010
At Slot [2] Address: 0x55ac8b13f020 | Stepping back 2 slots -> Master Base: 0x55ac8b13f010
```

> Notice the addresses increase by **8 bytes** each slot — because each `int*` pointer is 8 bytes on a 64-bit system.

---

## 🧹 Cleanup

```c
free(deref_pointer);
```

`calloc` borrows memory from the system. `free` gives it back.  
**Always free what you calloc.** If you don't, the memory stays occupied even after your program ends — this is called a **memory leak**.

---

## 💡 Key Takeaways

| Concept | What to remember |
|---|---|
| `calloc` | Reserves N empty slots and returns the base address of the first one |
| `deref_pointer + i` | Move forward `i` slots from the base |
| `current - i` | Step back `i` slots to return to the base |
| All 3 `calculated_base` values are the same | Proves the base address never changes |
| `free()` | Always call this when done — no memory leaks |

---

*This code is a drill to build muscle memory: in a `**pointer` array, every slot knows where home is.* 🏠
