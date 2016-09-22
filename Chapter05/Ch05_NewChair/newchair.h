// file: smartchair.h
// chair class definition
#ifndef NEWCHAIR_H
#define NEWCHAIR_H

class Chair
{
public:
	enum class styles { basic, modern, traditional };
	enum class colors { black, white, red, green, blue };

private:      // all data members are made private
	static double cumulativeWeight;
	static long numberOfPersons;
	static long chairCounter;

	colors  acolor;       // color of a chair
	styles  astyle;       // style of a chair
	bool    broken;       // is the chair broken?
	double  currentLoad;  // current total weight on chair
	double  maxWeight;    // weight capacity of the chair
	double  personWeight; // weight of person sitting
	                      // on chair. No person = -1
	double  addedWeight;  // non person weight added to chair.

protected:
	double  setCurrentWeight();

public:
	// constructors and destructor
	Chair();
	Chair(colors aColor, styles aStyle);
	// Chair(const Chair &aChair); // copy constructor
	~Chair();                      // destructor

	// methods (behavior)
	static double averageWeight();  // calculate average weight
	static long chairsActive();     // calculate average weight

	double  sit(double weightOfPerson);   // sit on chair
	double  getOff();                     // get off the chair
	double  addWeight(double aWeight);    // add weight
	double  removeWeight(double aWeight); // remove weight
	double  currentWeight()const;         // weight on chair
	bool    isBroken() const;             // true if broken
	bool    isSitting() const;            // true if person seated
	void clear();                         // set weight to 0.0
	void refurbish();         // make the chair new again!

	// accessor functions for private data members
	colors color() const;
	Chair& setColor(colors aColor);
	styles style() const;
	Chair& setStyle(styles aStyle);
	double capacity() const;
	Chair& setCapacity(double limit);
};

#endif  // NEWCHAIR_H
