	# Assessment Submission Portfolio

**Assessment A1: Engine Compartment Monitor (Temperature & Status Display)**  
**Due:** Week 4 | **Weight:** 10%

---

## Version Control

| Field | Details |
|-------|---------|
| **Assessment Type** | Individual Portfolio Submission |
| **Assessment Code** | A1 |
| **Platform** | GitHub + Blackboard |
| **Document Version** | v1.0 |

---

## Introduction

This assessment submission form documents the completion of Assessment A1 (Engine Compartment Monitor). Your code and project work must be completed and committed to your GitHub portfolio repository in the `/A1-Electronics-Fundamentals/` folder.

**Important:** This form is for submission evidence only. Your actual code stays on GitHub.

---

## Submission Instructions

### Assessment Overview

Build an IoT device with temperature monitoring and status display using the following:
- **Thermistor (NTC 10kΩ)** for analog temperature sensing
- **RGB LED** for colour-coded status display (green/yellow/red)
- Temperature-to-colour mapping logic
- Serial output with temperature readings and colour state

### How to Complete This Assessment

1. Complete thermistor and RGB LED code in your `/A1-Electronics-Fundamentals/code/esp32-arduino/` folder
2. Test on breadboard or Wokwi simulation
3. Commit all files to GitHub
4. Fill out this form with your submission details
5. Copy completed form into Blackboard by the due date

### What to Submit on GitHub

- ✅ Arduino `.ino` file with thermistor reading and RGB LED control code
- ✅ Wiring diagram (Fritzing export or hand-drawn schematic)
- ✅ README.md describing thermistor wiring, ADC conversion, and colour logic
- ✅ Wokwi simulation link OR breadboard photo

---

## Student Information

| Field | Details |
|-------|---------|
| **Student Name** | Xavier Banham |
| **Student ID** | 20094400 |
| **Assessment** | A1 – Engine Compartment Monitor |
| **Submission Date** | 17/04/26 |

---

## Assessment Summary

### GitHub Portfolio Repository

| Field | Details |
|-------|---------|
| **Repository URL** | https://github.com/banhax/iot-portfolio |
| **Assessment Folder** | `/A1-Electronics-Fundamentals/` |
| **Code Location** | `/A1-Electronics-Fundamentals/code/esp32-arduino/` |
| **Last Commit Date** | 17/04/26 |

### Work Completed

**Brief Description:**  
Describe which temperature range you achieved, what colours the LED displayed at each range, and any challenges with thermistor calibration.

ANSWER: By using the online Wokwi simulator, the thermistor they use has a range of -24 degrees celsius, all the way up to 80 degrees celsius.
I used the Steinhart-Hart equation to translate the output from the thermistor in Wokwi into kelvin (which I then converted to celsius).
The RGB LED displayed a green light when the temperature (celsius) was below 60, a yellow light when it was greater than or equal to 60 AND less than 80 degrees,
and finally the light would be red whenever the temperature was above 80 degrees!

I experiences many challenges when it came to the calibration of the thermistor, most notably, having to do a whole lot of math! Wokwi included example code
for an Arduino, but upon trying it on the ESP32, it didn't work and the thermistor outputs were completely different. I tried a few different methods, such as the map()
function to clamp the thermistor outputs to the temperature range in Wokwi (-24 to 80), but that wasn't nearly accurate enough. I ended up calculating the A, B, and C co-efficients
for the aforementioned Steinhart-Hart equation, which I then used to aid in calibrating the thermistor to be able to read as celsius.

Originally, I had the maximum, minimum, and the middle temperature value (alongside the analog output 'resistance values') for the equation, but I found that
the outputted temperature wasn't nearly as accurate as I would have hoped, especially for the important 60 degrees. Meaning I had to alter my R2 and T2 to be more accurate.

Desmos, the graphing calculator website was incredibly helpful for working through this equation!

---

## Assessment Evidence

### Code and Documentation

| Requirement | Evidence Provided | Location in Repository |
|-------------|-------------------|------------------------|
| Arduino `.ino` file with thermistor and RGB LED code | 🗹 Included | `/A1-Electronics-Fundamentals/code/esp32-arduino/` |
| Thermistor ADC reading and temperature conversion | 🗹 Working | Serial output in code |
| RGB LED PWM control | 🗹 Working | analogWrite() in code |
| Temperature-to-colour mapping logic | 🗹 Included | Code comments explain thresholds |
| Wiring diagram | 🗹 Included | Fritzing file or image in folder |
| Assessment README.md | 🗹 Included | `/A1-Electronics-Fundamentals/README.md` |

### Hardware Evidence

| Requirement | Evidence | Provided |
|-------------|----------|----------|
| **Wokwi Simulation** | Simulation link showing circuit and code working | 🗹 Yes |
| **OR Breadboard Photo** | Photo of physical circuit with sensors wired | 🗹 Yes |
| **Working System** | Screenshot of serial monitor showing sensor readings | 🗹 Yes |

**Wokwi Link (if used):**  
https://wokwi.com/projects/461544347037666305

**Breadboard Photo/Screenshot:**  
"A1-Electronics-Fundamentals\XavierBanham_AT1-EvidencePHOTO.png"

---

## Assessment Evidence Checklist

Confirm all requirements completed before submitting:

| Requirement | Completed |
|-------------|-----------|
| Thermistor sensor reads temperature correctly | 🗹 |
| Thermistor ADC values convert to °C via formula | 🗹 |
| RGB LED displays green for normal temperature | 🗹 |
| RGB LED displays yellow for warning temperature | 🗹 |
| RGB LED displays red for critical temperature | 🗹 |
| Serial output displays temperature readings | 🗹 |
| Wiring diagram included and accurate | 🗹 |
| Code is clean and commented | 🗹 |
| GitHub repository is accessible | 🗹 |
| Assessment README documents the work | 🗹 |
| Hardware evidence provided (simulation or photo) | 🗹 |

---

## Optional Notes

https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation

---

## Submission Declaration

By submitting this form, I confirm that:

- 🗹 All code in my A1 folder is my own work
- 🗹 Thermistor is correctly wired and functional
- 🗹 RGB LED is correctly wired and functional
- 🗹 Temperature-to-colour mapping logic is working
- 🗹 Code follows ICTIOT502 assessment requirements
- 🗹 I have not plagiarized or breached academic integrity

---

## For Assessor Use

| Field | Details |
|-------|---------|
| **Assessor Name** | [Assessor completes] |
| **Date Assessed** | [Assessor completes] |
| **Result** | ☐ Satisfactory ☐ Not Yet Satisfactory |
| **Feedback** | [Assessor completes] |

---

**Submission recorded by Blackboard:** [Auto-recorded]

**Your actual work is assessed on GitHub. This form provides proof of submission.**
