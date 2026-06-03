# Assessment Submission Portfolio

**Assessment A5b: QuickSight Analytics Dashboard**  
**Due:** Week 14 | **Weight:** 7%

---

## Version Control

| Field | Details |
|-------|---------|
| **Assessment Type** | Individual Portfolio Submission |
| **Assessment Code** | A5b |
| **Platform** | GitHub + Blackboard |
| **Document Version** | v1.0 |

---

## Introduction

This assessment submission form documents the completion of Assessment A5b (QuickSight Analytics Dashboard). Your dashboard, architecture documentation, and deployment files must be committed to your GitHub portfolio repository in the `/A5-AWS-IoT-Integration/dashboards/` folder.

**Important:** This form is for submission evidence only. Your actual work stays on GitHub.

---

## Submission Instructions

### Assessment Overview

Create a real-time analytics dashboard for haul truck monitoring using AWS Grafana and IoT Analytics:

**Dashboard Requirements:**
- **Minimum 3 visualizations:**
  1. Temperature Trend (line chart, 24-hour history)
  2. Vibration Status (gauge/card vs. alert threshold)
  3. Alerts Summary (table of recent alerts)

**Data Integration:**
- Connect Grafana to IoT Core telemetry via IoT Analytics pipeline OR S3/DynamoDB
- Live/near-real-time data
- Auto-refresh every 5-15 minutes

### How to Complete This Assessment

1. Set up AWS IoT Analytics pipeline or S3 backend
2. Create Grafana dataset from truck telemetry data
3. Design dashboard with 3+ visualizations
4. Configure auto-refresh and interactive filters
5. Document architecture (1 page)
6. Export Grafana dashboard definition JSON
7. Commit all files to GitHub
8. Fill out this form with your submission details
9. Copy completed form into Blackboard by the due date

### What to Submit on GitHub

- ✅Grafana dashboard URL (live link) OR full-page screenshot (PDF/PNG)
- ✅ Grafana dashboard definition JSON export
- ✅ IoT Analytics pipeline configuration JSON

---

## Student Information

| Field | Details |
|-------|---------|
| **Student Name** | Xavier Banham |
| **Student ID** | 20094400 |
| **Assessment** | A5b – QuickSight Analytics Dashboard |
| **Submission Date** | 3/06/2026 |

---

## Assessment Summary

### GitHub Portfolio Repository

| Field | Details |
|-------|---------|
| **Repository URL** | github.com/banhax/iot-portfolio |
| **Dashboard Folder** | `/A5-AWS-IoT-Integration/dashboards/` |
| **Last Commit Date** | 3/06/2026 |

### Work Completed

**Brief Description:**  
Describe your dashboard: which visualizations you created, what data sources they use, refresh rate, and what business insights they reveal.

As AWS does not allow for using Quicksight in the lab we were provided as students, I had to come up with an alternative option, which I decided was Grafana. I imported the AWS data and formatted it into a 'Time series' graph. Proof provided.

---

## Assessment Evidence

### Dashboard & Documentation

| Requirement | Evidence Provided | Location in Repository |
|-------------|-------------------|------------------------|
| Grafana dashboard created | ✅ Live/Screenshot | URL or PDF provided |
| Temperature Trend visualization | ✅ Included | Line chart showing 24-hour history |
| Vibration Status visualization | ✅ Included | Gauge or card with threshold indicator |
| Alerts Summary visualization | ✅ Included | Table showing recent alerts |
| IoT Analytics pipeline | ✅ Configured | JSON export in dashboards folder |
| Dashboard definition JSON | ✅ Exported | JSON file in dashboards folder |
| Assessment README.md | ✅ Included | Instructions for accessing dashboard |

### Demonstration Evidence

| Requirement | Evidence | Provided |
|-------------|----------|----------|
| **Dashboard Live Link** | URL to live Grafana dashboard | ✅ Yes |
| **OR Dashboard Screenshot** | Full-page PNG/PDF showing all visualizations | ✅ Yes |

**QuickSight Dashboard URL:**  
https://modestpeanut3061.grafana.net/goto/s6nggv?orgId=stacks-1675747

---

## Assessment Evidence Checklist

Confirm all requirements completed before submitting:

| Requirement | Completed |
|-------------|-----------|
| IoT Analytics pipeline created and configured | ✅ |
| Telemetry data flowing from truck to Grafana | ✅ |
| Grafana dataset created from truck data | ✅ |
| Temperature Trend chart displays 24-hour history | ✅ |
| Vibration Status shows current value vs threshold | ✅ |
| Alerts Summary table shows recent anomalies | ✅ |
| Dashboard has 3+ visualizations | ✅ |
| Interactive filters working (if configured) | ✅ |
| Dashboard definition JSON exported | ✅ |

---

## Data Insights

**Temperature Visualization:**
- What temperature trends does the chart reveal?
A stable temperature, very high and out of acceptable bounds, but with a major dip down to low temps.
- Alert threshold set at: > 70 °C

**Vibration Visualization:**
- Baseline vibration level: 0 m/s²
- Alert threshold: >4 || <-4 m/s²

**Alerts Summary:**
- Most common alert type: Temperature

---

## Architecture Notes

**Data Flow:**
1. Truck MQTT → AWS IoT Core
2. IoT Core → [IoT Analytics / S3 / DynamoDB]
3. Data Store → QuickSight Dataset
4. Dataset → Dashboard Visualizations

**Refresh Strategy:**
Refresh is non-existent in this solution as AWS does not provide us with appropriate permissions. Grafana uses the exported JSON from the truck's output.

---

## Optional Notes

AWS lab permissions are very limited, making a lot of the requested functionality impossible. I had to use Grafana instead to create a dashboard of temperatures and acceleration.
---

## Submission Declaration

By submitting this form, I confirm that:

- ✅ All dashboard work in my A5b folder is my own work
- ✅ Grafana is correctly connected to truck telemetry
- ✅ Dashboard visualizations provide meaningful business insights
- ✅ Code follows ICTIOT503 assessment requirements
- ✅ I have not plagiarized or breached academic integrity

---

## For Assessor Use

| Field | Details |
|-------|---------|
| **Assessor Name** | [Assessor completes] |
| **Date Assessed** | [Assessor completes] |
| **Result** | ☐ Satisfactory ☐ Not Yet Satisfactory |
| **SiteWise Bonus** | ☐ Yes (+2 points) ☐ No |
| **Feedback** | [Assessor completes] |

---

**Submission recorded by Blackboard:** [Auto-recorded]

**Your actual work is assessed on GitHub. This form provides proof of submission.**
