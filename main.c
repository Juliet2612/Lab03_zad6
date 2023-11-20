#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159265358979323846

double calculateSphereSurfaceArea(double radius) {
    return 4.0 * PI * pow(radius, 2.0);
}

double calculateSphereVolume(double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3.0);
}

double calculateSphericalSegmentVolume(double radius, double height, double angle) {
    double segmentVolume = (PI * pow(height, 2.0) * (3.0 * radius - height)) / 6.0;
    double capVolume = (PI * pow(height, 3.0)) / 6.0;

    return segmentVolume + capVolume - (capVolume * cos(angle));
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    double radius, height, angle;


    printf("Podaj promień kuli: ");
    scanf("%lf", &radius);

    printf("Podaj wysokość wycinka kuli: ");
    scanf("%lf", &height);

    printf("Podaj kąt wycięcia alfa (w stopniach): ");
    scanf("%lf", &angle);
    angle = angle * (PI / 180.0);  // Konwersja kąta z stopni na radiany

    double sphereSurfaceArea = calculateSphereSurfaceArea(radius);
    double sphereVolume = calculateSphereVolume(radius);
    double sphericalSegmentVolume = calculateSphericalSegmentVolume(radius, height, angle);

    printf("\nPole powierzchni kuli: %.2lf\n", sphereSurfaceArea);
    printf("Objętość kuli: %.2lf\n", sphereVolume);
    printf("Objętość wypukłego wycinka kuli: %.2lf\n", sphericalSegmentVolume);

    return 0;
}

