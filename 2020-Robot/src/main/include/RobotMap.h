//RobotMap: A collection of constant variables for declarations and settings.
//Significantly reduces the amount of time spent looking for and configuring.

#pragma once

/*_____RoboRIO PWM Pin Declarations_____*/
/*___End RoboRIO PWM Pin Declarations___*/

/*_____RoboRIO DIO Pin Declarations_____*/
/*___End RoboRIO DIO Pin Declarations___*/

/*_____RoboRIO CAN Bus ID Declarations_____*/
//const int R_frontRightSwerveMotorCANID = 1;
//const int R_frontRightDriveMotorCANID  = 2;
//const int R_frontLeftSwerveMotorCANID  = 3;
//const int R_frontLeftDriveMotorCANID   = 4;
//const int R_rearLeftSwerveMotorCANID   = 5;
//const int R_rearLeftDriveMotorCANID    = 6;
//const int R_rearRightSwerveMotorCANID  = 7;
//const int R_rearRightDriveMotorCANID   = 8;

const int R_launcherIndexMotorCANID = 9;
const int R_launcherLaunchMotorCANID = 10;
/*___End RoboRIO CAN Bus ID Declarations___*/

/*_____PCM Pin Declarations_____*/
/*___End PCM Pin Declarations___*/

/*_____Global Robot Variable Settigns_____*/
const int R_playerOneControllerPort = 0;
const int R_playerTwoControllerPort = 1;

//This deadzone is used to determine when the controller is completely motionless...
const double R_controllerDeadzone = .075;
//And this one is to determine when rotation is being induced, as simply operation
//of the controller often results in errant rotation.
const double R_controllerZDeadzone = .6;

//These are the playerOne raw controller buttons that are used for manually
//zeroing Zion one wheel at a time by holding them down.
const int R_zeroButtonFR = 0;
const int R_zeroButtonFL = 0;
const int R_zeroButtonRL = 0;
const int R_zeroButtonRR = 0;
//And this is the execution cap for the speed at which this process can be done.
const double R_controllerZeroExecutionCap = .1;

//This is the highest decimal percentage of full speed that Zion can actually go.
const double R_zionExecutionCap = .25;

const double R_swerveTrainAssumePositionTolerance = .1;
const double R_swerveTrainAssumePositionSpeedCalculationFirstEndBehaviorAt = 3.5;
const double R_swerveTrainAssumePositionSpeedCalculationFirstEndBehaviorSpeed = .2;
const double R_swerveTrainAssumePositionSpeedCalculationSecondEndBehaviorAt = 1;
const double R_swerveTrainAssumePositionSpeedCalculationSecondEndBehaviorSpeed = .02;

//The amount of REV rotations it takes for a swerve assembly to make a full rotation.
//Often, a REV Rotation is referred to as a Nic, although they mean different things.
//Truly, a Nic is ~17.976 REV Rotation values.
const double R_nicsConstant = 17.9761447906494;
/*___End Global Robot Variable Settings___*/
