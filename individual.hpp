#ifndef __INDIVIDUAL_HEADER__
#define __INDIVIDUAL_HEADER__

#include <cmath>
#include <iostream>
#include <vector>
#include "./Gene.hpp"
#include "./GeneticOperator.hpp"

class Gene;

class Individual
{
  public:
    std::vector<Gene> genotype_;  // a set of genes
    double fitness_;    

  public:
    Individual(void){}
    Individual(std::size_t length, std::size_t value_max);
    ~Individual(void){}
   

    // initialize genotype 
    void initGenotype(std::size_t chromosome_length, std::size_t gene_max);

    // copy operation for individual
    Individual& operator=(const Individual &copied);

    // compare fitness of individuals
    // if this individual's fittness is bigger than compared individual's
    // this method returns true. 
    bool operator>(const Individual &compared) const;

    // mutation
    void mutate(void);

    //----- accesser method -----//
    std::vector<Gene> GetGenotype(void) const { return this->genotype_; }
    void              SetGenotype(const std::vector<Gene> &genotype) { this->genotype_ = genotype; }
    
    std::size_t GetValue(int locus) { return this->genotype_[locus].GetValue(); }
    void        SetValue(int locus, int value) { this->genotype_[locus].SetValue(value); }

    std::size_t length(void) const { return genotype_.size(); }
    double GetFitness(void) const     { return fitness_; }
    void   SetFitness(double fitness) { this->fitness_ = fitness; }

    //----- information -----//
    void print(void) const;
};

#endif // __INDIVIDUAL_HEADER__
