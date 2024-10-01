#include <iostream>
#include <iomanip>

using namespace std;

double calculateTemperature(double t1, double t2, double d1, double d2, double l1, double l2) {
    double b1 = d1 / l1;
    double b2 = d2 / l2;
    double tc = ((l1 / b1) * t2 + (l2 / b2) * t1) / ((l1 / b1) + (l2 / b2));
    return tc;
}

double calculateCoordinate(double t, double t1, double tc, double t2, double b1, double b2) {
    if (t > tc) {
        return ((t - t1) / (tc - t1)) * b1;
    }
    else {
        return ((t - tc) / (t2 - tc)) * b2 + b1;
    }
}
int main() {
    double t1 = 650.0; 
    double t2 = 45.0;  
    double d1 = 0.55;  
    double d2 = 0.13;  
    double l1 = 0.8;   
    double l2 = 0.2;   

    double tc = calculateTemperature(t1, t2, d1, d2, l1, l2);

    double temperatures[] = { 500.0, 400.0, 250.0, 150.0 };

    cout << fixed << setprecision(3);
    cout << "Температура на стыке: " << tc << " °C" << endl;
    cout << "Координаты стенки:" << endl;

    for (double temp : temperatures) {
        double coordinate;
        if (temp > tc) {
            coordinate = calculateCoordinate(temp, t1, tc, t2, d1 / l1, d2 / l2);
        }
        else {
            coordinate = calculateCoordinate(temp, t1, tc, t2, d1 / l1, d2 / l2);
        }
        cout << "Для температуры " << temp << " °C: x = " << coordinate << " м" << endl;
    }

    return 0;
}


