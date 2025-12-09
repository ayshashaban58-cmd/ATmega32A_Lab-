# ATmega32A_Lab

Here’s a short and clear **Expected Results** README section in English for all the experiments you posted:

### Experiment 4.1 - Toggle LEDs
**Expected Result:**  
All 8 LEDs connected to PORTB will blink together (ON for 500 ms, OFF for 500 ms) continuously, creating a clear blinking effect.

### Experiment 4.2 - Input Switches Control LEDs
**Expected Result:**  
When you press any switch connected to PD0–PD3 (active-low), the corresponding LED on PB0–PB3 will turn ON. Release the switch → LED turns OFF. Multiple switches can be pressed simultaneously to light multiple LEDs.

### Experiment 4.3 - Analog Input (Potentiometer on PA0)
**Expected Result:**  
Turning the potentiometer will change the number of lit LEDs on PORTB in bar-graph style:
- 0 V → all LEDs OFF
- ~0.6 V → 1 LED ON
- ~1.3 V → 2 LEDs ON
- …
- 5 V → all 8 LEDs ON  
Smoothly acts like an 8-level LED voltage meter.

### Experiment 4.4 - LM35 Temperature Sensor on PA1
**Expected Result:**  
The number of lit LEDs on PORTB represents temperature in steps of 5°C:
- 0–4°C   → 0 LEDs
- 5–9°C   → 1 LED
- 10–14°C → 2 LEDs
- …
- ≥40°C    → all 8 LEDs ON  
LEDs increase as temperature rises.

### Experiment 4.5 - LCD 16x2 + LM35 Temperature Display
**Expected Result:**  
After 2-second welcome screen (“Aysha Shaban” & “Temp Monitor”), the LCD continuously shows:
- Line 1: “Temp: XX.XX C” (real-time temperature with 2 decimal places)
- Line 2: “HELLO AYSHA”
Temperature updates every ~800 ms.

### Experiment 4.6 - Simple Tone Generation using Timer1 PWM
**Expected Result:**  
A buzzer or speaker connected to the PWM pin will play the notes C5 → D5 → E5 (do-re-mi), each lasting 500 ms, followed by 1 second of silence. The sequence repeats forever.

### Experiment 4.7 - UART Control of LEDs
**Expected Result:**  
Open any serial terminal (9600 baud):
- Send '1' → all LEDs on PORTB turn ON
- Send '0' → all LEDs turn OFF
- Every character you send is echoed back followed by a new line.

### Experiment 4.8 - Keypad Calculator on LCD
**Expected Result:**  
Each key on the 4x4 keypad instantly shows a different cool pattern on the 8 LEDs (PORTB).  
When no key is pressed → all LEDs OFF.

| Key | LED Pattern (PB7 ... PB0) | Visual Effect                   |
|-----|----------------------------|---------------------------------|
| 1   | 00000001                   | Only rightmost LED              |
| 2   | 00000011                   | First 2 LEDs                    |
| 3   | 00000111                   | First 3 LEDs                    |
| 4   | 00001111                   | First 4 LEDs                    |
| 5   | 11111111                   | All LEDs ON                     |
| 6   | 10101010                   | Checkerboard                    |
| 7   | 11001100                   | Alternate pairs                 |
| 8   | 11110000                   | Left 4 LEDs ON                  |
| 9   | 00001111                   | Right 4 LEDs ON                 |
| 0   | 01010101                   | Every other LED                 |
| *   | 10000001                   | Only two ends ON                |
| #   | 11111110                   | All except rightmost            |
| A   | 00010001                   | Symmetric wings                 |
| B   | 00110011                   | Two middle pairs                |
| C   | 01100110                   | X shape                         |
| D   | Fast blink (3 times)       | All LEDs flash quickly 3 times  |
