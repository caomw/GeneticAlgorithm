#ifndef __GENE_HEADER__
#define __GENE_HEADER__

#include <string>

class Gene {

  private:
    std::size_t value_;
    std::size_t max_value_;

  public:
    Gene(void)
    {
    }
    Gene(const std::size_t value)
      : value_(value)
    {
    }


    std::size_t GetValue(void)
    {
      return this->value_;
    }
    void SetValue(std::size_t value)
    {
      this->value_ = value;
    }

    std::size_t GetMaxValue(void)
    {
      return this->max_value_;
    }
    void SetMaxValue(std::size_t max_value)
    {
      this->max_value_ = max_value;
    }
};

#endif
