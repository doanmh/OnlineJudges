/*
	Codeforces
	Ancient Berland Circus
*/

#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

#define PI 3.14159265

int main() {
	double ax, ay, bx, by, cx, cy;
	scanf("%lf %lf", &ax, &ay);
	scanf("%lf %lf", &bx, &by);
	scanf("%lf %lf", &cx, &cy);

	//Catesian Coordinates to find circumcenter
	double d = 2.0*(ax*(by - cy) + bx*(cy - ay) + cx*(ay - by));
	double ux = (((ax * ax) + (ay * ay)) * (by - cy) + ((bx * bx) + (by * by)) * (cy - ay) + ((cx * cx) + (cy * cy)) * (ay - by)) / d;
	double uy = (((ax * ax) + (ay * ay)) * (cx - bx) + ((bx * bx) + (by * by)) * (ax - cx) + ((cx * cx) + (cy * cy)) * (bx - ax)) / d;

	double angleCircumcenter = acos(((ux - ax) * (ux - ax) + (uy - ay) * (uy - ay) + (ux - bx) * (ux - bx) + (uy - by) * (uy - by) - (ax - bx) * (ax - bx) - (ay - by) * (ay - by)) / (2*sqrt((ux - ax) * (ux - ax) + (uy - ay) * (uy - ay))*sqrt((ux - bx) * (ux - bx) + (uy - by)*(uy - by))));

	int edges = 3;

	for (int i = 3; i <= 100; i++) {
		double angle = 2.0*PI/i;
		double px = ax - ux;
		double py = ay - uy;
		double temp_px, temp_py;
		bool foundB = false;
		bool foundC = false;

		for (int j = 1; j < i; j++) {

			temp_px = px*cos(angle) - py*sin(angle);
			temp_py = px*sin(angle) + py*cos(angle);

			px = temp_px;
			py = temp_py;

			if (!foundB) {
				foundB = (abs(px - bx + ux) < 0.00001 && abs(py - by + uy) < 0.00001);
			}
			if (!foundC) {
				foundC = (abs(px - cx + ux) < 0.00001 && abs(py - cy + uy) < 0.00001);
			}
		}
		if (foundB && foundC) {
			edges = i;
			break;
		}
	}

	double R = sqrt((ux - ax) * (ux - ax) + (uy - ay) * (uy - ay));
	double area = 0.5 * (edges * R * R) * sin(2.0*PI/edges);

	printf("%f\n", area);

	return 0;
}