//psuedocode missing boilerplate
task main()
{
    // 1. Variable Initialization
    int x = 0;
    int y = 0;
    int z = 0;

    while (true) {
        // 2. Update Sensor Readings
        x = sensorValue(leftLineFollower);
        y = sensorValue(centerLineFollower);
        z = sensorValue(rightLineFollower);

        // 3. Line Following Logic
        // Center sensor sees dark (line) -> Go Straight
        if (sensorValue(centerLineFollower) > 2700) {
            startMotor(rightMotor, -70);
            startMotor(leftMotor, -70);
        }
        // Left sensor sees dark -> Correct Right
        else if (sensorValue(leftLineFollower) > 2700) {
            startMotor(rightMotor, 80);
            startMotor(leftMotor, -80);
        }
        // Right sensor sees dark -> Correct Left
        else if (sensorValue(rightLineFollower) > 2700) {
            startMotor(rightMotor, -80);
            startMotor(leftMotor, 80);
        }
        
        // 4. Object Handling (Pickup Sequence)
        // If no sensors see the line (Value <= 2700), assume we are in the object zone
        else {
            // Open claw and move forward to approach object
            startMotor(clawMotor, -50);
            startMotor(rightMotor, -70);
            startMotor(leftMotor, -70);
            wait(1);

            // Stop moving and Close claw to grab object
            stopMotor(rightMotor);
            stopMotor(leftMotor);
            startMotor(clawMotor, 50);
            wait(1);

            // Turn left with object
            stopMotor(clawMotor);
            startMotor(leftMotor, -50);
            startMotor(rightMotor, 50);
            wait(1);

            // Stop turning, ensure claw is held, then Reverse
            stopMotor(leftMotor);
            stopMotor(rightMotor);
            startMotor(clawMotor, -70); // Note: Image shows -70 here, possibly holding tension?
            wait(1);
            stopMotor(clawMotor);

            // Reverse a bit
            startMotor(leftMotor, 50);
            startMotor(rightMotor, -50); // Note: Mixed signs usually mean turning, check your wiring.
            wait(1);

            // Continue forward
            startMotor(rightMotor, 70);
            startMotor(leftMotor, 70);
            wait(1);
            stopMotor(rightMotor);
            stopMotor(leftMotor);
            wait(100);
        }
    }
}
