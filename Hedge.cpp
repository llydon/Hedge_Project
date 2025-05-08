#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> //For precision.

using namespace std;

vector<vector <double>> hedgeAlgo(int n, int t, double lr, vector<vector<double>> M) {
    vector<vector<double>> expertProbs;
    vector<double> weights(n, 1.0);
    //double totalWeight = 0.0; It was redundacnt to have it delcared here.
    for (int i = 0; i < t; i++) {
        double totalWeight = 0.0; //Total weight needs to be reset each round or else it causes errors.
        for (int w = 0; w < n; w++) {
            totalWeight += weights[w];
        }
        vector <double> probabilities(n);
        for (int j = 0; j < n; j++) {
            probabilities[j] = weights[j] / totalWeight;
        }
        expertProbs.push_back(probabilities);
        for (int k = 0; k < n; k++) {
            double losses = M[i][k];
            weights[k] = weights[k] * exp(-lr * losses);
        }
    }
    return expertProbs;
}

int main() {
    int n; // Number of experts
    int t; // Number of rounds
    double lr; //learning rate
    cin >> n >> t >> lr;

    //Had to move the matrix to main to read in the values and then pass it into hedgeAlgo.
    vector<vector<double>> M(t, vector<double>(n));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    vector<vector<double>> finalProbs = hedgeAlgo(n, t, lr, M);

    cout << fixed << setprecision(6); //Set preciosion to 6 ro keep the spacing uniform.

    cout << "Expert probabilities: " << endl;
    for (int i = 0; i < finalProbs.size(); i++) {
        for (int j = 0; j < finalProbs[i].size(); j++) {
            //Output is the probability of each expert in a row, depending on the number of experts based on the input.
            //The number of rows corresponds to the number of rounds/iterations.
            //With this we can see how the probabilities change over time.
            cout << finalProbs[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
