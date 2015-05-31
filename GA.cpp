#include "./Gene.hpp"
#include "./individual.hpp"
#include "./GeneticOperator.hpp"
#include "./GA.hpp"

void GA::selectCrossoverMethod(GA::CrossoverMethod type)
{
  switch(type) {
    case ONE_POINT:
      break;
    case TWO_POINTS:
      break;
    case UNIFORM:
      crossover = GeneticOperator::uniform_crossover;
      break;
    default:
      std::cerr << "select crossover function" << std::endl;
  }
}
void GA::selectSelectionMethod(GA::SelectionMethod type)
{
  switch(type) {
    case ROULETTE:
      selection = GeneticOperator::roulette_selection;
      break;
    case RANK:
      break;
    case TOURNAMENT:
      break;
    default:
      std::cerr << "select selection function" << std::endl;
  }
}

void GA::initializePopulation(std::size_t population_size,
    std::size_t chromosome_length, std::size_t max_value)
{
  this->population_.resize(population_size);
  this->parent_population_.resize(population_size);
  for(auto &individual : this->population_) {
    individual.initGenotype(chromosome_length, max_value);
  }
  for(auto &individual : this->parent_population_) {
    individual.initGenotype(chromosome_length, max_value);
  }
}

void GA::SimpleGA(void)
{
  Individual max_ind;

  // ===== selection ===== //
  selection(this->population_, &this->parent_population_, 0);
 
  // ===== crossover ===== //
  for(std::size_t ind=0; ind<population_.size(); ind+=2) {
    crossover(this->parent_population_[ind], this->parent_population_[ind+1],
         &this->population_[ind], &this->population_[ind+1]);
  }

  if(population_.size() % 2 != 0) {
    this->population_[population_.size()-1] 
      = this->parent_population_[population_.size()-1];
  }

  // ===== conduct mutation ===== //
  for(auto &individual : population_) {
    individual.mutate();
  }
  
  // ===== calculate fitness for all individuals ===== //
  this->CalcFitness();
}


// calculate fitness for all individuals
void GA::CalcFitness(void)
{
  for(auto &individual : this->population_) {
    calc_fitness(&individual);
  }
}
void GA::Progress(void)
{
  for(auto &individual : this->population_) {
    individual.print();
  }
}

void GA::TestMethod(void)
{
  // initialize individual
  Individual ind1(15, 20), ind2(15, 20);
  ind1.initGenotype(15, 20);
  ind2.initGenotype(15, 20);

  std::cout << "========== Initial Individual ==========" << std::endl;
  std::cout << "Individual 1: ";
  ind1.print();
  std::cout << "individual 2: ";
  ind2.print();

  // swap chromosome
  GeneticOperator::swap(&ind1, &ind2);

  std::cout << "========== After Swap ==========" << std::endl;
  std::cout << "Individual 1: ";
  ind1.print();
  std::cout << "individual 2: ";
  ind2.print();

  // mutation
  ind1.mutate();
  ind2.mutate();

  std::cout << "========== After Mutation ==========" << std::endl;
  std::cout << "Individual 1: ";
  ind1.print();
  std::cout << "individual 2: ";
  ind2.print();

  // crossover 
  Individual child1, child2;
  GeneticOperator::uniform_crossover(ind1, ind2, &child1, &child2);

  std::cout << "========== After Uniform CrossOver ==========" << std::endl;
  std::cout << "Individual 1: ";
  ind1.print();
  std::cout << "individual 2: ";
  ind2.print();
  std::cout << "child      1: ";
  child1.print();
  std::cout << "child      2: ";
  child2.print();
}

void GA::TestRun(void)
{
  
  GA ga;
  // population size: 10
  // chromosome length: 5
  // value max: 10
  ga.initializePopulation(10, 5, 10);
  ga.selectCrossoverMethod(GA::UNIFORM);
  ga.selectSelectionMethod(GA::ROULETTE);
  
  ga.SetFitnessFunction(TestFitnessFunction);
  ga.CalcFitness();
 
  for(int i=0; i<30; ++i) {
    std::cout << "generation time: " << i << std::endl;
    ga.SimpleGA();
    ga.Progress();
    std::cin.get();
  };
}
