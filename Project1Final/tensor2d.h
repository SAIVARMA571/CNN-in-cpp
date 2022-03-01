#pragma once
#include<iostream>
#include<vector>
using namespace std;
class tensor2d
{
public:
	tensor2d(int rows, int cols);
	friend ostream &operator<<(ostream& out, const tensor2d &td);
	friend istream &operator>>(istream& in, tensor2d& td2d);
	double operator*(const tensor2d& td)
	{
		double sum = 0.0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				sum += mat[i][j]*td.mat[i][j];
			}
		}
		return sum;
	}

	tensor2d operator+(double val)
	{
		tensor2d td2d(row, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				td2d.mat[i][j] = mat[i][j]  + val;
			}
		}
		return td2d;
	}

	tensor2d operator+(const tensor2d& t2d)
	{
		tensor2d td2d(row, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				td2d.mat[i][j] = mat[i][j] + t2d.mat[i][j];
			}
		}
		return td2d;
	}

	const vector<double> &operator[](int i) const
	{
		if (i >= row)
		{
			throw "Out of range Index";
		}
		return mat[i];
	}

	vector<double> &operator[](int i)
	{
		if (i >= row)
		{
			throw "Out of range Index";
		}
		return mat[i];
	}
private:
	vector<vector<double>> mat;
	int row, col;
	
};


