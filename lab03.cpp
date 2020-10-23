#include <iostream>
#include <vector>
#include <iomanip>
#include "cmath"



double Func(double& x) {
    return x * x * sin(x);
}

double UnimodalFunc(double& x) {
    return x * x * sin(x) * sin(5 * x);
}



double P(double &df,  double &Ti) {
    const int minus = -1;
    return exp(minus * (df) / Ti);

}

void PrintPoints(const int &N, const double &Ti, double &xi) {

    std::cout << N;
    std::cout << "|" << std::right << std::setprecision(5) << std::setw(6) << Ti;
    std::cout << "|" << std::right << std::setw(7) << std::setprecision(6) << xi;
    std::cout << "|" << std::right << std::setprecision(5) << Func(xi) << std::endl;
}

void PrintTitle() {

    std::cout << "N" << "    T" << "       x" << "     f(x)" << std::endl;

}



void MethodOtzhigaFunc(double Ti, const double Tmin,
                       const int a, const int b) {

    PrintTitle();
    std::vector<std::pair<double,double>> vectorx;
    const double rc = 1000.0;
    const int rd = 1000;
    const double alpha = 0.95; // коеффициент альфа
    int N = 0; // счетчик итераций выполнения условия
    double x1 = ((rand() % ((b - a) * rd)) / rc) + a;
    double y1 = Func(x1);

    while (Ti > Tmin) {


        double xi = ((rand() % ((b - a) * rd)) / rc) + a;
        double yi = Func(xi);
        double df;
        df = yi - y1;
        if (df <= 0) {

            x1 = xi;

        }else if (df > 0) {

            if (P(df, Ti) >= (rand() % ((1) * rd)) / rc);
            x1 = xi;
        }

        std::pair<double, double> point(xi, yi);
        vectorx.push_back(point);
        N++;

        PrintPoints(N, Ti, xi);
        Ti *= alpha;

    }

    auto xmin = std::min_element(
            vectorx.begin(), vectorx.end(),
            [](std::pair<double, double> p1, std::pair<double, double> p2) {
                return p1.second < p2.second; });

    std::cout << std::endl << "Result: Xmin = " << xmin->first << " Fmin = " << Func(xmin->first) << std::endl << std::endl;

}



void MethodOtzhigaUnimodalFunc(double Ti, const double Tmin,
                               const int a, const int b) {

    PrintTitle();


    std::vector<std::pair<double, double>> vectorx;
    const double rc = 1000.0;
    const int rd = 1000;
    const double alpha = 0.95; // коеффициент альфа
    int N = 0; // счетчик итераций выполнения условия
    double x1 = ((rand() % ((b - a) * rd)) / rc) + a;
    double y1 = UnimodalFunc(x1);

    while (Ti > Tmin) {


        double xi = ((rand() % ((b - a) * rd)) / rc) + a;
        double yi = UnimodalFunc(xi);
        double df;
        df = yi - y1;
        if (df <= 0) {

            x1 = xi;

        }else if (df > 0) {

            if (P(df, Ti) >= (rand() % ((1) * rd)) / rc);
            x1 = xi;
        }

        std::pair<double, double> point(xi, yi);
        vectorx.push_back(point);

        N++;
        PrintPoints(N, Ti, xi);

        Ti *= alpha;

    }
    auto xmin = std::min_element(
            vectorx.begin(), vectorx.end(),
            [](std::pair<double, double> p1, std::pair<double, double> p2) {
                return p1.second < p2.second; });

    std::cout << std::endl << "Result: Xmin = " << xmin->first << " Fmin = " << UnimodalFunc(xmin->first) << std::endl << std::endl;

}





int main() {

    double Ti = 10000;
    const double Tmin = 0.1;
    int a = 9;
    int b = 12;

    MethodOtzhigaFunc(Ti, Tmin, a, b);
    MethodOtzhigaUnimodalFunc(Ti, Tmin, a, b);

    system("pause>nul");
    return 0;
}