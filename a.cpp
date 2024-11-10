#include "matrix.hpp"
#include <vector>
#include <stdexcept>

class Matrix
{
public:
    Matrix() : numRows(0), numCols(0) {}

    Matrix(int rows, int cols) : numRows(rows), numCols(cols), data(rows, std::vector<int>(cols)) {
        if (rows < 0 || cols < 0) {
            throw std::out_of_range("Количество строк и столбцов должно быть неотрицательным");
        }
    }

    void Reset(int rows, int cols) {
        if (rows == 0 || cols == 0) {
            numRows = 0;
            numCols = 0;
            data.clear();
        }
        else {
            numRows = rows;
            numCols = cols;
            data.assign(rows, std::vector<int>(cols));
        }
    }

    int& At(int row, int col) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return data[row][col];
    }

    const int& At(int row, int col) const {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return data[row][col];
    }

    int GetRows() const {
        return numRows;
    }

    int GetCols() const {
        return numCols;
    }

    bool operator==(const Matrix& m2) const {
        return numRows == m2.numRows && numCols == m2.numCols && data == m2.data;
    }

    bool operator!=(const Matrix& m2) const {
        return !(*this == m2);
    }

    Matrix operator+(const Matrix& m2) const {
        if (numRows != m2.numRows || numCols != m2.numCols) {
            throw std::invalid_argument("Размеры матриц не совпадают");
        }

        Matrix result(numRows, numCols);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                result.At(i, j) = At(i, j) + m2.At(i, j);
            }
        }
        return result;
    }

private:
    int numRows;
    int numCols;
    std::vector<std::vector<int>> data;
};
