/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4

 You forgot to do this in Part2:
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
 
 Part 4 instructions:
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()





/*
1) Acoustic Guitar
5 properties:
    1) Number of strings it has
    2) Number of frets
    3) Fret number of a capo
    4) Year it was built
    5) Whether or not it has amplification
3 things it can do:
    1) Play a single note
    2) Play a chord
    3) Tune its strings (you would want a nested type "string"?)
 */

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
    if (stringNumber <= 2) noteNumber -= 1;

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

/*
2) Library
5 properties:
    1) Number of books
    2) Number of members
    3) Fee for returning books late
    4) Number of books each member can have out at once
    5) Duration that a member can take a book out for
3 things it can do:
    1) Check out a book
    2) Return a book
    3) Search whether a book is in the libarry
 */

struct Library
{
    Library();
    int numBooks;
    int numMembers;
    float lateFee;
    int maxBooksLoaned;
    int maxDaysLoan;

    void checkOutBook(std::string bookTitle);

    void returnBook(std::string bookTitle);

    bool isBookInLibrary(std::string bookTitle);
};

Library::Library()
{
    numBooks = 100;
    numMembers = 100;
    lateFee = 1.25f;
    maxBooksLoaned = 5;
    maxDaysLoan = 14;  
}

void Library::checkOutBook(std::string bookTitle)
{
    std::cout << bookTitle << std::endl;
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

/*
3) smart light bulb
5 properties:
    1) Number of Watts
    2) Brightness level
    3) Whether it's currently on or not
    4) Keeps track of total energy it has used
    5) Keeps track of the total hours it's been on
3 things it can do:
    1) toggle on/off
    2) turn off automatically after a given time
    3) it can send a signal when it needs to be replaced
 */

struct SmartBulb
{
    SmartBulb();
    int watts;
    float brightness;
    bool isOn;
    float totalEnergy;
    float totalHoursOn;

    void toggle();

    void toggleAfterDelay(float delay);

    void alertReplacement();

};

SmartBulb::SmartBulb()
{
    watts = 200;
    brightness = 0.8f;
    isOn = false;
    totalEnergy = 0.f;
    totalHoursOn = 0.f;
}

void SmartBulb::toggle()
{

}

void SmartBulb::toggleAfterDelay(float delay)
{
    delay += 1;
}

void SmartBulb::alertReplacement()
{

}


/*
4) Cat
5 properties:
    1) Age
    2) Whether or not it's male
    3) Whether or not it's a tabby cat
    4) How hungry it is
    5) How thirsty it is
3 things it can do:
    1) It can purr
    2) It can meow
    3) It can drink water
 */
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


/*
Thing 5) Harmonic set (generates a set of frequencies from two input frequencies)
5 properties:
    1) Bass Frequency
    2) Generator Frequency 
    3) Minimum output frequency
    4) maximum output frequency
    5) generator rule # (would select among a few pre-coded rules)
3 things it can do:
    1) calculate and output a set of frequencies
    2) calculate statistics about the frequencies (how harmonically coherent they are, etc)
    3) filter the frequency set according to certain rules
 */

struct HarmonicSet
{
    HarmonicSet();
    float bassFrequency, genFrequency;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);
};

HarmonicSet::HarmonicSet()
{
    bassFrequency = 220.0f;
    genFrequency = 440.0f;
}

void HarmonicSet::playSet(float minFrequency, float maxFrequency)
{
    float outputNote = (bassFrequency + genFrequency);
    if (minFrequency < outputNote)
    {
        if (maxFrequency > outputNote)
        {
            std::cout << outputNote << std::endl;
        }
    }
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


/*
Thing 6) Rhythmic Rules
5 properties:
    1) density / note gap %
    2) "convolution rate" (how complicated the rhythms are)
    3) tempo
    4) rate of variation (how far it randomly strays from the selected settings)
    5) meter / pulse structure (this would have to be a UDT also)
3 things it can do:
    1) output a rhythm that controls the pattern generator
    2) modify the rhythmic properties according to a control signal from the UI
    3) modify the meter and tempo according to UI control
 */

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

/*
Thing 7) Pattern Generator
5 properties:
    1) "rootedness" (how often it plays the generator frequencies)
    2) repetition rate (how likely to repeat notes)
    3) step size (how far away in the set it will pick the next note)
    4) variability rate
    5) fractal dimension (would be used in the pattern calculation)
3 things it can do:
    1) receives inpulses from the rhythm generator
    2) calculates next note based on current harmonic set
    3) outputs control signals to the synth
 */

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

/*
Thing 8) Synthesizer
5 properties:
    1) wave shape
    2) amplitude
    3) attack time
    4) max polyphony
    5) distortion
3 things it can do:
    1) respond to signals from the pattern generator
    2) respond to signals from UI display
    3) output audio
 */
struct Synthesizer
{
    Synthesizer();
    std::string waveShape;
    float amplitude;
    float attackTime;
    int maxPolyphony;
    float distortion;

    void getPattern(PatternGenerator patternGen);
    void getUI();
    void playAudio(float duration);

};

Synthesizer::Synthesizer()
{
    waveShape = "sine";
    amplitude = 1.0f;
    attackTime = 2.0f;
    maxPolyphony = 6;
    distortion = 1.0f;
}

void Synthesizer::getPattern(PatternGenerator patternGen)
{
    patternGen.generatePattern();
}

void Synthesizer::getUI()
{

}

void Synthesizer::playAudio(float duration)
{
    duration += 0.6f;
}

/*
Thing 9) Distortion
5 properties:
    1) brightness
    2) number of echoes
    3) room size
    4) hipass filter cutoff
    5) lopass filter cutoff
3 things it can do:
    1) process a sound input
    2) calculate changes to its values
    3) turn on/off bypass
 */
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

/*
10) Melodic Sequencer
5 properties:
    1) Harmonic set (to take pitches from)
    2) Rhythmic rules (for deciding when to play what)
    3) Pattern generator (brings together harmonic set and rhythm rules)
    4) Synthesizer (selects/generates the actual sound)
    5) Distortion
3 things it can do:
    1) It can play a melodic sequence
    2) It can display patterns on the screen
    3) It can accept user instructions
 */

struct MelodicSequencer
{
    MelodicSequencer();
    HarmonicSet harmonicSet;
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


    std::cout << "good to go!" << std::endl;
}
