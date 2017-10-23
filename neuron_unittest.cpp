#include <iostream>
#include <cmath>
#include "neuron.hpp"
#include "gtest/gtest.h"

///Test if we have the right equation for the membrane potential
TEST (NeuronTest, MembranePotential) {
	Neuron n(0,1.0,1.5);
	
	//First update test
	n.update();
	EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0)), n.getV());
}
