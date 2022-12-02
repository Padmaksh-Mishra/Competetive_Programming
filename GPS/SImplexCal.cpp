# include<bits/stdc++.h>
using namespace std;


class SimplexMethod{
public:

    void solveForMinimization(vector<vector<double>> data, vector<double> objectives){
        int count = 0;

        // Add the constraints to the tableau
        for(int i = 0; i < data.size(); ++i){
            vector<double> tempData;
            // Push all variables into tempData
            for(int j = 0; j < data[0].size()-1; ++j){
                tempData.push_back(data[i][j]);
            }

            // push the stack variables to tempData
            for(int j = 0; j < data.size()+1; ++j){
                if(count == j){
                    tempData.push_back(1);
                }else{
                    tempData.push_back(0);
                }
            }

            // push the last value into tempData
            tempData.push_back(data[i][data[0].size()-1]);
            
            // push tempData into _vectorTableau
            _vectorTableau.push_back(tempData);

            // Increment count for stack variables
            ++count;
        }
        
        { // Add the objective function to the tableau
            vector<double> tempData;
            for(int i = 0; i < objectives.size(); ++i){
                tempData.push_back(objectives[i]*-1);
            }
            for(int i = 0; i < data.size()+1; ++i){
                if(count == i){
                    tempData.push_back(1);
                }else{
                    tempData.push_back(0);
                }
            }
            tempData.push_back(0);
            _vectorTableau.push_back(tempData);
        }
        printTableauVector();
        solveSimplex();
    }

    void solveForMinimization(vector<vector<double>> tableau){
        _vectorTableau = tableau;
        solveSimplex();
    }

private: // Auxillary Functions

    void solveSimplex(){
        auto noOfEquation = _vectorTableau.size()-1;
        auto noOfVariables = _vectorTableau[0].size()-1;
        double lowest = 0; // lowest value in the objective function (no need for INT_MAX since we only need negative values)
        int pivotColumn = 0;

        // find the lowest value in the objective function
        for(int i = 0; i < noOfEquation+1; ++i){
            if(_vectorTableau[noOfEquation][i] < lowest){
                lowest = _vectorTableau[noOfEquation][i];
                pivotColumn = i;
            }
        }

        // if the lowest value is less than zero, then we need to pivot
        if(lowest < 0){
            lowest = INT_MAX; //  lowest value in the column
            int pivotRow = 0;

            // Find the lowest value in the column by getting the ratio of the last column and the pivot column 
            for(int i = 0; i < noOfEquation; ++i){
                double temp = _vectorTableau[i][noOfVariables] / _vectorTableau[i][pivotColumn];
                if(temp < lowest){
                    lowest = temp;
                    pivotRow = i;
                }
            }

            // Initialize the Pivot Formula
            double pivotFormula = 1/_vectorTableau[pivotRow][pivotColumn];

            // if the pivot value is negative, make the pivot formula negative
            if(_vectorTableau[pivotRow][pivotColumn] < 0){
                pivotFormula *= -1;
                return;
            }            

            // Multiply the pivot row by the pivot formula
            for(int i = 0; i < noOfVariables+1; ++i){
                _vectorTableau[pivotRow][i] *= pivotFormula;
            }

            // Identify pivot column formula
            for(int i = 0; i < noOfEquation+1; ++i){
                // if it's not in the pivot row
                if(i != pivotRow){
                    // Get the multiplier
                    double fDifference = _vectorTableau[i][pivotColumn];

                    // apply the formula to all the rows
                    for(int j = 0; j < noOfVariables+1; ++j){
                        _vectorTableau[i][j] = _vectorTableau[i][j]-(fDifference*_vectorTableau[pivotRow][j]);
                    }
                }
                printTableauVector();
            }
            printTableauVector();
            solveSimplex();
        }else{
            return;
        }
    }

private: // others
    void printTableauVector(){
        cout << "Step : " << _printCount++ << "\n";
        for(int i = 0; i < _vectorTableau.size(); ++i){
            for(int j = 0; j < _vectorTableau[i].size(); ++j){
                cout << " "<< _vectorTableau[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";
    }

private: // Variables
    vector<vector<double>> _vectorTableau;
    int _printCount = 1;
};


int main(){
    SimplexMethod _calculator;
    vector<double> first = {0,1,10};
    vector<double> second = {2,5,60};
    vector<double> third = {3,1,44};
    vector<double> objective = {2,1};

    vector<vector<double>> data;
    data.push_back(first);
    data.push_back(second);
    data.push_back(third);

    _calculator.solveForMinimization(data, objective);
    return 0;
}