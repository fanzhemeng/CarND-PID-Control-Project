#include "PID.h"
#include <algorithm>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double dKp_, double dKi_, double dKd_, double tolerance) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kpid[0] = Kp_;
  Kpid[1] = Ki_;
  Kpid[2] = Kd_;
  pid_error[0] = pid_error[1] = pid_error[2] = 0.0;

  td = new Twiddle();
  td->Init(dKp_, dKi_, dKd_, tolerance);
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  pid_error[2] = cte - pid_error[0];
  pid_error[0] = cte;
  pid_error[1] += cte;

  td->IncreTotalErr(cte * cte);

  //td->DoTwiddle(cte, this);
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  //return 0.0;  // TODO: Add your total error calc here!
  double total_err = -Kpid[0] * pid_error[0] - Kpid[1] * pid_error[1] - Kpid[2] * pid_error[2];
  return std::max(-1.0, std::min(1.0, total_err));
}

double PID::GetPidError(int index) {
  return pid_error[index];
}

void PID::SetPidError(int index, double val) {
  pid_error[index] = val;
}

double PID::GetKpid(int index) {
  return Kpid[index];
}

void PID::SetKpid(int index, double val) {
  Kpid[index] = val;
}