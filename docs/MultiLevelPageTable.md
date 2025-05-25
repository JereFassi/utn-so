### ✅ **Most Used Method in Current Linux:**

Linux **does not** use **inverted page tables** or **hashed page tables** for general-purpose memory management.
Instead, modern Linux uses:

---

## 🧠 **Multi-Level Page Tables**

### Why?

Because they are:

- **Fast** for lookups
- **Scalable** to large address spaces
- **Hardware-supported** (via MMU – Memory Management Unit)

---

### 🔍 How it works (in simple terms):

Let’s say you have a 64-bit virtual address. Instead of one huge page table, Linux splits the address into **levels**, like:

```
[ Level 1 ][ Level 2 ][ Level 3 ][ Page Offset ]
```

Each level is a page table that points to the next level — until you reach the actual page frame.

This **reduces memory usage** because page tables are only allocated when needed.

---

### 🧱 Linux’s 4-Level Page Table (on x86_64):

- **PGD**: Page Global Directory
- **PUD**: Page Upper Directory
- **PMD**: Page Middle Directory
- **PTE**: Page Table Entry → points to actual physical page

📦 Example lookup:

```
Virtual Address → PGD → PUD → PMD → PTE → Physical Page
```

---

### 🏁 Summary:

| Table Type             | Used in Linux? | Notes                                                                 |
| ---------------------- | -------------- | --------------------------------------------------------------------- |
| Inverted Page Table    | ❌             | Not used, too slow for general memory, but sometimes used in hardware |
| Hashed Page Table      | ❌             | Used in Solaris, but not mainstream Linux                             |
| **Multi-Level Tables** | ✅ Yes         | Default approach for Linux with MMU support                           |

---

Linux also uses a **TLB (Translation Lookaside Buffer)** — a hardware cache for recent translations — to speed up page table lookups.

---

## 🧠 Imagine this:

You have a **64-bit virtual address**, but you don’t want one huge page table (it would be _massive_).

So instead, we **break the address into chunks**, each chunk pointing to another smaller table. This forms a **tree-like structure**.

---

## 🧱 Address Breakdown (example: x86_64 with 4 levels):

Let’s say your virtual address is structured like this:

```
| 9 bits | 9 bits | 9 bits | 9 bits | 12 bits |
|  PGD   |  PUD   |  PMD   |  PTE   | Offset  |
```

- Each 9-bit chunk indexes 512 entries (2⁹).
- The final 12 bits are the offset inside the 4 KB page.

---

## 🔁 Step-by-Step Access Simulation

Let’s say the virtual address is `0x0000_ABCD_1234_5678`

Here's how the translation might look:

```
[Virtual Address] = 0x0000_ABCD_1234_5678

↓ Break it down:

PGD Index → 0x001
  ↓
+-----------+
| PGD Table |
+-----------+
| Entry[0]  |
| Entry[1] ──────────┐
| Entry[2]  |         ↓
+-----------+       +-----------+
                    | PUD Table |
                    +-----------+
                    | Entry[5] ─────┐
                    | Entry[6]     ↓
                    +-----------+ +-----------+
                                | PMD Table   |
                                +-----------+
                                | Entry[2] ─────┐
                                +-----------+   ↓
                                            +-----------+
                                            | PTE Table |
                                            +-----------+
                                            | Entry[7] ─────> Physical Frame #42
                                            +-----------+

Offset = 0x678

Final Physical Address = Frame 42 + Offset 0x678
```

---

### ✅ Recap:

- You **traverse 4 tables** (PGD → PUD → PMD → PTE)
- Each step picks the next table based on 9 bits of the virtual address
- Once you hit the **Page Table Entry**, you get the **physical frame**
- Add the **offset**, and you have your final physical address

---

## 🔄 Why is this efficient?

- Only allocate page tables when you need them
- Can efficiently represent **sparse memory** (e.g., a huge address space with only a few pages in use)
- Works well with **hardware support** (MMU + TLB)

---
