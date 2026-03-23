# Assessment Submission Portfolio

**Assessment A2: RFID Access Control System**  
**Due:** Week 6 | **Weight:** 10%

---

## Version Control

| Field | Details |
|-------|---------|
| **Assessment Type** | Individual Portfolio Submission |
| **Assessment Code** | A2 |
| **Platform** | GitHub + Blackboard |
| **Document Version** | v1.0 |

---

## Introduction

This assessment submission form documents the completion of Assessment A2 (RFID Access Control System). Your code and project work must be completed and committed to your GitHub portfolio repository in the `/A2-RFID-Access-Control/` folder.

**Important:** This form is for submission evidence only. Your actual code stays on GitHub.

---

## Submission Instructions

### Assessment Overview

Implement an RFID authentication system with timestamp logging using:
- **RFID-RC522 module** reading multiple card types
- **DS3231 RTC module** for accurate timestamp logging
- **Serial output** logging all access events
- **Access control logic** to distinguish authorized vs. unauthorized cards

### How to Complete This Assessment

1. Complete RFID and RTC code in `/A2-RFID-Access-Control/code/esp32-arduino/`
2. Test with multiple RFID cards and verify logging
3. Generate CSV log file with 5+ access attempts
4. Commit all files to GitHub
5. Fill out this form with your submission details
6. Copy completed form into Blackboard by the due date

### What to Submit on GitHub

- ✅ Arduino `.ino` file with RFID-RC522 and DS3231 RTC code
- ✅ CSV log file showing 5+ access event timestamps
- ✅ README.md explaining RFID setup and authorized cards
- ✅ Breadboard photo showing RFID and RTC wiring

---

## Student Information

| Field | Details |
|-------|---------|
| **Student Name** | [Your full name] |
| **Student ID** | [Your student/enrollment ID] |
| **Assessment** | A2 – RFID Access Control |
| **Submission Date** | [Date submitted to Blackboard] |

---

## Assessment Summary

### GitHub Portfolio Repository

| Field | Details |
|-------|---------|
| **Repository URL** | [Paste your GitHub portfolio URL] |
| **Assessment Folder** | `/A2-RFID-Access-Control/` |
| **Code Location** | `/A2-RFID-Access-Control/code/esp32-arduino/` |
| **Last Commit Date** | [Date of final commit] |

### Work Completed

**Brief Description:**  
Describe your RFID system: how many authorized cards, what the RTC logs, and how unauthorized cards are handled.

[Your description here - 2-3 sentences]

---

## Assessment Evidence

### Code and Documentation

| Requirement | Evidence Provided | Location in Repository |
|-------------|-------------------|------------------------|
| Arduino `.ino` file with RFID and RTC code | ☐ Included | `/A2-RFID-Access-Control/code/esp32-arduino/` |
| RFID-RC522 reading multiple cards | ☐ Working | Serial output shows card UIDs |
| DS3231 RTC module providing timestamps | ☐ Working | CSV log includes accurate timestamps |
| Access control logic (authorized/unauthorized) | ☐ Included | Code distinguishes card types |
| CSV log file with 5+ access events | ☐ Included | CSV in assessment folder |
| Assessment README.md | ☐ Included | `/A2-RFID-Access-Control/README.md` |

### Hardware Evidence

| Requirement | Evidence | Provided |
|-------------|----------|----------|
| **Breadboard Photo** | Photo showing RFID-RC522 and DS3231 RTC wired correctly | ☐ Yes |
| **Access Log Sample** | CSV showing timestamps of access attempts | ☐ Yes |
| **Working System** | Screenshot of serial monitor showing access log output | ☐ Yes |

**Breadboard Photo/Screenshot:**  
[Describe what's shown in your evidence]

**Sample CSV Entry:**  
[Paste 1-2 rows from your CSV log showing timestamp, card UID, and access status]

---

## Assessment Evidence Checklist

Confirm all requirements completed before submitting:

| Requirement | Completed |
|-------------|-----------|
| RFID-RC522 reads card UIDs correctly | ☐ |
| DS3231 RTC provides accurate timestamps | ☐ |
| Serial output logs each access attempt | ☐ |
| CSV file contains 5+ access events | ☐ |
| Authorized cards are identified | ☐ |
| Unauthorized cards are rejected | ☐ |
| Code is clean and commented | ☐ |
| GitHub repository is accessible | ☐ |
| Assessment README documents the setup | ☐ |
| Breadboard photo shows all connections | ☐ |

---

## Optional Notes

[Add any additional context: card UIDs used, how you defined authorization, challenges with RTC synchronization, etc.]

---

## Submission Declaration

By submitting this form, I confirm that:

- ☐ All code in my A2 folder is my own work
- ☐ RFID and RTC modules are correctly wired and functional
- ☐ Access logging system works as designed
- ☐ Code follows ICTIOT502 assessment requirements
- ☐ I have not plagiarized or breached academic integrity

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
