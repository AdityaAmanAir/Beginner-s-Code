#include <vector>
#include "matplotlibcpp.h" 
namespace plt = matplotlibcpp;

int main() {
    // Create x and y arrays from 0 to 99
    std::vector<int> x(100), y(100);
    for (int i = 0; i < 100; ++i) {
        x[i] = i;
        y[i] = i;
    }
    
    // Create meshgrid equivalent
    std::vector<std::vector<int>> X(100, std::vector<int>(100));
    std::vector<std::vector<int>> Y(100, std::vector<int>(100));
    std::vector<std::vector<int>> Z(100, std::vector<int>(100));
    
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            X[i][j] = x[j];  // Note: swapped indices for proper meshgrid
            Y[i][j] = y[i];
            Z[i][j] = X[i][j] ^ Y[i][j];  // XOR operation
        }
    }
    
    // Create 3D plot
    plt::plot_surface(X, Y, Z);
    plt::show();
    
    return 0;
}