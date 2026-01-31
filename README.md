# MA.PH.EAN: Autonomous Delivery Robot

[Live Documentation Site](https://deanthebean16.github.io/MA.PH.EAN/) | [YouTube Video Demo 1](https://youtu.be/h0-LLMVobVA) [YouTube Video Demo 2](https://youtu.be/1TIr5CaIgGw) | [View Source Code](code)

### Project Overview
Maphean is a VEX-based autonomous robot designed to navigate complex trails using a triple-sensor array and transport logistics via a motorized claw. This project demonstrates the integration of **Embedded C** logic for hardware control and **HTML/CSS** for technical documentation. 

![Maphean Robot](images/maphean.JPG)

---

### Technical Implementation
* **Hardware Blueprint:** Refer to the [Navigation Blueprint Diagram](./images/blueprint.PNG) for the autonomous pathing logic.
* **Web Documentation:** Created using [HTML](./index.html) and [CSS](./style.css) to present code explanations and project goals.
* **Sensor Logic:** Detailed breakdown of the triple line-following array and threshold calibration can be found in the [Documentation Site](https://github.com/deanthebean16/MA.PH.EAN).

---

### Project Sub-routines & Logic Breakdown
This project involved programming several distinct sub-routines to handle navigation and mechanical interaction:

#### 1. Drift Correction & Pathing
Utilizes a triple IR sensor array to calculate positional error. If the left sensor detects a light surface (value > 2700), the robot executes a left-turn correction to re-center on the black line.

```c
// Sample Logic: Navigation Thresholds
if (SensorValue(leftSensor) > 2700) {
    motor[leftMotor] = 0;
    motor[rightMotor] = 63; // Turn left to correct drift
}
```



[View Navigation Logic Details](#line-routine)

#### 1. Drift Correction & Pathing
Triggered when the center sensor detects an object zone (value < 2450). The sequence stops the drive motors, actuates the claw servo, and executes a 180-degree pivot for the return trip.

```c
// Sample Logic: Object Interaction
if (SensorValue(centerSensor) < 2450) {
    stopMotors();
    motor[clawMotor] = 30; // Actuate claw to grab object
    wait1Msec(500);
}
```

[View Object Pickup Code Details](https://deanthebean16.github.io/MA.PH.EAN/#pickup-code)


#### Built With

* **VEX Robotics Hardware**: High-torque motors, Infrared Line Trackers, and motorized claw assembly.
* **Embedded C (ROBOTC)**: Developed the core navigation, sensor threshold logic, and control algorithms.
* **Dabble App**: Used for real-time wireless teleoperation and hybrid control.
* **HTML5 / CSS3**: Built the technical showcase and documentation platform.
