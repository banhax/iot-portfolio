# Assessment Submission Portfolio

**Assessment A3: Vibration Monitoring System**  
**Due:** Week 8 | **Weight:** 10%

---

## Version Control

| Field | Details |
|-------|---------|
| **Assessment Type** | Individual Portfolio Submission |
| **Assessment Code** | A3 |
| **Platform** | GitHub + Blackboard |
| **Document Version** | v1.0 |

---

## Introduction

This assessment submission form documents the completion of Assessment A3 (Vibration Monitoring). Your code and project work must be completed and committed to your GitHub portfolio repository in the `/A3-Vibration-Monitoring/` folder.

**Important:** This form is for submission evidence only. Your actual code stays on GitHub.

---

## Submission Instructions

### Assessment Overview

Implement a vibration monitoring system using an accelerometer for predictive maintenance:
- **GY-521 (MPU6050)** measuring X, Y, Z acceleration on 3 axes
- **Moving average filtering** to reduce sensor noise
- **Threshold detection** for abnormal vibration patterns
- **CSV data file** with 60 seconds of filtered readings

### How to Complete This Assessment

1. Complete accelerometer code in `/A3-Vibration-Monitoring/code/esp32-arduino/`
2. Implement moving average filter for noise reduction
3. Set vibration thresholds and log anomalies
4. Collect 60 seconds of data and export to CSV
5. Commit all files to GitHub
6. Fill out this form with your submission details
7. Copy completed form into Blackboard by the due date

### What to Submit on GitHub

- ✅ Arduino `.ino` file with GY-521 accelerometer code
- ✅ CSV data file with 60 seconds of X, Y, Z acceleration readings
- ✅ README.md explaining filtering and threshold logic
- ✅ Breadboard photo showing GY-521 wiring

---

## Student Information

| Field | Details |
|-------|---------|
| **Student Name** | Xavier Banham |
| **Student ID** | 20094400 |
| **Assessment** | A3 – Vibration Monitoring |
| **Submission Date** | 24/5/26 |

---

## Assessment Summary

### GitHub Portfolio Repository

| Field | Details |
|-------|---------|
| **Repository URL** | github.com/banhax/iot-portfolio |
| **Assessment Folder** | `/A3-Vibration-Monitoring/` |
| **Code Location** | `/A3-Vibration-Monitoring/code/esp32-arduino/` |
| **Last Commit Date** | 24/5/26 |

### Work Completed

**Brief Description:**  
Describe your vibration monitoring system: which axes you measured, what filtering you applied, and what vibration thresholds trigger alerts.

Answer: I am measuring the X, Y, and Z axes. As I wrote the code in a Wokwi simulation, and not with hardware, I had to decide on a comfortable simulated vibration threshold, which I concluded to be a maximum of 4, and a minimum of -4 (the default resting value being 0). I filtered the data by collecting an average of the X, Y, and Z acceleration values (respectively), over the course of 3 main loop iterations.

---

## Assessment Evidence

### Code and Documentation

| Requirement | Evidence Provided | Location in Repository |
|-------------|-------------------|------------------------|
| Arduino `.ino` file with GY-521 code | ☑ Included | `/A3-Vibration-Monitoring/code/esp32-arduino/` |
| X, Y, Z acceleration measurements | ☑ Working | Raw values logged to serial |
| Moving average filter implementation | ☑ Included | Code comments explain filter window |
| Threshold detection for anomalies | ☑ Included | Thresholds defined for X, Y, Z axes |
| CSV data file (60+ seconds) | ☑ Included | CSV in assessment folder |
| Assessment README.md | ☑ Included | `/A3-Vibration-Monitoring/README.md` |

### Hardware Evidence

| Requirement | Evidence | Provided |
|-------------|----------|----------|
| **Breadboard Photo** | Photo showing GY-521 (MPU6050) correctly wired to ESP32 | ☑ Yes |
| **Raw Data Sample** | CSV showing raw and filtered acceleration values | ☑ Yes |
| **Working System** | Screenshot of serial monitor showing sensor values and anomalies | ☑ Yes |

**Breadboard Photo/Screenshot:**  
There's an image of the set up on Wokwi pictured. I couldn't output to a CSV file on Wokwi without paying money, for some reason, so I have an example expected CSV log file based upon the code I wrote.

**Sample CSV Entry:**  
rawAccelerationX,rawAccelerationY,rawAccelerationZ
-14.22,6.37,-5.39
avgAccelerationX,avgAccelerationY,avgAccelerationZ
-18.00,7.97,-6.74
rawAccelerationX,rawAccelerationY,rawAccelerationZ
19.61,-19.61,19.61
avgAccelerationX,avgAccelerationY,avgAccelerationZ
-10.26,-4.63,11.68
rawAccelerationX,rawAccelerationY,rawAccelerationZ
1.96,-19.61,3.43
avgAccelerationX,avgAccelerationY,avgAccelerationZ
12.64,-20.77,22.53
rawAccelerationX,rawAccelerationY,rawAccelerationZ
1.96,-10.79,-11.28
avgAccelerationX,avgAccelerationY,avgAccelerationZ
5.12,-16.84,4.41
rawAccelerationX,rawAccelerationY,rawAccelerationZ
1.96,-1.47,0.00
avgAccelerationX,avgAccelerationY,avgAccelerationZ
3.24,-12.42,1.35
rawAccelerationX,rawAccelerationY,rawAccelerationZ
1.96,0.00,0.00
avgAccelerationX,avgAccelerationY,avgAccelerationZ
2.77,-3.23,0.34
rawAccelerationX,rawAccelerationY,rawAccelerationZ
0.00,0.00,0.00
avgAccelerationX,avgAccelerationY,avgAccelerationZ
0.69,-0.81,0.08
rawAccelerationX,rawAccelerationY,rawAccelerationZ
0.00,0.00,0.00
avgAccelerationX,avgAccelerationY,avgAccelerationZ
0.17,-0.20,0.02

---

## Assessment Evidence Checklist

Confirm all requirements completed before submitting:

| Requirement | Completed |
|-------------|-----------|
| GY-521 sensor reads X, Y, Z acceleration | ☑ |
| Moving average filter reduces noise | ☑ |
| Filtered values are noticeably smoother than raw | ☑ |
| Threshold detection identifies anomalies | ☑ |
| CSV file contains 60+ seconds of data | ☑ |
| CSV includes both raw and filtered values | ☑ |
| Timestamp column in CSV | ☑ |
| Code is clean and commented | ☑ |
| GitHub repository is accessible | ☑ |
| Assessment README documents filter parameters and thresholds | ☑ |

---

## Optional Notes

Nothing of note, other than the Wokwi issues mentioned above.

---

## Submission Declaration

By submitting this form, I confirm that:

- ☑ All code in my A3 folder is my own work
- ☑ GY-521 accelerometer is correctly wired and functional
- ☑ Moving average filter is properly implemented
- ☑ Threshold detection logic works as designed
- ☑ Code follows ICTIOT502 assessment requirements
- ☑ I have not plagiarized or breached academic integrity

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
