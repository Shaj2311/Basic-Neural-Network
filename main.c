//basic neural network that predicts sin() of quadrantal angles
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define EPOCHS 1000
#define NUM_INPUTS 4
#define NUM_HIDDEN 4
#define NUM_OUTPUTS 3


//get a random value between 0 and 1
double getRand()
{
	return (double)rand() / (RAND_MAX + 1.0);
}

//sigmoid and sigmoid derivative
double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}
double dSigmoid(double x)
{
	return sigmoid(x) * (1 - sigmoid(x));
}

int main()
{
	srand(time(0));

	//neuron biases
	double HIDDEN_BIASES[NUM_HIDDEN];
	double OUTPUT_BIASES[NUM_OUTPUTS];
	//edge weights
	double HIDDEN_WEIGHTS[NUM_INPUTS][NUM_HIDDEN];
	double OUTPUT_WEIGHTS[NUM_HIDDEN][NUM_OUTPUTS];

	//training data
	//0, 90, 180, 270
	double TRAINING_INPUTS[4][NUM_INPUTS] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	//0, 1, -1
	double TRAINING_OUTPUTS[4][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{1, 0, 0},
		{0, 0, 1}
	};

	//initialize weights and biases
	for(int i = 0; i < NUM_HIDDEN; i++)
	{
		HIDDEN_BIASES[i] = getRand();
		for(int j = 0; j < NUM_INPUTS; j++)
		{
			HIDDEN_WEIGHTS[j][i] = getRand();
		}
	}
	for(int i = 0; i < NUM_OUTPUTS; i++)
	{
		OUTPUT_BIASES[i] = getRand();
		for(int j = 0; j < NUM_HIDDEN; j++)
		{
			OUTPUT_WEIGHTS[j][i] = getRand();
		}
	}

	//one epoch for now

	//for each input,
	for(int input = 0; input < 4; input++)
	{
		//forward pass
		//hidden layer
		double HIDDEN_RESULT[NUM_HIDDEN]; //values computed by hidden layer neurons
		//for each hidden neuron,
		for(int i = 0; i < NUM_HIDDEN; i++)
		{
			//for each input neuron,
			double result = 0.f;
			for(int j = 0; j < NUM_INPUTS; j++)
			{
				//get input
				double inputValue = TRAINING_INPUTS[input][j];
				//apply weight
				inputValue *= HIDDEN_WEIGHTS[j][i];
				//add to result
				result += inputValue;
			}

			//apply hidden neuron bias
			result += HIDDEN_BIASES[i];

			//apply activation to introduce non-linearity
			result = sigmoid(result);

			//store final output
			HIDDEN_RESULT[i] = result;
		}

		//output layer
		double OUTPUT_RESULT[NUM_OUTPUTS];
		//for each output neuron,
		for(int i = 0; i < NUM_OUTPUTS; i++)
		{
			double result = 0.f;
			//for each hidden neuron,
			for(int j = 0; j < NUM_HIDDEN; j++)
			{
				//get input (from hidden neuron)
				double inputValue = HIDDEN_RESULT[j];

				//apply weight
				inputValue *= OUTPUT_WEIGHTS[j][i];

				//add to result
				result += inputValue;
			}

			//apply output neuron bias
			result += OUTPUT_BIASES[i];

			//apply activation to introduce non-linearity
			result = sigmoid(result);

			//store final result
			OUTPUT_RESULT[i] = result;
		}

		//loss calculation

		//back propagation
		//output layer
		//hidden layer
	}
	return 0;
}
