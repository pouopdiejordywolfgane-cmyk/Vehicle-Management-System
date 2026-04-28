#include <iostream>
using namespace std;

class Vehicle{
	public:
		string brand;
		string model;
		int year;
		
	public:
		Vehicle(string brand, string model, int year){
			this ->brand = brand;
			this ->model = model;
			this ->year = year;
			cout<<brand<< " " <<model << " " <<year << " " <<endl;
		}
		
	public:
		virtual string GetInfo(){
			 return "brand:" + brand + ", model:" + model + ", year:" + to_string(year);			
			}
};

class Car: public Vehicle{
	private: 
	     int numDoors;
	     
	public:
	     Car(string brand, string model, int year, int numDoors):Vehicle(brand , model, year){
	     	cout<<"Enter the number of numDoors:";
	     	cin>>numDoors;
		 }
		 string GetInfo() override {
		 	return Vehicle::GetInfo() + ", numDoors: " + to_string(numDoors);
		 }		 
};

class Motorcycle: public Vehicle{
	private:
		bool Sidecar;
		
	public:
		Motorcycle(string brand, string model, int year, bool Sidecar):Vehicle(brand, model, year){
		}
		
		string GetInfo() override {
			string sidecarInfo = Sidecar ? "Yes" : "No";
			return Vehicle::GetInfo() = ", Sidecar: " + sidecarInfo;
		}
};


int main(){
	string brand, model;
	int numDoors, year;
	bool sidecarInfo;
	
	cout<<"What's the car's brand:";
	cin>>brand;
	
	cout<<"What's the model:";
	cin>>model;
	
	cout<<"What year is it:";
	cin>>year;
	
	cout<<"How many doors does  it have:";
	cin>>numDoors;
	
	cout<<"Does it have a sidecar (1 for yes, 0 for no): ";
	cin>> sidecarInfo;
	
	Car car1(brand, model, year,numDoors);
	Motorcycle motor1(brand, model, year, sidecarInfo);

	
	cout<< "/nCar Info: /n" << car1.GetInfo() << endl;
	cout<< "/nMotorcycle Info: /n" << motor1.GetInfo() << endl;
	
	return 0;
}