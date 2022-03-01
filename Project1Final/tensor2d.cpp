#include "tensor2d.h"

tensor2d::tensor2d(int rows, int cols)
{
	mat.resize(rows);
	row = rows;
	col = cols;
	for (int i1 = 0; i1 < rows; i1++) {
		mat[i1].resize(cols);
	}
}

ostream& operator<<(ostream& out, const tensor2d& td2d)
{
	for (int i = 0; i < td2d.row; i++)
	{
		for (int j = 0; j < td2d.col; j++)
		{
			out << td2d.mat[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}

istream &operator>>(istream& in, tensor2d& td2d)
{
	for (int i = 0; i < td2d.row; i++)
	{
		for (int j = 0; j < td2d.col; j++)
		{
			in >> td2d.mat[i][j];
		}
	}
	return in;
}

