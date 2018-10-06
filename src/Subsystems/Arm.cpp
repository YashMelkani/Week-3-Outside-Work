/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/MoveArm.h"

Arm::Arm() : Subsystem("ExampleSubsystem"), arm(new TalonSRX(1)) {
	arm->ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 10);
	arm->SetSelectedSensorPosition(0,0,10);
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveArm());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Arm::Move(double power){
	arm->Set(ControlMode::PercentOutput, power);
}

TalonSRX* Arm::getArm(){
	return arm;
}

