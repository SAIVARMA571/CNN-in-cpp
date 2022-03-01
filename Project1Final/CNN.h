#pragma once
#include "tensor4d.h"
class CNN
{
public:
	tensor3d conv(tensor3d &t3d, tensor4d &filter);
	tensor3d RELU(const tensor3d& t3d);
	tensor3d MaxPooling(const tensor3d& t3d, int filterSize, int stride);
	vector<double> DotProduct4d(tensor4d& t4d1, tensor3d& t3d);
	void Normalise(vector<double> &t2);
	vector<double> SoftMax(const vector<double>& td2);
private:
	tensor3d padding(tensor3d& t3d, int pad);
	double dotproduct(const tensor3d& t3d, const tensor3d &t3d2, int i, int j);
};

