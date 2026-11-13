# Automatized Garden

Automated plant watering system built with Arduino.

## Overview

This project automates the irrigation of a small garden/plant bed. The system periodically waters the plants based on time intervals and soil moisture readings from a capacitive humidity sensor.

## Project Structure

```
├── src/
│   └── automatized_garden.ino    # Main Arduino source code
├── layers/                        # PCB layout files (KiCad)
│   ├── automatized_garden.pdsprj
│   ├── automatized_garden schematics.pdf
│   ├── automatized_garden top silk.pdf
│   ├── automatized_garden bottom copper.pdf
│   └── ...
└── building materials/
    └── materials.docx             # Component list
```

## Hardware

- Arduino microcontroller
- Soil humidity sensor (connected to pin 5)
- Relay/motor driver (connected to pin 8)
- LED indicator (connected to pin 9)

## Humidity Sensor Note

The humidity sensor was originally used for soil moisture feedback but is **not reliable long-term** — it degrades quickly when exposed to soil. Its functionality has been commented out in the code. The system currently operates on **time-based watering only** (every 12 hours) without moisture feedback.

## How It Works

### Pin Mapping

| Pin | Component       |
|-----|-----------------|
| 8   | Motor/Relay     |
| 9   | LED Indicator   |
| 5   | Humidity Sensor |

### Logic Flow

1. **`setup()`** — Initializes pins, performs a brief LED blink sequence, and runs an initial watering cycle to ensure the soil starts moist.

2. **`loop()`** — Checks if 12 hours (`hr12 = 43200000 ms`) have passed since the last check. If so, triggers a 10-second watering pulse. The LED blinks every ~11.5 seconds as a status indicator.

3. **`isDry()`** — Reads the humidity sensor and returns whether the soil is dry. Currently disabled (always returns `false`).

4. **`moistureLevel()`** — Reads the analog value from the humidity sensor and maps it to a 0–200 scale. Currently disabled (always returns `0`).

### Key Timings

| Variable | Value      | Meaning              |
|----------|------------|----------------------|
| `hr12`   | 43200000   | 12 hours (ms)        |
| `hr3`    | 10800000   | 3 hours (ms)         |
| Watering | 10000      | 10 seconds (ms)      |

## PCB

The PCB design files are in the `layers/` folder:

- KiCad project (`.pdsprj`)
- Schematic PDF
- Top silk layer PDF
- Bottom copper layer PDF

## Code Source Documentation

See `src/automatized_garden.ino` for the complete and documented source code. All comments in the code are in Portuguese.
