#pragma once
#include "tensor3d.h"
class tensor4d
{
public:
	tensor4d(int row, int col, int depth, int dim);
	friend ostream& operator<<(ostream& out, const tensor4d& td);
	friend istream& operator>>(istream& in, tensor4d& td2d);
	double operator*(const tensor4d& t4d)
	{
		double sum = 0.0;
		for (int i = 0; i < dimension; i++)
		{
			sum += tens4d[i] * t4d.tens4d[i];
		}
		return sum;
	}

	vector<int> size()
	{
		return { row, col, depth, dimension};
	}

	tensor3d operator[](int i)
	{
		if (i >= dimension)
		{
			throw "Out of range Index";
		}
		return tens4d[i];
	}
private:
	vector<tensor3d> tens4d;
	int row, col, depth, dimension;
};