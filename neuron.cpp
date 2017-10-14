#include "neuron.hpp"
#include <fstream>
#include <cmath>
using namespace std;


//======================================================================
//Constructors
//======================================================================

//default constructor
Neuron::Neuron(int time, double I)
	: V_(10), nb_spikes_(0), time_(time), threshold_(20), isRefractory_(0), tau_(20), tauRef_(2), h_(0.1), R_(20), J_(0.2), I_(I), spike_(false) {}


//======================================================================
//getters
//======================================================================

double Neuron::getV() const { return V_; }

double Neuron::getNb_spikes() const { return nb_spikes_; }

double Neuron::getTime_() const { return time_*0.1; } 

bool Neuron::getStateSpike_() const { return spike_;}

//double Neuron::getI() const { return I_;}

//======================================================================
//setters
//======================================================================
	
void Neuron::setV (const double& V) { V_= V; }

//void Neuron::setI (const double& I) { I_ = I}

//======================================================================
//Methods
//======================================================================

bool Neuron::update() {

	if (isRefractory_ > 0){
		V_= 10;
		isRefractory_ -=1;
		spike_ = false;
	} else {
		V_ = (V_ + (exp(-h_/tau_)*V_ + I_*R_*(1-exp(-h_/tau_)) ));
	}
			
	if (V_ > threshold_ ) {
		nb_spikes_+=1;
		isRefractory_ = tauRef_/h_;
		spike_ = true;
	}
		
	time_ += 1;
	return spike_;
}

void Neuron::Interact(Neuron &other) {
	if (other.spike_ == true) {
		other.V_ += J_;
	}
}
