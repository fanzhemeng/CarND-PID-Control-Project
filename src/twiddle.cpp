#include "twiddle.h"
#include <iostream>
#include <limits>

Twiddle::Twiddle() {}

Twiddle::~Twiddle() {}

void Twiddle::Init(double dp, double di, double dd, double tolerance) {
  dpid[0] = dp;
  dpid[1] = di;
  dpid[2] = dd;
  tol = tolerance;
  total_err = 0.0;
  best_err = std::numeric_limits<double>::max();

  block = 0;
  coeff_index = 0;
}

void Twiddle::IncreTotalErr(double val) {
  total_err += val;
}

void Twiddle::DoTwiddle(double cte, PID *pid) {
  if (dpid[0]+dpid[1]+dpid[2] > tol) {
    if (block == 0) {
      pid->SetKpid(coeff_index, pid->GetKpid(coeff_index)+dpid[coeff_index]);
    }
    else if (block == 1) {
      if (total_err < best_err) {
        best_err = total_err;
        dpid[coeff_index] *= 1.1;
      }
      else {
        pid->SetKpid(coeff_index, pid->GetKpid(coeff_index) - 2*dpid[coeff_index]);
        block = 2;
      }
    }
    else if (block == 2) {
      if (total_err < best_err) {
        best_err = total_err;
        dpid[coeff_index] *= 1.1;
        block = 2;
      }
      else {
        pid->SetKpid(coeff_index, pid->GetKpid(coeff_index) - 2*dpid[coeff_index]);
        dpid[coeff_index] *= 0.9;
      }
    }

    total_err = 0.0;
    pid->SetPidError(0, 0.0);
    pid->SetPidError(1, 0.0);
    pid->SetPidError(2, 0.0);

    if (coeff_index == 2) {
      coeff_index = 0;
      block = 0;
    }
    else if (block == 2) {
      coeff_index ++;
      block = 0;
    }
    else {
      block ++;
    }
  }
}