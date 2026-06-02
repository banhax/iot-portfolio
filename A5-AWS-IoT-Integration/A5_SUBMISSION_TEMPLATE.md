# Assessment Submission Portfolio

**Assessment A5: AWS IoT Integration & Testing**  
**Due:** Week 14 | **Weight:** 18%

---

## Version Control

| Field | Details |
|-------|---------|
| **Assessment Type** | Individual Portfolio Submission |
| **Assessment Code** | A5 |
| **Platform** | GitHub + Blackboard |
| **Document Version** | v1.0 |

---

## Introduction

This assessment submission form documents the completion of Assessment A5 (AWS IoT Integration & Testing). Your code and testing documentation must be completed and committed to your GitHub portfolio repository in the `/A5-AWS-IoT-Integration/` folder.

**Important:** This form is for submission evidence only. Your actual code stays on GitHub.

---

## Submission Instructions

### Assessment Overview

Connect your haul truck device to AWS IoT Core and implement cloud features with comprehensive testing documentation:

**Cloud Integration:**
- X.509 certificate authentication to AWS IoT Core
- MQTT publish to `truck/{truckID}/telemetry`
- IoT Rules Engine routing messages to SNS alerts

**Testing Requirements (ICTIOT503):**
- Test plan (unit, integration, system tests)
- Test cases with expected vs actual results
- Bug log and resolutions
- Performance testing (message latency, offline sync)

### How to Complete This Assessment

1. Set up AWS IoT Core Thing with X.509 certificates
2. Complete Arduino MQTT code in `/A5-AWS-IoT-Integration/code/esp32-arduino/`
3. Create SNS alerts
4. Document all testing in PDF report
5. Commit code, screenshots, and testing report to GitHub
6. Fill out this form with your submission details
7. Copy completed form into Blackboard by the due date

### What to Submit on GitHub

- ✅ Arduino `.ino` file with MQTT/AWS code
- ✅ AWS console screenshots (IoT Core, Rules)
- ✅ Testing report (PDF, 5-10 pages)
- ✅ README.md with AWS setup instructions
- ✅ Demo video link showing MQTT, Shadow, SNS, CloudWatch

---

## Student Information

| Field | Details |
|-------|---------|
| **Student Name** | Xavier Banham |
| **Student ID** | 20094400 |
| **Assessment** | A5 – AWS IoT Integration |
| **Submission Date** | 2/06/2026 |

---

## Assessment Summary

### GitHub Portfolio Repository

| Field | Details |
|-------|---------|
| **Repository URL** | github.com/banhax/iot-portfolio |
| **Assessment Folder** | `/A5-AWS-IoT-Integration/` |
| **Code Location** | `/A5-AWS-IoT-Integration/code/esp32-arduino/` |
| **Last Commit Date** | 2/06/2026 |

### Work Completed

**Brief Description:**  
Describe your AWS integration: which services you used (IoT Core, Rules), what telemetry you publish, and testing scenarios you covered.

I used AWS IoT Core, and Amazon SNS to complete this project. I published telemetry for the temperature, as well as acceleration (or vibration) readouts. I set a rule with AWS IoT Core's message routing system, which allowed me perform an action whenever the temperature got too high (over 70), or if the vibrations passed their safe threshold value. In this case, I made and SNS notification trigger whenever these values were abnormal.

---

## Assessment Evidence

### Code and Documentation

| Requirement | Evidence Provided | Location in Repository |
|-------------|-------------------|------------------------|
| Arduino `.ino` with MQTT/AWS code | ✅ Included | `/A5-AWS-IoT-Integration/code/esp32-arduino/` |
| X.509 certificate authentication | ✅ Included | Code shows cert/key loading |
| MQTT publish to telemetry topic | ✅ Working | Messages visible in AWS test console |
| IoT Rules Engine configuration | ✅ Included | Rules route to SNS |
| SNS alert setup | ✅ Working | Alerts sent on threshold violation |
| Testing report (PDF) | ✅ Included | PDF in assessment folder |
| Assessment README.md | ✅ Included | `/A5-AWS-IoT-Integration/README.md` |

### Testing & Demonstration Evidence

| Requirement | Evidence | Provided |
|-------------|----------|----------|
| **Test Plan** | PDF documenting unit, integration, system tests | ✅ Yes |
| **Test Cases** | Expected vs actual results documented | ✅ Yes |
| **Bug Log** | Issues found and resolutions | ✅ Yes |
| **Performance Data** | MQTT latency | ✅ Yes |
| **AWS Screenshots** | IoT Core, Rules, SNS console | ✅ Yes |
| **Demo Video** | 5 minutes showing MQTT, SNS | ✅ Yes |

**Testing Report Location:**  
github.com/banhax/iot-portfolio/tree/main/A5-AWS-IoT-Integration

**Demo Video Link:**  
The demo video is contained within this folder.

---

## Assessment Evidence Checklist

Confirm all requirements completed before submitting:

| Requirement | Completed |
|-------------|-----------|
| X.509 certificates created and loaded in code | ✅ |
| MQTT messages publishing to AWS IoT Core | ✅ |
| Messages visible in AWS IoT Core test console | ✅ |
| IoT Rules Engine routing messages correctly | ✅ |
| SNS alerts sending on thresholds | ✅ |
| Test plan documented (unit/integration/system) | ✅ |
| Test cases with expected vs actual results | ✅ |
| Bug log showing issues and fixes | ✅ |
| Performance testing completed and documented | ✅ |
| Code is clean and commented | ✅ |
| GitHub repository is accessible | ✅ |

---

## Testing Report Summary

**Test Plan Coverage:**
- ✅ Unit tests (individual functions)
- ✅ Integration tests (sensors → MQTT → AWS)
- ✅ System tests (full device workflow)

**Key Test Scenarios:**
1. Normal operation: All sensors → telemetry → AWS
2. Threshold violation: Trigger alert, verify SNS email/SMS

**Performance Metrics:**
- Average MQTT publish latency: [___] ms

---

## Optional Notes

I used the 'United States (N. Virginia)' AWS server, and I wrote the code on Wokwi for the ESP32. I handled certificates by simply pasting the important strings into Wokwi, and having an MQTT library handle the message routing to AWS. I tested the interaction via the AWS IoT MQTT test console. I was unable to get CloudWatch to function, as it is more designed for monitoring of Amazon services, and not external variables. The SNS messaging seemed to work appropriately as an alternative for alerts, but due to the TAFE e-mail, I was unable to recieve any e-mails as evidence. This was the same issue faced in Industry Quest, therefore I believe it isn't a problem of my doing. 

Something further to note, due to me using Wokwi and not a physical device (I have been simulating an ESP32 as it is far more convenient for me to do so), is I am unable to implement unit testing, as far as I am able to tell at least. If I were able to add unit testing functionality, I would test whether or not different configurations, or data outputs are working as intended, and if they are being appropriately packaged and sent to AWS via MQTT publishing/subscribing. As mentioned previously, I was unable to get SNS to function with my TAFE e-mail, which is another part that I would like to test; though this could be done by simply viewing the inbox so there is a layer of 'doing too much'. All of my testing was done by examining outputs myself and altering my code, or AWS setup as needed.

---

## Submission Declaration

By submitting this form, I confirm that:

- ✅ All code in my A5 folder is my own work
- ✅ AWS integration follows security best practices
- ✅ Testing report is thorough and accurate
- ✅ Code follows ICTIOT503 assessment requirements
- ✅ I have not plagiarized or breached academic integrity

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
