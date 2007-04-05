//Fuzzy Function Approximation
#ifndef FuzzyApprox_H
#define FuzzyApprox_H
#include <vector>
#include "common.h"
#include "processor.h"
#include "mem_hierarchy.h"
#include "RuleList.h"
#include "FunctionApprox.h"

#define ERR_MEMORY 20

class CFuzzyFunctionApproximation : public CFunctionApproximation {

public:
  CFuzzyFunctionApproximation();
  ~CFuzzyFunctionApproximation();

  bool Init(REAL _threshold, int min, int max, int nouts);
  
  bool FuzzySetsInit(const vector<pair<int,int> >& min_max);
  bool StartUp(int MaxNumberOfRules, REAL threshold, int _min, int _max);
 
  bool Learn(REAL* InputValues, REAL* OutputValues);
  bool Learn(Configuration conf,Simulation sim,Processor& p,Mem_hierarchy& mem);
  bool Learn(const Configuration& conf,const Dynamic_stats& dyn);
  bool GenerateInputFuzzySets(int Dimensionality, int* InputFuzzySetsNumberVector, REAL *InMinimumValuesVector, REAL *InMaximumValuesVector);
  bool EstimateG(REAL* InputValues,REAL* OutputVector);
  Simulation Estimate1(Configuration conf,Processor& p,Mem_hierarchy& mem);
  Dynamic_stats Estimate2(Configuration conf);
  bool Reliable();
  int GetSystem();
  void Clean();

private:
  int position();
  int InDim,OutDim;
  int *InputSetsNumber;
  REAL *InputsMin;
  REAL *InputsMax;
  REAL *InputCenters;
  CRuleList *RuleTable;
  Rule newRule;
  REAL *estimatedValues;
  REAL *degrees;
  REAL *alpha;
  int *Sets;
  int count;
  bool calcola;
  REAL *errore;
  REAL **errmatrix;
  int prove;
  REAL *stima;
  REAL threshold;
  int min_sims,max_sims;
  int posx;
  FILE* fuzzy_log;
  FILE* fuzzy_error;
};
#endif
