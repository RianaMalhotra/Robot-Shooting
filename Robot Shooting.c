#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

const double g = 9.81;

double calculate_angle(double d, double H) {
  double v = 20.0;
  double l = 2.0;

  for (int alpha = 0; alpha <= 90; ++alpha) {
    double alpha_rad = M_PI * alpha / 180.0;

    double vx = v * cos(alpha_rad);
    double vy_0 = v * sin(alpha_rad);

    double t_travel = d / vx;

    double y = l + vy_0 * t_travel - 0.5 * g * t_travel * t_travel;

    if (fabs(y - H) <= 0.3) {
      return alpha;
    }
  }

  return -1;
}

int main() {
  double d, H;

  do {
    printf(
        "Please enter the horizontal distance from the wall between 3 and 30 "
        "m: ");
    scanf("%lf", &d);
  } while (!(3 <= d && d <= 30));

  do {
    printf("Please enter the target height between 3 and 6 m: ");
    scanf("%lf", &H);
  } while (!(3 <= H && H <= 6));

  double angle = calculate_angle(d, H);

  if (angle != -1) {
    printf("The angle should be %.2lf\n", angle);
  } else {
    printf("No valid angle found.\n");
  }

  return 0;
}
