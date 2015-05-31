#include "./individual.hpp"
#include <iomanip>

Individual::Individual(std::size_t length, std::size_t gene_max)
{
  this->genotype_.resize(length);
  for(auto &gene : this->genotype_) {
    gene.SetMaxValue(gene_max);
  }
  this->fitness_ = 0;
}

void Individual::initGenotype
  (std::size_t chromosome_length, std::size_t gene_max)
{
  // initialize gene random value
  this->genotype_.resize(chromosome_length);
  for(auto &gene : genotype_) {
    gene.SetMaxValue(gene_max);
    gene.SetValue(GeneticOperator::rnd(gene.GetMaxValue()));
  }
}

Individual& Individual::operator=(const Individual &copied)
{
  this->genotype_ = copied.genotype_;
  this->fitness_  = copied.fitness_;

  return (*this);
}

bool Individual::operator>(const Individual &compared) const
{
  if(this->fitness_ > compared.fitness_) {
    return true;
  } else {
    return false;
  }
}

void Individual::mutate(void)
{
  for(auto &gene : genotype_) {
    // conduct mutation
    if( GeneticOperator::rnd() < GeneticOperator::mutation_rate ) {
      gene.SetValue(GeneticOperator::rnd());
    }
  }

}

void Individual::print(void) const
{
  for(auto gene : this->genotype_) {
    std::cout << std::setw(2) << gene.GetValue() << ", ";
  }
  std::cout << this->fitness_ << std::endl;
}
