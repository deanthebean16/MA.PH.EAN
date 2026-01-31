//pseudocode missing boilerplate
task main()
{
    int x = 0;
    int y = 0;
    int z = 0;

    while (true) {
        // Update variables (though they aren't used in the logic below, the image includes them)
        x = sensorValue(leftLineFollower);
        y = sensorValue(centerLineFollower);
        z = sensorValue(rightLineFollower);

        // Move Forward while on the black line
        if (sensorValue(centerLineFollower) > 2700) {
            startMotor(rightMotor, -70);
            startMotor(leftMotor, -70);
        }
        // If the surface gets light (value < 2450), stop and grab
        else if (sensorValue(centerLineFollower) < 2450) {
            // Close claw
            stopMotor(rightMotor);
            stopMotor(leftMotor);
            startMotor(clawMotor, 50);
            wait(1);

            // Turn 180 degrees
            startMotor(leftMotor, -80);
            startMotor(rightMotor, 80);
            wait(2.5); // 2.5 seconds determines the 180 degree rotation
        }
    }
}
