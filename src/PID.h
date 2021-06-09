#ifndef PID_H
#define PID_H

#include "twiddle.h"
class Twiddle;

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_, double dKp_, double dKi_, double dKd_, double tolerance);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  /**
   * Getters and Setters
   */
  double GetPidError(int index);
  void SetPidError(int index, double val);
  double GetKpid(int index);
  void SetKpid(int index, double val);

 private:
  /**
   * PID Errors
   */
  double pid_error [3];

  /**
   * PID Coefficients
   */ 
  double Kpid [3];

  Twiddle *td;
};

#endif  // PID_H