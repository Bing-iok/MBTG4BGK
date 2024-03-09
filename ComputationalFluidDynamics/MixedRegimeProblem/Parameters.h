// ==============================================================================
//
//  Parameters.h
//  QTR
//
//  Created by Albert Lu on 8/4/18.
//  alu@tacc.utexas.edu
//
//  Last modified on 7/12/22
//
//  Note:
//
// ==============================================================================

#ifndef QTR_PARAMETERS_H
#define QTR_PARAMETERS_H

#ifdef QTRMPI
#include <mpi.h>
#endif

#include <string>

#include "Pointers.h"

using std::string;

namespace QTR_NS   {
    
    class Parameters : protected Pointers   {
        
    public:
        
        Parameters();
        ~Parameters();
        
        int      load(string filename);
        int      load(FILE *file);
        
        // MAIN //
        string   job;
        string   inFilename;
        string   logFilename;
        bool     quiet;
        bool     timing;
        bool     writeLog;
        
        // MPI //
# ifdef QTRMPI
        MPI_Comm   universe;
        MPI_Comm   world;
# endif
        long     i;
        int      me;
        int      nprocs;
     
        // SCATTERXD //
        int      scxd_dimensions;
        bool     scxd_isFullGrid;
        bool     scxd_isTrans;
        bool     scxd_isAcf;
        bool     scxd_isDensityMatrix;
        bool     scxd_isPrintEdge;
        bool     scxd_isPrintDensity;
        bool     scxd_isPrintLocalDensity;
        bool     scxd_isPrintDriftVelocity;
        bool     scxd_isPrintLocalTemperature;
        bool     scxd_isPrintElectricField;
        bool     scxd_isPrintWavefunc;
        bool     scxd_isIsothermal;
        bool     scxd_isLinearizedCollision;
        bool     scxd_isModCL;
        bool     scxd_isDampX1;
        bool     scxd_isDampX2;
        int      scxd_Vmode_1;
        int      scxd_Vmode_2;
        int      scxd_Vmode_3; 
        int      scxd_Vmode_4;    
        int      scxd_period;
        int      scxd_sortperiod;
        int      scxd_printperiod;
        int      scxd_printwavefuncperiod;
        int      scxd_ExLimit;
        int      scxd_cfactor;
        int      scxd_skin;
        int      scxd_edge;
        int      scxd_Np;
        int      scxd_lcorr;  // correlation length
        double     scxd_k;
        double     scxd_h1;
        double     scxd_h2;
        double     scxd_h3;
        double     scxd_h4;
        double     scxd_xi1;
        double     scxd_xf1;
        double     scxd_xi2;
        double     scxd_xf2;
        double     scxd_xi3;
        double     scxd_xf3;
        double     scxd_xi4;
        double     scxd_xf4;
        double     scxd_bi1;
        double     scxd_bf1;
        double     scxd_bi2;
        double     scxd_bf2;
        double     scxd_bi3;
        double     scxd_bf3;
        double     scxd_bi4;
        double     scxd_bf4;
        double     scxd_Tf;
        double     scxd_x01;
        double     scxd_x02;
        double     scxd_x03;
        double     scxd_x04;
        double     scxd_a1;
        double     scxd_a2;
        double     scxd_a3; 
        double     scxd_a4;  
        double     scxd_p1;
        double     scxd_p2;
        double     scxd_p3; 
        double     scxd_p4;                
        double     scxd_hb;
        double     scxd_m;
        double     scxd_TolH;
        double     scxd_TolL;
        double     scxd_TolHd;
        double     scxd_TolLd;
        double     scxd_ExReduce;
        double     scxd_w;  // HO specific
        double     scxd_V0; // Eckart potential 
        double     scxd_ek2v;
        double     scxd_alpha;          
        double     scxd_k0; // Related HO
        double     scxd_sig;        
        double     scxd_lan;         
        double     scxd_De; // Morse
        double     scxd_Da;
        double     scxd_r0;
        double     scxd_lambda; // Henon-Heiles
        double     scxd_sigma;  // Scek
        double     scxd_beta;   // Gauk
        double     scxd_dk;     // Spectrum
        double     scxd_kmax;   // Spectrum
        double     scxd_kb;     // phase
        double     scxd_temp;   // phase
        double     scxd_gamma;  // phase
        double     scxd_chempotl;
        double     scxd_chempotr;
        double     scxd_chempotbarr;
        double     scxd_biasvol;
        double     scxd_potl;
        double     scxd_potr;
        double     scxd_charge;
        double     scxd_permittivity;
        double     scxd_latconst; // lattice constant for potential
        double     scxd_omega;  // phase
        double     scxd_trans_x0;
        double     scxd_quantumness;
        
        // RANDOM //
        string     rngType;
        long       rngSeed;
        
    private:
        
        string toLowerCase(string s);
    };

}

#endif /* QTR_PARAMETERS_H */
