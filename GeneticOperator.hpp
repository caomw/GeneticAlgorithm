#ifndef __GENETIC_OPERATOR_HEADER__
#define __GENETIC_OPERATOR_HEADER__

#include "./individual.hpp"
#include <random>

class Individual;

namespace GeneticOperator {

  const double crossover_rate = 0.80;
  const double mutation_rate  = 0.50;

  static std::mt19937 mt_engine;

  // 個体indi1と個体indi2を入れ替える
  void swap(Individual *ind1, Individual *indi2);

  // 個体ind1と個体ind2の遺伝子座locusを入れ替える
  void swap(Individual *ind1, Individual *ind2, std::size_t locus);

  // 交叉オペレーション
  // 親個体parent1, parent2 --> 子個体child1, child2
  void one_point_crossover(const Individual& parent1, const Individual& parent2,
      Individual* child1, Individual* child2);
  void two_points_crossover(const Individual& parent1, const Individual& parent2,
      Individual* child1, Individual* child2);
  void uniform_crossover(const Individual& parent1, const Individual& parent2,
      Individual* child1, Individual* child2);


  // 選択オペレーション
  void roulette_selection(const std::vector<Individual> &candidate,
      std::vector<Individual> *selected, std::size_t nElite);


  // 乱数生成
  void init_random(std::size_t seed);

  // generate [0, n-1] random number as integer
  std::size_t rnd(std::size_t n);

  // generate [min, max]  random number as integer
  std::size_t rnd(std::size_t min, std::size_t max);

  // generate [0.0, 1.0] random number as double
  double rnd(void);

  // generate [min, max] random number as double
  double rnd(double min, double max);
}

#endif // __GENETIC_OPERATOR_HEADER__
