#pragma once
#include "tensor2d.h"
class tensor3d
{
public:
	tensor3d(){}
	tensor3d(int row, int col, int depth);
	friend ostream& operator<<(ostream& out, const tensor3d& td);
	friend istream& operator>>(istream& in, tensor3d& td2d);
	double operator*(const tensor3d& t3d)
	{
		double sum = 0.0;
		for (int i = 0; i < depth; i++)
		{
		  sum += tens3d[i] * t3d.tens3d[i];
		}
		return sum;
	}
	tensor3d operator+(const vector<double>& t2d)
	{
		tensor3d td3d(row, col, depth);
		for (int i = 0; i < depth; i++)
		{
			td3d.tens3d[i] = tens3d[i] + t2d[i];
		}
		return td3d;
	}

	tensor3d operator+(const tensor3d& t3d)
	{
		vector<int> t3dsize = { t3d.row, t3d.col, t3d.depth };
		if (size() != t3dsize)
		{
			throw "Incompatible Size";
		}
		tensor3d td3d(row, col, depth);
		for (int i = 0; i < depth; i++)
		{
			td3d.tens3d[i] = tens3d[i] + t3d.tens3d[i];
		}
		return td3d;
	}

	const tensor2d &operator[](int i) const
	{
		if (i >= depth)
		{
			throw "Out of range Index";
		}
		return tens3d[i];
	}

	tensor2d& operator[](int i)
	{
		if (i >= depth)
		{
			throw "Out of range Index";
		}
		return tens3d[i];
	}



	vector<int> size() const;


private:
	vector<tensor2d> tens3d;
	int row, col, depth;

};

