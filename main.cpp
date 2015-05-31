#include "./GA.hpp"
#include "./GeneticOperator.hpp"

int main(void)
{
  GeneticOperator::init_random(1);
  GA::TestRun();
  return 0;
}
