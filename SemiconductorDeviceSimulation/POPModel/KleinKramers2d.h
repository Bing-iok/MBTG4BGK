// ==============================================================================
//
//  KleinKramers2d.h
//  QTR
//
//  Created by Albert Lu on 8/13/19.
//  alu@tacc.utexas.edu
//
//  Last modified on 7/12/22
//
//  Note:
//
// ==============================================================================

#ifndef QTR_KLEINKRAMERS2D_H
#define QTR_KLEINKRAMERS2D_H

#include <complex>

#include "Containers.h"
#include "Eigen.h"
#include "Pointers.h"

namespace QTR_NS {
    
    class KleinKramers2d {
        
    public:
        KleinKramers2d(class QTR *q);
        ~KleinKramers2d();
  
        void                          Evolve();
        VectorXi                      IdxToGrid(int idx);
        inline int                    GridToIdx(int x1, int x2);

        inline double                 Wavefunction_DW1(double x1, double x2);
        inline double                 Potential_DW1(double x1, double x2);
        inline double                 Vx_DW1(double x1, double x2);

        inline double                 Wavefunction_DW2(double x1, double x2);
        inline double                 Potential_DW2(double x1);
        inline double                 Vx_DW2(double x1);
        inline double                 DopingProfile_GaAs(double x1);

        inline double                 Wavefunction_DW3(double x1, double x2);
        inline double                 Potential_DW3(double x1, double x2);
        inline double                 Vx_DW3(double x1, double x2);

    private:

        void            init();
        QTR             *qtr;
        Error           *err;
        Log             *log;
        Parameters      *parameters;

        // General parameters
        std::complex<double>  I;      // sqrt(-1)
        std::complex<double>  xZERO;  // complex zero
        int             DIMENSIONS;
        int             EDGE;
        int             PERIOD;
        int             SORT_PERIOD;
        int             PRINT_PERIOD;
        int             PRINT_WAVEFUNC_PERIOD;
        int             GRIDS_TOT;
        bool            QUIET;
        bool            TIMING;
        double          TIME;   
        double          PI_INV;  // 1/pi
        double          HBSQ_INV; // (1/hb)^2
        double          PIHB_INV; // 1/hb/pi

        // Grid size
        double          kk;    // time resolution
        VectorXd        H;     // grid size
        VectorXd        S;  
        int Np;                // Number of Grid Points in Momentum Space.

        // Domain size
        VectorXd        Box;
        VectorXi        BoxShape;
        int             M1;
        int             W1;
        int             O1;

        // Potential parameters
        int             idx_x0; 
        double          trans_x0;      
        double          hb;
        double          m;
        double          kb;
        double          temp;
        double          gamma;
        double          chempotl;
        double          chempotr;
        double          chempotbarr;
        double          biasvol;
        double          potl;
        double          potr;
        double          charge;
        double          permittivity;
        double          popenergy;
        double          vacpermittivity;
        double          dielconst;
        double          hfdielconst;
        int             lcorr;
        double          latconst;

        // Wavefunction
        VectorXd        Wave0;
        VectorXd        A;
        VectorXd        P;

        // Truncate parameters
        bool            isFullGrid; 
        bool            isExtrapolate;  
        bool            isTouchBoundary;       
        double          TolH;
        double          TolL;
        double          TolHd;
        double          TolLd;
        double          ExReduce;
        int             ExLimit;

        // Domains
        MeshIndex       TA;
        MeshIndex       TB;    // Truncation boundary
        MeshIndex       TBL;
        MeshIndex       TBL_P;          
        MeshIndex       DBi;   // Grid boundary
        MeshIndex       DBi2;  // Extrapolation-restricted area
        MeshIndex       ExFF;
        MeshIndex       ExFF2;

        // Output
        bool            isTrans;
        bool            isCorr;
        bool            isPrintEdge;
        bool            isPrintDensity;
        bool            isPrintLocalDensity;
        bool            isPrintDriftVelocity;
        bool            isPrintLocalTemperature;
        bool            isPrintElectricField;
        bool            isPrintElectricPotential;
        bool            isPrintWavefunc;

        // Condition for Local Maxwellian
        bool            isIsothermal;
        bool            isLinearizedCollision;
    };
}

#endif /* QTR_KLEINKRAMERS2D_H */
