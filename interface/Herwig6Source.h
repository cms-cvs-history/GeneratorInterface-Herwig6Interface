#ifndef Herwig6Source_h
#define Herwig6Source_h

/** \class Herwig6Source
 *
 * Generates Herwig HepMC events
 *
 ***************************************/


#include "FWCore/Framework/interface/GeneratedInputSource.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include <map>
#include <string>
#include "HepMC/GenEvent.h"

class Run;

namespace edm
{
  class Herwig6Source : public GeneratedInputSource {

  public:

    Herwig6Source(const ParameterSet &, const InputSourceDescription &);
    virtual ~Herwig6Source();

    void endRun( Run& r);

  private:

    virtual bool produce(Event & e);
    void clear();

    bool hwgive(const std::string& iParm );
    bool setRngSeeds(int);

    HepMC::GenEvent  *evt;
    int herwigVerbosity_;
    bool herwigHepMCVerbosity_;
    int herwigLhapdfVerbosity_;
    int maxEventsToPrint_;
    double comenergy;
    std::string lhapdfSetPath_;
    bool useJimmy_;
    bool doMPInteraction_;
    bool printCards_;
    int numTrials_;

    double extCrossSect;
    double intCrossSect;
    double extFilterEff;

  };
} 

#endif
