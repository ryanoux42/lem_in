# 🐜 LEM_IN

## Description

**LEM_IN** is a graph pathfinding project written in **C**.  
An **anthill** is described on the standard input: a number of ants, a set of **rooms** and the **tunnels** connecting them. All the ants start in the `##start` room and must reach the `##end` room **in as few turns as possible**.

Rules:
- A room can only hold **one ant at a time** (except start and end).
- Each turn, every ant can move **once**, through **one tunnel**.

This project focuses on **graph representation**, **parsing**, **Breadth-First Search (BFS)** and **ant flow optimization**.

---

## 🧩 Features

- Robust **parsing** of the anthill (comments, commands, invalid lines)
- **Graph** built from rooms and tunnels (neighbors list)
- **BFS** from the end room to compute every room's **distance to the exit**
- Ants always move to the **closest free neighbor** toward the end
- Move-by-move **output** of every ant
- Error handling for invalid maps

---

## ⚙️ Usage

### Compilation

```bash
make
```

Other rules:
```bash
make re      # Rebuild everything
make clean   # Remove object files
make fclean  # Remove binaries and object files
```

---

### Execution

```bash
./lem_in < anthill_file
```

---

## 🗺️ Input Format

```
3               # number of ants
##start
0 1 2           # room "0" at position (1, 2)
##end
1 9 2
2 5 0
3 5 4
0-2             # tunnel between room 0 and room 2
0-3
2-1
3-1
```

- `##start` / `##end` → the next room is the entrance / the exit
- `#` → comment
- `name x y` → room
- `a-b` → tunnel

## 📤 Output Format

The program prints the parsed anthill, then the moves, one line per turn:

```
#number_of_ants
3
#rooms
##start
0 1 2
##end
1 9 2
2 5 0
3 5 4
#tunnels
0-2
0-3
2-1
3-1
#moves
P1-2
P1-1 P2-2
P2-1 P3-2
P3-1
```

`P<n>-<room>` means **ant n moves to room `room`**.

---

## 🫂 Team

- Ryan Hercule
- Zacharie Rodde
- Camil Kaddouri
- Jean-Garice Denoncin
