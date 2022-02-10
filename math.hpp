#include <vector>
#include <cmath>

using namespace std;


vector<double> multiply(const vector<double> &a, const vector<vector<double> > &b){
    vector<double> res;
    res.resize(a.size());

    for(int i=0; i<a.size(); i++){
        res[i]=0;    
    }
    for(int i=0; i<1; i++){ // 1 - l. wierszy a (a jest poziome)
        for(int j=0; j<b[0].size(); j++){ //b[0].size() - l. kolumn b
            for(int k=0; k<a.size(); k++){ //a.size() - l. kolumn a
                res[j] += a[k]*b[k][j];
            }
        }
    }
    return res;
}
vector<double> multiply(const vector<vector<double> > &a, const vector<double> &b){
    vector<double> res;
    res.resize(a.size());

    for(int i=0; i<a.size(); i++){
        res[i]=0;    
    }
    for(int i=0; i<a.size(); i++){ // a.size() - l. wierszy a (a jest poziome)
        for(int j=0; j<1; j++){ //1 - l. kolumn b
            for(int k=0; k<a.size(); k++){ //a.size() - l. kolumn a
                res[i] += a[i][k]*b[k];
            }
        }
    }
    return res;
}

double norm(const vector<double> &vec){
    return sqrt(vec[0]*vec[0]+vec[1]*vec[1]+vec[2]*vec[2]);
}

double dotProduct(const vector<double> &a, const vector<double> &b)
{
    double product = 0.0;
    if(a.size() == b.size()){
        for (int i = 0; i<a.size(); i++)
            product += + a[i]*b[i];
        return product;
    }
    else{
        return NULL;
    }
}
vector<double> crossProduct(const vector<double> &a, const vector<double> &b){
    vector<double> res;
    res = {a[1]*b[2]-a[2]*b[2], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};
    return res;
}

double getDeterminant(const vector<vector<double> > &vec) {
    if(vec.size() != vec[0].size()) {
        return NULL;
    } 
    int dimension = vec.size();

    if(dimension == 0) {
        return 1;
    }

    if(dimension == 1) {
        return vec[0][0];
    }

    //Formula for 2x2-matrix
    if(dimension == 2) {
        return vec[0][0] * vec[1][1] - vec[0][1] * vec[1][0];
    }

    double result = 0;
    int sign = 1;
    for(int i = 0; i < dimension; i++) {
        //Submatrix
        vector<vector<double> > subVect(dimension - 1, vector<double> (dimension - 1));
        for(int m = 1; m < dimension; m++) {
            int z = 0;
            for(int n = 0; n < dimension; n++) {
                if(n != i) {
                    subVect[m-1][z] = vec[m][n];
                    z++;
                }
            }
        }
        //recursive call
        result = result + sign * vec[0][i] * getDeterminant(subVect);
        sign = -sign;
    }
    return result;
}
vector<vector<double> > getTranspose(const vector<vector<double> > &matrix1) {
    //Transpose-matrix: height = width(matrix), width = height(matrix)
    vector<vector<double> > solution(matrix1[0].size(), vector<double> (matrix1.size()));

    //Filling solution-matrix
    for(size_t i = 0; i < matrix1.size(); i++) {
        for(size_t j = 0; j < matrix1[0].size(); j++) {
            solution[j][i] = matrix1[i][j];
        }
    }
    return solution;
}
vector<vector<double> > getCofactor(const vector<vector<double> > &vec) {
    /*if(vec.size() != vec[0].size()) {
        throw std::runtime_error("Matrix is not quadratic");
    } */

    vector<vector<double> > solution(vec.size(), vector<double> (vec.size()));
    vector<vector<double> > subVect(vec.size() - 1, vector<double> (vec.size() - 1));

    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[0].size(); j++) {

            int p = 0;
            for(int x = 0; x < vec.size(); x++) {
                if(x == i) {
                    continue;
                }
                int q = 0;

                for(int y = 0; y < vec.size(); y++) {
                    if(y == j) {
                        continue;
                    }

                    subVect[p][q] = vec[x][y];
                    q++;
                }
                p++;
            }
            solution[i][j] = pow(-1, i + j) * getDeterminant(subVect);
        }
    }
    return solution;
}
vector<vector<double> > getInverse(const vector<vector<double> > &vec) {
    if(getDeterminant(vec) == 0) {
        throw std::runtime_error("Determinant is 0");
    } 
    double d = 1.0/getDeterminant(vec);
    vector<vector<double> > solution(vec.size(), vector<double> (vec.size()));

    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            solution[i][j] = vec[i][j] * d; 
        }
    }

    return getTranspose(getCofactor(solution));
}

void printMatrix(const vector<vector<double> > &vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        for(size_t j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}