
#include "PathfinderPID.c"


// GLOBAL VARIABLES
const int diameter = 4; // inches
const int tile_length = 24; // inches
const float pi = 22 / 7;    // 3.14159...
const float circumference = (pi * diameter);     // the total distance one full rotation of the wheel covers (inches)
const float rotations_per_tile = (tile_length / circumference);    // the number of rotations the wheel makes to cover one tile
const float radius_of_robot = 5.5;            // this is the length from the center of the robot to the wheel (in inches)
const float RobotCircumference = (2 * pi * radius_of_robot);    // this is the circumference of the circle that would be made by a turning robot
float Rcurrent, Lcurrent, tolerance;
int proportionalWeight, MinPower;
int DirectionFacing = 2;
float tarDeg = 60; //Arbitrary value for a degree target
float proportionalWeight;
float integralWeight;
float derivativeWeight;
float sampleTime = 50; //arbitrary, but should be calculated if possible. Milliseconds
//sampleTime is the time between intervals of taking a measurement. Useful for integral
// and derivative
float RmotPow = 0, LmotPow = 0; //a temporary place to store the result from PID.



float proportional_Cont(float input, float kp)
{
  return (error * kp);
}
float integral_Cont(float ki)
{
  if(abs(error) < abs(tolerance))
  {
    totalError = totalError + (error * dt);
  }
  else
  {
    totalError = 0;
  }
  return (totalError * ki);
}
float derivative_Cont(float kd)
{
  return (((error - prevError)/(dt)) * kd);
}

float PIDController(float target, float senseVal, float senseTime, float kp, float ki, float kd)
{
  float result;
  /*target is your target value
  sense is the value of a sensor
  kp is your weight for the proportional controller
  ki is your weight for the integral controller
  kd is your weight for the derivative controller
  */
  dt = senseTime/1000; //since time is defined in miliseconds
  currSens = senseVal;
  error = input - currSens;
  result = proportional_Cont(target, kp) + integral_Cont(ki) + derivative_Cont(kd);
  return result;
}


float degToInch(int degree)
{
    float inch = ((4 * pi) * (degree/360));
    return inch;
}

bool nearTol(float Rcurrent, float Lcurrent, float tarDeg, float tolerance)     // checks whether value of encoder is within tolerance
{
    bool check = true;
    if((Rcurrent <= (tarDeg - tolerance) || Rcurrent >= (tarDeg + tolerance)) && (Lcurrent <= (tarDeg - tolerance) || Lcurrent >= (tarDeg + tolerance)))
    {
        check = false;
    }
    return check;
}  

task PIDControl()
{
  while(true) //in a while true loop to maintain the angle desired
  {
    RmotPow = PIDController(tarDeg, Rcurrent, proportionalWeight, integralWeight, derivativeWeight);
    LmotPow = PIDController(tarDeg, Lcurrent, proportionalWeight, integralWeight, derivativeWeight);
    //this only changes a value, not the motor power, to avoid power assigning issues
    wait1msec(sampleTime); //waits for the amount of sampleTime
  }
}

void move(float distance)
{
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0;
    tarDeg = (distance);
    Rcurrent = degToInch(SensorValue[REncoder]);    // current distance
    Lcurrent = degToInch(SensorValue[LEncoder]);
    proportionalWeight = 15;
    integralWeight = 10;
    derivativeWeight = 10;
    tolerance = 1;    // inches
    MinPower = 25;    // Minimum power for Motor
    startTask(PIDControl);
    while(nearTol(Rcurrent, Lcurrent, tarDeg, tolerance))
    {
        Rcurrent = degToInch(SensorValue[REncoder]);
        Lcurrent = degToInch(SensorValue[LEncoder]);

        motor[RMotor] = RmotPow;
        motor[LMotor] = LmotPow;
        if((abs(motor[RMotor])) && (abs(motor[LMotor])) < MinPower)
        {

            if((motor[RMotor] && motor[LMotor]) > 0)
            {
                motor[RMotor] = MinPower;
                motor[LMotor] = MinPower;
            }
            else if ((motor[RMotor] && motor[LMotor]) < 0)
            {
                motor[RMotor] = -MinPower;
                motor[LMotor] = -MinPower;
            }
        }
    }
    motor[RMotor] = 0;
    motor[LMotor] = 0;
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0;

}

void turn(int NumofDegrees)
{
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0;
    tarDeg = (RobotCircumference / 360) * NumofDegrees;
    Rcurrent = degToInch(SensorValue[REncoder]);
    Lcurrent = degToInch(SensorValue[LEncoder]);
    proportionalWeight = 5;
    tolerance = 3.8;    // inches
    MinPower = 18;        // Minimum power for Motor
    startTask(PIDControl);
    while(nearTol(Rcurrent, Lcurrent, tarDeg, tolerance))
    {
        Rcurrent = degToInch(SensorValue[REncoder]);
        Lcurrent = degToInch(SensorValue[LEncoder]);

        motor[RMotor] = -RmotPow;
        motor[LMotor] = LmotPow;
        if((abs(motor[RMotor])) && (abs(motor[LMotor])) < MinPower)
        {
            if((motor[RMotor] > 0) && (motor[LMotor] > 0))
            {
                motor[RMotor] = -MinPower;
                motor[LMotor] = MinPower;
            }
            else if ((motor[RMotor] < 0) && (motor[LMotor] < 0))
            {
                motor[RMotor] = MinPower;
                motor[LMotor] = -MinPower;
            }
        }
    }
    motor[RMotor] = 0;
    motor[LMotor] = 0;
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0;
}

void faceDirection(int DirectionFacing, int GoalDirection)
{
    // N = 1, E = 2, S = 3, W = 4
    int DirectionToTurn = DirectionFacing - GoalDirection;
    switch(DirectionToTurn)
    {
    case 1:
    case -3:
        turn(-90);
        break;
    case -1:
    case 3:
        turn(90);
        break;
    case 2:
    case -2:
        turn(180);
        break;
    default:
        break;
    }
    DirectionFacing = GoalDirection;
}

void PrintField()
    {
        for(int i = 0; i < X_size; i++)
        {
            printf(" [ ");
            for(int j = 0; j < Y_size; j++)
            {
                if(field[i][j] == 2)
                {
                    printf(" G ");
                }
                else if(field[i][j] == 99)
                {
                    printf(" R ");
                }
                else if(field[i][j] == 1)
                {
                    printf(" X ");
                }
                else if(field[i][j] == 100)
                {
                    printf(" * ");
                }
                else
                {
                    printf(" %i ", field[i][j]);
                }
            }
            printf(" ] \n");
        }
        printf("\n\n");
    }

void MakePaths()
    {
        int goal_x, goal_y;
        int stepsValue = 2;
        int check = 1;
        
        // FIND GOAL
        while(check == 1)
        {
            check = 0;
            for(int i = 0; i < X_size; i++)
            {
                for(int j = 0; j < Y_size; j++)
                {
                    if(field[i][j] == stepsValue)    // If Goal is found
                    {
                        check = 1;
                        goal_x = i;
                        goal_y = j;
                        // Increment values around stepsValue
                        if((goal_x > 0) && (field[goal_x-1][goal_y] == 0))     // increment left element
                        {
                            field[goal_x-1][goal_y] = stepsValue + 1;
                        } 
                        if((goal_x < (X_size-1)) && (field[goal_x+1][goal_y] == 0))   // increment right element
                        {
                            field[goal_x+1][goal_y] = stepsValue + 1;
                        }
                        if((goal_y > 0) && (field[goal_x][goal_y-1] == 0))     // increment upward element
                        {
                            field[goal_x][goal_y-1] = stepsValue + 1;
                        }
                        if((goal_x < (Y_size-1)) && (field[goal_x][goal_y+1] == 0))   // increment downward element
                        {
                            field[goal_x][goal_y+1] = stepsValue + 1;
                        }
                    }
                }
            }
            PrintField();
            stepsValue++;
        }
    }

void TakePath()
{
    int GoalDirection;
    int nextValue = 99;
    int current_x, current_y;
    int next_x, next_y;

    for(int i = 0; i < X_size; i++)
    {
        for(int j = 0; j < Y_size; j++)
        {
            // FIND ROBOT
            if(field[i][j] == 99)
            {
                current_x = i;
                current_y = j;
            }
        }
    }

    while(nextValue > 2)
    {
        nextValue = 99;
        if((current_x > 0) && (field[current_x-1][current_y] != 1) && (field[current_x-1][current_y] != 0) &&  (field[current_x-1][current_y] < nextValue))     // check left element
        {
            nextValue = field[current_x-1][current_y];
            next_x = current_x-1;
            next_y = current_y;
            GoalDirection = 4;
        }
        if((current_x < (X_size-1)) && (field[current_x+1][current_y] != 1) && (field[current_x+1][current_y] != 0) && (field[current_x+1][current_y] < nextValue))   // check right element
        {
            nextValue = field[current_x+1][current_y];
            next_x = current_x+1;
            next_y = current_y;
            GoalDirection = 2;
        }
        if((current_y > 0) && (field[current_x][current_y-1] != 1) && (field[current_x][current_y-1] != 0) && (field[current_x][current_y-1] < nextValue))     // check upward element
        {
            nextValue = field[current_x][current_y-1];
            next_x = current_x;
            next_y = current_y-1;
            GoalDirection = 1;
        }
        if((current_y < (Y_size-1)) && (field[current_x][current_y+1] != 1) && (field[current_x][current_y+1] != 0) && (field[current_x][current_y+1] < nextValue))   // check downward element
        {
            nextValue = field[current_x][current_y+1];
            next_x = current_x;
            next_y = current_y+1;
            GoalDirection = 3;
        }
        field[next_x][next_y] = 99;
        field[current_x][current_y] = 100;
        faceDirection(DirectionFacing, GoalDirection);
        move(tile_length);
        PrintField();
        current_x = next_x;
        current_y = next_y;
    }
}

void DoPathfinding()
    {
        PrintField();
        MakePaths();
        TakePath();
    }
