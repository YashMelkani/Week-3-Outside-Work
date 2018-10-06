/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MoveArm.h"
#include "Robot.h"


MoveArm::MoveArm() : posPid(new WVPIDController(0.1,0,0,0,false)){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm);
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
	double targetPos = Robot::m_oi->getJoy()->GetY() * 100; // assume the range for the arm is 100
	if(targetPos < 0){
		targetPos = 0;
	}
	double currentPos = Robot::arm->getArm()->GetSelectedSensorPosition() * 10; // assume 10 converts to position of arm
	Robot::arm->Move(posPid->Tick(currentPos));
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveArm::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {

}
