#include "CNN.h"

void read1d(vector<double>& vec, int size)
{
	double temp;
	for(int i = 0; i < size; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
}

vector<double> operator+(vector<double>& D1, vector<double>& D2)
{
	vector<double> result;
	for (int i = 0; i < D1.size(); i++)
	{
		result.push_back(D1[i] + D2[i]);
	}
	return result;
}

ostream& operator<<(ostream& out, const vector<double> td)
{
	for (int i = 0; i < td.size(); i++)
	{
		out << td[i] << endl;
	}
	return out;
}

int main()
{
	CNN cnn;
	tensor3d D1(32, 32, 3), D2, D5, D6, D7, D10, D11, D12, D15, D16;
	tensor4d D3(5, 5, 3, 16), D8(5, 5, 16, 20), D13(5, 5, 20, 20), D18(4, 4, 20, 10);
	vector<double> bias, bias2, bias3, bias4, D17, D20;
	cin >> D1;
	cin >> D3;
	read1d(bias, 16);
	cin >> D8;
	read1d(bias2, 20);
	cin >> D13;
	read1d(bias3, 20);
	cin >> D18;
	read1d(bias4, 10);

	D2 = cnn.conv(D1, D3) + bias;
	D5 = cnn.RELU(D2);
	D6 = cnn.MaxPooling(D5, 2, 2);
	cout << D6;
	D7 = cnn.conv(D6, D8) + bias2;
	D10 = cnn.RELU(D7);
	D11 = cnn.MaxPooling(D10, 2, 2);
	D12 = cnn.conv(D11, D13) + bias3;
	D15 = cnn.RELU(D12);
	D16 = cnn.MaxPooling(D15, 2, 2);
	vector<double> temp = cnn.DotProduct4d(D18, D16);
	D17 = temp + bias4;
	cnn.Normalise(D17);
	cout << D17;
	D20 = cnn.SoftMax(D17);
	cout << "SoftMax Layer Output :" << endl;
	cout << D20;
	return 0;
}