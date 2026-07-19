# SimForge

Real-Time Discrete-Event Simulation Engine. 

## Overview
A factory-floor discrete-event simulator: entities flow through stations (source → queue → process → conveyor → sink), with live 3D visualization and real-time statistics in mind.

This repository is currently in **Phase 1** of development, establishing the core scheduling and event loops.

### Features (Phase 1)
- Priority queue-based `EventCalendar`
- `SimEvent` structs for handling timeline actions
- Basic `run_until` simulation loops
- Fully set up with CMake (C++14 target for MinGW support)

## Build Instructions

This project uses CMake as its build system. Currently configured and tested with MinGW (GCC 6.3.0) on Windows.

```bash
# Generate the Makefiles
cmake -G "MinGW Makefiles" -B build -S .

# Build the project
cmake --build build

# Run the executable
./build/SimForge.exe
```
