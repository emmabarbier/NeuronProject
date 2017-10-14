#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
using namespace std;

class Neuron {
	
private:
	
	double V_; 
	int nb_spikes_;
	double time_;
	double threshold_;
	double isRefractory_;
	int tau_;
	double tauRef_;
	double h_;
	double R_;
	double J_;
	double I_;
	
public:
	
	//constructors
	Neuron(double time); //default constructor
	
	//getters
	double getV() const;
	double getNb_spikes() const;
	double getTime_() const;
	//double getI() const;
	
	//setter
	void setV (const double& V);
	//void setI (const double& I);
	
	//methods
	bool update(double I);
	void Interact(Neuron &other);
};


#endif
