// tag::doc[]
#include <numeric>
#include <random>
#include <vector>

namespace nerva {

inline
std::vector<std::size_t> reservoir_sample(std::size_t k, std::size_t n, std::mt19937& rng)
{
  std::vector<std::size_t> reservoir(k);
  std::iota(reservoir.begin(), reservoir.end(), 0);

  for (std::size_t i = k; i < n; i++)
  {
    std::uniform_int_distribution<unsigned int> dist(0, i + 1);
    auto j = dist(rng);
    if (j < k)
    {
      reservoir[j] = i;
    }
  }

  return reservoir;
}

} // namespace nerva

int main()
{
  std::mt19937 rng{static_cast<unsigned int>(12345)};
  auto x = nerva::reservoir_sample(3, 5, rng);
  return 0;
}
// end::doc[]
