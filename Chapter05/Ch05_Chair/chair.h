// file: chair.h
// chair class definition
#ifndef CHAIR_H
#define CHAIR_H

class Chair
{
public:
	enum class styles { basic, modern, traditional };
	enum class colors { black, white, red, green, blue };

private:      // all data members are made private
	colors        acolor;
	styles        astyle;
	bool          broken;
	double        currentLoad;
	double        maxWeight;
	double        personWeight;
	double        addedWeight;

 protected:
    double        setCurrentWeight();

 public:
	// constructors and destructor
	Chair();
	Chair(colors aColor, styles aStyle);
//	Chair(const Chair &aChair); // copy constructor
	~Chair();                   // destructor

	// methods (behavior)
	double  sit(double weightOfPerson);
	double  getOff();
	double  addWeight(double aWeight);
	double  removeWeight(double aWeight);
	double  currentWeight() const;
	bool    isBroken() const;
	bool    isSitting() const; // true if person seated
	void clear();              // remove all load from chair
	void refurbish();          // make the chair new again!

	// accessor functions for private data members
	colors color() const;
	Chair& setColor(colors aColor);
	styles style() const;
	Chair& setStyle(styles aStyle);
	double capacity() const;
	Chair& setCapacity(double limit);
};

#endif