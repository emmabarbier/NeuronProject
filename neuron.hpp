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
	
public:
	
	//constructors
	Neuron(double time); //default constructor
	
	//getters
	double getV() const;
	double getNb_spikes() const;
	double getTime_() const;
	
	//setter
	void setV (const double& V);
	
	//methods
	void update(double I);
};


#endif
