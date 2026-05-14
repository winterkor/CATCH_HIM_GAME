# CATCH HIM!

A two-player terminal race game written in C. Both players chase a boy who runs away from them across a grid map. First player to step on the boy wins.

## How to Build

```bash
make
make run
```

Requires a POSIX terminal (macOS/Linux). On Windows, compile with MinGW — the Windows APIs are used natively.

## How to Play

- **Player 1** moves with `W A S D`, uses items with `E`, drops a bomb with `F`
- **Player 2** moves with `I J K L`, uses items with `O`, drops a bomb with `P`
- Players alternate turns. Step onto the boy (`B`) to win.
- The boy moves away from whoever just moved each turn.

## Map Legend

| Symbol | Meaning |
|--------|---------|
| `1` | Player 1 |
| `2` | Player 2 |
| `B` | The boy (catch him!) |
| `.` | Open path |
| `*` | Destructible block (bomb it) |
| `#` | Indestructible wall |

## Items

Items are found by bombing destructible blocks.

| Item | Effect |
|------|--------|
| `D` (Double) | Take 2 extra moves this turn |
| `T` (Triple) | Take 3 extra moves this turn |
| `S` (Shield) | Block enemy pushback for 3 turns |
| `B` (Push Back) | Send the opponent back to their starting corner |

Each player holds up to 3 items. Use the inventory menu (`E`/`O`) to select and activate one.

## Controls Summary

| Action | Player 1 | Player 2 |
|--------|----------|----------|
| Move up | `W` | `I` |
| Move down | `S` | `K` |
| Move left | `A` | `J` |
| Move right | `D` | `L` |
| Open inventory | `E` | `O` |
| Drop bomb | `F` | `P` |
| Quit (in menu) | `Q` | `Q` |
