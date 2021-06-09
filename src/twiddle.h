#ifndef TWIDDLE_H
#define TWIDDLE_H

#include "PID.h"
class PID;

class Twiddle {
 public:
  /**
   * Constructor
   */
  Twiddle();

  /**
   * Destructor
   */
  virtual ~Twiddle();

  void Init(double dp, double di, double dd, double tolerance);

  void IncreTotalErr(double val);

  void DoTwiddle(double cte, PID *pid);

 private:
  double dpid[3];
  double tol;
  double best_err;
  double total_err;

  int block;
  int coeff_index;
};

#endif