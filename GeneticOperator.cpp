#include "./GeneticOperator.hpp"
#include "./individual.hpp"

void GeneticOperator::swap(Individual *ind1, Individual *ind2)
{
  Individual tmp_ind;
  tmp_ind = (*ind1);
  (*ind1) = (*ind2);
  (*ind2) = tmp_ind;
}
void GeneticOperator::swap(Individual *ind1, Individual *ind2, std::size_t locus)
{
  std::swap(ind1->genotype_[locus], ind2->genotype_[locus]);
}


/*
 * Crossover
*/
void GeneticOperator::one_point_crossover(
    const Individual& parent1, const Individual& parent2,
    Individual* child1, Individual* child2)
{
}
void GeneticOperator::two_points_crossover(
    const Individual& parent1, const Individual& parent2,
    Individual* child1, Individual* child2)
{
}
void GeneticOperator::uniform_crossover(
    const Individual& parent1, const Individual& parent2,
    Individual* child1, Individual* child2)
{
  
  // check crossover probability
  if( rnd() > crossover_rate ) {
    return;
  }

  // copy parents to children
  std::size_t length = parent1.length();
  (*child1) = parent1;
  (*child2) = parent2;

  // conduct uniform crossover
  for(std::size_t locus=0; locus<length; ++locus) {
    if( rnd() < 0.50 ) {
      GeneticOperator::swap(child1, child2, locus); 
    }
  }
}

/*
 * Selection 
 */
void GeneticOperator::roulette_selection(const std::vector<Individual> &candidate,
    std::vector<Individual> *selected, std::size_t nElite)
{
  double sum_fitness, border, border_rate;

  // calculate sum of fitness
  sum_fitness = 0.0;
  for(auto individual : candidate) {
    sum_fitness += individual.GetFitness();
  }

  // spin roulette "rouletteTimes" times
  int j;
  for(std::size_t n=0; n<10; n++) {
    border_rate = sum_fitness * GeneticOperator::rnd();
    border = candidate[0].GetFitness();
    j = 0;
    while(border < border_rate) {
      border += candidate[++j].GetFitness();
    }
    (*selected)[n] = candidate[j];
  } 
}

/*
 * Random Generator
 */
void GeneticOperator::init_random(std::size_t seed)
{
  mt_engine = std::mt19937(seed);
}

std::size_t GeneticOperator::rnd(std::size_t n)
{
  std::uniform_int_distribution<int> dist(0, n); 
  return dist(mt_engine);
}

std::size_t GeneticOperator::rnd(std::size_t min, std::size_t max)
{
  std::uniform_int_distribution<int> dist(min, max); 
  return dist(mt_engine);
}

double GeneticOperator::rnd(void)
{
  std::uniform_real_distribution<double> dist(0.0, 1.0); 
  return dist(mt_engine);
}
double GeneticOperator::rnd(double min, double max)
{
  std::uniform_real_distribution<double> dist(min, max); 
  return dist(mt_engine);
}
