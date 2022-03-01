#include "CNN.h"



void CNN::Normalise(vector<double> &A)
{
	double sum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i] * A[i];
	}
	double squareRootSum = sqrt(sum);

	for (int i = 0; i < A.size(); i++)
	{
		A[i] = A[i] / squareRootSum;
	}
}
tensor3d CNN::conv(tensor3d& t3d, tensor4d &filter)
{
	vector<int> dimensions = t3d.size();
	vector<int> filterDimensions = filter.size();
	tensor3d result(dimensions[0], dimensions[1], filterDimensions[3]);
	int pad = (filterDimensions[0] - 1) / 2;
	tensor3d paddedtensor = padding(t3d, pad);
	for (int k = 0; k < filterDimensions[3]; k++)
	{
		for (int i = 0; i < dimensions[0]; i++) {
			for (int j = 0; j < dimensions[1]; j++) {
				result[k][i][j] = dotproduct(paddedtensor, filter[k], i, j);
			}
		}
	}

	return result;

}

tensor3d CNN::padding(tensor3d& const t3d, int pad)
{
	vector<int> dimensions = t3d.size();
	int depth = dimensions[2];
	int rows = dimensions[0] + pad * 2;
	int cols = dimensions[1] + pad * 2;
	tensor3d result(rows, cols,depth);
	for (int i = 0; i < depth; i++) {
		for (int j = pad; j < pad + dimensions[0]; j++) {
			for (int k = pad; k < pad + dimensions[1]; k++) {
				result[i][j][k] = t3d[i][j - pad][k - pad];
			}
		}
	}
	return result;
}

double CNN::dotproduct(const tensor3d& t3d,const tensor3d& t3d2, int sx, int sy)
{
	vector<int> dimensions = t3d2.size();
	int depth = dimensions[2];
	int rows = dimensions[0];
	int cols = dimensions[1];
	double sum = 0;
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				sum += t3d2[i][j][k] * t3d[i][sx + j][sy + k];
			}
		}
	}
	return sum;
}

tensor3d CNN::RELU(const tensor3d& t3d)
{
	vector<int> dimensions = t3d.size();
	tensor3d result(dimensions[0], dimensions[1], dimensions[2]);
	for (int i = 0; i < dimensions[2]; i++)
	{
		for (int j = 0; j < dimensions[1]; j++)
		{
			for (int k = 0; k < dimensions[0]; k++)
			{
				result[i][j][k] = max(0.0, t3d[i][j][k]);
			}
		}
	}
	return result;
}

vector<double> CNN::SoftMax(const vector<double>& A)
{
	vector<double> result;
	double sum = 0.0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += exp(A[i]);
	}

	for (int i = 0; i < A.size(); i++)
	{
		result.push_back(exp(A[i]) / sum);
	}
	return result;
}


tensor3d CNN::MaxPooling(const tensor3d& t3d, int filterSize, int stride)
{
	vector<int> dimensions = t3d.size();
	int depth = dimensions[2];
	int row = (dimensions[0] - filterSize) / stride + 1;
	int col = (dimensions[1] - filterSize) / stride + 1;
	tensor3d result(row, col, depth);
	for (int i = 0; i < depth; i++)
	{
		int r = 0;
		for (int j = 0; j <= dimensions[0] - filterSize; j += stride, r++)
		{
			int c = 0;
			for (int k = 0; k <= dimensions[1] - filterSize; k += stride, c++)
			{
				double maxValue = DBL_MIN;
				for (int l = j; l < j + filterSize; l++)
				{
					for (int m = k; m < k + filterSize; m++)
					{
						maxValue = max(maxValue, t3d[i][l][m]);
					}
				}
				result[i][r][c] = maxValue;
			}
		}
	}

	return result;
}

vector<double> CNN::DotProduct4d(tensor4d& t4d1, tensor3d& t3d)
{
	vector<double> result;
	for (int i = 0; i < t4d1.size().back(); i++)
	{
		result.push_back(t4d1[i] * t3d);
	}
	return result;
}