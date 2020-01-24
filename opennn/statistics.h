//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   S T A T I S T I C S   H E A D E R
//
//   Artificial Intelligence Techniques, SL
//   artelnics@artelnics.com

#ifndef STATISTICS_H
#define STATISTICS_H

// System includes

#include <math.h>
#include <vector>
#include <iostream>

// OpenNN includes

#include "config.h"
#include "functions.h"

// Eigen includes

#include "../eigen/Eigen/Eigen"
#include "../eigen/unsupported/Eigen/CXX11/Tensor"

using namespace std;
using namespace Eigen;

namespace OpenNN
{

/// This structure contains the simplest Descriptives for a set, variable, etc. It includes :

///
/// <ul>
/// <li> Minimum.
/// <li> Maximum.
/// <li> Mean.
/// <li> Standard Deviation.
/// </ul>

struct Descriptives {

  // Default constructor.

  explicit Descriptives();

  // Values constructor.

  explicit Descriptives(const type&, const type&, const type&, const type&);

  /// Destructor.

  virtual ~Descriptives();

  // Set methods

  void set_minimum(const type&);

  void set_maximum(const type&);

  void set_mean(const type&);

  void set_standard_deviation(const type&);

  Tensor<type, 1> to_vector() const;

  bool has_minimum_minus_one_maximum_one();

  bool has_mean_zero_standard_deviation_one();

  void save(const string &file_name) const;

  void print(const string& = "Basic descriptives:") const;

  /// Name of variable

  string name;

  /// Smallest value of a set, function, etc.

  type minimum = 0;

  /// Biggest value of a set, function, etc.

  type maximum = 0;

  /// Mean value of a set, function, etc.

  type mean = 0;

  /// Standard deviation value of a set, function, etc.

  type standard_deviation = 0;

};


/// BoxPlot is a visual aid to study the distributions of dataset variables.

/// This structure contains the essentials for making boxplots
/// and obtained the data generated by the boxplot :
/// <ul>
/// <li> Minimum.
/// <li> Maximum.
/// <li> Median.
/// <li> First Quartile.
/// <li> Third Quartile.
/// </ul>

struct BoxPlot {

  // Default constructor.

  explicit BoxPlot() {}

  // Values constructor.

  explicit BoxPlot(const type&, const type&, const type&, const type&, const type& );

  virtual ~BoxPlot() {}

  type minimum;

  type first_quartile;

  type median;

  type third_quartile;

  type maximum;
};


/// The Histograms is a visual aid to study the distributions of dataset variables.

///
/// This structure contains the essentials for making histograms
/// and obtained the data generated by the histogram :
/// <ul>
/// <li> Minimum.
/// <li> Maximum.
/// <li> Centers.
/// <li> Frequencies.
/// </ul>

struct Histogram
{
  /// Default constructor.

  explicit Histogram();

  /// Bins number constructor.

  explicit Histogram(const Index &);

  /// Values constructor.

  explicit Histogram(const Tensor<type, 1>&, const Tensor<Index, 1>&);

  /// Destructor.

  virtual ~Histogram();

  // Methods

  Index get_bins_number() const;

  Index count_empty_bins() const;

  Index calculate_minimum_frequency() const;

  Index calculate_maximum_frequency() const;

  Index calculate_most_populated_bin() const;

  Tensor<type, 1> calculate_minimal_centers() const;

  Tensor<type, 1> calculate_maximal_centers() const;

  Index calculate_bin(const type&) const;

  Index calculate_frequency(const type&) const;

  /// Positions of the bins in the histogram.

  Tensor<type, 1> centers;

  /// Minimum positions of the bins in the histogram.

  Tensor<type, 1> minimums;

  /// Maximum positions of the bins in the histogram.

  Tensor<type, 1> maximums;

  /// Population of the bins in the histogram.

  Tensor<Index, 1> frequencies;
};


     // Minimum

     type minimum(const Tensor<type, 1>&);
     Index minimum(const Tensor<Index, 1>&);
     time_t minimum(const Tensor<time_t, 1>&);
     type minimum(const Tensor<type, 2>&);
     type minimum_missing_values(const Tensor<type, 1>&);
     Tensor<type, 1> columns_minimums(const Tensor<type, 2>&, const Tensor<Index, 1>& = Tensor<Index, 1>());

     // Maximum

     type maximum(const Tensor<type, 1>&);
     Index maximum(const Tensor<Index, 1>&);
     time_t maximum(const Tensor<time_t, 1>&);
     type maximum(const Tensor<type, 2>&);
     type maximum_missing_values(const Tensor<type, 1>&);
     Tensor<type, 1> columns_maximums(const Tensor<type, 2>&, const Tensor<Index, 1>& = Tensor<Index, 1>());

     type strongest(const Tensor<type, 1>&);

     // Range
     type range(const Tensor<type, 1>&);

     // Mean
     type mean(const Tensor<type, 1>&);
     type mean(const Tensor<type, 1>&, const Index&, const Index&);
     type mean(const Tensor<type, 2>&,  const Index&);
     Tensor<type, 1> mean(const Tensor<type, 2>&);
     Tensor<type, 1> mean(const Tensor<type, 2>&, const Tensor<Index, 1>&);
     Tensor<type, 1> mean(const Tensor<type, 2>&, const Tensor<Index, 1>&, const Tensor<Index, 1>&);
     type mean_missing_values(const Tensor<type, 1>&);
     Tensor<type, 1> mean_missing_values(const Tensor<type, 2>&, const Tensor<Index, 1>&, const Tensor<Index, 1>&);
     Tensor<type, 1> columns_mean(const Tensor<type, 2>&);
     Tensor<type, 1> rows_means(const Tensor<type, 2>&, const Tensor<Index, 1>&);

     // Median
     type median(const Tensor<type, 1>&);
     type median(const Tensor<type, 2>&, const Index&);
     Tensor<type, 1> median(const Tensor<type, 2>&);
     Tensor<type, 1> median(const Tensor<type, 2>&, const Tensor<Index, 1>&);
     Tensor<type, 1> median(const Tensor<type, 2>&, const Tensor<Index, 1>&, const Tensor<Index, 1>&);
     type median_missing_values(const Tensor<type, 1>&);
     Tensor<type, 1> median_missing_values(const Tensor<type, 2>&);
     Tensor<type, 1> median_missing_values(const Tensor<type, 2>&, const Tensor<Index, 1>&, const Tensor<Index, 1>&);

     // Variance
     type variance(const Tensor<type, 1>&);
     type variance_missing_values(const Tensor<type, 1>&);
     Tensor<type, 1> explained_variance(const Tensor<type, 1>&);

     // Standard deviation
     type standard_deviation(const Tensor<type, 1>&);
     Tensor<type, 1> standard_deviation(const Tensor<type, 1>&, const Index&);
     type standard_deviation_missing_values(const Tensor<type, 1>&);

     // Assymetry
     type asymmetry(const Tensor<type, 1>&);
     type asymmetry_missing_values(const Tensor<type, 1>&);

     // Kurtosis
     type kurtosis(const Tensor<type, 1>&);
     type kurtosis_missing_values(const Tensor<type, 1>&);

     // Quartiles
     Tensor<type, 1> quartiles(const Tensor<type, 1>&);
     Tensor<type, 1> quartiles_missing_values(const Tensor<type, 1>&);

     // Box plot
     BoxPlot box_plot(const Tensor<type, 1>&);
     BoxPlot box_plot_missing_values(const Tensor<type, 1>&);
     Tensor<BoxPlot, 1> box_plots(const Tensor<type, 2>&, const Tensor<Tensor<Index, 1>, 1>&, const Tensor<Index, 1>&);

     // Descriptives vector
     Descriptives descriptives(const Tensor<type, 1>&);
     Descriptives descriptives_missing_values(const Tensor<type, 1>&);

     // Descriptives matrix
     Tensor<Descriptives, 1> descriptives(const Tensor<type, 2>&);
     Tensor<Descriptives, 1> descriptives(const Tensor<type, 2>&);
     Tensor<Descriptives, 1> descriptives(const Tensor<type, 2>&, const Tensor<Index, 1>&, const Tensor<Index, 1>&);
     Tensor<Descriptives, 1> descriptives_missing_values(const Tensor<type, 2>&);
     Tensor<Descriptives, 1> descriptives_missing_values(const Tensor<type, 2>&, const Tensor<Index, 1>&, const Tensor<Index, 1>&);

     // Histograms
     Histogram histogram(const Tensor<type, 1>&, const Index & = 10);
     Histogram histogram_missing_values(const Tensor<type, 1>&, const Index & = 10);
     Histogram histogram_centered(const Tensor<type, 1>&, const type& = 0.0, const Index & = 10);
     Histogram histogram(const Tensor<bool, 1>&);
     Histogram histogram(const Tensor<Index, 1>&, const Index & = 10);
     Tensor<Histogram, 1> histograms(const Tensor<type, 2>&, const Index& = 10);
     Tensor<Histogram, 1> histograms_missing_values(const Tensor<type, 2>& matrix, const Index& bins_number);
     Tensor<Index, 1> total_frequencies(const Tensor<Histogram, 1>&);

     // Distribution
     Index perform_distribution_distance_analysis(const Tensor<type, 1>&);
     Index perform_distribution_distance_analysis_missing_values(const Tensor<type, 1>&, const Tensor<Index, 1>&);
     type normal_distribution_distance(const Tensor<type, 1>&);
     type half_normal_distribution_distance(const Tensor<type, 1>&);
     type uniform_distribution_distance(const Tensor<type, 1>&);

     // Normality
     Tensor<bool, 1> perform_normality_analysis(const Tensor<type, 1>&);
     type normality_parameter(const Tensor<type, 1>&);
     //bool perform_Lilliefors_normality_test(const Tensor<type, 1>&, const type&);
     //Tensor<bool, 1> perform_Lilliefors_normality_test(const Tensor<type, 1>&, const Tensor<type, 1>&);

     // Minimal indices
     Index minimal_index(const Tensor<type, 1>&);
     Tensor<Index, 1> minimal_indices(const Tensor<type, 1>&, const Index &);
     Tensor<Index, 1> minimal_indices_omit(const Tensor<type, 2>&, const type&);
     Tensor<Index, 1> minimal_indices(const Tensor<type, 2>&);

     // Maximal indices
     Index maximal_index(const Tensor<type, 1>&);
     Tensor<Index, 1> maximal_indices(const Tensor<type, 1>&, const Index &);
     Tensor<Index, 1> maximal_indices(const Tensor<type, 2>&);
     Tensor<Index, 1> maximal_indices_omit(const Tensor<type, 2>&, const type&);
     Tensor<type, 1> variation_percentage(const Tensor<type, 1>&);
     type column_minimum(const Index&);
     type column_maximum(const Index&);

     // Means binary
     Tensor<type, 1> means_binary_column(const Tensor<type, 2>&);
     Tensor<type, 1> means_binary_columns(const Tensor<type, 2>&);
     Tensor<type, 1> means_binary_columns_missing_values(const Tensor<type, 2>&);

     // Mean weights
     type weighted_mean(const Tensor<type, 1>&, const Tensor<type, 1>&);
     Tensor<Index, 1> maximal_indices();
     Tensor<Tensor<Index, 1>, 1> minimal_maximal_indices();

     // Percentiles
     Tensor<type, 1> percentiles(const Tensor<type, 1>&);
     Tensor<type, 1> percentiles_missing_values(const Tensor<type, 1>&);

     // Means by categories
     Tensor<type, 1> means_by_categories(const Tensor<type, 2>& matrix);
     Tensor<type, 1> means_by_categories_missing_values(const Tensor<type, 2>& matrix);

     // Means continuous
}

#endif // __STATISTICS_H
