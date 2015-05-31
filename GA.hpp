#ifndef __GA_HEADER__
#define __GA_HEADER__

#include "./Gene.hpp"
#include "./individual.hpp"
#include "./GeneticOperator.hpp"
#include <functional>

class GA 
{
public:
  typedef std::function<void(Individual, Individual,
      Individual*, Individual*)> CrossoverFunc;
  typedef std::function<void(const std::vector<Individual>&,
      std::vector<Individual>*, std::size_t)> SelectionFunc;
  typedef std::function<void(Individual*)> FitnessFunc;
  
  enum CrossoverMethod {ONE_POINT, TWO_POINTS, UNIFORM};
  enum SelectionMethod {ROULETTE, RANK, TOURNAMENT};


  private:
    std::vector<Individual> population_;
    std::vector<Individual> parent_population_;

    // Function Members
    CrossoverFunc crossover;
    SelectionFunc selection;
    FitnessFunc   calc_fitness;

  public:
    GA(void) {}
    ~GA(void) {}

    // set functions
    void selectCrossoverMethod(CrossoverMethod type);
    void selectSelectionMethod(SelectionMethod type);
    void SetFitnessFunction(FitnessFunc func) { calc_fitness = func; }

    // initialize
    void initializePopulation(std::size_t population_size,
        std::size_t chromosome_length, std::size_t max_value);

    // Generation Alternation
    void SimpleGA(void);
   
 
    // Calculate fitness
    void CalcFitness(void);

    // Progress(genotype and fitness value)
    void Progress(void);


    static void TestMethod(void);
    static void TestRun(void);
    static void TestFitnessFunction(Individual* ind)
    {
      double fitness;

      // calc fitness
      fitness = 0.0;
      for(auto i=0; i<5; ++i) {
        fitness += (10 - ind->genotype_[i].GetValue());
      }

      fitness /= 5;
      ind->SetFitness(fitness);
    }
};

#endif // __GA_HEADER__
