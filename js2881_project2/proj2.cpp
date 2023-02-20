#include <iostream>
using namespace std;
template <class U>
class Vector
{
private:
    U *x;
    int size;

public:
    int getsize()
    {
        return size;
    }
    Vector()
    {
        size = 0;
        x = NULL;
    }
    Vector(int n)
    {
        size = n;
        x = new U[n];
    }
    Vector(U *x1, int y)
    {
        size = y;
        x = new U[y];
        for (int i = 0; i < y; i++)
        {

            x[i] = x1[i];
        }
    }
    Vector(const Vector &vect)
    {
        size = vect.size;
        x = new U[size];
        for (int i = 0; i < size; i++)
        {
            x[i] = vect.x[i];
        }
    }
    void operator=(const Vector &A)
    {
        size = A.size;
        x = new U[size];
        for (int i = 0; i < size; i++)
        {
            x[i] = A.x[i];
        }
    }
    ~Vector() {}
    friend ostream &operator<<(ostream &os, const Vector &B)
    {
        for (int i = 0; i < B.size; i++)
        {
            os << B.x[i];
        }
        return os;
    }
    friend istream &operator>>(istream &is, const Vector &B)
    {
        for (int i = 0; i < B.size; i++)
        {
            is >> B.x[i];
        }
        return is;
    }
    Vector operator+(const Vector &plus)
    {
        Vector sum;
        sum.size = plus.size;
        sum.x = new U[size];
        for (int i = 0; i < sum.size; i++)
        {
            sum.x[i] = x[i] + plus.x[i];
        }
        return sum;
    }
    Vector operator-(const Vector &sub)
    {
        Vector diff;
        diff.size = sub.size;
        diff.x = new U[size];
        for (int i = 0; i < diff.size; i++)
        {
            diff.x[i] = x[i] + sub.x[i];
        }
        return diff;
    }
    Vector operator*(U c)
    {
        Vector prod;
        prod.size = size;
        prod.x = new U[size];
        for (int i = 0; i < prod.size; i++)
        {
            prod.x[i] = x[i] * c;
        }
        return prod;
    }
    U &operator[](int n) { return x[n]; }
};
class Matrix
{
private:
    int rows;
    int cols;
    Vector<double> *mat;

public:
    Matrix()
    {
        rows = 0;
        cols = 0;
        mat = NULL;
    }
    Matrix(int row, int col)
    {
        rows = row;
        cols = col;
        mat = new Vector<double>[row];
        for (int i = 0; i < row; i++)
        {
            mat[i] = Vector<double>(col);
        }
    }
    Matrix(Vector<double> *copy, int r, int c)
    {
        rows = r;
        cols = c;
        mat = new Vector<double>[r];
        for (int i = 0; i < r; i++)
        {
            mat[i] = Vector<double>(copy[i]);
        }
    }
    Matrix(const Matrix &g)
    {
        rows = g.rows;
        cols = g.cols;
        mat = new Vector<double>[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = Vector<double>(g.mat[i]);
        }
    }
    ~Matrix() {}
    void operator=(const Matrix &g)
    {
        rows = g.rows;
        cols = g.cols;
        mat = new Vector<double>[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = Vector<double>(g.mat[i]);
        }
    }
    Matrix operator+(const Matrix &g)
    {
        Matrix sum;
        sum.rows = g.rows;
        sum.cols = g.cols;
        sum.mat = new Vector<double>[rows];
        for (int i = 0; i < sum.rows; i++)
        {
            sum.mat[i] = mat[i] + g.mat[i];
        }
        return sum;
    }
    Matrix operator-(const Matrix &g)
    {
        Matrix diff;
        diff.rows = g.rows;
        diff.cols = g.cols;
        diff.mat = new Vector<double>[rows];
        for (int i = 0; i < diff.rows; i++)
        {
            diff.mat[i] = mat[i] - g.mat[i];
        }
        return diff;
    }
    Matrix operator*(double c)
    {
        Matrix mul;
        mul.rows = rows;
        mul.cols = cols;
        mul.mat = new Vector<double>[rows];
        for (int i = 0; i < mul.rows; i++)
        {
            mul.mat[i] = mat[i] * c;
        }
        return mul;
    }
    Vector<double> &operator[](int n) { return mat[n]; }
    friend ostream &operator<<(ostream &os, const Matrix &B)
    {
        for (int i = 0; i < B.rows; i++)
        {
            os << B.mat[i];
        }
        return os;
    }
    friend istream &operator>>(istream &is, const Matrix &B)
    {
        for (int i = 0; i < B.rows; i++)
        {
            is >> B.mat[i];
        }
        return is;
    }
    int getrows() { return rows; }
    int getcols() { return cols; }
};
// extra credit part 3
class Image
{
private:
    int height;
    int width;
    Matrix<double> *r;
    Matrix<double> *g;
    Matrix<double> *b;

public:
    Image()
    {
        width = 0;
        height = 0;
        r = NULL;
        g = NULL;
        b = NULL;
    }
    Image(int h, int w)
    {
        width = w;
        height = h;
        r = new Matrix<double>(height, width);
        g = new Matrix<double>(height, width);
        b = new Matrix<double>(height, width);
    }
    Image operator*(double alpha)
    {
        Image out;
        out.height = height;
        out.width = width;
        out.r = new Matrix<double>(height, width);
        out.g = new Matrix<double>(height, width);
        out.b = new Matrix<double>(height, width);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                out.r[i][j] = alpha * r[i][j];
                out.g[i][j] = alpha * g[i][j];
                out.b[i][j] = alpha * b[i][j];
            }
        }
        return out;
    }
    Image operator+(const Image &vect)
    {
        Image sum;
        sum.height = vect.height;
        sum.width = vect.width;
        sum.r = new Matrix<double>(height, width);
        sum.g = new Matrix<double>(height, width);
        sum.b = new Matrix<double>(height, width);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                sum.r[i][j] = vect.r[i][j] + r[i][j];
                sum.g[i][j] = vect.g[i][j] + g[i][j];
                sum.b[i][j] = vect.b[i][j] + b[i][j];
            }
        }
        return sum;
    }
    Image operator-(const Image &vect)
    {
        Image diff;
        diff.height = vect.height;
        diff.width = vect.width;
        diff.r = new Matrix<double>(height, width);
        diff.g = new Matrix<double>(height, width);
        diff.b = new Matrix<double>(height, width);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                diff.r[i][j] = r[i][j] - vect.r[i][j];
                diff.g[i][j] = g[i][j] - vect.g[i][j];
                diff.b[i][j] = b[i][j] - vect.b[i][j];
            }
        }
        return diff;
    }
};
int main()
{
    Matrix A(2, 2);
    cin >> A;
    Matrix B;
    B = A + A + A;
    B[1][1] = 50;
    cout << B;

    return 0;
}
