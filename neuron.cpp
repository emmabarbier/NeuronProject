#include "neuron.hpp"
#include <fstream>
#include <cmath>
using namespace std;


//======================================================================
//Constructors
//======================================================================

//default constructor
Neuron::Neuron(double time)
	: V_(10), nb_spikes_(0), time_(time), threshold_(20), isRefractory_(0), tau_(20), tauRef_(2), h_(0.1), R_(20) {}


//======================================================================
//getters
//======================================================================

double Neuron::getV() const { return V_; }

double Neuron::getNb_spikes() const { return nb_spikes_; }

double Neuron::getTime_() const { return time_; } 

//======================================================================
//setters
//======================================================================
	
void Neuron::setV (const double& V) { V_= V; }

//======================================================================
//Methods
//======================================================================

void Neuron::update( double I) {
	
	//qd on aura plsr neurones, là où on devra itérer sur le I


	if (isRefractory_ > 0){
		V_= 10;
			isRefractory_ -=1;
	} else {
		V_ = (V_ + (exp(-h_/tau_)*V_ + I*R_*(1-exp(-h_/tau_)) ));
	}
			
	if (V_ > threshold_ ) {
		nb_spikes_+=1;
		isRefractory_ = tauRef_/h_;
	}
		
	time_ += h_;
}
