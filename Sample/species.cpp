#include "./species.hpp"
#include <fstream>
#include <iostream>
#include <random>

// constructor
Species::Species(std::string filename, long seed)
{
  int i1, kind, num;
  std::ifstream ifs(filename);

  ifs >> this->alleleUpper_ >> this->alleleLower_;
  ifs >> this->maxLength_ >> this->minLength_;
  ifs >> this->dup_a_ >> this->dup_s_;
  ifs >> this->popSize_ >> this->maxChildren_;

  std::cout << this->alleleUpper_ << ", " << this->alleleLower_ << std::endl;
  std::cout << this->maxLength_ << ", " << this->minLength_ << std::endl;
  std::cout << this->dup_a_ << ", " << this->dup_s_ << std::endl;
  std::cout << this->popSize_ << ", " << this->maxChildren_ << std::endl;

  // you must write check method !
 
  num = this->popSize_ + this->maxChildren_;
  this->ind_.resize(num, std::vector<int>(maxLength_));
  this->edge_.resize(maxLength_, std::vector<int>(5));
  this->pi_.resize(num);
  this->ro_.resize(num);
  this->len_.resize(num);
  this->crossOverWorkspace1_.resize(maxLength_);
  this->crossOverWorkspace2_.resize(maxLength_);
  this->s_w_.resize(num);
  this->pi_w_.resize(num);

  mt = std::mt19937(seed);
  randomGen = std::uniform_real_distribution<double>(0.0, 1.0);
}

Species::~Species(void)
{
}

int Species::position(int n)
{
  int k=-1, sw=0;
  int num = this->popSize_ + this->maxChildren_;
  if(n<0) {
    for(int i=0; i<num; ++i) {
      if(pi_w_[i]==0) {
        k = i;
      }
      if(k<0) {
        std::cerr << "there is no space." << std::endl;
        return -1;
      }
    } 
  } else {
    for(int i=0; i<num && sw==0; i++) {
      if(pi_w_[i]==2) {
        k++;
        if(k==n) {
          sw = 1;
          k = i;
        }
      } 
    } 
  }
  
  return k;
}

int Species::select(int method, double bias, double step)
{
  double sum = 0.0, x;
  int k, min, n, sw;
  int num = this->popSize_ + this->maxChildren_;
 
  // roulette selection
  switch(method) {
  case -1: // random
    n = 0;
    for(int i=0; i<num; ++i) {
      if(this->pi_w_[i] > 1) n++;
    }
    sum = 1.0 / static_cast<double>(n);
    for(int i=0; i<num; ++i) {
      if(this->pi_w_[i] > 1) this->ro_[i] = sum; 
    }
    break;

  case 0: // use fitness
    n = 0;
    break;

  case 1: // fitness - min
    break;

  case 2: // linear
    break;
  
  }
  
  sum = 0.0;
  for(int i=0; i<num; ++i) {
    if(this->pi_w_[i] > 1) {
      sum += this->ro_[i];
      this->ro_[i] = sum;
    } 
  }
  x = randomGen(mt);
  sw = k = 0;
  for(int i=0; i<num && sw==0; ++i) {
    if(this->pi_w_[i]>1) {
      if( x<= this->ro_[i] ) {
        sw = 1;
        k = i;
      } 
    } 
  }

  return k;
}

// init
void Species::init(void)
{
  int length, lid, sw1, sw2;
  int num = this->popSize_ + this->maxChildren_;
  for(int i=0; i<num; ++i) {
    this->pi_w_[i] = (i < this->popSize_) ? 1 : 0; 
  }

  // gene
  for(int i=0; i<this->popSize_; ++i) {
    sw1 = 0;
    while(sw1==0) {
      // gene length 
      if(minLength_ < 0) {
        length = maxLength_; 
      } else {
        length = static_cast<int>(randomGen(mt)*(maxLength_-minLength_+1)+minLength_);
        if(length>maxLength_) length = maxLength_;
      }
      this->len_[i] = length;
      // gene
      for(int j=0; j<length; ++j) {
        sw2 = 0;
        while(sw2==0) {
          lid = static_cast<int>(randomGen(mt)*(alleleUpper_-alleleLower_+1)+alleleLower_);
          if(lid>alleleUpper_) lid = alleleUpper_;
          ind_[i][j] = lid;
          // check duplicate
          sw1 = 1;
          if(this->dup_a_==0) {
            for(int k=0; k<this->len_[i] && sw2==0; ++k) {
              if(ind_[i][k]!=ind_[j][k]) sw2=1;
            }
            if(sw2==0) sw1=0;
          }
        }
      }
    }
  }
}

// output
void Species::out(int sw, int out_m, int gen, std::string filename)
{
  
}
