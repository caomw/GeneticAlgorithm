#ifndef __SPECIES_HEADER__
#define __SPECIES_HEADER__

#include <iostream>
#include <vector>
#include <string>
#include <random>

class Species {
  protected:
    double maxFitness_;       // fitness max
    double meanFitness_;      // fitness mean
    std::vector<double> pi_;  // fitness
    std::vector<double> ro_;  // roulette
    int alleleUpper_;
    int alleleLower_;
    int popSize_;
    int maxChildren_;
    int maxLength_;
    int minLength_;
    int maxNumber_;
    bool dup_a_;
    bool dup_s_;
    std::vector<std::vector<int> > ind_;
    std::vector<int> len_;
    std::vector<int> crossOverWorkspace1_;
    std::vector<int> crossOverWorkspace2_;
    std::vector<int> s_w_;
    std::vector<std::vector<int> > edge_;
    std::vector<char> pi_w_;

    std::mt19937 mt;
    std::uniform_real_distribution<double> randomGen;

    int position(int);
    int select(int method=-1, double bias=0.0, double step=1.0);

  public:
    Species(std::string filename, long seed);
    ~Species(void);
    void init(void);
    void out(int, int, int, char*);
  
    // crossover
    void copyParents(int method=2, int pair=0, int k_method=-1,
        double k_bias=0.0, double k_step=1.0);
    
    // mutation
};

#endif // __SPECIES_HEADER__
