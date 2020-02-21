#include <cameraserver/CameraServer.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <time.h>

#include "Arduino.h"
//#include "Climber.h"
#include "Intake.h"
#include "Launcher.h"
#include "Limelight.h"
#include "NavX.h"
#include "Robot.h"
#include "RobotMap.h"
#include "SwerveModule.h"
#include "SwerveTrain.h"

Arduino arduino;
//Climber climber(R_launcherIndexMotorCANID, R_launcherLaunchMotorCANID);
Intake intake(R_CANIDmotorIntake);
Launcher launcher(R_CANIDmotorLauncherIndex, R_CANIDmotorLauncherLaunch);
Limelight limelight;
NavX navX(NavX::ConnectionType::kMXP);
SwerveModule frontRightModule(R_CANIDzionFrontRightDrive, R_CANIDzionFrontRightSwerve);
SwerveModule frontLeftModule(R_CANIDzionFrontLeftDrive, R_CANIDzionFrontLeftSwerve);
SwerveModule rearLeftModule(R_CANIDzionRearLeftDrive, R_CANIDzionRearLeftSwerve);
SwerveModule rearRightModule(R_CANIDzionRearRightDrive, R_CANIDzionRearRightSwerve);
SwerveTrain zion(frontRightModule, frontLeftModule, rearLeftModule, rearRightModule, navX);

frc::Joystick *playerOne;
frc::XboxController *playerTwo;

void Robot::RobotInit() {

    playerOne = new frc::Joystick(R_controllerPortPlayerOne);
    playerTwo = new frc::XboxController(R_controllerPortPlayerTwo);

    frc::CameraServer::GetInstance()->StartAutomaticCapture();

    frc::SmartDashboard::PutNumber("Launcher::Index-Speed:", R_launcherDefaultSpeedIndex);
    frc::SmartDashboard::PutNumber("Launcher::Launch-Speed:", R_launcherDefaultSpeedLaunch);
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {

    frc::SmartDashboard::PutBoolean("RegistrySet:", arduino.setRegister(Arduino::Registry::kRegisterTx0, "101010"));
}
void Robot::AutonomousPeriodic() {

    if (playerTwo->GetAButton()) {

        frc::SmartDashboard::PutBoolean("RegistrySent:", arduino.tx());
    }
}
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

    if (playerOne->GetRawButtonPressed(3)) {

        zion.setZeroPosition();
    }
    
    if (playerOne->GetRawButton(1)) {
        
        navX.resetYaw();
    }
    zion.driveController(playerOne);

/*
    if (playerTwo->GetBackButton()) {

        double climberSpeed = -playerTwo->GetTriggerAxis(frc::GenericHID::kLeftHand) + playerTwo->GetTriggerAxis(frc::GenericHID::kRightHand);
        climber.setSpeed(Climber::LiftMotor::kPrimary, climberSpeed);
        climber.setSpeed(Climber::LiftMotor::kSecondary, -climberSpeed);
    }
    else {

        climber.setSpeed(Climber::LiftMotor::kPrimary);
        climber.setSpeed(Climber::LiftMotor::kSecondary);
    }
}
*/

    intake.setSpeed(-playerTwo->GetTriggerAxis(frc::GenericHID::kLeftHand) * R_executionCapIntake + playerTwo->GetTriggerAxis(frc::GenericHID::kRightHand) * R_executionCapIntake);

    if (playerTwo->GetYButton()) {

        frc::SmartDashboard::PutNumber("Launcher::Launch-Speed:", playerTwo->GetY(frc::GenericHID::kLeftHand));
    }
    if (playerTwo->GetXButton()) {

        frc::SmartDashboard::PutNumber("Launcher::Index-Speed:", playerTwo->GetY(frc::GenericHID::kLeftHand));
    }
    if (playerTwo->GetBButton()) {

        launcher.setLaunchSpeed(frc::SmartDashboard::GetNumber("Launcher::Launch-Speed:", 0));
    }
    else {

        launcher.setLaunchSpeed(0);
    }
    if (playerTwo->GetAButton()) {

        launcher.setIndexSpeed(frc::SmartDashboard::GetNumber("Launcher::Index-Speed:", 0));
    }
    else {

        launcher.setIndexSpeed(0);
    }

    frc::SmartDashboard::PutNumber("LimeTA:", limelight.targetArea());
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
