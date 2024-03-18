#include <iostream>
#include <cmath>
#include <chrono>

double estimateF(int N) {
    double gamma = 0.57721566;
    return gamma * N + log(N)*N + 0.5;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <N>" << std::endl;
        return 1;
    }

    int N = std::atoi(argv[1]);
    double estimatedValue, realValue;
    double precision = 0;

    if (N <= 100) {
        estimatedValue = 0;
        for (int i = 1; i <= N; i++) { estimatedValue += 1.0 / static_cast<double>(i); }
        estimatedValue = estimatedValue * N;
    } else { estimatedValue = estimateF(N); }

    std::cout << "Estimated F(" << N << ") = " << estimatedValue << std::endl;

    // Confidence Interval Calculation
    N = 100;
    double mean = estimateF(N);

    double variance = 0.0;
    for (int i = 1; i <= N; ++i) {
        double p = (static_cast<double>(N) - static_cast<double>(i - 1)) / static_cast<double>(N);
        variance += (1 - p) / (p * p);
    }

    double std_deviation = sqrt(variance);
    double z_score = 2.58;
    double interval_length = z_score * (std_deviation / sqrt(N));
    double L = mean - interval_length;
    double R = mean + interval_length;

    std::cout << "Interval [L, R] for F(100) 99% confidence: [" << L << ", " << R << "]" << std::endl;

    return 0;
}
