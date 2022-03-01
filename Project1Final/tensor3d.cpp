#include "tensor3d.h"

tensor3d::tensor3d(int rows, int cols, int dep)
{
	row = rows;
	col = cols;
	depth = dep;
	for (int i = 0; i < dep; i++)
	{
		tens3d.emplace_back(row, col);
	}
}

vector<int> tensor3d::size() const
{
	return { row, col, depth };
}

ostream& operator<<(ostream& out, const tensor3d& td3d)
{
	for (int i = 0; i < td3d.depth; i++)
	{
		out << td3d.tens3d[i] << endl << endl;
	}
	return out;
}

istream& operator>>(istream& in, tensor3d& td3d)
{
	for (int i = 0; i < td3d.depth; i++)
	{
		in >> td3d.tens3d[i];
	}
	return in;
}