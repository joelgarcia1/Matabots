#pragma config(UART_Usage, UART1, uartUserControl, baudRate9600, IOPins, None, None)
#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    lineSens1,           sensorLineFollower)
#pragma config(Sensor, in3,    lineSens2,           sensorLineFollower)
#pragma config(Sensor, in4,    lineSens3,           sensorLineFollower)
#pragma config(Sensor, in8,    Potent,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  LED1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LED1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  LED1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  LED1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl5,  LimL1,          sensorTouch)
#pragma config(Sensor, dgtl6,  LimR1,          sensorTouch)
#pragma config(Sensor, dgtl7,  LEnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  REnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl11, stackEnc,       sensorQuadEncoder)
#pragma config(Motor,  port1,           CMot,          tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           LMots1,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LMots2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LMots3,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           MobMots1,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RMots1,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RMots2,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RMots3,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           MobMots2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          LiftMot,       tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "BoffMain.c" //auton
#include "AutonCommands.h"
#include "Commands.h"
#include "v2DriveControls.h"
#include "v2BoffPIDStackerTest.c" //drive
#include "PixyUart.h"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	auton();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task usercontrol()
{
	setVariables();
  drive();
}
