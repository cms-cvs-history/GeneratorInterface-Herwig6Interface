#ifndef gen_Herwig6Instance_h
#define gen_Herwig6Instance_h

#include "GeneratorInterface/Core/interface/FortranInstance.h"

namespace CLHEP { class HepRandomEngine; } // forward declaration

namespace gen {

// the callbacks from Herwig which are passed on to the Herwig6Instance
extern "C" {
	double hwrgen_(int*);
}

class Herwig6Instance : public FortranInstance {
    public:
	Herwig6Instance(CLHEP::HepRandomEngine *randomEngine = 0);
	virtual ~Herwig6Instance();

	// passes a configuration parameter
	bool give(const std::string &line);

	bool callWithTimeout(unsigned int secs, void (*fn)())
	{ InstanceWrapper wrapper(this); return timeout(secs, fn); }

    private:
	// list all the Fortran callbacks here
	friend double gen::hwrgen_(int*);

	// call with timeout
	bool timeout(unsigned int secs, void (*fn)());

	// used from timeout
	static void _timeout_sighandler(int signr);

	// the random engine
	// in order to make sure no one else uses this engine
	// the access is only possible if pyr_ is called after
	// the current instance has been selected using enter()
	// if Herwig is called without an active instance and does
	// either a callback or requests a random number an
	// an exception will be thrown
	CLHEP::HepRandomEngine	*randomEngine;

	// for timeout facility
	void			*timeoutPrivate;
};

} // namespace gen

#endif // gen_Herwig6Instance_h
