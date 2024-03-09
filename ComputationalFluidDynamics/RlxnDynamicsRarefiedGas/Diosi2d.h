// ==============================================================================
//
//  Diosi2d.h
//  QTR
//
//  Created by Albert Lu on 10/5/19.
//  alu@tacc.utexas.edu
//
//  Last modified on 4/14/20
//
//  Note:
//
// ==============================================================================

#ifndef QTR_DIOSI2D_H
#define QTR_DIOSI2D_H

#include <complex>

#include "Containers.h"
#include "Eigen.h"
#include "Pointers.h"

namespace QTR_NS {
    
    class Diosi2d {
        
    public:
        Diosi2d(class QTR *q);
        ~Diosi2d();
  
        void                          Evolve();
        VectorXi                      IdxToGrid(int idx);
        inline int                    GridToIdx(int x1, int x2);

        inline double                 Wavefunction_DW1(double x1, double x2);
        inline double                 Potential_DW1(double x1, double x2);
        inline double                 Vx_DW1(double x1, double x2);
        inline double                 Vxxx_DW1(double x1, double x2);

        inline double                 Wavefunction_DW2(double x1, double x2);
        inline double                 Potential_DW2(double x1, double x2);
        inline double                 Vx_DW2(double x1, double x2);
        inline double                 Vxxx_DW2(double x1, double x2);

        inline double                 Wavefunction_DW3(double x1, double x2);
        inline double                 Potential_DW3(double x1, double x2);
        inline double                 Vx_DW3(double x1, double x2);
        inline double                 Vxxx_DW3(double x1, double x2);

        inline double                 Wavefunction_DW4(double x1, double x2);
        inline double                 Potential_DW4(double x1, double x2);
        inline double                 Vx_DW4(double x1, double x2);
        inline double                 Vxxx_DW4(double x1, double x2);

        inline double                 Wavefunction_DW5(double x1, double x2);
        inline double                 Potential_DW5(double x1, double x2);
        inline double                 Vx_DW5(double x1, double x2);
        inline double                 Vxxx_DW5(double x1, double x2);

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
        int             PERIOD;
        int             SORT_PERIOD;
        int             PRINT_PERIOD;
        int             PRINT_WAVEFUNC_PERIOD;
        int             GRIDS_TOT;
        bool            QUIET;
        bool            TIMING;
        double          TIME;   
        double          PI_INV;  // 1/pi

        // Grid size
        double          kk;    // time resolution
        VectorXd        H;     // grid size
        VectorXd        Hi;    // inverse grid size
        VectorXd        Hisq;  // inverse grid size square     
        VectorXd        S;  

        // Domain size
        VectorXd        Box;
        VectorXi        BoxShape;
        int             M1;
        int             W1;
        int             O1;

        // Potential parameters
        int             idx_x0;  
        int             skin;     
        bool            isModCL;
        bool            isDampX1;
        bool            isDampX2;
        double          trans_x0; 
        double          hb;
        double          m;
        double          kb;
        double          temp;
        double          gamma;
        double          omega;
        double          alpha;
        double          lambda;
        double          V0;
        double          quantumness;

        // Wavefunction
        VectorXd        Wave0;
        VectorXd        A;
        VectorXd        P;

        // Truncate parameters
        bool            isEmpty;
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
        bool            isPrintWavefunc;
        bool            isDensityMatrix;

        // Condition for Local Maxwellian
        bool            isIsothermal;
        bool            isLinearizedCollision;
    };
}

#endif /* QTR_DIOSI2D_H */
