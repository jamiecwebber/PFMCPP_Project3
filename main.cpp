/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()



struct AcousticGuitar 
{
    AcousticGuitar();
    int numStrings;
    int numFrets;
    int capoFretNumber;
    int yearOfConstruction;
    bool hasAmplification;

    void playNote(int stringNumber, int fretNumber);

    void playChord(std::string chordName);

    void tuneString(int stringNumber, float tuningFrequency);
};

AcousticGuitar::AcousticGuitar()
{
    numStrings = 6;
    numFrets = 18;
    capoFretNumber = 7;
    yearOfConstruction = 1972;
    hasAmplification = true;
}

void AcousticGuitar::playNote(int stringNumber, int fretNumber)
{
    int noteNumber = ((6 - stringNumber) * 5) + fretNumber;
    if (stringNumber <= 2) 
        noteNumber -= 1;

    std::cout << "play note: " << noteNumber << std::endl;
}

void AcousticGuitar::playChord(std::string chordName)
{
    chordName = chordName + " strum";
    std::cout << chordName << std::endl;
}

void AcousticGuitar::tuneString(int stringNumber, float tuningFrequency)
{
    stringNumber += 1;
    tuningFrequency *= 1.5f;
}



struct Library
{
    
    int numBooks;
    int numMembers;
    float lateFee;
    int maxBooksLoaned;
    int maxDaysLoan;

    Library() : 
        numBooks(100),
        numMembers(100),
        lateFee(1.25f),
        maxBooksLoaned(5),
        maxDaysLoan(14) {}

    void checkOutBook(std::string bookTitle);

    void returnBook(std::string bookTitle);

    bool isBookInLibrary(std::string bookTitle);
};

void Library::checkOutBook(std::string bookTitle)
{
    std::cout << bookTitle << " checked out for " << maxDaysLoan << " days." << std::endl;
}

void Library::returnBook(std::string bookTitle)
{
    std::cout << bookTitle << std::endl;
}

bool Library::isBookInLibrary(std::string bookTitle)
{
    std::cout << bookTitle << std::endl;
    return true;
}



struct SmartBulb
{
    SmartBulb()
    {
        std::cout << "Constructing a smart bulb!" << std::endl;
    }
    int watts {200};
    float brightness {0.8f};
    bool isOn = false;
    float totalEnergy = 0.f;
    float totalHoursOn {0.f}; // different formatting like this obviously isn't advised

    void toggle();

    void toggleAfterDelay(float delay);

    void alertReplacement();

};

void SmartBulb::toggle()
{
    isOn = !isOn;
    if (isOn)
    {
        std::cout << "Smart bulb shining at " << brightness << " brightness" << std::endl;
    }
    else
    {
        totalEnergy += 0.1f;
        std::cout << "Smart bulb is off." << std::endl;
    }
}

void SmartBulb::toggleAfterDelay(float delay)
{
    delay += 1;
}

void SmartBulb::alertReplacement()
{

}


struct Cat
{
    Cat();
    int age;
    bool isMale;
    bool isTabby;
    float hunger;
    float thirst;

    void purr();
    void meow();
    void drink(float volumeOfWater);
};

Cat::Cat()
{
    age = 1;
    isMale = false;
    isTabby = true;
    hunger = 0.5f;
    thirst = 10.f;  
}

void Cat::purr()
{

}

void Cat::meow()
{
    std::cout << "meow! Kitty wants attention" << std::endl;
}
    
void Cat::drink(float volumeOfWater = 0.2f)
{
    thirst -= volumeOfWater;
}



struct HarmonicSet
{
    HarmonicSet(float bass, float gen);
    float bassFrequency, genFrequency;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);
};

// I made this a conditional constructor, I don't think we've covered that
HarmonicSet::HarmonicSet(float bass, float gen)
{
    bassFrequency = bass;
    genFrequency = gen;
}

// Updated this function with a loop
// The function calculates a set of frequencies by repeatedly adding the last two together, like in the fibonacci series
// This involves creating a placeholder variable inside the scope of the while loop
void HarmonicSet::playSet(float minFrequency, float maxFrequency)
{
    std::cout << "Harmonic set of bass " << bassFrequency << " and generator " << genFrequency << std::endl;
    float outputNote = (bassFrequency + genFrequency);
    float previous = genFrequency;
    while (outputNote < maxFrequency) 
    {
        if (minFrequency < outputNote)
        {
            std::cout << outputNote << " ";
        }
        float current = outputNote;
        outputNote += previous;
        previous = current;
    }
    std::cout << std::endl;
}


float HarmonicSet::calculateHarmonicity()
{
    return bassFrequency + genFrequency;
}

void HarmonicSet::playFiltered(float minFrequency, float maxFrequency, int genRule)
{
    float outputNote = (bassFrequency + genFrequency); 
    genRule += 1; 
    if (minFrequency < outputNote)
    {
        if (maxFrequency > outputNote)
        {
            std::cout << outputNote << std::endl;
        }
    }
}



struct RhythmicRules
{
    RhythmicRules();
    float gapPercentage;
    float convolutionRate;
    float tempo;
    float variation;

    struct Meter
    {
        Meter();
        int numerator; 
        int denominator; 
        int tempo; 
        int bars; 

        int bigStep(int currentBeat, int smallestBeat, int beatsPerBigStep); 
        int littleStep(int currentBeat, int smallestBeat); 
        void reset(); 
    };

    void outputRhythm(Meter meter);

    float setGapPercentage(float newGapPercentage);

    float setTempo(float newTempo);
};

RhythmicRules::RhythmicRules()
{
    gapPercentage = 0.2f;
    convolutionRate = 0.5f;
    tempo = 120.f;
    variation = 1.0f;
}

RhythmicRules::Meter::Meter()
{
    numerator = 4; 
    denominator = 4; 
    tempo = 120; 
    bars = 8; 
}

void RhythmicRules::outputRhythm(Meter meter)
{
    meter.bigStep(1,2,4);
}

float RhythmicRules::setGapPercentage(float newGapPercentage)
{
    return newGapPercentage;
}

float RhythmicRules::setTempo(float newTempo)
{
    return newTempo;
}

int RhythmicRules::Meter::bigStep(int currentBeat, int smallestBeat, int beatsPerBigStep)
{
    return currentBeat + (smallestBeat * beatsPerBigStep);
}

int RhythmicRules::Meter::littleStep(int currentBeat, int smallestBeat)
{
    return currentBeat + smallestBeat;
}
        
void RhythmicRules::Meter::reset()
{

}



struct PatternGenerator
{
    PatternGenerator();
    float rootedness;
    float repetitionPercentage;
    int stepSize;
    float variability;
    float fractalDimension;

    struct Pattern
    {
        Pattern();
        bool repeat; 
        int numberOfNotes;  
        int startingMIDI;  
        bool isArpeggio;    
        std::string patternName;

        void play();
        void reverse();
        void stop();
    };

    void getRhythm(RhythmicRules rhythms); 
    void calculateNote(HarmonicSet harmonies);
    Pattern generatePattern();
};

PatternGenerator::PatternGenerator()
{
    rootedness = 1.0f;
    repetitionPercentage = 0.15f;
    stepSize = 2;
    variability = 1.0f;
    fractalDimension = 1.618f;
}

PatternGenerator::Pattern::Pattern()
{
    repeat = false; 
    numberOfNotes = 5;  
    startingMIDI = 69;  
    isArpeggio = true;    
    patternName = "triads";
}

void PatternGenerator::getRhythm(RhythmicRules rhythms)
{
    RhythmicRules::Meter meter;
    rhythms.outputRhythm(meter);
}

void PatternGenerator::calculateNote(HarmonicSet harmonies)
{
    harmonies.calculateHarmonicity();
}
    
PatternGenerator::Pattern PatternGenerator::generatePattern()
{
    PatternGenerator::Pattern newPattern;
    std::cout << "new pattern: 12345" << std::endl;
    return newPattern;
}

void PatternGenerator::Pattern::play()
{
    std::cout << patternName << std::endl;
}

void PatternGenerator::Pattern::reverse()
{

}

void PatternGenerator::Pattern::stop()
{

}


struct Synthesizer
{
    std::string waveShape;
    float amplitude;
    float attackTime;
    int maxPolyphony;
    float distortion;

    Synthesizer()
    {
        waveShape = "sine";
        amplitude = 1.0f;
        attackTime = 2.0f;
        maxPolyphony = 6;
        distortion = 1.0f;
    }

    void getPattern(PatternGenerator patternGen);
    void getUI();
    void playAudio(float duration);

};



void Synthesizer::getPattern(PatternGenerator patternGen)
{
    patternGen.generatePattern();
}

void Synthesizer::getUI()
{
    std::cout << "attack time: " << attackTime << std::endl;
    std::cout << "amplitude: " << amplitude << std::endl;
}

void Synthesizer::playAudio(float duration)
{
    duration += 0.6f;
}


struct Distortion
{
    Distortion();
    float brightness;
    int numEchoes;
    float roughness;
    int vinylTap;

    void processInput();

    float calculateBrightness(float roomSize, float hiPass, float loPass);

    bool toggleBypass(bool bypass = false);
};

Distortion::Distortion()
{
    brightness = 0.5f;
    numEchoes = 3;
    roughness = 0.8f;
    vinylTap = 11;
}

void Distortion::processInput()
{
    std::cout << "DISTORRTIIOOOOON"<< std::endl;
    for (int n = numEchoes; n > 0; n -= 1)
    {
        std::cout << "DISTORRTI";
        for (int m = n; m > 0; m -= 1)
        {
            std::cout << "O";
        }
        std::cout << "N" << std::endl;
    }
}

float Distortion::calculateBrightness(float roomSize, float hiPass, float loPass)
{
    if (roomSize < loPass)
    {
        return loPass;
    }
    if (roomSize > hiPass)
    {
        return hiPass;
    }
    return roomSize;
}

bool Distortion::toggleBypass(bool bypass)
{
    return !bypass;
}



struct MelodicSequencer
{
    MelodicSequencer();
    // HarmonicSet harmonicSet;
    RhythmicRules rhythmicRules;
    PatternGenerator patternGenerator;
    Synthesizer synthesizer;
    Distortion distortion;
    void playSequence(bool repeat = true);
    void displayUI(int screenWidth = 400, int screenHeight = 300);
    int getUI(int screenWidth = 400, int screenHeight = 300);
};

MelodicSequencer::MelodicSequencer()
{
    // everything the MelodicSequencer contains has its own constructor
}

void MelodicSequencer::playSequence(bool repeat)
{
    std::cout << "playing sequence 12345" << std::endl;
    if (repeat)
    {
        MelodicSequencer newSequencer;
        newSequencer.playSequence(false);
    }
}

void MelodicSequencer::displayUI(int screenWidth, int screenHeight)
{
    int size = screenWidth * screenHeight;
    std::cout << size << std::endl;
}

int MelodicSequencer::getUI(int screenWidth, int screenHeight)
{
    return screenWidth * screenHeight;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();

    AcousticGuitar ag;
    ag.playChord("G");
    ag.playNote(6,0); // should be note 0
    ag.playNote(6,7); // these represent string number and fret number
    ag.playNote(5,0);
    ag.playNote(3,4); 
    ag.playNote(2,0);
    ag.playChord("D");
    ag.playChord("A");


    Cat cat;
    cat.meow();
    std::cout << "cat is tabby? : " << cat.isTabby << std::endl;
    std::cout << "cat is male? : " << cat.isMale << std::endl;
    std::cout << "cat thirst before drinking: " << cat.thirst << std::endl;
    cat.drink();
    std::cout << "after drinking default: " << cat.thirst << std::endl;
    cat.drink(2.0f);
    std::cout << "after drinking 2.0f: " << cat.thirst << std::endl;


    PatternGenerator::Pattern pattern;
    std::cout << "pattern's name: " << pattern.patternName << std::endl;
    pattern.play(); // prints the same name

    PatternGenerator pg;
    pg.generatePattern(); // prints "new pattern: 12345"


    Distortion ds;
    ds.processInput();
    std::cout << "brightness: " << ds.calculateBrightness(250.f, 300.f, 100.f) << std::endl;
    std::cout << "brightness: " << ds.calculateBrightness(350.f, 300.f, 200.f) << std::endl;


    MelodicSequencer ms;
    std::cout << "do repeat:"<< std::endl;
    ms.playSequence(true);
    std::cout << "don't repeat:"<< std::endl;
    ms.playSequence(false);

    std::cout << "----------New ones start here---------" << std::endl;

    Library lib;
    lib.checkOutBook("To Kill a Mockingbird");

    SmartBulb sb;
    sb.toggle();
    sb.toggle();
    sb.brightness = 1.2f;
    sb.toggle();
    sb.toggle();
    std::cout << "total energy used by bulb is " << sb.totalEnergy << std::endl;
    sb.toggle();
    sb.toggle();
    std::cout << "total energy used by bulb is " << sb.totalEnergy << std::endl;

    Synthesizer synth;
    std::cout << synth.maxPolyphony << " notes at a time on the Synth" << std::endl;
    synth.getUI();

    std::cout << "----------Part 5 starts here---------" << std::endl;

    HarmonicSet harmonicSet = HarmonicSet(220.0f, 440.0f);
    harmonicSet.playSet(220.0f, 22000.0f);
    HarmonicSet harmonicSetTwo(100.0f, 360.0f);
    harmonicSetTwo.playSet(10.f, 22000.0f);
    std::cout << "Sum of bass and generator is " << harmonicSetTwo.calculateHarmonicity() << std::endl;

    Distortion ds2;
    ds2.processInput();

    ds2.numEchoes = 15;
    ds2.processInput();


    std::cout << "good to go!" << std::endl;
}
