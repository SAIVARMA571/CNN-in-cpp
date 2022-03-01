#include "tensor4d.h"

tensor4d::tensor4d(int rows, int cols, int dep, int dim)
{
	row = rows;
	col = cols;
	depth = dep;
	dimension = dim;
	for (int i = 0; i < dimension; i++)
	{
		tens4d.emplace_back(row, col, depth);
	}
}

ostream& operator<<(ostream& out, const tensor4d& td4d)
{
	for (int i = 0; i < td4d.dimension; i++)
	{
		out << td4d.tens4d[i] << endl << endl << endl;
	}
	return out;
}

istream& operator>>(istream& in, tensor4d& td4d)
{
	for (int i = 0; i < td4d.dimension; i++)
	{
		in >> td4d.tens4d[i];
	}
	return in;
}
